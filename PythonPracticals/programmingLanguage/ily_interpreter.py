# ily_interpreter.py
# Minimal Ily language interpreter
# Usage: python ily_interpreter.py program.ily

import sys
import re

##### LEXER #####
TOKEN_SPEC = [
    ("NUMBER",   r"\d+"),
    ("ID",       r"[A-Za-z_][A-Za-z0-9_]*"),
    ("ASSIGN",   r"="),
    ("LPAREN",   r"\("),
    ("RPAREN",   r"\)"),
    ("LBRACE",   r"\{"),
    ("RBRACE",   r"\}"),
    ("COMMA",    r","),
    ("SEMICOLON",r";"),
    ("PLUS",     r"\+"),
    ("MINUS",    r"-"),
    ("MUL",      r"\*"),
    ("DIV",      r"/"),
    ("EQ",       r"=="),
    ("NEQ",      r"!="),
    ("LT",       r"<"),
    ("GT",       r">"),
    ("LE",       r"<="),
    ("GE",       r">="),
    ("NEWLINE",  r"\n"),
    ("SKIP",     r"[ \t\r]+"),
    ("COMMENT",  r"//.*"),
]
TOK_REGEX = re.compile("|".join("(?P<%s>%s)" % pair for pair in TOKEN_SPEC))

class Token:
    def __init__(self, typ, val):
        self.type = typ
        self.value = val
    def __repr__(self):
        return f"Token({self.type},{self.value})"

def lex(code):
    pos = 0
    while pos < len(code):
        m = TOK_REGEX.match(code, pos)
        if not m:
            raise SyntaxError(f"Illegal char at {pos}: {code[pos]!r}")
        typ = m.lastgroup
        val = m.group(typ)
        pos = m.end()
        if typ == "NUMBER":
            yield Token("NUMBER", int(val))
        elif typ == "ID":
            yield Token("ID", val)
        elif typ == "NEWLINE" or typ == "SKIP" or typ == "COMMENT":
            continue
        else:
            yield Token(typ, val)
    yield Token("EOF", "")

##### PARSER (recursive descent) #####
class Parser:
    def __init__(self, tokens):
        self.tokens = iter(tokens)
        self._advance()
    def _advance(self):
        self.cur = next(self.tokens)
    def _accept(self, typ):
        if self.cur.type == typ:
            val = self.cur.value
            self._advance()
            return val
        return None
    def _expect(self, typ):
        if self.cur.type == typ:
            val = self.cur.value
            self._advance()
            return val
        raise SyntaxError(f"Expected {typ} but got {self.cur}")

    # program: stmt*
    def parse(self):
        stmts = []
        while self.cur.type != "EOF":
            stmts.append(self.stmt())
        return ("block", stmts)

    def stmt(self):
        # Skip empty statement
        if self.cur.type == "SEMICOLON":
            self._advance()
            return ("nop",)

        # print statement
        if self.cur.type == "ID" and self.cur.value == "print":
            return self.print_stmt()

        # function definition
        if self.cur.type == "ID" and self.cur.value == "fn":
            return self.fn_def()

        # assignment or expression
        if self.cur.type == "ID":
            name = self.cur.value
            self._advance()
            if self.cur.type == "ASSIGN":
                self._advance()
                expr = self.expr()
                if self.cur.type == "SEMICOLON":
                    self._advance()
                return ("assign", name, expr)
            else:
                # expression beginning with identifier
                left = ("var", name)
                expr = self._expr_tail(left)
                if self.cur.type == "SEMICOLON":
                    self._advance()
                return ("expr", expr)

        # generic expression
        e = self.expr()
        if self.cur.type == "SEMICOLON":
            self._advance()
        return ("expr", e)

    def print_stmt(self):
        self._expect("ID")  # print
        self._expect("LPAREN")
        expr = self.expr()
        self._expect("RPAREN")
        if self.cur.type == "SEMICOLON":
            self._advance()
        return ("print", expr)

    def fn_def(self):
        self._expect("ID")  # fn
        name = self._expect("ID")
        self._expect("LPAREN")
        params = []
        if self.cur.type != "RPAREN":
            params.append(self._expect("ID"))
            while self._accept("COMMA"):
                params.append(self._expect("ID"))
        self._expect("RPAREN")
        body = self.block()
        return ("fn", name, params, body)

    def block(self):
        self._expect("LBRACE")
        stmts = []
        while self.cur.type != "RBRACE":
            stmts.append(self.stmt())
        self._expect("RBRACE")
        return ("block", stmts)

    def expr(self):
        left = self.term()
        return self._expr_tail(left)

    def _expr_tail(self, left):
        while self.cur.type in ("PLUS","MINUS"):
            op = self.cur.type
            self._advance()
            right = self.term()
            left = ("binop", op, left, right)
        return left

    def term(self):
        left = self.factor()
        while self.cur.type in ("MUL","DIV"):
            op = self.cur.type
            self._advance()
            right = self.factor()
            left = ("binop", op, left, right)
        return left

    def factor(self):
        if self._accept("NUMBER") is not None:
            return ("num", self.tokens_consumed_value)  # placeholder
        # simplified because we can't peek previous consumed value easily
        # so instead let's check cur was NUMBER before advance; adjust:
        if self.cur.type == "NUMBER":
            val = self.cur.value
            self._advance()
            return ("num", val)
        if self.cur.type == "ID":
            name = self.cur.value
            self._advance()
            if self.cur.type == "LPAREN":
                # function call
                self._advance()
                args = []
                if self.cur.type != "RPAREN":
                    args.append(self.expr())
                    while self._accept("COMMA"):
                        args.append(self.expr())
                self._expect("RPAREN")
                return ("call", name, args)
            return ("var", name)
        if self._accept("LPAREN"):
            e = self.expr()
            self._expect("RPAREN")
            return e
        raise SyntaxError(f"Unexpected token in factor: {self.cur}")

##### EVALUATOR #####
class Env(dict):
    def extend(self):
        e = Env()
        e.update(self)
        return e

class Function:
    def __init__(self, params, body, env):
        self.params = params
        self.body = body
        self.env = env

def eval_node(node, env):
    typ = node[0]
    if typ == "block":
        res = None
        for s in node[1]:
            res = eval_node(s, env)
            if isinstance(res, tuple) and res[0] == "return":
                return res
        return res
    if typ == "num":
        return node[1]
    if typ == "var":
        name = node[1]
        if name in env:
            return env[name]
        raise NameError(f"Name {name} not defined")
    if typ == "assign":
        _, name, expr = node
        val = eval_node(expr, env)
        env[name] = val
        return val
    if typ == "binop":
        _, op, left, right = node
        a = eval_node(left, env)
        b = eval_node(right, env)
        if op == "PLUS": return a + b
        if op == "MINUS": return a - b
        if op == "MUL": return a * b
        if op == "DIV": return a // b
    if typ == "print":
        val = eval_node(node[1], env)
        print(val)
    if typ == "fn":
        _, name, params, body = node
        env[name] = Function(params, body, env.copy())
    if typ == "call":
        _, name, args = node
        if name == "print":  # builtin
            for a in args:
                print(eval_node(a, env))
            return None
        fn = env.get(name)
        if not isinstance(fn, Function):
            raise TypeError(f"{name} is not a function")
        if len(args) != len(fn.params):
            raise TypeError("arg count mismatch")
        local = fn.env.copy()
        for p, a in zip(fn.params, args):
            local[p] = eval_node(a, env)
        res = eval_node(fn.body, local)
        if isinstance(res, tuple) and res[0] == "return":
            return res[1]
        return None
    if typ == "expr":
        return eval_node(node[1], env)
    raise NotImplementedError(f"Eval for {typ} not implemented")

##### DRIVER #####
def run(code):
    tokens = list(lex(code))
    p = Parser(iter(tokens))
    ast = p.parse()
    global_env = Env()
    # add builtin print (we also used print as statement above)
    global_env["print"] = "builtin"
    return eval_node(ast, global_env)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python ily_interpreter.py file.ily")
        sys.exit(1)
    fname = sys.argv[1]
    source = open(fname).read()
    run(source)
