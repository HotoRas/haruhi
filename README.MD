# The Length of SuperPermutations

This repository contains some suggestions (minimum, maximum, and a newly suggested forms after year of 2022) of finding the Length of SuperPermutations.

## Compile and run
> Both C and C++ codes are using same algorithm- C++ version implements bigint for larger integer calculations.
>
> C should be faster than C++: but unable to handle too large numbers around 15! and up.

Using GCC (C99 compatible)
```sh
gcc -o haruhi src/main.c
```
and run by
```sh
./haruhi <the value you want to see>
```

> The upper bound of valid value is around 14 and 15 on C.

Using G++
```sh
g++ -o haruhi src/main2.cpp src/bigint.h
```
and run by
```sh
./haruhi <the value you want to see>
```

## What is SuperPermutation?
SuperPermutation is the shortest array of kinds, which contains the every possible permutations using those kinds are in.

While, a permutation indicates an arrangement if its members in a sequence.

For example, if we come up with a set {1, 2, 3} and we're going to get the length of superpermutation of it:

1. We'll list the possible permutations on it which ends up with
  - (1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)

2. We now arrange the permutations with overlap allowed, so when beginning with (1, 2, 3) it will be
  - (1, 2, 3, 1, 2, 1, 3, 2, 1)

3. Now we check if it contains all possibilities
  - and yes (omitted)

4. So we count it, and it's **9**.

## Why it's so hard to get the length?
Since we don't know the forming algorithm of superpermutations (until now), we can\'t just count how many they are.

Instead we should do calculations.

## The first findings
The upper bound is firstly declared.

Using a computer search, the length of the superpermutation would match on:
```
S(n) <= Sigma(k=1..n) k!
```

## Upper bounds
The optimized upper bound was found on 20 Oct. 2018.

Greg Egan, SF author and mathematician, created an algorithm to produce superpermutations of length
```
len = n! + (n-1)! + (n-2)! + (n-3)! + n - 3
```
and were the shortest known for n>=7.

On n=7 specifically, on 27 Feb. 2019 Egan produced one on length 5906.

## Lower bounds
The lower bound was "proved" by an anonymous poster on the Science & Math(`"/sci/"`) board of 4chan, while debating about "how long it will take if we watch <The Melancholy of Haruhi Suzumiya> (aka 'Haruhi') with the every possible order at the shortest term?"

They declared in Sep. 2011 that it should be larger than
```
S(n) >= n! + (n-1)! + (n-2)! + n - 3
```

Robin Houston tweeted about it on Oct. 2018, and published version posted on 25 Oct. 2018 to OEIS.

## A new approach
For now, the approaches were using only factorials.

However, a high schooler, "Developer Tomi" (Lee, Junghoon), discussed there might be a linkage with Fibonacci Sequence through his YouTube channel, on 22 Apr. 2025.

He argued the formula is
```
S(n) ~= n!/(n-1) * n + F(2(n-3)) (n>=3)
where F(x) is Fibonacci sequence
```
and using Python the result plays around the minimum.
> With YouTube comments he told the formula in notepad was wrong: he was too sleepy.

### So I decided to code it on C
To check his formula, I (@HotoRas) decided to code the above 3.
Two of them are widely known and the result should be in between, so I chose.

With some mathematical optimizations, I decided to use
```
S(n) <= (n-3)! ( ( (n+1)(n-1) + 1 ) (n-2) + 1) + n - 3
S(n) >= (n-2)! ( (n+1)(n-1) + 1 ) + n - 3
S(n) ~= n^2 (n-2)! + F(2(n-3))
where
	n >= 3,
	F(n) for n >= 3 is Fibonacci sequence
```
in code. These optimizations were done because compilers mostly do algorithmic optimizations to STLs but not custom implied ones.

### And implement the "big int"
Firstly, I coded the thing into C (src: [main.c](./src/main.c)) to check the concept out.
The result was neat, but the result would peak on 15 since it's heavily using factos and fibos.

So I implemented it into C++, using STLlike "big int" implementations (see [bigint.h](./src/bigint.h)).

It now handles up to 22 (tested on my PC) but the time increments as n\^1.2x formula and stubbed on 24.
(Might have bug, so some more fixes might require)

## Afterwords
I should check where the overhead is: or maybe switch onto Python to get more static results.

## Credits
- YouTuber and developer [CodingApple](https://codingapple.com) to talk about superpermutations in his YouTube channel
- An anonymous 4chan poster who told the minimum formula
- Greg Egan who provided an algorithm to try superpermutation arrays, which is now the upper bounds
- YouTuber and high-schooler [Developer Tomi](https://github.com/ImLuni5), who discusses about the rules behind superpermutations
- You watching this long journey
