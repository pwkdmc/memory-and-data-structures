# Pointer-Driven Data Processing Toolkit 🔧
A collection of five C++ console applications demonstrating mastery of raw pointers, manual memory management, C-style arrays, pointer arithmetic, and low-level string manipulation. All code resides in a single `main.cpp` file.
## 🌟 Overview
This project showcases fundamental systems programming concepts without relying on STL containers or modern C++ abstractions. Every data structure is manually allocated and managed — dynamic arrays are resized with `new[]`/`delete[]`, strings are `char` arrays manipulated through pointers, and matrices use double-pointer indirection. The code heavily emphasizes pointer arithmetic and memory ownership patterns.
## 🧩 Applications
### 📊 Group Performance Analyzer
Statistical analysis of student grades using raw arrays and pointer traversal:
- **Random grade generation** — populates array with grades 2–5 via pointer-based loop
- **Average score** — sums elements through pointer arithmetic
- **Underachiever count** — counts grades below 3
- **Excellent student percentage** — ratio of 5s to total students
- **Mode calculation** — finds the most frequent grade using a frequency array
- Functions receive `int*` with size parameter, never use `[]` subscripting
### 🧮 Smart Calculator with Operation History
A multi-function calculator with ring-buffer history storage:
- **Arithmetic operations** — addition, subtraction, multiplication, division, remainder — all via function pointers
- **Operation history** — fixed-size array of `struct Calculation`, shifted on each new operation (oldest drops off)
- **Value exchange** — swaps two `double` variables through pointers
- **Min/max finder** — dynamically allocates user-specified array, finds extremes through pointer traversal, then deallocates
- Division/modulo validation prevents zero division and non-integer remainder operations
### 🔤 Palindrome & Anagram Detector
Comprehensive C-string processing toolkit with six sub-operations:
- **Palindrome check** — two-pointer technique from both ends, skips spaces, handles case-insensitive Latin and Cyrillic comparison
- **Anagram detection** — character frequency counting by nested pointer loops, compares counts between strings
- **String reversal** — in-place reversal using two-pointer swap, no temporary buffer
- **Word count** — state-machine traversal counting space-to-word transitions
- **Longest word** — builds words character-by-character in a buffer, tracks maximum length
- **Non-alpha character removal** — filters string keeping only A–Z, a–z, А–Я, а–я
- 20-character limit with `cin.getline()` for safe input
### 🔄 Arbitrary-Size Matrix Transposition
Dynamic 2D array manipulation with manual allocation:
- **Matrix creation** — `int**` allocated as array of pointers to row arrays
- **Random filling** — double-pointer nested loops populate with values 1–10
- **Transposition** — swaps rows/columns using index arithmetic: `*(*(matrix + row) + col)` notation
- **Row/column sum matrix** — calculates sum of each element's row and column (subtracting the element itself once)
- Dynamic column width formatting using `log10` for proper alignment
- Triple cleanup — deallocates original, transposed, and sum matrices
### 📚 Book Library Management System
A dynamically-resizing sorted catalog with manual memory management:
- **`struct Book`** — fixed-size `char[21]` fields (C-style strings)
- **Sorted insertion** — `Add()` creates new array of `size+1`, inserts book in publication year order, copies all existing elements, deletes old array
- **Search by title** — `FindBook()` scans with `strcmp`, reports all matches
- **Filter by author** — `OutputBooks()` lists all books matching an author name
- **Delete by index** — `DeleteBook()` creates smaller array, copies non-deleted elements, deallocates old array
- **Full listing** — iterates and displays all books in sorted order
- Book count starts at 0 with empty `new Book[0]` allocation
## 🎯 Shared Patterns
- **Consistent error messages** — `"ОШИБКА: Введено недопустимое число"` standardized
- **Input validation** — `cin.fail()`, `cin.clear()`, `cin.ignore()` pattern everywhere
- **Task-repeat workflow** — nested "Run again / Exit" (`1`/`0`) loops
- **Russian UI** — all prompts in Russian language
- **20-character limit** — enforced via `cin.getline(buffer, 20)` for safety
- **C-style structs** — `strcmp` for comparison, manual field copying
## 📄 License
The project is intended for educational purposes. It can be used and modified freely.