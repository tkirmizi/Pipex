# Pipex

This project implements a simplified version of the `shell` utility

`< infile command1 | command2 > outfile`

by impelementing multiple commands together using pipes. The program handles the 

creation of `child processes` via `fork()` and manages inter-process communication using

`Pipes`. It can execute commands by passing the output of one command as the input to the

next thanks to pipe feature.


<img width="664" alt="Screenshot 2024-08-12 at 22 06 44" src="https://github.com/user-attachments/assets/9a5b6295-0b6f-4911-be5d-899dd1caacac">
