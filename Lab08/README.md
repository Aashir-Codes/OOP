# Lab 08 — Dynamic Memory, Double Pointers & OOP (C++)

Single program with a master menu covering all three tasks.

## Tasks
- **Q1 — Text editor** (`Document` using `String**`): insert / delete / add / get / display lines.
  Only pointers are shifted on insert/delete, not whole objects.
- **Q2 — Names sorter**: `names.txt` → `sorted_names.txt` (read dynamically, sort, write).
- **Q3 — Student sorter**: `student.txt` → `sorted_student.txt`. Parses
  `name, roll, cgpa, m1,m2,...`, stores in `Student**`, sorts by name, writes same format.

## Files
| File | Purpose |
|------|---------|
| `Lab08.cpp` | `main()` + menu (Q1/Q2/Q3) |
| `String.h/.cpp` | custom string class |
| `Vector.h/.cpp` | custom int vector (course marks) |
| `Document.h/.cpp` | text editor over `String**` |
| `Student.h/.cpp` | `Student` class + `sortStudentFile()` |
| `names.txt`, `student.txt` | sample inputs |

## Build & run
```bash
g++ -std=c++17 -o lab08 Lab08.cpp String.cpp Document.cpp Student.cpp Vector.cpp
./lab08
```
(Visual Studio: open `Lab08.slnx`. `system("cls")` is Windows-only and harmless elsewhere.)
