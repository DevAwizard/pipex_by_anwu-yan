![cover-pipex](https://github.com/user-attachments/assets/557e560b-87c0-4dd5-aaca-be94247a947b)

### Table of Contents for Pipex Documentation

## Table of Contents

1. [Project Overview](#project-overview)
    - [Introduction to Pipex](#introduction-to-pipex)
    - [Objectives and Goals](#objectives-and-goals)
2. [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Required Functions and Libraries](#required-functions-and-libraries)
    - [Project Structure Overview](#project-structure-overview)
3. [Program Usage](#program-usage)
    - [How to Run the Program](#how-to-run-the-program)
    - [Example Commands](#example-commands)
    - [Expected Input and Output](#expected-input-and-output)
4. [Core Logic and Implementation](#core-logic-and-implementation)
    - [Setting up the PATH Environment](#setting-up-the-path-environment)
    - [Command Parsing and Validation](#command-parsing-and-validation)
    - [Pipe Creation and Redirection](#pipe-creation-and-redirection)
    - [Forking Child Processes](#forking-child-processes)
    - [Executing Commands with execve()](#executing-commands-with-execve)
    - [Closing File Descriptors](#closing-file-descriptors)
5. [Error Handling](#error-handling)
    - [Common Errors and Handling](#common-errors-and-handling)
    - [Systematic Error Messages](#systematic-error-messages)
6. [Memory Management](#memory-management)
    - [Dynamic Memory Allocation and Deallocation](#dynamic-memory-allocation-and-deallocation)
    - [Avoiding Memory Leaks](#avoiding-memory-leaks)
7. [Tester - Mandatory Part](#tester---mandatory-part)
    - [Non-valid Cases](#non-valid-cases)
    - [Valid Command Combinations for Two Commands](#valid-command-combinations-for-two-commands)


### **Project Overview**

#### **Introduction to Pipex**
`Pipex` is a project aimed at understanding and implementing the piping mechanism in UNIX. The goal is to create a program that mimics the behavior of the shell in handling input/output redirection between commands. By doing this project, you will deepen your understanding of how UNIX pipes work, particularly in the context of system calls like `pipe()`, `fork()`, `dup2()`, and `execve()`.

**Objective**: 
- Replicate the functionality of the shell command:  
  ```bash
  < infile cmd1 | cmd2 > outfile
  ```
- `Pipex` takes two commands, reads input from a file, passes the output of the first command as input to the second command, and writes the final output to another file.


### **Getting Started**

#### **Prerequisites**
- **System Requirements**: A Unix-based system (e.g., Linux, macOS).
- **Compiler**: GCC or any standard C compiler.
- **Knowledge**: Familiarity with UNIX system calls such as `fork()`, `pipe()`, `execve()`, `dup2()`, and working with file descriptors.
- **Makefile**: You need to deliver a `Makefile` that compiles your project using the `-Wall`, `-Werror`, and `-Wextra` flags, without relinking unnecessary files.

#### **Required Functions and Libraries**
You are allowed to use the following functions:
- `open()`, `close()`, `read()`, `write()`
- `malloc()`, `free()`
- `perror()`, `strerror()`
- `access()`, `dup()`, `dup2()`
- `execve()`, `exit()`, `fork()`, `pipe()`, `unlink()`
- `wait()`, `waitpid()`

Additionally, your project can use the `libft` library.

### **Project Structure Overview**

#### **File Descriptions**
- **pipex.h**: This header file contains function prototypes, macros, and structure definitions that will be shared across the project files.
- **pipex.c**: The core logic of the program, where the pipes, redirection, and execution of commands take place.
- **utils.c**: Helper functions, such as string manipulation or memory management routines, to support the main program.
- **Makefile**: The build script that compiles the project and handles common tasks like cleaning object files and rebuilding.


### **Program Usage**

#### **How to Run the Program**
The `pipex` program takes the following command-line arguments:
```bash
./pipex infile "cmd1" "cmd2" outfile
```
- `infile`: The input file whose contents will be fed into `cmd1`.
- `cmd1`: The first shell command that reads from the input file.
- `cmd2`: The second shell command that reads the output of `cmd1`.
- `outfile`: The output file where the result of `cmd2` will be written.

#### **Example Commands**
```bash
./pipex infile "ls -l" "wc -l" outfile
```
This command reads the contents of `infile`, runs `ls -l`, passes its output to `wc -l`, and writes the result to `outfile`.

#### **Expected Input and Output**
- **Input**: The content of the `infile`.
- **Output**: The result of the commands piped together, written to the `outfile`.


### **Core Logic and Implementation**

To understand the core logic of the `pipex` program, refer to the visual diagram provided. The diagram outlines the entire process, from setting up the environment to executing commands and handling pipes.

Below is a brief overview of the steps:

1. **Setting up the `PATH` Environment**:  
   Retrieves and parses the `PATH` variable to locate executable commands.

2. **Command Parsing and Validation**:  
   Validates and locates each command, ensuring it's executable.

3. **Pipe Creation and Redirection**:  
   Creates pipes to link the output of the first command to the input of the second.

4. **Forking Child Processes**:  
   Two child processes are created to run the commands concurrently.

5. **Executing Commands with `execve()`**:  
   Executes the commands by replacing the current process with the specified program.

6. **Closing File Descriptors**:  
   Properly closes all file descriptors to prevent resource leaks.

For a detailed breakdown of how each step is executed, please refer to the following  **visual diagram**.



![Pipex project](https://github.com/user-attachments/assets/f85ee2a6-6f4f-4235-b728-973805c75491)


### **Error Handling**

#### **1. Common Errors and Handling**
The program must gracefully handle the following:
- **Invalid Command**: If a command is not found in the `PATH`, the program prints an error and exits.
- **Permission Denied**: If the program cannot open the input/output files due to permissions, it must exit with a meaningful error message.
- **Broken Pipe**: If `cmd1` fails, the pipe should not hang, and the program should terminate cleanly.

#### **2. Systematic Error Messages**
Custom error messages are displayed for invalid arguments, permission errors, or failed system calls. These messages are accompanied by an exit status to indicate failure.

### **Memory Management**

#### **1. Dynamic Memory Allocation and Deallocation**
Any dynamically allocated memory (e.g., for storing command arguments) must be freed after use. Failure to do so will result in memory leaks.

#### **2. Avoiding Memory Leaks**
Tools like `valgrind` can be used to ensure there are no memory leaks in the program. All allocated memory should be tracked and released properly before the program exits.


### Tester - Mandatory Part

### Non valid cases:

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


### Valid arguments - Command Combinations for Two Commands:

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

