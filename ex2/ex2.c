// Write a program that opens the text.txt file (with the `fopen()` system call) located in this directory 
// Then calls `fork()` to create a new process.
// Can both the child and parent access the file descriptor returned by `fopen()`?
// What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    int n;
    FILE *fptr;
    fptr = fopen("text.txt","a+");
    
    if(fptr == NULL) {
        printf("Error");
        exit(1);
    }

    int forked = fork();

    if(forked == 0) {
        printf("Welcome to the Thunder Dome!\n");
        printf("Enter number: \n");
        scanf("%d", &n);
        fprintf(fptr,"%d", n);
        fclose(fptr);
    } else {
        waitpid(forked, NULL, 0);
        printf("Enter number: \n");
        scanf("%d", &n);
        fprintf(fptr, "%d", n);
        fclose(fptr);
        printf("It's been fun :/\n");
    }
    return 0;
}
