# Really-Quick-Primes

This program will calculate all of the prime numbers between 1 and 100 very quickly. I could not make the code anymore time or space efficient. In order to run it, you will need to use the GCC compiler.

## Speed savings
To achieve my blazing speeds, I used a number of tricks. It is important to keep in mind, however, that due to the power of modern compilers, most of these tricks will yeild little to no results.

### Pragmas
Using `#pragma GCC optimize("Ofast")` will tell the compiler to compile your code in a very speed efficient manor. In some cases, the compiler may sacrifice memory for speed, which was fine by me. This trick had very little effect on the speed of my code.

### Array definition
Originally, I had a for loop that would populate the initial values for the array. While this is a common practice, it isn't very speedy. Instead, for small arrays, it is often better to initialize them by hand (when you can). For larger arrays, I would recommend using `memset()`. This trick had little effect and made my code an eyesore.

### Prefix increment
While the savings are small, it is slightly faster to use prefix incrementing rather than postfix. There was no noticable difference in speed.

### Register variables
In my code, you will notice that I defined a variable `i`, which uses the `register` keyword:
```c
register uint8_t i = 2;
```
The register keyword is used to tell the compiler that a given variable will be used often and should be stored in a register (which is quicker to access than Random Access Memory). This trick also had little to no effect because the compiler likely already knew to store the variable in a register.

### Variable reduction
Initializing variables takes time. The processor must allocate memory for the value and then assign it the proper value. To cut down on a couple of assembly instructions, I reused the `i` index variable and simply assigned it a new value. Because this only cut down on a couple assembly instructions, there was no noticable difference in speed.

### Algorithms
The biggest speed boost you can gain will be found in using the right algorithm. I'm not sure if I used the most efficient, however, it does the job pretty quick. I didn't test out a bunch of different algorithms, so I can't comment on how this may have affected the execution speed.

### File stream buffering mode
By far the greatest gain in speed that I found (aside from a decent algorithm) was setting the buffering mode for `stdout`.
```c
uint8_t buffer[1024];
setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));
```
Doing this cut the exection time in half. After this chage, my code actually ran faster than using `printf()` and printing precalculated values. I could likely save even more time if I only used a single print statement, however, I was happy with this result.
