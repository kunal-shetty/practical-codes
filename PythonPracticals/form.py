import tkinter as tk
from tkinter import messagebox

def submitForm():
    name = entryName.get().strip()
    email = entryEmail.get().strip()
    phone = entryPhone.get().strip()
    password = entryPassword.get().strip()
    gender = genderVar.get()
    country = countryVar.get()
    terms = termsVar.get()

    if not name or not email or not phone or not password:
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
                        f"Gender: {gender}\nCountry: {country}\n"
                        f"Address: {address_text}\nPassword: {password}")

def resetForm():
    entryName.delete(0, tk.END)
    entryEmail.delete(0, tk.END)
    entryPhone.delete(0, tk.END)
    entryPassword.delete(0, tk.END)
    genderVar.set("Male")
    countryVar.set("Select Country")
    textAddress.delete("1.0", tk.END)
    termsVar.set(0)
    newsletterVar.set(0)

# Gradient background function
def draw_gradient(canvas, color1, color2):
    width = canvas.winfo_width()
    height = canvas.winfo_height()
    limit = height
    (r1, g1, b1) = canvas.winfo_rgb(color1)
    (r2, g2, b2) = canvas.winfo_rgb(color2)
    r_ratio = float(r2-r1) / limit
    g_ratio = float(g2-g1) / limit
    b_ratio = float(b2-b1) / limit
    canvas.delete("gradient")  # clear old gradient
    for i in range(limit):
        nr = int(r1 + (r_ratio * i))
        ng = int(g1 + (g_ratio * i))
        nb = int(b1 + (b_ratio * i))
        color = f"#{nr>>8:02x}{ng>>8:02x}{nb>>8:02x}"
        canvas.create_line(0, i, width, i, fill=color, tags="gradient")

# === COLORS ===
BG_FRAME = "#f3e5f5"   # light lavender
FG_TEXT = "#4a148c"    # deep purple
BTN_PURPLE = "#9c27b0"
BTN_PINK = "#ec407a"

# Main Window
window = tk.Tk()
window.title("User Details Form")
window.geometry("500x700")

# Gradient background
canvas = tk.Canvas(window, highlightthickness=0)
canvas.pack(fill="both", expand=True)
canvas.bind("<Configure>", lambda e: draw_gradient(canvas, "#ba68c8", "#f48fb1"))  # purple → pink gradient

# Frame for all widgets
mainFrame = tk.Frame(canvas, bg=BG_FRAME, bd=3, relief="ridge")
mainFrame.place(relx=0.5, rely=0.5, anchor="center")

# Name
tk.Label(mainFrame, text="Name:", font=("Century Gothic", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=0, column=0, sticky="w", pady=5)
entryName = tk.Entry(mainFrame, font=("Century Gothic", 12), width=30)
entryName.grid(row=0, column=1, pady=5)

# Email
tk.Label(mainFrame, text="Email:", font=("Century Gothic", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=1, column=0, sticky="w", pady=5)
entryEmail = tk.Entry(mainFrame, font=("Century Gothic", 12), width=30)
entryEmail.grid(row=1, column=1, pady=5)

# Phone
tk.Label(mainFrame, text="Phone:", font=("Century Gothic", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=2, column=0, sticky="w", pady=5)
entryPhone = tk.Entry(mainFrame, font=("Century Gothic", 12), width=30)
entryPhone.grid(row=2, column=1, pady=5)

# Password
tk.Label(mainFrame, text="Password:", font=("Century Gothic", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=3, column=0, sticky="w", pady=5)
entryPassword = tk.Entry(mainFrame, font=("Century Gothic", 12), width=30, show="*")
entryPassword.grid(row=3, column=1, pady=5)

# Gender
tk.Label(mainFrame, text="Gender:", font=("Century Gothic", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=4, column=0, sticky="w", pady=5)
genderVar = tk.StringVar(value="Male")
tk.Radiobutton(mainFrame, text="Male", variable=genderVar, value="Male", bg=BG_FRAME, fg=FG_TEXT, font=("Century Gothic", 11)).grid(row=4, column=1, sticky="w")
tk.Radiobutton(mainFrame, text="Female", variable=genderVar, value="Female", bg=BG_FRAME, fg=FG_TEXT, font=("Century Gothic", 11)).grid(row=4, column=1, padx=100, sticky="w")

# Country
tk.Label(mainFrame, text="Country:", font=("Century Gothic", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=5, column=0, sticky="w", pady=5)
countryVar = tk.StringVar(value="Select Country")
countries = ["Select Country", "India", "USA", "UK", "Canada", "Australia"]
tk.OptionMenu(mainFrame, countryVar, *countries).grid(row=5, column=1, sticky="w", pady=5)

# Address
tk.Label(mainFrame, text="Address:", font=("Century Gothic", 12, "bold"), bg=BG_FRAME, fg=FG_TEXT).grid(row=6, column=0, sticky="nw", pady=5)
textAddress = tk.Text(mainFrame, font=("Century Gothic", 12), width=30, height=4)
textAddress.grid(row=6, column=1, pady=5)

# Checkbuttons
termsVar = tk.IntVar()
newsletterVar = tk.IntVar()
tk.Checkbutton(mainFrame, text="I agree to the Terms & Conditions", variable=termsVar, font=("Century Gothic", 12), bg=BG_FRAME, fg=FG_TEXT, selectcolor="#f48fb1").grid(row=7, column=0, columnspan=2, pady=5, sticky="w")
# tk.Checkbutton(mainFrame, text="Subscribe to Newsletter", variable=newsletterVar, font=("Century Gothic", 12), bg=BG_FRAME, fg=FG_TEXT, selectcolor="#f48fb1").grid(row=8, column=0, columnspan=2, pady=5, sticky="w")

# Buttons (inside main frame so they resize with it)
btnFrame = tk.Frame(mainFrame, bg=BG_FRAME)
btnFrame.grid(row=9, column=0, columnspan=2, pady=20)
tk.Button(btnFrame, text="Submit", font=("Century Gothic", 13, "bold"), bg=BTN_PURPLE, fg="white", command=submitForm).grid(row=0, column=0, padx=10)
tk.Button(btnFrame, text="Reset", font=("Century Gothic", 13, "bold"), bg=BTN_PINK, fg="white", command=resetForm).grid(row=0, column=1, padx=10)

window.mainloop()
