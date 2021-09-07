/**
 * Simple program demonstrating shared memory in POSIX systems.
 * This is the producer process that writes to the shared memory region.
 * @author Silberschatz, Galvin, and Gagne
 * Modified for CSC2404
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

void convert(char* str)
{
    // get length of string str
    int str_length = strlen(str);
    // create an array with size as string
    // length and initialize with 0
    int *arr=(int*)malloc(str_length*sizeof(int));
    int j = 0, i, sum = 0;
    // Traverse the string
    for (i = 0; str[i] != '\0'; i++) {
        // if str[i] is ', ' then split
        if (str[i] == ',')
            continue;
         if (str[i] == ' '){
            // Increment j to point to next
            // array location
            j++;
        }
        else {
            // subtract str[i] by 48 to convert it to int
            // Generate number by multiplying 10 and adding
            // (int)(str[i])
            arr[j] = arr[j] * 10 + (str[i] - 48);
			//printf("arr[%d]: %d \n ",j,arr[j]);
        }
    }
    for (i = 0; i <= j; i++) {
		//-------------ADD YOUR CODE HERE--------------------
		// add the array element to the sum
        sum += arr[i]; // sum of array
    }
		//-------------ADD YOUR CODE HERE--------------------
         printf("sum: %d ",sum);
}
int main()
{
	const char *name = "OS";
	const int SIZE = 4096;
	int shm_fd;
	void *ptr;
	int i;
	/* open the shared memory segment */
	shm_fd = shm_open(name, O_RDONLY, 0666);
	if (shm_fd == -1) {
		printf("shared memory failed\n");
		exit(-1);
	}
	/* now map the shared memory segment in the address space of the process */
	ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("Map failed\n");
		exit(-1);
	}
	/* now read from the shared memory region */
    printf("%s",(char *)ptr);
	printf("\n");
	convert(ptr);
	/* remove the shared memory segment */
	if (shm_unlink(name) == -1) {
		printf("Error removing %s\n",name);
		exit(-1);
	}
	return 0;
}