# Multithreaded Array Sorting in C++

This project implements a multithreaded C++ program that sorts an array of integers.  
It divides the array into two halves, sorts each half concurrently using separate threads, and then merges the two sorted halves with a third thread.

---

## 🚀 Features

- Divides the array into two subarrays.
- Sorts each subarray concurrently using POSIX threads (pthreads).
- Merges the two sorted halves concurrently with a third thread.
- Supports both even and odd numbers of elements.
- Lightweight, efficient, and easy to extend.

---

## 🛠️ Technologies Used

- C++ (11 and later)
- POSIX Threads (pthreads)
- Linux / Unix-based systems

---

## 📥 How to Run

### 1. Clone the repository:

```bash
git clone https://github.com/your-username/Multithreaded-Sorting-Application
cd Multithreaded-Sorting-Application
```

### 2. Compile the program:

```bash
g++ multithreaded_sorting.cpp -o sorting_app -pthread
```

### 3. Run the program:

```bash
./sorting_app
```

### 4. Provide the input:

First enter the number of elements, followed by the elements themselves.

---

## 📋 Example Input

```
7
7 3 5 9 1 2 4
```

### Expected Output

```
Sorted Array:
1 2 3 4 5 7 9
```

---

## 💬 About the Project

This project was created to practice and demonstrate multithreading concepts in C++.  
It focuses on synchronization, thread management, and efficient division of work between threads.  
Managing both even and odd-sized arrays was also considered to ensure robustness.

---
