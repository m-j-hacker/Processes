// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    
    int x = 100;
    pid_t pid = fork();
    printf("Line 14: value of x: %d\n", x);
    if (pid == 0) {
        x = 90;
        printf("child: value of x: %d\n", x);
        exit(7);
    } else {
        x = 80;
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("parent: child exited with status %d\n", WEXITSTATUS(status));
            printf("parent: value of x: %d\n", x);
        } else {
            printf("parent: child killed by signal, crashed, or stopped\n");
        }
    }

    return 0;
}
