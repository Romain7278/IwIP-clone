#include <stdint.h>
#include <time.h>

/* lwIP expects sys_now() to return time in milliseconds */
uint32_t sys_now(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint32_t)(ts.tv_sec * 1000u + ts.tv_nsec / 1000000u);
}
