MyShell — Custom Unix Shell in C

MyShell is a custom Unix-like shell written in C. The goal of this project was to understand how a shell works internally and to practice low-level systems programming concepts such as process creation, command parsing, and execution.

The shell runs on Linux and was tested using Windows Subsystem for Linux (WSL).

------------------------------------------------------------

Features

- Interactive shell with a REPL loop
- Safe input handling using getline
- Command parsing into argv format
- Execution of external commands using fork, execvp, and waitpid
- Built-in commands:
  - cd
  - exit
  - help
- Custom productivity commands:
  - chrome
  - code
  - search <query>
  - yt <query>
  - gh <query>
  - so <query>
- Browser-based commands open results in the Windows default browser when running on WSL

------------------------------------------------------------

Build Instructions

Requirements:
- Linux environment (tested on Ubuntu via WSL)
- gcc
- make

Install build tools:
sudo apt update
sudo apt install build-essential

Build the shell:
make clean
make

Run the shell:
./mysh

------------------------------------------------------------

Install for Easy Access (Optional)

Copy the shell binary to a system path:
sudo cp mysh /usr/local/bin/mysh

Run from anywhere:
mysh

------------------------------------------------------------

Running as an App on Windows (WSL)

WSL does not support Linux desktop launchers.  
To run MyShell like an app on Windows, a wrapper script and Windows shortcut are used.

Create a wrapper script in WSL:
nano ~/run-mysh.sh

Add:
#!/bin/bash
exec /usr/local/bin/mysh

Make it executable:
chmod +x ~/run-mysh.sh

Create a Windows desktop shortcut with target:
wsl.exe -- bash -lc "~/run-mysh.sh"

Double-clicking the shortcut opens MyShell directly.

------------------------------------------------------------

Learning Outcomes

- Understanding of Unix process model
- Difference between built-in commands and external programs
- Practical use of fork, execvp, and waitpid
- Safe memory management in C
- POSIX system calls and headers
- Real-world debugging in Linux and WSL environments

------------------------------------------------------------

Limitations

- No job control
- No pipes or redirection
- No scripting support
- No GUI

These were intentionally excluded to keep the project focused on core shell concepts.

------------------------------------------------------------

Author

Krishan Malhotra  
B.E. Electronics & Computer Engineering (3rd Year)

------------------------------------------------------------

License

This project is intended for educational and personal use.
