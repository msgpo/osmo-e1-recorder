#include <stdint.h>
#include "flip_bits.h"

static uint8_t flip_table[256];

void init_flip_bits(void)
{
        int i,k;

        for (i = 0 ; i < 256 ; i++) {
                uint8_t sample = 0 ;
                for (k = 0; k<8; k++) {
                        if ( i & 1 << k ) sample |= 0x80 >>  k;
                }
                flip_table[i] = sample;
        }
}

uint8_t *flip_buf_bits(uint8_t *buf, int len)
{
        int i;
        uint8_t *start = buf;

        for (i = 0 ; i < len; i++) {
                buf[i] = flip_table[(uint8_t)buf[i]];
        }

        return start;
}
