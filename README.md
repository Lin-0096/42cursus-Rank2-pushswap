<div align="center">
  <picture>
    <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/pushswapm.png" alt="42 push_swap badge">
  </picture>

  <p><a href="https://www.hive.fi/en/curriculum">Hive (42 School Network)</a> core curriculum project</p>
  <h1>push_swap</h1>
</div>

`push_swap` is a 42 project focused on sorting integers using two stacks and a limited set of stack operations, under strict constraints.

---

## 🚀 Key Features  

- Sorts a stack of integers with minimal operations.
- Uses only specific operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- Designed to be efficient with input sizes up to 500 numbers.
- Optional `checker` program validates the output instructions.

---

## 🧠 Core Technical Skills  

- Stack manipulation using linked lists.
- Algorithm optimization under operation constraints.
- Memory management and defensive programming in C.
- Handling edge cases and invalid input.

---

## 📁 Project Structure  

```
push_swap/
├── include/
│   └── push_swap.h             # Function prototypes & macros
├── src/
│   ├── main.c                  # Entry point
│   ├── parser.c                # Input parsing and validation
│   ├── operations.c            # Stack operations
│   ├── sort_small.c            # Sorting for small input sizes (3-5)
│   ├── sort_big.c              # Sorting for large input sizes
│   ├── utils.c                 # Utilities: error, free, helper functions
│   └── checker/                # Optional: checker program to validate solution
├── Makefile
└── README.md
```

---

## ⚙️ How to Compile & Run  

```bash
make
./push_swap 3 2 1 6 5
```

Example output (instructions to sort the input):
```
pb
pb
sa
pa
pa
```

To compile and use the bonus checker:
```bash
make bonus
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
```

---

## 🎯 Learning Outcomes  

- Implemented a custom sorting algorithm using stack operations only.
- Improved understanding of time and space complexity tradeoffs.
- Gained experience writing optimized C code and managing project structure.

---

**Developed by [Lin-0096](https://github.com/Lin-0096)**
