import tkinter as tk
from tkinter import messagebox

def submitForm():
    name = entryName.get().strip()
    email = entryEmail.get().strip()
    phone = entryPhone.get().strip()
    password = entryPassword.get().strip()
    dob = entryDOB.get().strip()
    account = accountVar.get()
    country = countryVar.get()
    terms = termsVar.get()

    # Validation
    if not name or not email or not phone or not password or not dob:
        messagebox.showerror("Incomplete Submission", "All fields are required!")
        return
    if not name.isalpha():
        messagebox.showerror("Input Error", "Name must contain only letters!")
        return
    if "@" not in email or "." not in email:
        messagebox.showerror("Input Error", "Please enter a valid email address!")
        return
    if not phone.isdigit() or len(phone) != 10:
        messagebox.showerror("Input Error", "Phone number must be exactly 10 digits!")
        return
    if len(password) < 8:
        messagebox.showerror("Input Error", "Password must be at least 8 characters!")
        return
    if not terms:
        messagebox.showerror("Agreement Required", "You must agree to the terms & conditions!")
        return

    address_text = textAddress.get("1.0", tk.END).strip()
    messagebox.showinfo("Form Submitted",
                        f"Name: {name}\nEmail: {email}\nPhone: {phone}\n"
                        f"Date of Birth: {dob}\nAccount: {account}\nCountry: {country}\n"
                        f"Address: {address_text}\nPassword: {password}")

def resetForm():
    entryName.delete(0, tk.END)
    entryEmail.delete(0, tk.END)
    entryPhone.delete(0, tk.END)
    entryPassword.delete(0, tk.END)
    entryDOB.delete(0, tk.END)
    accountVar.set("Student")
    countryVar.set("Select Country")
    textAddress.delete("1.0", tk.END)
    termsVar.set(0)
    updatesVar.set(0)

# === COLORS ===
BG_MAIN = "#fff9c4"   # light pastel yellow
BG_FRAME = "#fffde7"  # slightly lighter yellow frame
FG_TEXT = "#5d4037"   # warm brown text
BTN_YELLOW = "#fbc02d" # golden yellow
BTN_ORANGE = "#fb8c00" # deep orange

# Main Window
window = tk.Tk()
window.title("User Details Form")
window.geometry("470x650")
window.config(bg=BG_MAIN)

frame = tk.Frame(window, bg=BG_FRAME, bd=2, relief="ridge")
frame.pack(padx=20, pady=20, fill="both", expand=True)

# Name
tk.Label(text="Name:", font=("Arial", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=0, column=0, sticky="w", pady=5)
entryName = tk.Entry(font=("Arial", 12), width=30)
entryName.grid(row=0, column=1, pady=5)

# Email
tk.Label(frame, text="Email:", font=("Arial", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=1, column=0, sticky="w", pady=5)
entryEmail = tk.Entry(frame, font=("Arial", 12), width=30)
entryEmail.grid(row=1, column=1, pady=5)

# Phone
tk.Label(frame, text="Phone:", font=("Arial", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=2, column=0, sticky="w", pady=5)
entryPhone = tk.Entry(frame, font=("Arial", 12), width=30)
entryPhone.grid(row=2, column=1, pady=5)

# Password
tk.Label(frame, text="Password:", font=("Arial", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=3, column=0, sticky="w", pady=5)
entryPassword = tk.Entry(frame, font=("Arial", 12), width=30, show="*")
entryPassword.grid(row=3, column=1, pady=5)

# DOB
tk.Label(frame, text="Date of Birth:", font=("Arial", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=4, column=0, sticky="w", pady=5)
entryDOB = tk.Entry(frame, font=("Arial", 12), width=30)
entryDOB.grid(row=4, column=1, pady=5)

# Account Type (Radiobuttons)
tk.Label(frame, text="Account Type:", font=("Arial", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=5, column=0, sticky="w", pady=5)
accountVar = tk.StringVar(value="Student")
tk.Radiobutton(frame, text="Student", variable=accountVar, value="Student", bg=BG_FRAME, fg=FG_TEXT).grid(row=5, column=1, sticky="w")
tk.Radiobutton(frame, text="Professional", variable=accountVar, value="Professional", bg=BG_FRAME, fg=FG_TEXT).grid(row=5, column=1, padx=100, sticky="w")

# Country (Dropdown)
tk.Label(frame, text="Country:", font=("Arial", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=6, column=0, sticky="w", pady=5)
countryVar = tk.StringVar(value="Select Country")
countries = ["Select Country", "India", "USA", "UK", "Canada", "Australia"]
tk.OptionMenu(frame, countryVar, *countries).grid(row=6, column=1, sticky="w", pady=5)

# Address (Text Area)
tk.Label(frame, text="Address:", font=("Arial", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=7, column=0, sticky="nw", pady=5)
textAddress = tk.Text(frame, font=("Arial", 12), width=30, height=4)
textAddress.grid(row=7, column=1, pady=5)

# Checkbuttons
termsVar = tk.IntVar()
updatesVar = tk.IntVar()
tk.Checkbutton(window, text="I agree to the Terms & Conditions", variable=termsVar, font=("Arial", 12), bg=BG_MAIN, fg=FG_TEXT).pack(pady=5)
tk.Checkbutton(window, text="Receive Updates via Email", variable=updatesVar, font=("Arial", 12), bg=BG_MAIN, fg=FG_TEXT).pack(pady=5)

# Buttons
btnFrame = tk.Frame(window, bg=BG_MAIN)
btnFrame.pack(pady=20)
tk.Button(btnFrame, text="Submit", font=("Arial", 14, "bold"), bg=BTN_YELLOW, fg="black", command=submitForm).grid(row=0, column=0, padx=10)
tk.Button(btnFrame, text="Reset", font=("Arial", 14, "bold"), bg=BTN_ORANGE, fg="white", command=resetForm).grid(row=0, column=1, padx=10)

window.mainloop()

import pymysql
db = pymysql.connect(user='root',password='',host='localhost',db='college')
cursor = db.cursor()
query = "INSERT INTO studentData(name, email, phone, password) VALUES('entryName.get()', 'entryEmail.get()', 'entryPhone.get()', 'entryPassword.get()')"
cursor.execute(query)
db.commit()
db.close()