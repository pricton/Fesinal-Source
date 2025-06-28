Fesinal – Automatic Reminder with Registry Startup
Project Overview
Fesinal is a simple C++ program demonstrating how a Windows application can copy itself to a temporary folder, add an autostart entry in the registry, and show periodic notifications. The goal is to help understand basic Windows system programming concepts.

Features
User Confirmation on Start: When launched, the program asks the user if they want to run it. If the user selects “No,” the program exits without making changes.

Self-Copy to Temp Folder: The executable copies itself to the Windows temporary directory as fesinal.exe.

Registry Autostart: It adds a registry key under HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run to launch automatically at Windows startup.

Periodic Notification: Every 60 seconds, a message box appears with the text “ich bin aktiv!” (“I am active!”).

Notes
This project is intended for educational purposes only. It does not contain harmful functions such as deleting files or stealing data. Because it modifies the registry and copies itself, some antivirus programs may flag it as suspicious. Test it only in safe environments like virtual machines.

Files Included

fesinal.exe — Compiled executable

main.cpp — Source code

fesinal.ico — Icon file

README.md — This description

Disclaimer
I am not responsible for any damage or data loss caused by using this software. Use it at your own risk.

