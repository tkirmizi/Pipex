# Pipex

This project implements a simplified version of the UNIX pipex utility,

< infile command1 | command2 > outfile

by impelementing multiple commands together using pipes. The program handles the 

creation of 'child' processes via 'fork()' and manages inter-process communication using 

'pipes'. It can execute commands by passing the output of one command as the input to the next thanks to pipe feature.

At the beginning it seems hard as because of many new funcitons used but after getting familiar with and

well understanding child-parent process communication, everything become easier. 
