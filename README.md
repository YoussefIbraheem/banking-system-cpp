# 💳 Banking System

A simple console-based Banking Management System built in **C++** as a graduation project. The system simulates a basic banking workflow and supports three types of users: **Admin**, **Employee**, and **Client** — each with their own permissions and interface.

> 🛠️ Built with Object-Oriented Programming principles and file-based data persistence.  
> ✅ Works on **Windows OS**.

---

## 📌 Features

### 👤 Admin
- Add, edit, or delete **Employees**
- View all Employees
- Add, edit, or delete **Clients**
- View all Clients

### 👨‍💼 Employee
- Add new **Clients**
- Edit or delete existing **Clients**
- Search and view **Client** details

### 🧑 Client
- View account **balance**
- Change **password**
- Transfer **money**
- View **transaction history**

---

## 🗂️ Project Structure

```
banking-system/
├── Admin.h / AdminManager.h
├── Client.h / ClientManager.h
├── Employee.h / EmployeeManager.h
├── FilesManager.h
├── Screens.h / Screens.cpp      # UI/UX flow & navigation
├── Data/
│   ├── Admins.txt               # Admin records
│   ├── Employees.txt            # Employee records
│   └── Clients.txt              # Client records
└── main.cpp
```

---

## 💾 Data Format

All data is stored in plain `.txt` files, one user per line, in the following format:

### 🔐 Admins & Employees

```
<id>-<name>-<password>-<salary>
```

✅ Example:
```
1-sleem-524252452452-99999
```

### 🏦 Clients

```
<id>-<name>-<password>-<balance>
```

✅ Example:
```
3-youssef-1111-5000
```

---

## 🖥️ How to Run

### ✅ Prerequisites
- Windows OS
- C++ compiler (e.g. MinGW or MSVC)
- Git Bash or CMD

### ⚙️ Steps

1. **Clone the repo**
   ```bash
   git clone https://github.com/YoussefIbraheem/banking-system.git
   cd banking-system
   ```

2. **Compile the project**
   ```bash
   g++ main.cpp Screens.cpp -o banking-app
   ```

3. **Run the app**
   ```bash
   ./banking-app
   ```

---

## 🧪 Sample Credentials

| User Type | ID  | Name   | Password     |
|-----------|-----|--------|--------------|
| Admin     | 1   | sleem  | 524252452452 |
| Client    | 3   | youssef| 1111         |

> Feel free to explore or modify the `Data/*.txt` files to test different scenarios.

---

## 🎓 Educational Goals

- Master object-oriented design (OOP) with C++
- Understand file-based data management
- Practice input validation and user-role segregation
- Build CLI-based real-world simulations

---

## 🚀 Future Improvements

- Add persistent logs for transactions
- Switch to JSON or SQLite for better data management
- Introduce encryption for password storage
- Port to GUI using Qt or web version using Flask/C++

---

## 📸 Screenshots

![Welcome Screen](screenshots/welcome.png)
![Login Screen](screenshots/login.png)
![Admin Dashboard](screenshots/admin.png)

> *(Screenshots are optional. You can add these by running the app and taking snapshots with `Snipping Tool` or `PrtSc`, then save under a `/screenshots` folder.)*

---

## 👨‍💻 Author

**Youssef Muhsen Ibraheem**  
[🇪🇬 Alexandria, Egypt]  
- Backend Developer (PHP | Python | C++)
- [LinkedIn](https://www.linkedin.com/in/YoussefIbraheem)  
- [GitHub](https://github.com/YoussefIbraheem)

---

## 📄 License

This project is open-source and free to use for educational and non-commercial purposes.

---
```

---