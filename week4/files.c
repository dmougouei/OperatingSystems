// C program for open and close system calls
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{    
    // create CSC2404.txt if it does not exit (O_CREAT)
    // open the file for red and write (O_RDWR)
    int fd = open("CSC2404.txt", O_RDWR | O_CREAT);
    printf("File descriptor: %d \n", fd);
     
    if (fd ==-1) // Error
    {
        // print which type of error have in a code
        printf("Error Number % d\n", errno);
        // print program detail "Success or failure"
        perror("Program"); 
        exit(1);
    }
    else{
      // Using close system Call
      if (close(fd) < 0)
      {
          perror("c1");
          exit(1);
      }
      else{
        printf("Closed the file.\n");
      }
    }
    return 0;
}
