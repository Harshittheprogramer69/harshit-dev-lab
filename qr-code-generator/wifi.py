import tkinter as tk
from tkinter import messagebox
import qrcode
import os
import time
import re
import webbrowser
import pyperclip


def is_url(text):
    return text.startswith("http://") or text.startswith("https://")


def sanitize_filename(text):
    return re.sub(r'[^a-zA-Z0-9_-]', '_', text)[:30]


def generate_qr(data):
    qr = qrcode.QRCode(
        version=1,
        box_size=12,
        border=4
    )
    qr.add_data(data)
    qr.make(fit=True)
    return qr.make_image(fill_color="black", back_color="white")


def handle_generate():
    data = entry.get().strip()

    if not data:
        messagebox.showerror("Error", "Input cannot be empty")
        return

    os.makedirs("outputs", exist_ok=True)

    safe_name = sanitize_filename(data)
    filename = f"outputs/qr_{safe_name}_{int(time.time())}.png"

    img = generate_qr(data)
    img.save(filename)

    os.startfile(os.path.abspath(filename))  # auto open image

    if is_url(data):
        webbrowser.open(data)
        messagebox.showinfo("Done", "QR created & website opened 🌐")
    else:
        pyperclip.copy(data)
        messagebox.showinfo("Done", "QR created & text copied 📋")


# ---------- GUI ----------
root = tk.Tk()
root.title("Smart QR Generator")
root.geometry("420x200")
root.resizable(False, False)

tk.Label(root, text="Enter Text or Website URL", font=("Arial", 12)).pack(pady=10)

entry = tk.Entry(root, width=45, font=("Arial", 11))
entry.pack(pady=5)

tk.Button(
    root,
    text="Generate QR",
    font=("Arial", 12),
    bg="#222",
    fg="white",
    command=handle_generate
).pack(pady=20)

tk.Label(
    root,
    text="• URLs open automatically\n• Text auto-copies",
    font=("Arial", 9),
    fg="gray"
).pack()

root.mainloop()
