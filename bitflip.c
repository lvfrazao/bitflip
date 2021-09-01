#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#define NUM_ELEMS 1000000000
// 1 billion longs is 64 billion bits -> ~7.45 gb mem

uint64_t sum(volatile uint64_t *arr, uint64_t len);
char *timestamp();

int main() {
        volatile uint64_t s, *bigMem = calloc(NUM_ELEMS, sizeof(long));
        char *t;
        while (!sleep(60)) {
            t = timestamp();
            s = sum(bigMem, NUM_ELEMS);
            printf("%s %ld\n", t, s);
            if (s)
                printf("HOLY SHIT ITS A BITFLIP!!!!!!Q!!!11!!!!\n");
            fflush(stdout);
            free(t);
        }
}

char *timestamp()
{
    time_t ltime; /* calendar time */
    ltime=time(NULL); /* get current cal time */
    char *t_str = calloc(100, sizeof(char)) ;
    snprintf(t_str, 100, "%s",asctime( localtime(&ltime) ) );
    t_str[strlen(t_str) - 1] = ' ';
    return t_str;
}

uint64_t sum(volatile uint64_t *arr, uint64_t len)
{
    uint64_t sum = 0;
    for (uint64_t i = 0; i < len; i++, arr++)
    {
        sum += *arr;
    }
    return sum;
}

