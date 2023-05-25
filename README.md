# pipex
pipex is a command-line utility that mimics the functionality of the pipe operator in shell commands. It allows you to redirect the output of one command as the input of another command, similar to the shell syntax "command1 | command2". With pipex, you can specify two commands and an input/output file, and it will execute the commands, redirecting the output from the first command as the input to the second command.

# Usage:
To use pipex, you can run it from the command line with the following syntax:

pipex file1 cmd1 cmd2 file2

- file1: Input file to be used as the initial input for cmd1.
- cmd1: First command to be executed.
- cmd2: Second command to be executed.
- file2: Output file where the final result will be written.

