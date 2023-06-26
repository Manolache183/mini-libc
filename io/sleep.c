#include <unistd.h>
#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec ts = {seconds, 0};
    struct timespec rem = {0, 0};

    int r = nanosleep(&ts, &rem);
    while (r == -1) {
        if (errno == EINTR) {
            ts = rem;
        } else {
            return rem.tv_sec;
        }

        r == nanosleep(&ts, &rem);
    }

    return 0;
}