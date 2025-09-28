# Pipex (42 Project)

**Pipex** is a program that mimics the behavior of shell pipes in C. It takes two commands and executes them in a pipeline, redirecting the output of the first command as input to the second command, similar to the shell command `< file1 cmd1 | cmd2 > file2`.

This project demonstrates understanding of **processes**, **pipes**, **file descriptors**, and **inter-process communication** in Unix systems.

---

## 🎯 Project Overview

Pipex recreates the functionality of shell pipes by:
- Creating child processes using `fork()`
- Establishing communication between processes using `pipe()`
- Redirecting input/output using `dup2()`
- Executing commands using `execve()`
- Properly handling exit codes and error cases

**Equivalent Shell Command:**
```bash
< file1 cmd1 | cmd2 > file2
```

**Pipex Usage:**
```bash
./pipex file1 cmd1 cmd2 file2
```

---

## 📦 Project Structure

```
├── src/
│   ├── pipex.c           # Main program logic and process management
│   ├── executor.c        # Child process execution and I/O redirection
│   ├── parser.c          # Command parsing and PATH resolution
│   ├── utils.c           # File operations and memory management
│   └── error_handler.c   # Error handling and cleanup
├── Libft/                # Custom C library (ft_split, ft_strjoin, etc.)
├── pipex.h               # Header file with function declarations
├── Makefile              # Build configuration
└── README.md             # Project documentation
```

---

## 🔧 Key Features

- **Process Management**: Creates and manages child processes using `fork()`
- **Pipe Communication**: Establishes inter-process communication with `pipe()`
- **I/O Redirection**: Redirects stdin/stdout using `dup2()`
- **Command Execution**: Executes shell commands with `execve()`
- **PATH Resolution**: Automatically finds executables in system PATH
- **Error Handling**: Comprehensive error handling for all edge cases
- **Memory Management**: Proper allocation and deallocation with no memory leaks
- **Exit Code Propagation**: Returns the exit code of the last executed command

---

## ⚙️ Compilation & Usage

### Compile
```bash
# Build the project
make

# Clean object files
make clean

# Clean everything including executable
make fclean

# Rebuild everything
make re
```

### Basic Usage
```bash
# Basic example: count lines in a file
./pipex input "cat" "wc -l" output

# Equivalent to: < input.txt cat | wc -l > output.txt
```

### Advanced Example
```bash
# Search and count words
./pipex input "grep hello" "wc -w" output
# Equivalent to: < input.txt grep hello | wc -w > output.txt
```

---

## 🔍 Technical Implementation

### Process Flow
1. **Argument Validation**: Checks for exactly 4 arguments
2. **Pipe Creation**: Creates a pipe for inter-process communication
3. **Child Process 1**: 
   - Redirects stdin from input file
   - Redirects stdout to pipe write end
   - Executes first command
4. **Child Process 2**:
   - Redirects stdin from pipe read end
   - Redirects stdout to output file
   - Executes second command
5. **Parent Process**: Waits for both children and returns exit code

### Key Functions

| Function | Purpose |
|----------|---------|
| `main()` | Program entry point, manages processes |
| `exec_child1()` | Handles first command execution |
| `exec_child2()` | Handles second command execution |
| `parse_command()` | Parses command strings and resolves paths |
| `get_path()` | Extracts PATH directories from environment |
| `open_infile()` | Opens input file with error handling |
| `open_outfile()` | Creates/opens output file with proper permissions |

### Error Handling
- **File Permissions**: Handles read/write permission errors
- **Command Not Found**: Returns appropriate exit codes (127)
- **Invalid Arguments**: Validates argument count and format
- **Memory Allocation**: Checks all malloc calls and frees memory
- **System Calls**: Handles pipe, fork, and execve failures

---

**Author**: ryachan  
**School**: 42 Kuala Lumpur  
**Project**: Pipex (Milestone 2)