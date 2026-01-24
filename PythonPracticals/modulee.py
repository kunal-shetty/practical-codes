from tkinter import messagebox, Tk, Label, Entry, Button, Checkbutton
import sys
window = Tk()
# var = StringVar()
# label = Label(window, textvariable=var, background='yellow', foreground='blue')
# var.set("Meow meow meow")
# label.pack()

def submitForm():
    username = usernameEntry.get()
    email = emailEntry.get()
    age = ageEntry.get()
    password = passwordEntry.get()
    passwordValidate = len(password) > 8
    if not username or not password:
        messagebox.showerror("Error", "Please Enter Valid Information ")
    elif not passwordValidate:
        messagebox.showerror("Error", "Password must be at least 8 characters long")
    else:
        messagebox.showinfo("Form Submitted", "fName : {username}\nEmail : {email}\nAge : {age}")

    # message


label1 = Label(window, text="Login Page")
label1.grid(row = 0, column = 2)
label2 = Label(window, text="Username")
label2.grid(row = 1, column = 1)
label3 = Label(window, text="Password")
label3.grid(row = 3, column = 1)
label4 = Label(window, text="Email")
label4.grid(row = 6, column = 1)
label5 = Label(window, text="Age")
label5.grid(row = 9, column = 1)

usernameEntry = Entry(window)
usernameEntry.grid(row = 1, column = 2, padx = 2)
emailEntry = Entry(window)
emailEntry.grid(row = 1, column = 2, padx = 2)
ageEntry = Entry(window)
ageEntry.grid(row = 1, column = 2, padx = 2)
passwordEntry = Entry(window)
passwordEntry.grid(row = 3, column = 2, padx = 2)
checkB = Checkbutton(window, text = "Accept terms and conditions")
checkB.grid(row = 11, column = 2, ipady = 10, ipadx = 10)
button = Button(window, text="Login", command=submitForm, bg='yellow', fg='black')
button.grid(row = 13, column = 2, pady = 10)
window.title("Meow")

window.mainloop()


# import tkinter as Tk
# window = Tk.Tk()
# window.title("BITMAP style buttons")
# b1 = Tk.Button(window, text = "meow", relief = "raised", cursor = "heart")
# b2 = Tk.Button(window, text = "meow", relief = "groove")
# b3 = Tk.Button(window, text = "meow meow", relief = "ridge")
# b4 = Tk.Button(window, text = "meow meow meow", relief = "flat")
# b5 = Tk.Button(window, text = "meow meow meow meow meow", relief = "groove")
# b1.pack()
# b2.pack()
# b3.pack()
# b4.pack()
# b5.pack()
# window.mainloop()