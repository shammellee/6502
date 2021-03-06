/**
 * The MIT License (MIT)

 * Copyright (c) 2016 Chaabane Jalal

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SPI_TEST_INSTRUCTION_H
# define SPI_TEST_INSTRUCTION_H

# include "spi/cpu/cpu_6502.h"

# define SPI_UNIT_TEST(cpu, mem, size, body) {  \
    spi_test_env_t  env;                        \
                                                \
    env.cpu = *cpu;                             \
    env.mem = mem;                              \
    env.mem_size = size;                        \
    body                                        \
}

struct spi_test_env_s {
    spi_cpu_t   cpu;
    spi_byte_t  *mem;
    size_t      mem_size;
};

typedef struct spi_test_env_s spi_test_env_t;

typedef void (*spi_test_fn_t)(spi_cpu_t *cpu, spi_byte_t *mem);

void spi_test_instruction(const spi_byte_t *opcodes,  const uint16_t value,
                          size_t nb_opcodes, spi_test_fn_t fn,
                          const spi_test_env_t *env);

#endif //SPI_6502_TEST_INSTRUCTION_H
