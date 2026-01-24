import matplotlib.pyplot as plt
import pandas as pd
from collections import defaultdict


def showCategoryChart(rows):
    """
    Creates a Pie Chart of expenses grouped by category.
    rows: list of tuples from getAllExpenses()
    """
    categories = defaultdict(float)
    for row in rows:
        category = row[4]
        amount = float(row[1])
        categories[category] += amount

    fig, ax = plt.subplots(figsize=(5, 5))
    ax.pie(categories.values(), labels=categories.keys(), autopct="%1.1f%%", startangle=140)
    ax.set_title("Category-wise Expenses")
    return fig


def showPaymentModeChart(rows):
    """
    Creates a Bar Chart of expenses grouped by payment mode.
    rows: list of tuples from getAllExpenses()
    """
    payments = defaultdict(float)
    for row in rows:
        payment = row[5]
        amount = float(row[2])
        payments[payment] += amount

    fig, ax = plt.subplots(figsize=(5, 4))
    ax.bar(payments.keys(), payments.values(), color="skyblue", edgecolor="black")
    ax.set_title("Payment Mode Distribution")
    ax.set_ylabel("Total Amount")
    return fig


def showMonthlyTrendChart(rows):
    """
    Creates a Line Chart of expenses grouped by month.
    rows: list of tuples from getAllExpenses()
    """
    data = []
    for row in rows:
        date = row[6]  # already a datetime object from DB
        amount = float(row[2])
        data.append({"date": date, "amount": amount})

    df = pd.DataFrame(data)
    df["month"] = pd.to_datetime(df["date"]).dt.to_period("M")
    monthly_expenses = df.groupby("month")["amount"].sum()

    fig, ax = plt.subplots(figsize=(6, 4))
    monthly_expenses.plot(ax=ax, marker="o", color="green", linewidth=2)
    ax.set_title("Monthly Expense Trend")
    ax.set_ylabel("Total Amount")
    ax.set_xlabel("Month")
    plt.xticks(rotation=45)
    return fig


def showAllCharts(rows):
    """
    Shows Category Pie, Payment Bar, and Monthly Trend in one figure.
    """
    categories = defaultdict(float)
    payments = defaultdict(float)
    data = []

    for row in rows:
        category = row[4]
        payment = row[5]
        date = row[6]
        amount = float(row[2])

        categories[category] += amount
        payments[payment] += amount
        data.append({"date": date, "amount": amount})

    df = pd.DataFrame(data)
    df["month"] = pd.to_datetime(df["date"]).dt.to_period("M")
    monthly_expenses = df.groupby("month")["amount"].sum()

    fig, axs = plt.subplots(1, 3, figsize=(14, 4))

    # Pie chart (categories)
    axs[0].pie(categories.values(), labels=categories.keys(), autopct="%1.1f%%")
    axs[0].set_title("Category-wise")

    # Bar chart (payment modes)
    axs[1].bar(payments.keys(), payments.values(), color="skyblue", edgecolor="black")
    axs[1].set_title("Payment Modes")

    # Line chart (monthly trend)
    monthly_expenses.plot(ax=axs[2], marker="o", color="green", linewidth=2)
    axs[2].set_title("Monthly Trend")
    axs[2].set_xlabel("Month")
    axs[2].set_ylabel("Amount")

    plt.tight_layout()
    return fig
