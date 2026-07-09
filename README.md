# CipherLog 🔒📔

A simple command-line personal diary application written in C++. CipherLog lets users create an account, log in, and write, read, or delete their own private diary entries — all stored locally in plain text files.

## Features

- **User Accounts** — Sign up with a unique username and password.
- **Login System** — Authenticate before accessing your diary.
- **Password Strength Check** — Passwords must be at least 8 characters, with confirmation on signup.
- **Write Entries** — Add dated diary entries (day/month/year + free-text content).
- **Read Entries** — View all previously saved entries for your account.
- **Delete Diary** — Permanently remove your diary file.
- **Basic Obfuscation** — Usernames, passwords, and diary entries are stored as space-separated ASCII codes rather than plain readable text.

## How It Works

- On startup, you're given the option to **Login**, **Sign Up**, or **Exit**.
- Account credentials are stored in `accounts.txt` in the working directory.
- Each user's diary entries are stored in a separate file named `<username>.txt`.
- Text is converted to and from ASCII integer sequences before being written to/read from files (this is a basic obfuscation technique, **not real encryption** — see [Security Notes](#security-notes) below).

## Requirements

- A C++ compiler supporting C++11 or later (e.g. `g++`)

## Building

```bash
g++ -o cipherlog main.cpp
```

## Running

```bash
./cipherlog
```

You'll be greeted with a menu:

```
HALLO! WELCOME TO CipherLog! :)

1. Login
2. SignUp
3. Exit
Enter your choice:
```

After logging in, you'll see the diary menu:

```
1. Write to the diary
2. Read the diary
3. Delete diary
4. Logout
```

## File Structure

| File            | Purpose                                      |
|-----------------|-----------------------------------------------|
| `main.cpp`      | Main source code                              |
| `accounts.txt`  | Stores all usernames/passwords (auto-created)  |
| `<username>.txt`| Stores an individual user's diary entries      |

> These data files are generated automatically the first time you sign up or write an entry. They don't need to be created manually.

## Security Notes

⚠️ This project is intended as a **learning exercise**, not a production-ready security tool. A few things to keep in mind:

- Storing character codes (ASCII values) instead of plain text is **not encryption** — it can be trivially reversed by anyone who reads the file format.
- Passwords are stored in the same reversible format as diary content, not hashed or salted.
- There is no protection against multiple users guessing each other's usernames/passwords.

## Possible Improvements / Roadmap

- [ ] Real password hashing
- [ ] Actual encryption for diary content
- [ ] Edit/search functionality for existing entries
- [ ] Export diary entries to PDF or plain text
- [ ] Cross-platform packaging (Windows/Linux/Mac builds)
