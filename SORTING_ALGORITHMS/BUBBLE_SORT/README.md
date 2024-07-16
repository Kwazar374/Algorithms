# Bubble Sort Algorithm
## How does it work?
**Bubble Sort is a simple sorting algorithm** that works by repeatedly stepping through the list (vector), comparing each pair of adjacent items and swapping them if they are in the wrong order. The pass through the list is repeated until no swaps are needed to be sure that the list is sorted.
## Coplexity
- **Bubble Sort has a worst-case and average complexity of O(n^2)**, where n is the number of items to be sorted.
- **It's simple and easy to implement, but it's not efficient for large lists (vectors)**.
## Example
`list to sort: [6, 2, 3, 1, 5, 2]`

We start from the beginning of the list and compare each pair of adjacent items till the end of the list. If the first item is greater than the second one, we swap them.

`[6, 2, 3, 1, 5, 2]` -> `[2, 6, 3, 1, 5, 2]` -> `[2, 3, 6, 1, 5, 2]` -> `[2, 3, 1, 6, 5, 2]` -> `[2, 3, 1, 5, 6, 2]` -> `[2, 3, 1, 5, 2, 6]`

`6` is the biggest number (the lightest bubble) in the list and after first iteration through the elements of the list it's in the right place. Now we start from the beginning again and repeat the process.

> Note: there's no need to make a comparison between last and second last element of the list, because the biggest number is already in the right place.

`[2, 3, 1, 5, 2, 6]` -> `[2, 3, 1, 5, 2, 6]` -> `[2, 1, 3, 5, 2, 6]` -> `[2, 1, 3, 2, 5, 6]`

'5' is the second biggest number in the list and after the second iteration through the elements of the list it's in the right place. Now we start from the beginning again and repeat the process.

> Note: there's no need to make a comparison between the last three elements of the list, because the two biggest numbers are already in the right place.

We repeat the process until the list is sorted.

`[2, 1, 3, 2, 5, 6]` -> `[1, 2, 3, 2, 5, 6]` -> `[1, 2, 2, 3, 5, 6]`

`List is sorted: [1, 2, 2, 3, 5, 6]`

End.

## Implementations
- **bubble_sort.cpp** - *C++ implementation for the vector of random integers*

# XOR Swap Algorithm (additional content)
In the **Bubble Sort algorithm**, there is a need to perform a **swap operation**. This can be done in two ways. The first is to use a temporary variable to store the value of one of the elements during the swap. The second way is to use the **XOR operation**. 

**The XOR operation is a bitwise operation that returns a 1 in each bit position where the corresponding bits of one of the operands, but not both, are 1. This is a very efficient way to swap two values without using a temporary variable.**

## How does it work?
The XOR operation is used to swap two values. The algorithm is as follows:

1. `a = a ^ b`
2. `b = a ^ b`
3. `a = a ^ b`

after these three steps, the values of a and b are swapped.

## Example
Let's assume that we have two variables `a = 5` and `b = 7`.
In binary representation, `a = 101` and `b = 111`.

1. `a = a ^ b` -> `a = 101 ^ 111` -> `a = 010`
2. `b = a ^ b` -> `b = 010 ^ 111` -> `b = 101` -> `b = 5`
3. `a = a ^ b` -> `a = 010 ^ 101` -> `a = 111` -> `a = 7`

End.

## Proof of Concept
**step 1:**

Let's assume that we have two variables `a1` and `b1` and we want to swap them using **XOR operation**

`a2 = a1 ^ b1`

`b2 = a2 ^ b1`

`a3 = a2 ^ b2`

**step 2:**

We assign first `a` to `a` in second and third assignment

`b2 = (a1 ^ b1) ^ b1`

`a3 = (a1 ^ b1) ^ b2`

**step 3:**

> XOR operation is associative

`b2 = a1 ^ (b1 ^ b1)`

`a3 = a1 ^ b1 ^ b2`

**step 4:**

> `b1 ^ b1` is always 0 (def. of XOR)

`b2 = a1 ^ 0`

`a3 = a1 ^ b1 ^ b2`

**step 5:**

> `a1 ^ 0` is always `a1` (neutral element of XOR)

`b2 = a1`

`a3 = a1 ^ b1 ^ b2`

**step 6:**

`a3 = a1 ^ b1 ^ a1`

**step 7:**

`b2 = a1`

`a3 = b1`

Where `b2` is value of `b` after swapping and `a3` is value of `a` after swapping 
and `a1` and `b1` are values of `a` and `b` before swapping

## Implementations
- **xor_swap.cpp** - *C++ implementation for swapping two integers using XOR operation*