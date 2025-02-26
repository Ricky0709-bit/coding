# Basic Virtual Assistant
import os
import time
import random
from datetime import datetime, timedelta
import threading
import webbrowser
import wikipedia
import requests
from bs4 import BeautifulSoup
from queue import Queue

tasks = {}
history = []
reminders = Queue()
quotes = Queue()
expenses = []

urls = {
    "google": "https://www.google.com",
    "youtube": "https://www.youtube.com",
    "github": "https://github.com",
    "gmail": "https://www.gmail.com",
    "linkedin": "https://www.linkedin.com"
}
m_quotes = [
    "Believe in yourself!",
    "You are stronger than you think.",
    "Success is not final; failure is not fatal: It is the courage to continue that counts."
]
words = [
    {"word": "serendipity", "meaning": "Finding something good without looking for it."},
    {"word": "ephemeral", "meaning": "Lasting for a very short time."},
    {"word": "lucid", "meaning": "Expressed clearly; easy to understand."}
]

def get_greet():
    hour = datetime.now().hour
    if hour < 12:
        return "Good morning! How can I assist you today?"
    elif 12 <= hour < 18:
        return "Good afternoon! What can I help you with?"
    else:
        return "Good evening! How may I assist you?"

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def get_tnw(city):
    date = datetime.now().strftime("%A, %d %B %Y")
    current_time = datetime.now().strftime("%H:%M:%S")
 
    try:
        url = f"https://wttr.in/{city}?format=%C+%t"
        response = requests.get(url)
        if response.status_code == 200:
            weather = response.text.strip()
        else:
            weather = "Could not fetch weather data."
    except Exception as e:
        weather = f"Error: {str(e)}"
    
    return date, current_time, weather

city = "Pune" 
date,time, weather = get_tnw(city)
print(f"Date: {date}")
print(f"Current Time: {time}")
print(f"Weather in {city}: {weather}")

def open_web(name):
    url = urls.get(name.lower())
    if url:
        webbrowser.open(url)
        history.append(f"Opened website: {url}")
        return f"Website {name.capitalize()} opened!"
    else:
        return "Website not found!"

def calculate(expression):
    try:
        result = eval(expression)
        history.append(f"Calculated: {expression} = {result}")
        return f"The result is {result}."
    except Exception as e:
        return f"Error in calculation: {str(e)}"

def search_info(query):
    try:
        summary = wikipedia.summary(query, sentences=50)
        history.append(f"Searched: {query}")
        return summary
    except Exception:
        return "Sorry, I couldn't find information on that topic."

def planner(action, task=None):
    if action == "add" and task:
        tasks[task] = "Pending"
        history.append(f"Added task: {task}")
    elif action == "remove" and task in tasks:
        del tasks[task]
        history.append(f"Removed task: {task}")
    elif action == "done" and task in tasks:
        tasks[task] = "Done"
        history.append(f"Marked task as done: {task}")
    return tasks
def show_tasks():
    if not tasks:
        return "Your to-do list is empty."
    return "Your to-do list:\n" + "\n".join(f"- {task}: {status}" for task, status in tasks.items())

def set_reminder(reminder, reminder_time):
    reminder_time_obj= datetime.strptime(reminder_time, "%H:%M:%S")
    reminders.append({"reminder": reminder, "time": reminder_time_obj})
    threading.Thread(target=reminder_scheduler).start()
    return f"Reminder set for {reminder_time}: {reminder}"


def reminder_scheduler():
    while True:
        now = datetime.now()
        for reminder in reminders[:]:  
            if now >= reminder["time"]:
                print(f"\nReminder: {reminder['reminder']}")
                reminders.remove(reminder)  
        time.sleep(1)
        
def show_reminders():
    if not reminders:
        return "No active reminders."
    reminder_list = "\n".join(
        [f"- {r['time'].strftime('%H:%M:%S')} : {r['reminder']}" for r in reminders]
    )
    return f"Active reminders:\n{reminder_list}"

def search_file(file_name, start_directory="C:\\"):
    matches = []
    for root, dirs, files in os.walk(start_directory):
        if file_name in files:
            matches.append(os.path.join(root, file_name))
    return matches if matches else "File not found."


def track_expenses(amount, description):
    try:
        expenses.append({"amount": amount, "description": description})
        return f"Expense added: {description} - Rs.{amount:.2f}"
    except Exception as e:
        return f"Error adding expense: {str(e)}"
    
def show_expense_history():
    if not expenses:
        return "No expenses recorded yet."
    history = "\n".join(
        [f"{idx + 1}. {e['description']}: ${e['amount']:.2f}" for idx, e in enumerate(expenses)]
    )
    return f"Expense History:\n{history}"
    
def play_media(media_type, media_name):
    media_files = {
        "music": {
            "song1": "C:\\Music\\song1.mp3",
            "song2": "C:\\Music\\song2.mp3",
            "song3": "C:\\Music\\song3.mp3"
        },
        "video": {
            "video1": "C:\\Videos\\interview.mp4",
            "video2": "C:\\Videos\\setup.mp4"
        }
    }
    if media_type in media_files and media_name in media_files[media_type]:
        os.system(f"start {media_files[media_type][media_name]}")
        history.append(f"Played {media_type}: {media_name}")
        return f"Playing {media_type}: {media_name}"
    return f"{media_type.capitalize()} not found!"

def get_wnq():
    word = random.choice(words)
    quote = quotes.get() if not quotes.empty() else "Keep pushing forward!"
    quotes.put(quote)  
    return word, quote

def get_history():
    return history[::-1]  


def exit():
    return "Goodbye! Exiting application."

def virtual_assistant():
    print("Virtual Assistant: Hello! " + get_greet())
    print("Type 'help' to see the list of commands.")
    
    while True:
        command = input(">> ").strip().lower()
        
        if command == "help":
            print("Available commands:")
            print(" - open <website_name>: Opens a website")
            print(" - calc <expression>: Perform calculation")
            print(" - search <query>: Search Wikipedia")
            print(" - add task <task_name>: Add a task")
            print(" - remove task <task_name>: Remove a task")
            print(" - done task <task_name>: Mark task as done")
            print(" - tasks: Show task list")
            print(" - reminder <HH:MM:SS> <message>: Set a reminder")
            print(" - show reminders: Show all active reminders")
            print(" - expense add <amount> <description>: Add an expense")
            print(" - expense history: Show all expenses")
            print(" - search file <name>: Search for a file by its name")
            print(" - play <media_type> <media_name>: Play media (music/video)")
            print(" - history: Show history")
            print(" - exit: Exit the assistant")
        elif command == "clear":
            clear_screen()
        elif command.startswith("open"):
            name = command.split(" ", 1)[-1]
            print(open_web(name))
        elif command.startswith("calc"):
            expression = command.split(" ", 1)[-1]
            print(calculate(expression))
        elif command.startswith("search"):
            query = command.split(" ", 1)[-1]
            print(search_info(query))
        elif command.startswith("add task"):
            task = command.split(" ", 2)[-1]
            print(planner("add", task))
        elif command.startswith("remove task"):
            task = command.split(" ", 2)[-1]
            print(planner("remove", task))
        elif command.startswith("done task"):
            task = command.split(" ", 2)[-1]
            print(planner("done", task))
        elif command == "tasks":
            print(show_tasks())
        elif command.startswith("reminder"):
            parts = command.split(" ", 2)
            if len(parts) < 3:
                print("Invalid format! Use: reminder <HH:MM:SS> <message>")
                continue
            reminder_time = parts[1]
            reminder_message = parts[2]
            print(set_reminder(reminder_message, reminder_time))
        elif command == "show reminders":
            print(show_reminders())
        elif command.startswith("expense add"):
            parts = command.split(" ", 2)
            try:
                amount = float(parts[2].split()[0])  
                description = " ".join(parts[2].split()[1:])  
                print(track_expenses(amount, description))
            except (IndexError, ValueError):
                print("Invalid format! Use: expense add <amount> <description>")
        elif command == "expense history":
            print(show_expense_history())
            total = sum(e["amount"] for e in expenses)
            print(f"Total Expenses: ${total:.2f}")
        elif command.startswith("search file"):
            file_name = input("Enter the file name to search for (including extension): ").strip()
            results = search_file(file_name)
            file_name = command.split(" ", 2)[2]
            print(f"Searching for '{file_name}'...")
            matches = search_file(file_name)
            if isinstance(matches, list):
                print(f"Found {len(matches)} result(s):")
                for path in matches:
                    print(path)
            else:
                print(matches)
        elif command.startswith("play"):
            parts = command.split(" ", 2)
            media_type = parts[1]
            media_name = parts[2]
            print(play_media(media_type, media_name))
        elif command == "history":
            print(get_history())
        elif command == "exit":
            print(exit())
            break
        else:
            print("Unknown command! Type 'help' for the list of commands.")

if __name__ == "__main__":
    virtual_assistant()
    
