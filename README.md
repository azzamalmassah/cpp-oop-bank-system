
---

# 🏦 OOPBank – Console Banking System in C++

A modular, object-oriented **banking management system** built in C++ using clean architecture principles.
The project simulates a real-world banking environment with support for **clients, users, currencies, transactions, authentication**, and **secure password storage** using file-based persistence.

This project focuses on **OOP design, separation of concerns, and maintainable structure**.

---

## ✨ Features

* 👤 **User Management**

  * Add, delete, update, find, and list users
  * Login system with permission control
  * 🔐 **Passwords are encrypted before saving to file**
  * 📝 Login logging (date, time, username, and permission level are saved to a log file)

* 🧾 **Client Management**

  * Add, delete, update, find, and list clients
  * Deposit & withdraw
  * Show total balances

* 💱 **Currency Module**

  * List currencies
  * Find currency
  * Update currency rate
  * Currency calculator & exchange screen

* 💸 **Transactions**

  * Transfer between clients
  * Transfer logging

* 🛠️ **Utilities / Libraries**

  * Date handling
  * String utilities
  * Input validation
  * General helper functions

* 🗂️ **File-Based Persistence**

  * All data is saved and loaded from files
  * Users, clients, currencies, and logs persist between runs

---

## 🧱 Project Structure

```
OOPBank
│
├── Core
│   ├── clsBankClient.h
│   ├── clsCurrency.h
│   ├── clsPerson.h
│   └── clsUser.h
│
├── Lib
│   ├── clsDate.h
│   ├── clsInputValidation.h
│   ├── clsString.h
│   └── clsUtil.h
│
├── Screens
│   ├── Client
│   ├── Currencies
│   └── User
│
├── clsMainScreen.h
├── clsScreen.h
├── Global.h
└── OOPBank.cpp   // Entry point
```

This structure follows a **layered approach**:

* **Core** → Business/domain logic
* **Lib** → Reusable utilities
* **Screens** → UI and user interaction flow

---

## 🔐 Security

* User passwords are **not stored in plain text**
* Passwords are **encrypted before being saved to files**
* During login, the entered password is processed and validated securely

---

## 🛠️ Technologies Used

* Language: **C++**
* Concepts:

  * Object-Oriented Programming (OOP)
  * Encapsulation, Abstraction, Inheritance
  * File I/O
  * Modular design
  * Separation of concerns

---

## ▶️ How to Build & Run

1. Open the project in **Visual Studio**
2. Build the solution
3. Run `OOPBank.cpp`
4. Use the console menu to navigate between:

   * Login
   * Client management
   * User management
   * Currency exchange
   * Transactions

---

---

