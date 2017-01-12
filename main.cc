#include "syscall.hh"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv){
	/* we're calling the write system call */
	/* file descriptor is 0 - standard output to the terminal */
	/* buffer is the string constant "hello" */
	/* the length of the buffer is 6 bytes */

	const char *data = "ABC";
	int fd = my_open("Output", O_CREAT|O_TRUNC|O_RDWR, 0666);
	size_t length = (1024 * atoi(argv[1])), total = 100, offset = 0;
	while(total > 0) {
		while(length > 0) {
			size_t written = my_write(fd, data + offset, length);
			offset += written;
			length -= written;
		}
		total -= length;
	}
	close(fd);
}
