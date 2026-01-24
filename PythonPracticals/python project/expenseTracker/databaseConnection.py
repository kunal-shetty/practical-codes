
import pymysql

def connectToDatabase():
    return pymysql.connect(
        host="localhost",
        user="root",
        password="",
        database="Expenses"
    )

def getAllExpenses():
    conn = connectToDatabase()
    cur = conn.cursor()

    query = """
        SELECT expenseId, expenseAmount, expenseName, description, category, paymentMode, date
        FROM Expenses
        WHERE del = 0
    """
    cur.execute(query)
    rows = cur.fetchall()
    for row in rows:
        expenseId = row[0]
        expenseName = row[2]
        expenseAmount = float(row[1])  # Convert Decimal -> float
        description = row[3]
        category = row[4]
        paymentMode = row[5]
        date = row[6].strftime("%Y-%m-%d") # Convert date -> string

        print(expenseName, expenseAmount, description, category, paymentMode, date)

    conn.close()
    return rows


def getTotalExpenseAmount(dateFrom=None, dateTo=None):
    conn = connectToDatabase()
    cur = conn.cursor()

    query = """SELECT SUM(expenseAmount) AS totalExpense
               FROM Expenses
               WHERE del = 0"""
    params = []

    if dateFrom and dateTo:
        query += " AND date BETWEEN %s AND %s"
        params.extend([dateFrom, dateTo])
    elif dateFrom:  # Only from date
        query += " AND date >= %s"
        params.append(dateFrom)
    elif dateTo:  # Only to date
        query += " AND date <= %s"
        params.append(dateTo)

    cur.execute(query, params)
    row = cur.fetchone()

    return float(row[0]) if row[0] is not None else 0.0


def getOneExpense(expenseId):
    conn = connectToDatabase()
    cur = conn.cursor()

    query = """
            SELECT expenseName, expenseAmount, description, category, paymentMode, date
            FROM Expenses
            WHERE expenseId = %s AND del = 0 
        """
    params = (expenseId,)
    cur.execute(query, params)
    row = cur.fetchone()
    if row:
        expenseName = row[0]
        expenseAmount = float(row[1])           # Decimal -> float
        description = row[2]
        category = row[3]
        paymentMode = row[4]
        date = row[5].strftime("%Y-%m-%d")      # date -> string

        print(expenseName, expenseAmount, description, category, paymentMode, date)
    else:
        print("No expense found with given ID")

    conn.close()

def addNewExpense(expenseName, expenseAmount, description, category, paymentMode, date):
    conn = connectToDatabase()
    cur = conn.cursor()

    query = """
        INSERT INTO Expenses (expenseName, expenseAmount, description, category, paymentMode, date)
        VALUES (%s, %s, %s, %s, %s, %s)
    """
    values = (expenseName, expenseAmount, description, category, paymentMode, date)
    cur.execute(query, values)
    conn.commit()

    inserted_id = cur.lastrowid   # Get the auto-generated expenseId
    conn.close()

    return inserted_id


