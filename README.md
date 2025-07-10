cat > README.md << 'EOF'

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

## 📁 File Structure

\`\`\`
captian-shell/
├── main.c          # Main interactive shell loop
├── uses.c          # Implementation of shell commands
├── uses.h          # Command mappings and function prototypes
└── README.md       # You're here
\`\`\`

---

## 📦 Prerequisites

Before running this project, ensure you have:

- A Unix-like environment (Linux/macOS or WSL on Windows)
- GCC (GNU Compiler Collection)

Install GCC if not already installed:

\`\`\`bash
sudo apt update
sudo apt install build-essential
\`\`\`

---

## 🚀 Installation

Clone the repo and compile:

\`\`\`bash
git clone https://github.com/yourusername/captian-shell.git
cd captian-shell
gcc main.c uses.c -o captian
\`\`\`

---

## ▶️ Usage

Launch the shell:

\`\`\`bash
./captian
\`\`\`

You can now run any of the supported commands:

\`\`\`
>>> whereami
>>> mkdir test
>>> cd test
>>> mkfile demo.txt
>>> show demo.txt
>>> ls
\`\`\`

To exit the shell, use \`Ctrl+C\`.

---

## 🧪 Testing

This shell is manually tested by executing supported commands in the CLI:

\`\`\`bash
./captian
>>> mkdir demo
>>> cd demo
>>> mkfile file.txt
>>> show file.txt
>>> rmfile file.txt
>>> cd ..
>>> rmdir demo
\`\`\`

> ✅ All commands return expected outputs and errors are properly handled.

---

## 📌 Notes

- This shell does not support piping, chaining, or background tasks.
- The shell currently reads one line of input per command.
- You can easily extend it by adding new entries in the \`captian[]\` array in \`uses.h\`.

---

## 📜 License

This project is licensed under the MIT License. See \`LICENSE\` file for details.

---

## ✍️ Author

**Your Name**  
GitHub: [@yourusername](https://github.com/sufikhab)  

---

## 🌟 Show Your Support

If you found this project useful:

⭐ Star the repo  
🍴 Fork it  
🛠️ Submit PRs  
📢 Share with others

---
EOF
