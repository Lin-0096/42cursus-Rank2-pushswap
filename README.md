<div align="center">
  <picture>
    <img src="https://github.com/ayogun/42-project-badges/blob/main/badges/push_swape.png" alt="42 push_swap badge">
  </picture>

  <p><a href="https://www.hive.fi/en/curriculum">Hive (42 School Network)</a> core curriculum project</p>
  <h1>push_swap</h1>
</div>

`push_swap` focused on sorting integers using two stacks and a limited set of stack operations, under strict constraints.

---

## Key Features  

- Sorts a stack of integers with minimal operations.
- Uses only specific operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- Designed to be efficient with input sizes up to 500 numbers.
- Optional `checker` program validates the output instructions.

---

## Core Technical Skills  

- Stack manipulation using linked lists.
- Algorithm optimization under operation constraints.
- Memory management and defensive programming in C.
- Handling edge cases and invalid input.

---

## How to Compile & Run  

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

## Learning Outcomes  

- Implemented a custom sorting algorithm using stack operations only.
- Improved understanding of time and space complexity tradeoffs.
