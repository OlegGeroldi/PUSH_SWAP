# PUSH_SWAP

`push_swap` is a C program that sorts integers using two stacks (`A` and `B`) and a limited set of stack operations.
It prints the operation sequence to `stdout`.

## Features

- Input validation with `Error` output on invalid data
- Duplicate and integer overflow checks
- Different sorting strategies by input size:
  - `2` numbers: simple swap when needed
  - `3` numbers: dedicated minimal-case logic
  - `4-5` numbers: move smallest values to `B`, sort `A`, push back
  - `>5` numbers: indexed "chunk/window" strategy

## Project Structure

- `/tmp/workspace/OlegGeroldi/PUSH_SWAP/main.c` - parsing, validation, algorithm dispatch
- `/tmp/workspace/OlegGeroldi/PUSH_SWAP/stack_utils.c` - linked-list stack helpers
- `/tmp/workspace/OlegGeroldi/PUSH_SWAP/operations_*.c` - push/swap/rotate/reverse-rotate ops
- `/tmp/workspace/OlegGeroldi/PUSH_SWAP/sort_small.c` - sort for 3 and 5 numbers
- `/tmp/workspace/OlegGeroldi/PUSH_SWAP/sort_big.c` - indexing + large-input sort strategy
- `/tmp/workspace/OlegGeroldi/PUSH_SWAP/validation.c` - number checks and comparator
- `/tmp/workspace/OlegGeroldi/PUSH_SWAP/Makefile` - build targets

## Build

From repository root:

```bash
make
```

Other targets:

```bash
make clean
make fclean
make re
```

## Usage

```bash
./push_swap <n1> <n2> <n3> ...
```

Example:

```bash
./push_swap 3 2 1
```

Output (example):

```text
sa
rra
```

> Note: this implementation expects numbers as separate CLI arguments.

## Allowed Operations (printed by program)

- `sa` - swap first two elements of stack `A`
- `pb` - push top of `A` to `B`
- `pa` - push top of `B` to `A`
- `ra` - rotate `A` up (first becomes last)
- `rb` - rotate `B` up
- `rra` - reverse rotate `A` (last becomes first)
- `rrb` - reverse rotate `B`

## Error Handling

The program writes:

```text
Error
```

to `stderr` and exits with status `1` for invalid input, including:

- non-integer tokens
- out-of-range values (outside `INT_MIN..INT_MAX`)
- duplicates

## Quick Check

You can verify and inspect the output sequence with the bundled checker binary:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

Expected checker output:

```text
OK
```

## Notes

- Built with `gcc` and flags `-Wall -Wextra -Werror`
- Stack storage is implemented as a doubly linked list
