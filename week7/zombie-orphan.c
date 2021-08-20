#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>
#include <sys/wait.h>
int main()
{
  
    int x;
    x = fork();
  
    if (x > 0)
        printf("IN PARENT PROCESS\nMY PROCESS ID : %d\n", getpid());
  
    else if (x == 0) {
        sleep(5);
        x = fork();
  
        if (x > 0) {
   printf("IN CHILD PROCESS\nMY PROCESS ID :%d\nPARENT PROCESS ID : %d\n", getpid(), getppid());
  
   while(1)
     sleep(1);
  
   printf("IN CHILD PROCESS\nMY PARENT PROCESS ID : %d\n", getppid());
        }
  
        else if (x == 0)
            printf("IN CHILD'S CHILD PROCESS\nMY PARENT ID : %d\n", getppid());
    }
  
    return 0;
}
