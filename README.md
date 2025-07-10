## 📖 Overview

**CAPTIAN** is a lightweight, interactive command-line shell implemented in C. It simulates some common shell utilities like `ls`, `mkdir`, `cd`, `show`, and more — using direct system calls. It serves as a learning tool for understanding how a shell works at the system level using C.

---

## 🧾 Features

- 📂 `ls` — List current directory contents  
- 🗃️ `mkdir <name>` — Create a new directory  
- 📄 `mkfile <name>` — Create and write to a file  
- ❌ `rmfile <name>` — Delete a file  
- 🧹 `rmdir <name>` — Delete an empty directory  
- 📁 `cd <name>` — Change the current working directory  
- 📍 `whereami` — Display the current path  
- 📜 `show <file>` — Display contents of a file

---

---

## 📦 Prerequisites

Before running this project, ensure you have:

- A Unix-like environment (Linux/macOS or WSL on Windows)
- GCC (GNU Compiler Collection)

Install GCC if not already installed:

```bash
sudo apt update
sudo apt install build-essential
