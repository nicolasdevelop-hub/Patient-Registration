# Hospital Patient Management System in C

A CLI (Command Line Interface) program developed to practice fundamental algorithms and data structures in C. The system allows registering patients, automatically sorting them by ID, and performing efficient searches.

## 🚀 Features

* **Patient Registration:** Stores ID, Name, and Room Number using `structs`.
* **Automatic Sorting:** Implements **Bubble Sort** to organize patients by ID in ascending order.
* **Efficient Search:** Implements **Binary Search** to find patients in $O(\log n)$ time complexity.
* **User Interface:** Interactive menu for navigation.

## 🛠️ Concepts Applied

* **C Syntax:** Loops, Conditions, I/O operations (`<stdio.h>`), String manipulation (`<string.h>`).
* **Data Structures:** Structs and Arrays.
* **Algorithms:**
    * *Bubble Sort* (for sorting data).
    * *Binary Search* (for optimized data retrieval).

## 💻 How to Run

1. Compile the code:
    ```bash
    make Patient_Registration (Capitalize the first letter)
    ```
3.  Run the executable:
    * On Windows:
        ```bash
        .\Patient_Registration
        ```
    * On Linux/Mac:
        ```bash
        ./Patient_Registration
        ```

## 📝 Example Usage

```text
=== PATIENT REGISTRATION ===
How many patients do you want to register? 3

Patient #1:
Chart Number (ID): 102
Name: Alice
Room Number: 305

👤 Author
Developed by [Seu Nome] as part of my Computer Science studies (OSSU curriculum).
