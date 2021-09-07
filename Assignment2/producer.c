/**
 * Simple program demonstrating shared memory in POSIX systems.
 * This is the producer process that writes to the shared memory region.
 * @author Silberschatz, Galvin, and Gagne
 * Modified for CSC2404
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

int main()
{
	const int SIZE = 4096;
	const char *name = "OS";
	const char *message0= "Studying ";
	const char *message1= "Operating Systems ";
	const char *message2= "Is Fun!";
	
	int shm_fd;
	void *ptr;

	/* create the shared memory segment */
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	/* configure the size of the shared memory segment */
	ftruncate(shm_fd,SIZE);

	/* now map the shared memory segment in the address space of the process */
	ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("Map failed\n");
		return -1;
	}
	/**
	 * Now write to the shared memory region.
	 * Note we must increment the value of ptr after each write.
	 */
	//--------------ADD YOUR CODE HERE ---------------
	int data[] = {0,1,2,3,4,5,6,7,8,9};
	for (int i=0; i< 10; i++){
		printf("%d, ",data[i]);
		ptr += sprintf(ptr,"%d, ",data[i]);
	}
    //-------------------------------------------------
	return 0;
}