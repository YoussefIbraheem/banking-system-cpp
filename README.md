# 🏦 Banking System (C++)

A simple **console-based Banking Management System** built in **C++** as a **Route Academy graduation project** under the mentorship of **Eng. Mohamed Adel**.  
This system simulates a real-world banking workflow with three distinct user roles — **Admin**, **Employee**, and **Client** — each having their own privileges and access levels.

> ⚠️ **Disclaimer:** This project is **not a production-ready application**.  
> It was created purely for **learning, practising OOP fundamentals**, and demonstrating **file-based data persistence** in C++.

---

## 📘 Overview

The **Banking System** provides a modular, text-based interface that allows different user types to manage accounts and perform simple financial operations.

Key programming concepts demonstrated:

- Object-Oriented Design (Encapsulation, Inheritance, Polymorphism)
- File Handling (Text-based persistent storage)
- Input Validation & Data Parsing
- Role-based User Interaction and Navigation Flow

---

## 🧩 Features

### 👤 Admin

- Add, edit, or remove **Employees**
- View all **Employees**
- Add, edit, or remove **Clients**
- View all **Clients**

### 👨‍💼 Employee

- Create and manage **Client** accounts
- Edit or delete existing **Clients**
- Search and view **Client** details

### 🧑 Client

- View account **balance**
- Change **password**
- Transfer **money**
- View **transaction history**

---

## 🗂️ Project Structure

```bash

banking-system-cpp/
├── Banking System.sln             # Visual Studio solution file
├── Banking System/                # Core project folder
│   ├── *.cpp / *.h                # Source & header files
│   ├── *.txt                      # Text-based data storage
│   ├── x64/Debug/                 # Build artifacts
└── x64/Debug/
└── Banking System.exe         # Compiled executable

```

Example of data organization inside `Banking System/`:

```bash

Admin.h / AdminManager.h
Client.h / ClientManager.h
Employee.h / EmployeeManager.h
FilesManager.h
Screens.cpp / Screens.h            # Handles UI flow & navigation
Admins.txt / Employees.txt / Clients.txt

```

---

## 💾 Data Format

All information is stored in **plain `.txt` files**, one record per line:

### 🔐 Admins & Employees

```bash

<id>-<name>-<password>-<salary>

```

✅ Example:

```bash

1-sleem-524252452452-99999

```

### 🏦 Clients

```bash

<id>-<name>-<password>-<balance>

```

✅ Example:

```bash

3-youssef-1111-5000

````

---

## 🖥️ How to Run

### ✅ Prerequisites

- **Windows OS**
- **C++ compiler** (MSVC or MinGW)
- **Git Bash / CMD / PowerShell**

### ⚙️ Steps

1. **Clone the repository**

```bash
   git clone https://github.com/YoussefIbraheem/banking-system-cpp.git
   cd banking-system-cpp

```

1. **Open with Visual Studio**
   Build and run the solution:

   ```bash
   Banking System.sln
   ```

   **Alternatively**, compile manually:

   ```bash
   g++ "Banking System/*.cpp" -o banking-system
   ./banking-system
   ```

---

## 🧪 Sample Credentials

| User Type | ID | Name    | Password     |
| --------- | -- | ------- | ------------ |
| Admin     | 1  | sleem   | 524252452452 |
| Client    | 3  | youssef | 1111         |

> You can modify `Admins.txt`, `Employees.txt`, or `Clients.txt` to create custom test users.

---

## 🎓 Educational Goals

This project was built to:

- Practice **Object-Oriented Programming** in C++
- Understand **data persistence** through text files
- Learn **modular design** and multi-role systems
- Develop **CLI-based applications** using structured code organization

---

## 🚀 Potential Future Improvements

- Add persistent transaction logs
- Replace `.txt` files with **SQLite** or **JSON**
- Encrypt stored passwords
- Create a **GUI version (Qt)** or **Web version (Flask / Django)**

---

## 👨‍🏫 Acknowledgements

Developed under the guidance of
**Eng. Mohamed Adel** — Route Academy, Egypt.

Special thanks to the Route Academy team for their C++ mentorship and project-based learning approach.

---

## 👨‍💻 Author

**Youssef Muhsen Ibraheem**
[🇪🇬 Alexandria, Egypt]

- Backend Developer (C++ | Python | PHP)
- [LinkedIn](https://www.linkedin.com/in/YoussefIbraheem)
- [GitHub](https://github.com/YoussefIbraheem)

---

## 📄 License

This repository is open-source and intended for **educational and non-commercial** purposes only.

---
