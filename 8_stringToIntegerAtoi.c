#include <stdint.h>
#include <limits.h>

int32_t myAtoi(const char *s) {
    const unsigned char *p = (const unsigned char *)s;
    /* skip leading spaces */
    while (*p == ' ') p++;

    /* optional sign */
    int neg = 0;
    if (*p == '+') {
        p++;
    } else if (*p == '-') {
        neg = 1;
        p++;
    }

    /* Use 64-bit accumulator to avoid signed overflow on (acc*10 + digit) */
    int64_t acc = 0;
    while (*p >= '0' && *p <= '9') {
        int digit = *p - '0';

        /* overflow check: clamp to 32-bit signed range */
        if (acc > 214748364LL ||
            (acc == 214748364LL && digit > (neg ? 8 : 7))) {
            return neg ? INT32_MIN : INT32_MAX;
        }

        acc = acc * 10 + digit;
        p++;
    }

    if (neg) acc = -acc;
    return (int32_t)acc;
}
