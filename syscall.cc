#include "syscall.hh"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* taken from linux kernel source in arch/x86/entry/syscalls/syscall_64.tbl */
/* system call constants */
#define READ_SYSTEM_CALL 0
#define WRITE_SYSTEM_CALL 1
#define OPEN_SYSTEM_CALL 2
#define CLOSE_SYSTEM_CALL 3
/* system call constants */


/*
 *	low level c++/assembly code for Intel 64-bit CPU to make a call to the write system call
 */

int my_open(const char *pathname, int flags, mode_t mode) {
	int returnVal;
	returnVal = syscall(OPEN_SYSTEM_CALL, pathname, flags, mode);
	return returnVal;
}

ssize_t my_write(int fd, const void *buffer, size_t size) {
	ssize_t returnValue;
	returnValue = syscall(WRITE_SYSTEM_CALL, fd, buffer, size);
	return returnValue;
}
