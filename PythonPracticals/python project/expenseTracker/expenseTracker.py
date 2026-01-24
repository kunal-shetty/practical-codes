import tkinter as tk
from tkinter import ttk, messagebox
from tkcalendar import DateEntry
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
from chartGenerators import *
from databaseConnection import addNewExpense, updateExpense, deleteExpense, getAllExpenses


class ModernButton:
    @staticmethod
    def create(parent, text, command, style="primary", width=None):
        """Create a modern styled button with hover effects"""
        styles = {
            "primary": {"bg": "#4A90E2", "hover": "#357ABD", "fg": "white"},
            "success": {"bg": "#27AE60", "hover": "#229954", "fg": "white"},
            "danger": {"bg": "#E74C3C", "hover": "#C0392B", "fg": "white"},
            "warning": {"bg": "#F39C12", "hover": "#E67E22", "fg": "white"},
            "info": {"bg": "#17A2B8", "hover": "#138496", "fg": "white"},
            "dark": {"bg": "#343A40", "hover": "#23272B", "fg": "white"}
        }

        style_config = styles.get(style, styles["primary"])

        btn = tk.Button(
            parent,
            text=text,
            command=command,
            font=("Segoe UI", 10, "bold"),
            bg=style_config["bg"],
            fg=style_config["fg"],
            relief="flat",
            cursor="hand2",
            padx=20,
            pady=8,
            bd=0
        )

        if width:
            btn.config(width=width)

        # Hover effects
        def on_enter(e):
            btn.config(bg=style_config["hover"])

        def on_leave(e):
            btn.config(bg=style_config["bg"])

        btn.bind("<Enter>", on_enter)
        btn.bind("<Leave>", on_leave)

        return btn


class ExpenseApp:
    def __init__(self, root):
        self.root = root
        self.root.title("💰 Expense Tracker Pro")
        self.root.geometry("1400x800")
        self.root.configure(bg="#F8F9FA")
        self.root.minsize(1200, 700)

        # Configure style
        self.setup_styles()

        # Header
        self.create_header()

        # Main container with shadow effect
        main_container = tk.Frame(root, bg="#FFFFFF", relief="flat", bd=0)
        main_container.pack(fill="both", expand=True, padx=20, pady=(0, 20))

        # Add subtle shadow effect
        shadow_frame = tk.Frame(root, bg="#E0E0E0", height=2)
        shadow_frame.place(x=20, y=80, width=1360)

        # Tabs with modern styling
        self.create_tabs(main_container)

        self.setup_dashboard()
        self.setup_manage_tab()

    def setup_styles(self):
        """Configure modern ttk styles"""
        style = ttk.Style()
        style.theme_use("clam")

        # Notebook styling
        style.configure("Modern.TNotebook",
                        background="#FFFFFF",
                        borderwidth=0,
                        tabmargins=[0, 0, 0, 0])

        style.configure("Modern.TNotebook.Tab",
                        background="#F8F9FA",
                        foreground="#495057",
                        padding=[20, 15],
                        font=("Segoe UI", 12, "bold"),
                        borderwidth=0)

        style.map("Modern.TNotebook.Tab",
                  background=[("selected", "#4A90E2"), ("active", "#6C757D")],
                  foreground=[("selected", "white"), ("active", "white")])

        # Treeview styling
        style.configure("Modern.Treeview",
                        background="white",
                        foreground="#495057",
                        rowheight=35,
                        fieldbackground="white",
                        borderwidth=0,
                        font=("Segoe UI", 10))

        style.configure("Modern.Treeview.Heading",
                        background="#4A90E2",
                        foreground="white",
                        font=("Segoe UI", 11, "bold"),
                        relief="flat",
                        borderwidth=0)

        style.map("Modern.Treeview",
                  background=[("selected", "#E3F2FD")],
                  foreground=[("selected", "#1976D2")])

    def create_header(self):
        """Create modern header with gradient effect"""
        header_frame = tk.Frame(self.root, height=80, bg="#4A90E2")
        header_frame.pack(fill="x")
        header_frame.pack_propagate(False)

        # Gradient effect simulation
        for i in range(5):
            color_intensity = 0.9 - (i * 0.1)
            hex_color = f"#{int(74 * color_intensity):02x}{int(144 * color_intensity):02x}{int(226 * color_intensity):02x}"
            gradient_line = tk.Frame(header_frame, height=1, bg=hex_color)
            gradient_line.pack(fill="x", side="bottom")

        # Header content
        content_frame = tk.Frame(header_frame, bg="#4A90E2")
        content_frame.pack(expand=True, fill="both")

        title_frame = tk.Frame(content_frame, bg="#4A90E2")
        title_frame.pack(expand=True)

        title = tk.Label(title_frame,
                         text="💰 Expense Tracker Pro",
                         font=("Segoe UI", 28, "bold"),
                         bg="#4A90E2",
                         fg="white")
        title.pack(pady=(15, 5))

        subtitle = tk.Label(title_frame,
                            text="Smart Financial Management Dashboard",
                            font=("Segoe UI", 12),
                            bg="#4A90E2",
                            fg="#E3F2FD")
        subtitle.pack()

    def create_tabs(self, parent):
        """Create modern tab control"""
        self.tab_control = ttk.Notebook(parent, style="Modern.TNotebook")

        self.tab_dashboard = ttk.Frame(self.tab_control)
        self.tab_manage = ttk.Frame(self.tab_control)

        self.tab_control.add(self.tab_dashboard, text="📊 Dashboard & Analytics")
        self.tab_control.add(self.tab_manage, text="💼 Manage Expenses")

        self.tab_control.pack(expand=1, fill="both", padx=0, pady=0)

    def setup_dashboard(self):
        """Setup modern dashboard"""
        # Main dashboard container
        dashboard_frame = tk.Frame(self.tab_dashboard, bg="#F8F9FA")
        dashboard_frame.pack(fill="both", expand=True, padx=20, pady=20)

        # Stats cards container
        stats_container = tk.Frame(dashboard_frame, bg="#F8F9FA")
        stats_container.pack(fill="x", pady=(0, 20))

        # Create stats cards
        self.create_stats_cards(stats_container)

        # Control panel
        control_panel = tk.LabelFrame(dashboard_frame,
                                      text="📈 Chart Controls",
                                      font=("Segoe UI", 14, "bold"),
                                      bg="white",
                                      fg="#495057",
                                      padx=20,
                                      pady=15)
        control_panel.pack(fill="x", pady=(0, 20))

        btn_container = tk.Frame(control_panel, bg="white")
        btn_container.pack()

        ModernButton.create(btn_container, "🔄 Refresh Charts",
                            self.load_charts, "info").pack(side="left", padx=10)

        ModernButton.create(btn_container, "📊 Category View",
                            self.show_category_chart, "primary").pack(side="left", padx=10)

        ModernButton.create(btn_container, "📅 Monthly Trends",
                            self.show_monthly_chart, "success").pack(side="left", padx=10)

        # Chart container with border
        chart_container = tk.LabelFrame(dashboard_frame,
                                        text="📈 Visual Analytics",
                                        font=("Segoe UI", 14, "bold"),
                                        bg="white",
                                        fg="#495057",
                                        padx=10,
                                        pady=10)
        chart_container.pack(fill="both", expand=True)

        self.chart_frame = tk.Frame(chart_container, bg="white")
        self.chart_frame.pack(fill="both", expand=True, padx=10, pady=10)

        self.load_charts()

    def create_stats_cards(self, parent):
        """Create modern statistics cards"""
        try:
            rows = getAllExpenses()

            if not rows:
                # Show empty state
                stats = [
                    ("💰", "Total Expenses", "₹0.00", "#E74C3C"),
                    ("📊", "Total Transactions", "0", "#4A90E2"),
                    ("📈", "Average Expense", "₹0.00", "#27AE60"),
                    ("🏷️", "Categories", "0", "#F39C12")
                ]
            else:
                # Based on your database schema: (expenseId, expenseAmount, expenseName, description, category, paymentMode, date)
                total_expenses = sum(float(row[1]) for row in rows)
                total_count = len(rows)
                avg_expense = total_expenses / total_count if total_count > 0 else 0

                # Categories count - category is at index 4
                categories = set(row[4] for row in rows if row[4])
                categories_count = len(categories)

                stats = [
                    ("💰", "Total Expenses", f"₹{total_expenses:,.2f}", "#E74C3C"),
                    ("📊", "Total Transactions", str(total_count), "#4A90E2"),
                    ("📈", "Average Expense", f"₹{avg_expense:.2f}", "#27AE60"),
                    ("🏷️", "Categories", str(categories_count), "#F39C12")
                ]

            for icon, title, value, color in stats:
                self.create_stat_card(parent, icon, title, value, color)

        except Exception as e:
            print(f"Error creating stats cards: {e}")
            # Create default empty stats on error
            stats = [
                ("💰", "Total Expenses", "Error", "#E74C3C"),
                ("📊", "Total Transactions", "Error", "#4A90E2"),
                ("📈", "Average Expense", "Error", "#27AE60"),
                ("🏷️", "Categories", "Error", "#F39C12")
            ]
            for icon, title, value, color in stats:
                self.create_stat_card(parent, icon, title, value, color)

    def create_stat_card(self, parent, icon, title, value, color):
        """Create individual stat card with modern styling"""
        card = tk.Frame(parent, bg="white", relief="flat", bd=0)
        card.pack(side="left", fill="x", expand=True, padx=10)

        # Add subtle shadow
        shadow = tk.Frame(parent, bg="#E0E0E0", height=2)
        shadow.pack(side="bottom", fill="x", padx=12)

        # Card content
        content_frame = tk.Frame(card, bg="white")
        content_frame.pack(expand=True, fill="both", padx=20, pady=20)

        # Icon
        icon_label = tk.Label(content_frame,
                              text=icon,
                              font=("Segoe UI", 24),
                              bg="white",
                              fg=color)
        icon_label.pack()

        # Value
        value_label = tk.Label(content_frame,
                               text=value,
                               font=("Segoe UI", 18, "bold"),
                               bg="white",
                               fg="#2C3E50")
        value_label.pack(pady=(5, 0))

        # Title
        title_label = tk.Label(content_frame,
                               text=title,
                               font=("Segoe UI", 10),
                               bg="white",
                               fg="#6C757D")
        title_label.pack()

    def setup_manage_tab(self):
        """Setup modern manage expenses tab"""
        # Main container
        manage_container = tk.Frame(self.tab_manage, bg="#F8F9FA")
        manage_container.pack(fill="both", expand=True, padx=20, pady=20)

        # Form section
        form_frame = tk.LabelFrame(manage_container,
                                   text="💼 Add / Edit Expense",
                                   font=("Segoe UI", 14, "bold"),
                                   bg="white",
                                   fg="#495057",
                                   padx=25,
                                   pady=20)
        form_frame.pack(fill="x", pady=(0, 20))

        self.create_expense_form(form_frame)

        # Table section
        table_frame = tk.LabelFrame(manage_container,
                                    text="📋 Expense Records",
                                    font=("Segoe UI", 14, "bold"),
                                    bg="white",
                                    fg="#495057",
                                    padx=15,
                                    pady=15)
        table_frame.pack(fill="both", expand=True)

        self.create_expense_table(table_frame)

    def create_expense_form(self, parent):
        """Create modern expense form"""
        # Form grid
        form_grid = tk.Frame(parent, bg="white")
        form_grid.pack(fill="x", pady=10)

        # Row 1
        self.create_form_field(form_grid, "Expense Name:", 0, 0)
        self.name_var = self.create_entry(form_grid, 0, 1)

        self.create_form_field(form_grid, "Amount (₹):", 0, 2)
        self.amount_var = self.create_entry(form_grid, 0, 3, width=15)

        # Row 2
        self.create_form_field(form_grid, "Category:", 1, 0)
        self.category_var = self.create_entry(form_grid, 1, 1)

        self.create_form_field(form_grid, "Payment Mode:", 1, 2)
        self.payment_var = ttk.Combobox(form_grid,
                                        values=["Cash", "Card", "UPI", "Bank Transfer", "Cheque"],
                                        font=("Segoe UI", 10),
                                        width=18,
                                        state="readonly")
        self.payment_var.grid(row=1, column=3, padx=10, pady=8, sticky="w")

        # Row 3
        self.create_form_field(form_grid, "Date:", 2, 0)
        self.date_var = DateEntry(form_grid,
                                  date_pattern="yyyy-mm-dd",
                                  font=("Segoe UI", 10),
                                  width=18)
        self.date_var.grid(row=2, column=1, padx=10, pady=8, sticky="w")

        self.create_form_field(form_grid, "Description:", 2, 2)
        self.desc_var = self.create_entry(form_grid, 2, 3, width=25)

        # Buttons
        btn_frame = tk.Frame(parent, bg="white")
        btn_frame.pack(pady=20)

        ModernButton.create(btn_frame, "➕ Add Expense",
                            self.add_expense, "success").pack(side="left", padx=8)

        ModernButton.create(btn_frame, "✏️ Update Selected",
                            self.update_selected, "warning").pack(side="left", padx=8)

        ModernButton.create(btn_frame, "🗑️ Delete Selected",
                            self.delete_selected, "danger").pack(side="left", padx=8)

        ModernButton.create(btn_frame, "🔄 Clear Form",
                            self.clear_form, "info").pack(side="left", padx=8)

    def create_form_field(self, parent, text, row, col):
        """Create form field label"""
        label = tk.Label(parent,
                         text=text,
                         font=("Segoe UI", 11, "bold"),
                         bg="white",
                         fg="#495057")
        label.grid(row=row, column=col, padx=10, pady=8, sticky="e")

    def create_entry(self, parent, row, col, width=20):
        """Create styled entry widget"""
        entry = tk.Entry(parent,
                         font=("Segoe UI", 10),
                         width=width,
                         relief="solid",
                         bd=1,
                         bg="#F8F9FA")
        entry.grid(row=row, column=col, padx=10, pady=8, sticky="w")

        # Focus effects
        def on_focus_in(e):
            entry.config(bg="white", bd=2)

        def on_focus_out(e):
            entry.config(bg="#F8F9FA", bd=1)

        entry.bind("<FocusIn>", on_focus_in)
        entry.bind("<FocusOut>", on_focus_out)

        return entry

    def create_expense_table(self, parent):
        """Create modern expense table"""
        # Table container with scrollbar
        table_container = tk.Frame(parent, bg="white")
        table_container.pack(fill="both", expand=True, padx=10, pady=10)

        columns = ("ID", "Name", "Amount", "Description", "Category", "Payment", "Date")
        self.tree = ttk.Treeview(table_container,
                                 columns=columns,
                                 show="headings",
                                 height=15,
                                 style="Modern.Treeview")

        # Configure columns
        column_configs = {
            "ID": (0, False),
            "Name": (200, True),
            "Amount": (120, True),
            "Description": (180, True),
            "Category": (140, True),
            "Payment": (120, True),
            "Date": (120, True)
        }

        headings = {
            "Name": "Expense Name",
            "Amount": "Amount (₹)",
            "Description": "Description",
            "Category": "Category",
            "Payment": "Payment Mode",
            "Date": "Date"
        }

        for col in columns:
            width, stretch = column_configs[col]
            self.tree.column(col, width=width, stretch=stretch, anchor="center")

            if col == "ID":
                self.tree.heading(col, text="")
            else:
                self.tree.heading(col, text=headings.get(col, col))

        # Scrollbars
        v_scrollbar = ttk.Scrollbar(table_container, orient="vertical", command=self.tree.yview)
        h_scrollbar = ttk.Scrollbar(table_container, orient="horizontal", command=self.tree.xview)
        self.tree.configure(yscrollcommand=v_scrollbar.set, xscrollcommand=h_scrollbar.set)

        # Pack scrollbars and tree
        self.tree.grid(row=0, column=0, sticky="nsew")
        v_scrollbar.grid(row=0, column=1, sticky="ns")
        h_scrollbar.grid(row=1, column=0, sticky="ew")

        table_container.grid_rowconfigure(0, weight=1)
        table_container.grid_columnconfigure(0, weight=1)

        # Row styling
        self.tree.tag_configure("even", background="#F8F9FA")
        self.tree.tag_configure("odd", background="white")

        # Bind selection event
        self.tree.bind("<<TreeviewSelect>>", self.on_row_select)

        self.load_expenses()

    def on_row_select(self, event):
        """Handle row selection to populate form"""
        selected = self.tree.selection()
        if selected:
            values = self.tree.item(selected[0])["values"]
            if len(values) >= 7:
                # Values structure: (ID, Name, Amount, Description, Category, Payment, Date)
                self.name_var.delete(0, tk.END)
                self.name_var.insert(0, str(values[1]))

                self.amount_var.delete(0, tk.END)
                # Remove currency symbol and formatting for editing
                amount_str = str(values[2]).replace('₹', '').replace(',', '')
                self.amount_var.insert(0, amount_str)

                self.desc_var.delete(0, tk.END)
                self.desc_var.insert(0, str(values[3]))

                self.category_var.delete(0, tk.END)
                self.category_var.insert(0, str(values[4]))

                self.payment_var.set(str(values[5]))

                # Handle date - it should already be in the correct format
                try:
                    date_str = str(values[6])
                    if date_str and date_str != 'None':
                        # If date is in format YYYY-MM-DD, use it directly
                        from datetime import datetime
                        if '-' in date_str:
                            self.date_var.set_date(datetime.strptime(date_str, '%Y-%m-%d').date())
                        else:
                            self.date_var.set_date(date_str)
                except Exception as e:
                    print(f"Date parsing error: {e}")
                    pass

    def clear_form(self):
        """Clear all form fields"""
        self.name_var.delete(0, tk.END)
        self.amount_var.delete(0, tk.END)
        self.desc_var.delete(0, tk.END)
        self.category_var.delete(0, tk.END)
        self.payment_var.set("")

        # Clear selection
        for item in self.tree.selection():
            self.tree.selection_remove(item)

    def load_charts(self):
        """Load default charts"""
        self.show_category_chart()

    def show_category_chart(self):
        """Show category-wise expense chart"""
        try:
            for widget in self.chart_frame.winfo_children():
                widget.destroy()

            rows = getAllExpenses()
            if not rows:
                no_data_label = tk.Label(self.chart_frame,
                                         text="📊 No expense data available\nAdd some expenses to see charts!",
                                         font=("Segoe UI", 14),
                                         bg="white",
                                         fg="#6C757D")
                no_data_label.pack(expand=True)
                return

            fig = showCategoryChart(rows)
            fig.patch.set_facecolor('white')

            chart_canvas = FigureCanvasTkAgg(fig, master=self.chart_frame)
            chart_canvas.draw()
            chart_canvas.get_tk_widget().pack(fill="both", expand=True, padx=10, pady=10)

        except Exception as e:
            error_label = tk.Label(self.chart_frame,
                                   text=f"Error loading chart: {str(e)}",
                                   font=("Segoe UI", 12),
                                   bg="white",
                                   fg="#E74C3C")
            error_label.pack(expand=True)

    def show_monthly_chart(self):
        """Show monthly expense trends (placeholder)"""
        for widget in self.chart_frame.winfo_children():
            widget.destroy()

        placeholder = tk.Label(self.chart_frame,
                               text="📅 Monthly Trends Chart\n(Feature coming soon!)",
                               font=("Segoe UI", 16),
                               bg="white",
                               fg="#6C757D")
        placeholder.pack(expand=True)

    def add_expense(self):
        """Add new expense with validation"""
        try:
            name = self.name_var.get().strip()
            amount_text = self.amount_var.get().strip()
            category = self.category_var.get().strip()
            payment = self.payment_var.get()
            date = self.date_var.get()
            desc = self.desc_var.get().strip()

            if not all([name, amount_text, category, payment]):
                messagebox.showwarning("Validation Error",
                                       "Please fill in all required fields:\n• Expense Name\n• Amount\n• Category\n• Payment Mode")
                return

            amount = float(amount_text)
            if amount <= 0:
                messagebox.showwarning("Validation Error", "Amount must be greater than 0")
                return

            addNewExpense(name, amount, desc, category, payment, date)
            messagebox.showinfo("Success", "✅ Expense added successfully!")

            self.load_expenses()
            self.clear_form()

        except ValueError:
            messagebox.showerror("Error", "Please enter a valid amount")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to add expense: {str(e)}")

    def update_selected(self):
        """Update selected expense"""
        selected = self.tree.selection()
        if not selected:
            messagebox.showwarning("Selection Required", "Please select a row to update")
            return

        values = self.tree.item(selected[0])["values"]
        expense_id = values[0]

        try:
            name = self.name_var.get().strip()
            amount_text = self.amount_var.get().strip()
            category = self.category_var.get().strip()
            payment = self.payment_var.get()
            date = self.date_var.get()
            desc = self.desc_var.get().strip()

            if not all([name, amount_text, category, payment]):
                messagebox.showwarning("Validation Error", "Please fill in all required fields")
                return

            amount = float(amount_text)
            if amount <= 0:
                messagebox.showwarning("Validation Error", "Amount must be greater than 0")
                return

            updateExpense(expense_id, name, amount, desc, category, payment, date)
            messagebox.showinfo("Success", "✅ Expense updated successfully!")

            self.load_expenses()
            self.clear_form()

        except ValueError:
            messagebox.showerror("Error", "Please enter a valid amount")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to update expense: {str(e)}")

    def delete_selected(self):
        """Delete selected expense"""
        selected = self.tree.selection()
        if not selected:
            messagebox.showwarning("Selection Required", "Please select a row to delete")
            return

        values = self.tree.item(selected[0])["values"]
        expense_id = values[0]
        expense_name = values[1]

        result = messagebox.askyesno("Confirm Deletion",
                                     f"Are you sure you want to delete:\n'{expense_name}'?\n\nThis action cannot be undone.")

        if result:
            try:
                deleteExpense(expense_id)
                messagebox.showinfo("Success", "🗑️ Expense deleted successfully!")
                self.load_expenses()
                self.clear_form()
            except Exception as e:
                messagebox.showerror("Error", f"Failed to delete expense: {str(e)}")

    def load_expenses(self):
        """Load and display all expenses"""
        try:
            for row in self.tree.get_children():
                self.tree.delete(row)

            rows = getAllExpenses()
            for idx, row in enumerate(rows):
                # Assuming row structure: (id, amount, name, description, category, payment, date)
                # Adjust based on your actual database schema
                expense_id, expense_amount, expense_name, description, category, payment_mode, date = row

                # Format amount with currency
                formatted_amount = f"₹{float(expense_amount):,.2f}"

                # Format date if needed
                formatted_date = str(date) if date else ""

                tag = "even" if idx % 2 == 0 else "odd"
                self.tree.insert("", "end",
                                 values=(expense_id, expense_name, formatted_amount,
                                         description, category, payment_mode, formatted_date),
                                 tags=(tag,))

        except Exception as e:
            print(f"Error loading expenses: {e}")
            messagebox.showerror("Error", f"Failed to load expenses: {str(e)}")


# Run the application
if __name__ == "__main__":
    root = tk.Tk()
    app = ExpenseApp(root)
    root.mainloop()