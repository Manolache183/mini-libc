#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    long r = syscall(__NR_nanosleep, req, rem);

    if (r < 0) {
        errno = -r;
        return -1;
    }

    return 0;
}