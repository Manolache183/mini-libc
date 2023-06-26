// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	long r = syscall(__NR_close, fd);

	if (r < 0) {
		errno = -r;
		return -1;
	}

	return 0;
}
