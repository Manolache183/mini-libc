// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long r = syscall(__NR_mmap, addr,length, prot, flags, fd, offset);

	if (r < 0) {
		errno = -r;
		return MAP_FAILED;
	}
	
	void *ret = r;
	return ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long r = syscall(__NR_mremap, old_address, old_size, new_size, flags);

	if (r < 0) {
		errno = -r;
		return MAP_FAILED;
	}
	
	void *ret = r;
	return ret;
}

int munmap(void *addr, size_t length)
{
	long r = syscall(__NR_munmap, addr, length);

	if (r < 0) {
		errno = -r;
		return -1;
	}
	
	return 0;
}
