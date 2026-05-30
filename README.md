markdown<h1 align="center">🎓 Student Portal Console Application</h1>
<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Course-Programming%20Fundamentals-blue?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/IDE-Visual%20Studio-purple?style=for-the-badge&logo=visualstudio&logoColor=white"/>
</p>

---

## 📌 Overview

A console-based **Student Portal** built in C++ that allows students
to register, login securely, calculate results, and view their
academic performance — all using file handling.

---

## ⚙️ Features

| Feature | Description |
|---------|-------------|
| 📝 Register | Save Student ID and password to files |
| 🔐 Login | Secure login with 3 attempt limit |
| 🧮 Calculate Result | Enter marks and calculate percentage |
| 📄 Print Result | View your own result after login |
| 📋 Print All | View all student results |

---

## 🧠 Concepts Used

![File Handling](https://img.shields.io/badge/File%20Handling-blueviolet?style=for-the-badge)
![Char Arrays](https://img.shields.io/badge/Char%20Arrays-orange?style=for-the-badge)
![Loops](https://img.shields.io/badge/Loops-blue?style=for-the-badge)
![Functions](https://img.shields.io/badge/Functions-red?style=for-the-badge)
![Conditionals](https://img.shields.io/badge/Conditionals-success?style=for-the-badge)
![Global Variables](https://img.shields.io/badge/Global%20Variables-yellow?style=for-the-badge)

---

## 📂 Files Used

| File | Description |
|------|-------------|
| `reg.txt` | Stores student serial number and ID |
| `pass.txt` | Stores student serial number and password |
| `result.txt` | Stores student results and percentage |

---

## 📤 Sample Output

```
******************************
*     STUDENT PORTAL         *
******************************
* 1. Register                *
* 2. Log In                  *
* 3. Calculate Result        *
* 4. Print Result            *
* 5. Print All               *
******************************
Enter Choice:
```

---

## ▶️ How to Run

### 🖥️ Visual Studio
1. Create new **Empty Project** → C++
2. Add `main.cpp` to project
3. Press **Ctrl + F5** to Run
4. Files will be created automatically in **Debug folder**

### 💻 VS Code
```bash
g++ main.cpp -o portal
./portal
```

### 🖱️ Dev C++
1. Open `main.cpp`
2. Press **F11** to Compile & Run

---

## 📁 Project Files

```
console-student-portal/
├── main.cpp        → complete source code
├── reg.txt         → student registration data
├── pass.txt        → student passwords
├── result.txt      → student results
└── README.md       → project documentation
```

---

## ⚠️ Important Notes

- Login limited to **3 attempts** only
- Must login before calculating or printing result
- Files are created automatically on first run
- No STL used — pure C++ with char arrays

---

## 👩‍💻 Author

**Aqsa Ismail** | [GitHub](https://github.com/aqsaismail04) | [LinkedIn](https://www.linkedin.com/in/aqsaismail04/)
