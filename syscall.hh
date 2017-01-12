#pragma once

//typedef int ssize_t;
//typedef unsigned int size_t;

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_open(const char *pathname, int flags, mode_t mode);
ssize_t my_write(int fd, const void *buffer, size_t size);
