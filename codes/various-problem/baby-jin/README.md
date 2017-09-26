## Learn
- Exhaustive searching method. Generate all permutations: n! sets of case generated for n elements.

- Non-Exhaustive searching method. Much faster for this problem.

- Pruning: When answer is found no need to generate case for further checking. 



## Problem:
Find baby-jin or not from 6 draw of cards. If 3 numbers are same it is called a 'Triplet', if 3 numbers are sequencial it is called a 'Run'. Each card can not be used twice to calculate 'Triplet' or 'Run'.

In order to be Baby-jin, any one of the condition must be met:

a) 1 Triplet + 1 Run

b) 2 Triplet

c) 2 Run



### Input:

20 // Total test cases

6 6 7 7 6 7   // Input card numbers

0 5 4 0 6 0

1 0 1 1 2 3



### Output:
#1 OK   // #Test case number, 'FAIL' or 'OK'

#2 OK

#3 FAIL
