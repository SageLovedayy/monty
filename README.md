# Monty Interpreter

This repository contains the source code for a Monty 0.98 interpreter, implementing various opcodes for stack manipulation. The Monty language is a scripting language that is first compiled into Monty byte codes, similar to Python.

## Table of Contents

1. [Compilation & Output](#compilation--output)
2. [Opcodes Implementation](#opcodes-implementation)
   - [push, pall](#push-pall)
   - [pint](#pint)
   - [pop](#pop)
   - [swap](#swap)
   - [add](#add)
   - [nop](#nop)
3. [Usage](#usage)
4. [Monty Byte Code Files](#monty-byte-code-files)
5. [Tests](#tests)
6. [Additional Notes](#additional-notes)

## Compilation & Output

Compile code using the following command:

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

## Opcodes Implementation

### push, pall

#### The `push` opcode

The opcode `push` pushes an element to the stack.

- **Usage:** `push <int>`
  - `<int>` is an integer.
  - If `<int>` is not an integer or if there is no argument given to push, it prints the error message `L<line_number>: usage: push integer`, followed by a new line, and exits with the status `EXIT_FAILURE`.

#### The `pall` opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack unless stack is empty

- **Usage:** `pall`

### pint

#### The `pint` opcode

The opcode `pint` prints the value at the top of the stack, followed by a new line.

- **Usage:** `pint`
  - If the stack is empty, prints the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exits with the status `EXIT_FAILURE`.

### pop

#### The `pop` opcode

The opcode `pop` removes the top element of the stack.

- **Usage:** `pop`
  - If the stack is empty, prints the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exits with the status `EXIT_FAILURE`.

### swap

#### The `swap` opcode

The opcode `swap` swaps the top two elements of the stack.

- **Usage:** `swap`
  - If the stack contains less than two elements, prints the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exits with the status `EXIT_FAILURE`.

### add

#### The `add` opcode

The opcode `add` adds the top two elements of the stack.

- **Usage:** `add`
  - If the stack contains less than two elements, prints the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exits with the status `EXIT_FAILURE`.
  - The result is stored in the second top element of the stack, and the top element is removed.

### nop

#### The `nop` opcode

The opcode `nop` doesn’t do anything.

- **Usage:** `nop`

## Usage

The `monty` program is used as follows:

```bash
$ ./monty file
```

Where `file` is the path to the file containing Monty byte code. If the user does not provide any file or provides more than one argument, the program prints the error message:

```bash
USAGE: monty file
```

and exit with status `EXIT_FAILURE`. If it's not possible to open the file, the program prints the error message:

```bash
Error: Can't open file <file>
```

and exits with status `EXIT_FAILURE`. If the file contains an invalid instruction, the program prints the error message:

```bash
L<line_number>: unknown instruction <opcode>
```

where `<line_number>` is the line number where the instruction appears. Line numbers always start at 1. If there is a malloc failure, the program prints:

```bash
Error: malloc failed
```

and exits with status `EXIT_FAILURE`.


## Additional Notes
- Line numbers start at 1.
- The interpreter stops execution if it encounters an error or finishes processing the entire file.