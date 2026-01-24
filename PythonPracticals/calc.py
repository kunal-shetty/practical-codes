from gui.QtWidgets import (QApplication, QWidget, QLabel, QPushButton, QVBoxLayout, QInputDialog)
from gui.QtGui import QFont, QIcon
import sys
import math
import statistics

class Calculator(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Advanced Calculator - PyQt")
        self.setGeometry(100, 100, 400, 350)
        self.setWindowIcon(QIcon("calculator.png"))  # Optional: replace with your icon file

        # Apply dark mode theme with gradient
        self.setStyleSheet("""
            QWidget {
                background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,
                            stop:0 #2c3e50, stop:1 #4ca1af);
            }
            QPushButton {
                background-color: #1abc9c;
                color: white;
                border-radius: 8px;
                padding: 10px;
                font-size: 14px;
                font-weight: bold;
            }
            QPushButton:hover {
                background-color: #16a085;
            }
            QLabel {
                font-size: 16px;
                color: #ecf0f1;
            }
        """)

        self.layout = QVBoxLayout()

        self.label = QLabel("Select an Operation Category")
        self.label.setFont(QFont("Arial", 16, QFont.Bold))
        self.layout.addWidget(self.label)

        self.btn_basic = QPushButton("Basic Operations")
        self.btn_basic.clicked.connect(self.basic_operations)
        self.layout.addWidget(self.btn_basic)

        self.btn_adv = QPushButton("Advanced Math")
        self.btn_adv.clicked.connect(self.advanced_math)
        self.layout.addWidget(self.btn_adv)

        self.btn_trig = QPushButton("Trigonometry")
        self.btn_trig.clicked.connect(self.trigonometry)
        self.layout.addWidget(self.btn_trig)

        self.btn_stats = QPushButton("Statistics")
        self.btn_stats.clicked.connect(self.statistics_menu)
        self.layout.addWidget(self.btn_stats)

        self.result = QLabel("Result: ")
        self.result.setFont(QFont("Arial", 14))
        self.layout.addWidget(self.result)

        self.setLayout(self.layout)

    def show_result(self, result):
        self.result.setText(f"Result: {result}")

    def get_float_input(self, prompt):
        val, ok = QInputDialog.getDouble(self, "Input", prompt)
        return val if ok else None

    def get_text_input(self, prompt):
        text, ok = QInputDialog.getText(self, "Input", prompt)
        return text if ok else None

    def basic_operations(self):
        a = self.get_float_input("Enter first number:")
        b = self.get_float_input("Enter second number:")
        op = self.get_text_input("Choose: +, -, *, /, %")

        if None in [a, b] or op is None:
            return

        try:
            if op == '+': result = a + b
            elif op == '-': result = a - b
            elif op == '*': result = a * b
            elif op == '/': result = a / b if b != 0 else "Cannot divide by zero"
            elif op == '%': result = a % b
            else: result = "Invalid Operation"
        except Exception as e:
            result = str(e)

        self.show_result(result)

    def advanced_math(self):
        choice = self.get_text_input("Choose: pow, sqrt, root, log10, ln, abs, fact")
        if not choice:
            return

        try:
            if choice == 'pow':
                x = self.get_float_input("Base:")
                y = self.get_float_input("Exponent:")
                result = math.pow(x, y)
            elif choice == 'sqrt':
                x = self.get_float_input("Number:")
                result = math.sqrt(x)
            elif choice == 'root':
                x = self.get_float_input("Number:")
                n = self.get_float_input("Root:")
                result = x ** (1 / n)
            elif choice == 'log10':
                x = self.get_float_input("Number:")
                result = math.log10(x)
            elif choice == 'ln':
                x = self.get_float_input("Number:")
                result = math.log(x)
            elif choice == 'abs':
                x = self.get_float_input("Number:")
                result = abs(x)
            elif choice == 'fact':
                x = self.get_float_input("Integer:")
                result = math.factorial(int(x))
            else:
                result = "Invalid choice"
        except Exception as e:
            result = str(e)

        self.show_result(result)

    def trigonometry(self):
        choice = self.get_text_input("Choose: sin, cos, tan, arcsin, arccos, arctan, deg2rad, rad2deg")
        if not choice:
            return

        try:
            x = self.get_float_input("Enter value or angle:")
            if choice == 'sin': result = math.sin(math.radians(x))
            elif choice == 'cos': result = math.cos(math.radians(x))
            elif choice == 'tan': result = math.tan(math.radians(x))
            elif choice == 'arcsin': result = math.degrees(math.asin(x))
            elif choice == 'arccos': result = math.degrees(math.acos(x))
            elif choice == 'arctan': result = math.degrees(math.atan(x))
            elif choice == 'deg2rad': result = math.radians(x)
            elif choice == 'rad2deg': result = math.degrees(x)
            else: result = "Invalid choice"
        except Exception as e:
            result = str(e)

        self.show_result(result)

    def statistics_menu(self):
        try:
            data = self.get_text_input("Enter numbers separated by space:")
            nums = list(map(float, data.split()))
            choice = self.get_text_input("Choose: mean, median, mode, stdev, variance, min, max, range")

            if choice == 'mean': result = statistics.mean(nums)
            elif choice == 'median': result = statistics.median(nums)
            elif choice == 'mode': result = statistics.mode(nums)
            elif choice == 'stdev': result = statistics.stdev(nums)
            elif choice == 'variance': result = statistics.variance(nums)
            elif choice == 'min': result = min(nums)
            elif choice == 'max': result = max(nums)
            elif choice == 'range': result = max(nums) - min(nums)
            else: result = "Invalid choice"
        except Exception as e:
            result = str(e)

        self.show_result(result)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    calc = Calculator()
    calc.show()
    sys.exit(app.exec_())
