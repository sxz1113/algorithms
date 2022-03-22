# Runtime Analysis

1. algorithm
2. correctness
3. runtime analysis

+ precise way - architecture dependent, instruction set dependent, runtime is not reproducible

+ simplification
    + only count the number of basic computer steps, as a function of the input size

    + leave out lower-order terms. e.g.
    $$
    5n^3 + 4n + 3
    \approx 5n^3
    $$

+ big O notation
    $$
    f = O(g) \\
    f(n) \le c \cdot g(n)
    $$
  grows no faster than g with const c > 0