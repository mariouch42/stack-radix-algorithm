# push_swap

*This project has been created as part of the 42 curriculum by [your_login].*

## Description

**push_swap** is a sorting algorithm project from the 42 school curriculum.  
The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, with the fewest moves possible.

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements of stack a |
| `sb` | Swap the first 2 elements of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element of b to a |
| `pb` | Push the first element of a to b |
| `ra` | Rotate stack a upward |
| `rb` | Rotate stack b upward |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack a |
| `rrb` | Reverse rotate stack b |
| `rrr` | `rra` and `rrb` at the same time |

### Algorithm

- **2-3 elements**: hardcoded optimal sorting
- **4-5 elements**: combination of push and sort
- **100+ elements**: radix sort on indexed values

---

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
# Numbers as separate arguments
./push_swap 3 2 1

# Numbers as a single quoted string
./push_swap "3 2 1"
```

### Check number of operations

```bash
ARG="3 2 1"; ./push_swap $ARG | wc -l
```

### Verify correctness

```bash
ARG="5 4 3 2 1"
./push_swap $ARG | ./checker_OS $ARG
```

### Cleanup

```bash
make clean   # remove object files
make fclean  # remove object files and binary
make re      # recompile from scratch
```

---

## Resources

- [Sorting algorithms — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix Sort — GeeksForGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [push_swap — Medium tutorial](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [42 Docs — push_swap subject](https://cdn.intra.42.fr/pdf/pdf/136659/en.subject.pdf)
- [paco tester](https://github.com/LeoFu9487/push_swap_tester)

### AI Usage

**Claude (Anthropic)** was used during this project for the following tasks:

- **Parsing**: helped design and debug the `parse_input` function to handle both `"3 2 1"` (single string) and `3 2 1` (separate arguments) input formats
- **Norminette compliance**: assisted in splitting functions and files to respect the 25-line and 5-function limits
- **Debugging**: helped identify bugs in `get_max_bits` (operator precedence) and `fill_array` (duplicate `j = 0`)
- **Code review**: reviewed `ft_split`, `ft_substr`, and `reverse_bits` implementations for correctness

All final code was written and validated by the student.

---

## Usage Example

```bash
$ ./push_swap 5 3 1 4 2
pb
pb
sa
pa
ra
pa
rra

$ ./push_swap "already sorted" 2>/dev/null || echo "Error"
Error

$ ./push_swap 1 2 3
# (no output — already sorted)
```
