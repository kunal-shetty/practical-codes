import tkinter as tk
from tkinter import ttk
from vosk import Model, KaldiRecognizer
import sounddevice as sd
import queue
import threading
import json
from googletrans import Translator, LANGUAGES
import pyttsx3
import time

# --- Globals ---
q = queue.Queue()
is_recording = False
recognized_text = ""
target_lang = "en"

# --- Initialize Translator and TTS ---
translator = Translator()
tts_engine = pyttsx3.init()
tts_engine.setProperty('rate', 150)

# --- Vosk Setup ---
model = Model("vosk-model-small-en-us-0.15")  # path to Vosk model
rec = KaldiRecognizer(model, 16000)

# --- Audio callback ---
def audio_callback(indata, frames, time, status):
    if status:
        print(status)
    q.put(bytes(indata))

# --- Mic toggle ---
def toggle_recording():
    global is_recording
    if not is_recording:
        is_recording = True
        animate_mic()
        record_btn.config(bg="red")
        threading.Thread(target=record_audio).start()
    else:
        is_recording = False
        record_btn.config(bg="green")

# --- Animation ---
def animate_mic():
    if is_recording:
        size = 100
        record_btn.config(width=size//10, height=size//25)
        root.after(300, lambda: record_btn.config(width=size//8, height=size//20))
        root.after(600, animate_mic)

# --- Recording function ---
def record_audio():
    global recognized_text
    recognized_text = ""
    with sd.RawInputStream(samplerate=16000, blocksize=8000, dtype='int16',
                           channels=1, callback=audio_callback):
        while is_recording:
            try:
                data = q.get()
                if rec.AcceptWaveform(data):
                    res = json.loads(rec.Result())
                    text = res.get("text", "")
                    recognized_text += text + " "
                    typewriter_display(recognized_text)
                    translate_text(recognized_text)
                else:
                    partial = json.loads(rec.PartialResult()).get("partial", "")
                    typewriter_display(recognized_text + partial)
            except Exception as e:
                print("Error:", e)

# --- Typewriter effect ---
def typewriter_display(text):
    display_area.config(state="normal")
    display_area.delete("1.0", tk.END)
    for i, char in enumerate(text):
        display_area.insert(tk.END, char)
        display_area.update()
        time.sleep(0.01)  # adjust speed
    display_area.config(state="disabled")

# --- Translation ---
def translate_text(text):
    translated = translator.translate(text, dest=target_lang)
    target_area.config(state="normal")
    target_area.delete("1.0", tk.END)
    target_area.insert(tk.END, translated.text)
    target_area.config(state="disabled")

# --- TTS ---
def play_translation():
    text = target_area.get("1.0", tk.END).strip()
    if text:
        tts_engine.say(text)
        tts_engine.runAndWait()

# --- Change target language ---
def change_target_lang(event):
    global target_lang
    target_lang = lang_var.get()

# --- Tkinter UI ---
root = tk.Tk()
root.title("Google Translate–Style Voice Translator")
root.geometry("700x600")

# Language selection
lang_var = tk.StringVar(value="en")
lang_menu = ttk.Combobox(root, textvariable=lang_var, values=list(LANGUAGES.keys()))
lang_menu.pack(pady=10)
lang_menu.bind("<<ComboboxSelected>>", change_target_lang)

# Source text display
display_area = tk.Text(root, height=8, wrap="word", state="disabled", font=("Arial", 14))
display_area.pack(pady=10, padx=10, fill="x")

# Target text display
target_area = tk.Text(root, height=8, wrap="word", state="disabled", font=("Arial", 14), fg="blue")
target_area.pack(pady=10, padx=10, fill="x")

# Mic button
record_btn = tk.Button(root, text="🎤", bg="green", fg="white",
                       font=("Arial", 24, "bold"), width=6, height=3,
                       command=toggle_recording)
record_btn.place(relx=0.5, rely=0.85, anchor="center")

# Play TTS button
tts_btn = tk.Button(root, text="🔊 Play Translation", bg="blue", fg="white",
                    font=("Arial", 12, "bold"), command=play_translation)
tts_btn.pack(pady=10)

root.mainloop()
