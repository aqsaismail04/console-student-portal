<h1 align="center">🎓 Student Portal System (C++)</h1>
<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Course-Introduction%20to%20Computing-blue?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/IDE-Visual%20Studio-purple?style=for-the-badge&logo=visualstudio&logoColor=white"/>
</p>

---

## 📌 Overview

A console-based **Student Portal** developed in C++ that allows students
to register, log in securely, calculate results, and store/retrieve
data using file handling.

---

## 🚀 Features

| Feature | Description |
|---------|-------------|
| 📝 Student Registration | Save Student ID and password to files |
| 🔐 Secure Login | 3 attempts limit |
| 📊 Result Calculation | Enter marks of 5 subjects |
| 💾 File Handling | Data stored in text files |
| 📄 Print Individual Result | View your own result |
| 📋 Print All Results | View all stored results |

---

## 🗂️ Files Used

| File | Description |
|------|-------------|
| `reg.txt` | Stores student IDs |
| `pass.txt` | Stores passwords |
| `result.txt` | Stores calculated results |

---

## ⚙️ How It Works

1. **Register** — Enter Student ID and Password → saved in files
2. **Login** — Enter ID and Password → maximum 3 attempts
3. **Calculate Result** — Enter marks of 5 subjects → percentage saved
4. **Print Result** — Displays logged-in student's result
5. **Print All** — Displays all stored results

---

## 🧠 Concepts Used

![File Handling](https://img.shields.io/badge/File%20Handling-blueviolet?style=for-the-badge)
![Char Arrays](https://img.shields.io/badge/Char%20Arrays-orange?style=for-the-badge)
![Loops](https://img.shields.io/badge/Loops-blue?style=for-the-badge)
![Conditionals](https://img.shields.io/badge/Conditionals-red?style=for-the-badge)
![Authentication](https://img.shields.io/badge/Authentication-success?style=for-the-badge)

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
```

---

## ▶️ How to Run

### 🖥️ Visual Studio
1. Create new **Empty Project** → C++
2. Add `main.cpp` to project
3. Press **Ctrl + F5** to Run

### 💻 VS Code
```bash
g++ main.cpp -o portal
./portal
```

### 🖱️ Dev C++
1. Open `main.cpp`
2. Press **F11** to Compile & Run

---

## 💡 Future Improvements

- Use `string` instead of char arrays
- Add GUI (Graphical Interface)
- Encrypt passwords 🔐
- Add delete/update student feature
- Store data using database

---

## 👩‍💻 Author

**Aqsa Ismail** | [GitHub](https://github.com/aqsaismail04) | [LinkedIn](https://www.linkedin.com/in/aqsaismail04/)
