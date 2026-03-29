🎓 Student Portal System (C++)


📌 Overview

This project is a **console-based Student Portal** developed in C++. It allows students to register, log in securely, calculate their results, and store/retrieve data using file handling.
The system demonstrates core programming concepts such as **file I/O, loops, arrays, conditional statements, and authentication logic


🚀 Features
* 📝 Student Registration
* 🔐 Secure Login System (3 attempts limit)
* 📊 Result Calculation (5 subjects)
* 💾 File Handling using text files
* 📄 Print Individual Result
* 📋 Print All Results (filtered output)

 🗂️ Files Used

The program automatically creates and uses:

`reg.txt` → stores student IDs
`pass.txt` → stores passwords
`result.txt` → stores calculated results
---
⚙️ How It Works

1. **Register**

   * Enter Student ID and Password
   * Data is saved in files

2. **Login**

   * Enter ID and Password
   * Maximum 3 attempts allowed

3. **Calculate Result**

   * Enter marks of 5 subjects
   * System calculates total & percentage
   * Result is saved

4. **Print Result**

   * Displays logged-in student's result

5. **Print All**

   * Displays stored results (filtered view)


## 🧠 Concepts Used

* File Handling (`ifstream`, `ofstream`)
* Arrays & Character Strings
* Loops (`while`, `for`)
* Conditional Statements (`if-else`)
* Basic Authentication Logic


## ▶️ How to Run

1. Open the code in any C++ compiler (e.g., Dev C++, CodeBlocks, VS Code)
2. Compile the program
3. Run the executable
4. Use menu options to interact

##📌 Example Output

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
💡 Future Improvements

* Use `string` instead of char arrays
* Add GUI (Graphical Interface)
* Encrypt passwords 🔐
* Add delete/update student feature
* Store data using database instead of text files

👩‍💻 Author

**Aqsa Ismail**
BS Computer Science

📜 License
This project is for educational purposes.
