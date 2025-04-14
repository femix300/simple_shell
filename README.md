# Simple Shell

Welcome to **Simple Shell**, a basic implementation of a Unix command-line interpreter created in the C programming language.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contribution](#contribution)
- [Authors](#authors)

---

## Overview

**Simple Shell** is a lightweight shell designed to emulate the functionality of a Unix shell. It provides an interactive environment for executing commands, running scripts, and learning how shells work at a fundamental level. This project was created as a part of a learning exercise to gain deeper insights into system programming.

---

## Features

- Interactive mode: Accepts user inputs in real-time.
- Non-interactive mode: Executes commands from a file or script.
- Executes both built-in and system commands.
- Includes basic error handling and input validation.
- Simple and efficient design using only C.

---

## Installation

To use the Simple Shell, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/femix300/simple_shell.git
   ```

2. Navigate to the project directory:
   ```bash
   cd simple_shell
   ```

3. Compile the program using GCC:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```

---

## Usage

### Interactive Mode
Launch the shell and start entering commands:
```bash
./hsh
```
Example:
```bash
$ ./hsh
$ ls -l
$ pwd
$ exit
```

### Non-Interactive Mode
Execute commands from a file:
```bash
echo "ls -l" | ./hsh
```
Or provide a script file:
```bash
./hsh < script_file.txt
```

---

## Examples

### Running Commands
```bash
$ ./hsh
$ ls -a
$ echo "Hello, World!"
$ exit
```

### Running a Script
```bash
$ cat script.txt
ls
pwd
echo "Done!"
$ ./hsh < script.txt
```

---

## Contribution

Contributions are welcome! If you'd like to add features, fix bugs, or improve the documentation, please fork the repository and create a pull request.

---

## Authors

This project was developed by:
- **[femix300](https://github.com/femix300)**
- **[KimuchuJr](https://github.com/KimuchuJr)**