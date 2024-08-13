# Pipex

This project implements a simplified version of the `shell` utility

`< infile command1 | command2 > outfile`

by impelementing multiple commands together using pipes. The program handles the 

creation of `child processes` via `fork()` and manages inter-process communication using

`Pipes`. It can execute commands by passing the output of one command as the input to the

next thanks to pipe feature.


![Screenshot 2024-08-12 at 22 46 26](https://github.com/user-attachments/assets/42cb94ac-99fb-4913-ba82-e01438c87200)

