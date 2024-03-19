1. Computing the nth Fibonacci number:

```
function fibonacci(n):
    if n <= 1:
        return n
    else:
        a = fibonacci(n - 1)
        b = fibonacci(n - 2)
        return a + b
```

2. Computing the factorial of a number:

```
function factorial(n):
    if n <= 1:
        return 1
    else:
        return n * factorial(n - 1)
```

3. Computing the square root of a number:

```
function squareRoot(x):
    return squareRootHelper(x, 0, x)

function squareRootHelper(x, low, high):
    mid = (low + high) / 2
    square = mid * mid

    if abs(square - x) < epsilon:
        return mid
    elif square < x:
        return squareRootHelper(x, mid, high)
    else:
        return squareRootHelper(x, low, mid)
```

4. Computing the prime factorization of a number:

```
function primeFactorization(n):
    for each prime p:
        if n is divisible by p:
            return p, primeFactorization(n / p)
    return n
```

5. Computing the greatest common divisor (GCD) of two numbers:

```
function gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
```

6. Computing the least common multiple (LCM) of two numbers:

```
function lcm(a, b):
    return (a * b) / gcd(a, b)
```

These pseudocode snippets illustrate the divide and conquer approach for each of the mentioned problems.
