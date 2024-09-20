![cover-pipex](https://github.com/user-attachments/assets/557e560b-87c0-4dd5-aaca-be94247a947b)


<div align="center">
<h1>Push swap Documentation</h1>
<img src="https://img.shields.io/badge/42-%23000000.svg?&style=for-the-badge&logo=42&logoColor=white" /> 
<img src="https://img.shields.io/badge/c-%23A8B9CC.svg?&style=for-the-badge&logo=c&logoColor=black" /> 
<img src="https://img.shields.io/badge/markdown-%23000000.svg?&style=for-the-badge&logo=markdown&logoColor=white" />
<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
</div>


### 🚀 Table of Contents


1. [📌 Project Overview](#project-overview)
   - [Introduction to Pipex](#introduction-to-pipex)
   - [Objectives and Goals](#objectives-and-goals)
2. [💡 Getting Started](#getting-started)
   - [Prerequisites](#prerequisites)
   - [Required Functions and Libraries](#required-functions-and-libraries)
   - [Project Structure Overview](#project-structure-overview)
3. [💻 Program Usage](#program-usage)
   - [How to Run the Program](#how-to-run-the-program)
   - [Example Commands](#example-commands)
   - [Expected Input and Output](#expected-input-and-output)
4. [🔍 Core Logic and Implementation](#core-logic-and-implementation)
5. [❗ Error Handling](#error-handling)
6. [🧠 Memory Management](#memory-management)
7. [🔧 Tester - Mandatory Part](#tester---mandatory-part)
   - [Non-valid Cases 🛑](Non-valid-Cases)
   - [Valid Command Combinations for Two Commands 🔄](Valid-Command-Combinations-for-Two-Commands)


### 📌Project Overview

### Introduction to Pipex
`Pipex` is a project aimed at understanding and implementing the **piping mechanism in UNIX**. The goal is to create a program that mimics the behavior of the shell in handling input/output redirection between commands. By completing this project, you'll deepen your understanding of UNIX system calls like:
- `pipe()` 🛠️
- `fork()` 👶
- `dup2()` 🔄
- `execve()` 🏃

### Objectives and Goals
- **Replicate the functionality** of this shell command:
  ```bash
  < infile cmd1 | cmd2 > outfile
  ```
- **How it works**:
   - Takes two commands.
   - Reads input from a file.
   - Pipes the output of the first command into the second command.
   - Writes the final output to another file.


### **💡Getting Started**

#### Prerequisites
- **System**: Unix-based system (e.g., Linux, macOS) 🖥️
- **Compiler**: GCC or any standard C compiler ⚙️
- **Knowledge**: Familiarity with system calls like `fork()`, `pipe()`, `dup2()`, `execve()` 🧠
- **Makefile**: A Makefile that compiles with `-Wall`, `-Werror`, `-Wextra` flags, without relinking unnecessary files. 📝

#### Required Functions and Libraries
You'll use these functions:
- `open()`, `close()`, `read()`, `write()` 📝
- `malloc()`, `free()` 💾
- `perror()`, `strerror()` ⚠️
- `access()`, `dup()`, `dup2()` 🔄
- `execve()`, `exit()`, `fork()`, `pipe()`, `unlink()` 🛠️
- `wait()`, `waitpid()` ⏳

#### Project Structure Overview

```bash
pipex/
├── main.c                        # Entry point of the program
├── error/                        # Error handling functionality
│   ├── error_pipex.c             # Handles errors specific to pipex
├── setup/                        # Setup and initialization
│   ├── pipex_setup.c             # Sets up the pipex environment (files, pipes)
├── free_memory/                  # Memory management
│   ├── free_pipex.c              # Frees allocated memory in pipex
├── command/                      # Command execution and validation
│   ├── command_execution.c       # Executes the parsed commands
│   ├── command_validation.c      # Validates commands by checking PATH and permissions
├── includes/                     # Header files
│   ├── pipex.h                   # Contains function prototypes and struct definitions
└── Makefile                      # Makefile to compile the project
```

**Explanation**:
- **Main file** (`main.c`): The entry point for your Pipex program.
- **Error handling** (`error/`): Manages any errors that occur in the program.
- **Setup** (`setup/`): Handles setting up pipes, redirections, and the environment.
- **Memory management** (`free_memory/`): Contains functions to free dynamically allocated memory.
- **Command execution** (`command/`): Functions related to command parsing, validation, and execution.
- **Includes** (`includes/`): Stores header files like `pipex.h`.
- **Makefile**: Automates the compilation process.


### 💻Program Usage

#### **How to Run the Program**
Use the following format to run the `pipex` program:
```bash
./pipex infile "cmd1" "cmd2" outfile
```
- **`infile`**: Input file 📂
- **`cmd1`**: First command 📝
- **`cmd2`**: Second command 🔄, takes `cmd1` output as input.
- **`outfile`**: Output file where results will be stored 💾

#### Example Commands
```bash
./pipex infile "ls -l" "wc -l" outfile
```
- **Input**: `infile` 📂
- **Command 1**: `ls -l` (lists files) 📄
- **Command 2**: `wc -l` (counts lines) 🔢
- **Output**: Written to `outfile` 💾

#### Expected Input and Output

#### **Expected Input** 📝

This section explains the files and commands you need to provide when running the program.

- **Input file (`infile`)** 📂:  
  A file containing the input data. The content of this file will be passed to the first command (`cmd1`).  
  *Example*: A file with a list of file names or text content.

- **Commands** 🖥️:  
  Two commands must be passed as arguments:
  - **`cmd1`**: The first command reads from `infile`.
  - **`cmd2`**: The second command processes the output of `cmd1`.  
    *Example commands*: `ls -l`, `grep`, `wc -l`.

- **Output file (`outfile`)** 💾:  
  The final output of `cmd2` will be written here. If it doesn’t exist, it will be created. If it exists, it will be overwritten.  
  *Example*: A text file that stores the result of the command chain.

#### **Example Input** 🖊️
```bash
./pipex infile "cat" "wc -l" outfile
```
- **`infile`**: A file that contains some text.
- **Command 1**: `cat` reads the content of `infile`.
- **Command 2**: `wc -l` counts the number of lines.
- **`outfile`**: The result (line count) will be saved here.


#### **Expected Output** 🖨️

This section describes what the output will look like after the program is executed.

- **Standard Output** 💻:  
  No output will be printed to the terminal. The results are saved directly to `outfile` (unless debugging).

- **Output File Content** 📄:  
  After execution, `outfile` will contain the result of the second command (`cmd2`).
  - *Example*: If using `wc -l`, the output will be the line count of `infile`.

- **Error Handling** ⚠️:  
  If an error occurs (e.g., missing files, permission errors, invalid commands), an error message will be displayed, and the program will exit without modifying `outfile`.

#### **Example Output** 📊
```bash
./pipex infile "cat" "wc -l" outfile
```
If the `infile` contains:
```
Hello World
How are you?
I'm learning Pipex.
```
The `outfile` will contain:
```
3
```
This output represents the number of lines in `infile`.


### **🔍Core Logic and Implementation**

To better understand the **core logic**, please refer to the **visual diagram** below, which outlines the entire process:

![Pipex project](https://github.com/user-attachments/assets/f85ee2a6-6f4f-4235-b728-973805c75491)

### **Steps Overview**:
1. **Setting up the `PATH` Environment** 🛠️  
   The program retrieves and parses the `PATH` variable to locate executables.

2. **Command Parsing and Validation** 🔍  
   Each command is validated and located, ensuring it's executable.

3. **Pipe Creation and Redirection** 🔄  
   Pipes are created to link the output of the first command to the input of the second.

4. **Forking Child Processes** 👶  
   Two child processes are created to run the commands concurrently.

5. **Executing Commands** 🏃  
   Commands are executed using `execve()`, which replaces the current process with the new one.

6. **Closing File Descriptors** 🚪  
   Properly closes all file descriptors to prevent resource leaks.



### **❗Error Handling**

1. **Common Errors**:
   - **Invalid Command**: Prints "Error: Command not found" and exits ❌.
   - **Permission Denied**: Handles permissions issues when reading or writing files 🔒.
   - **Broken Pipe**: If the first command fails, the program handles the failure gracefully ⚠️.

2. **Systematic Error Messages**:
   - Custom error messages are shown for incorrect arguments, permission errors, or failed system calls 📢.

### **🧠Memory Management**

1. **Dynamic Memory Allocation**  
   All dynamically allocated memory (e.g., for command arguments) must be freed after use to avoid memory leaks 💾.

2. **Avoiding Memory Leaks**  
   Use tools like `valgrind` to check for memory leaks and ensure all allocated memory is freed properly before the program exits 🚨.



### **🔧Tester - Mandatory Part**

### Non-valid Cases 🛑:

#### 1. **Wrong Number of Arguments**:
- **Command**: `valgrind ./pipex infile "cat" outfile`
  - **Expected Behavior**: The program should print an error message (e.g., "Error: Invalid number of arguments") and exit.
  - **Reason**: The mandatory part requires exactly 4 arguments (infile, command1, command2, outfile). Any deviation should trigger an error.

#### 2. **Non-existent Input File**:
- **Command**: `valgrind ./pipex nonexistentfile "cat" "wc -l" outfile`
  - **Expected Behavior**: The program should print an error like `Error: Could not open input file` and exit.
  - **Reason**: If `infile` does not exist, the program should handle this error gracefully, informing the user that the input file cannot be opened.

#### 3. **No Read Permission on Input File**:
- **Command**: `chmod -r infile && valgrind ./pipex infile "cat" "wc -l" outfile`
  - **Expected Behavior**: The program should print an error like `Error: Permission denied for input file` and exit.
  - **Reason**: If the program cannot read the input file due to permission issues, it should handle this error gracefully.

#### 4. **No Write Permission on Output File**:
- **Command**: `chmod -w outfile && valgrind ./pipex infile "cat" "wc -l" outfile`
  - **Expected Behavior**: The program should print an error like `Error: Permission denied for output file` and exit.
  - **Reason**: If the program cannot write to the output file, it should handle this error gracefully.

#### 5. **Non-existent Command (Invalid Command)**:
- **Command**: `valgrind ./pipex infile "invalidcommand" "wc -l" outfile`
  - **Expected Behavior**: The program should print an error like `Error: Command not found` and exit.
  - **Reason**: If `execve()` cannot find or execute the command, the program should catch the error and inform the user that the command is invalid.

#### 6. **Invalid Permissions on a Command**:
- **Command**: `chmod -x /bin/cat && valgrind ./pipex infile "/bin/cat" "wc -l" outfile`
  - **Expected Behavior**: The program should print an error like `Error: Permission denied for command /bin/cat` and exit.
  - **Reason**: If a command exists but lacks execution permissions, the program should handle this and exit with a meaningful error message.

#### 7. **Empty Input File**:
- **Command**: `valgrind ./pipex emptyfile "cat" "wc -l" outfile`
  - **Expected Behavior**: The program should write `0` to `outfile` since the input file is empty.
  - **Reason**: An empty input file is a valid case, but it can lead to a `wc -l` output of `0`. Ensure the program handles empty files correctly and outputs the expected result.

#### 8. **Broken Pipe**:
- **Command**: `valgrind ./pipex infile "invalidcommand" "wc -l" outfile`
  - **Expected Behavior**: The program should handle this gracefully without crashing or leaving file descriptors open.
  - **Reason**: If the first command fails, there’s no output to pipe to the second command. The program should handle the broken pipe case and avoid hanging.

#### 9. **Invalid Output File Path**:
- **Command**: `./pipex infile "cat" "wc -l" /invalid/path/to/outfile`
  - **Expected Behavior**: The program should print an error like `Error: Could not open output file` and exit.
  - **Reason**: If the output file path is invalid or points to a directory that doesn’t exist, the program should handle this error.

#### 10. **File Descriptors Exhaustion**:
- **Command**: Test a scenario where too many file descriptors are open, preventing the program from opening more pipes or files.
  - **Expected Behavior**: The program should print an error like `Error: Too many open files` and exit gracefully.
  - **Reason**: In cases where the system runs out of available file descriptors, the program should handle this failure scenario gracefully.

#### 11. **Invalid Path in Environment**:
- **Command**: Modify the `PATH` environment variable to an invalid path, then run:
  ```bash
  PATH=/invalid/path valgrind ./pipex infile "cat" "wc -l" outfile
  ```
  - **Expected Behavior**: The program should print an error like `Error: Command not found` for both `cat` and `wc -l`.
  - **Reason**: If the `PATH` environment variable is invalid, commands like `cat` and `wc` won’t be found, and the program should handle this case gracefully.

#### 12. **Output File in a Read-Only Directory**:
- **Command**: Create a read-only directory and try writing an output file to it:
  ```bash
  mkdir readonlydir && chmod -w readonlydir && valgrind ./pipex infile "cat" "wc -l" readonlydir/outputfile
  ```
  - **Expected Behavior**: The program should print an error like `Error: Permission denied for output file` and exit.
  - **Reason**: If the output file cannot be created due to directory permissions, the program should fail gracefully.

#### 13. **Incorrect Syntax (Quotes Not Handled Properly)**:
- **Command**: `valgrind ./pipex infile "cat" "'wc -l'" outfile`
  - **Expected Behavior**: The program should print an error like `Error: Invalid syntax or command not found` and exit.
  - **Reason**: If quotes are not handled correctly in commands, this can lead to the command being passed incorrectly to `execve()`. The program should identify and handle incorrect syntax.



### Valid Command Combinations for Two Commands 🔄:

#### 1. **Word Count**
- **Command**: `valgrind ./pipex infile "cat" "wc -w" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `wc -w` counts the words, writing the result to `outfile`.

#### 2. **Line Count**
- **Command**: `valgrind ./pipex infile "cat" "wc -l" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `wc -l` counts the number of lines.

#### 3. **Character Count**
- **Command**: `valgrind ./pipex infile "cat" "wc -c" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `wc -c` counts the number of characters (including whitespace and newlines).

#### 4. **Sort File Contents**
- **Command**: `valgrind ./pipex infile "cat" "sort" outfile`
- **Explanation**: `cat` outputs the content of `infile`, and `sort` sorts the lines alphabetically.

#### 5. **Reverse File Content**
- **Command**: `valgrind ./pipex infile "cat" "rev" outfile`
- **Explanation**: `cat` reads `infile`, and `rev` reverses each line of text before writing to `outfile`.

#### 6. **Search for a Pattern**
- **Command**: `valgrind ./pipex infile "cat" "grep 'pattern'" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `grep 'pattern'` filters lines containing the pattern "pattern".

#### 7. **Remove Empty Lines**
- **Command**: `valgrind ./pipex infile "cat" "grep -v '^$'" outfile`
- **Explanation**: `cat` reads the file, and `grep -v '^$'` removes empty lines from the output.

#### 8. **Count the Number of Lines Matching a Pattern**
- **Command**: `valgrind ./pipex infile "grep 'pattern'" "wc -l" outfile`
- **Explanation**: `grep 'pattern'` searches for lines containing the word "pattern", and `wc -l` counts how many lines matched the pattern.

#### 9. **Find and Count Specific Words**
- **Command**: `valgrind ./pipex infile "grep 'txt'" "wc -w" outfile`
- **Explanation**: `grep 'txt'` searches for lines containing the word "txt", and `wc -w` counts how many words match.

#### 10. **Count Non-Empty Lines**
- **Command**: `valgrind ./pipex infile "grep -v '^$'" "wc -l" outfile`
- **Explanation**: `grep -v '^$'` filters out empty lines, and `wc -l` counts the number of non-empty lines.

#### 11. **Transform Text to Uppercase**
- **Command**: `valgrind ./pipex infile "cat" "tr 'a-z' 'A-Z'" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `tr 'a-z' 'A-Z'` converts all lowercase letters to uppercase.

#### 12. **Transform Text to Lowercase**
- **Command**: `valgrind ./pipex infile "cat" "tr 'A-Z' 'a-z'" outfile`
- **Explanation**: `cat` reads `infile`, and `tr 'A-Z' 'a-z'` converts uppercase letters to lowercase.

#### 13. **Display the First 5 Lines of the File**
- **Command**: `valgrind ./pipex infile "head -n 5" "cat" outfile`
- **Explanation**: `head -n 5` reads the first 5 lines from `infile`, and `cat` writes it to `outfile`.

#### 14. **Display the Last 5 Lines of the File**
- **Command**: `valgrind ./pipex infile "tail -n 5" "cat" outfile`
- **Explanation**: `tail -n 5` reads the last 5 lines from `infile`, and `cat` outputs them.

#### 15. **Find Files in a Directory and Count Matching Files**
- **Command**: `valgrind ./pipex infile "ls -l" "grep 'txt'" outfile`
- **Explanation**: `ls -l` lists files in the directory, and `grep 'txt'` filters files that contain "txt" in their names.

#### 16. **Unique Lines from a File**
- **Command**: `valgrind ./pipex infile "cat" "uniq" outfile`
- **Explanation**: `cat` reads the content of `infile`, and `uniq` filters out duplicate consecutive lines.

#### 17. **Sort and Remove Duplicates**
- **Command**: `valgrind ./pipex infile "sort" "uniq" outfile`
- **Explanation**: `sort` sorts the lines alphabetically, and `uniq` removes duplicate lines.

#### 18. **Replace a Word in the File**
- **Command**: `valgrind ./pipex infile "sed 's/old/new/g'" "cat" outfile`
- **Explanation**: `sed 's/old/new/g'` replaces all occurrences of "old" with "new" in the file.

#### 19. **Count the Occurrences of a Pattern**
- **Command**: `./pipex infile "grep -o 'word'" "wc -l" outfile`
- **Explanation**: `grep -o 'word'` prints each occurrence of the word "word", and `wc -l` counts how many times it appeared.

#### 20. **Display File Content with Line Numbers**
- **Command**: `valgrind ./pipex infile "cat -n" "cat" outfile`
- **Explanation**: `cat -n` displays each line with its line number, and `cat` writes it to `outfile`.


---
