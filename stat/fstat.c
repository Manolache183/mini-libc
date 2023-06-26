// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	long r = syscall(5, fd, st);
	
	if (r < 0) {
        errno = -r;
        return -1;
    }

    return 0;
	return -1;
}
