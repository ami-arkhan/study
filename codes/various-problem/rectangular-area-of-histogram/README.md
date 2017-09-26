## Learn:
- Divide and Conquer: Problem is divided into 2 parts and each part is solved.

- Problem solving methods:
  - [x] Recursion: Each part is recursively called to solve. Recursive call is reduced by applying divide and conquer. Problem solve time is faster.
  - [ ] Iterative: Each height is compared with other and max area is checked. Time complexity is extremely high. If total number of heights increased, iterative loop also increases. Sample code is provided to understand the scenario.



## Problem:
Find largest rectangular area of the histogram.

![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/various-problem/rectangular-area-of-histogram/reactangular_area_of_histogram.png "Area of Histogram")

Total heights in a histogram are between 10~10000.



### Input:

20    // Total test cases

10    // Number of bars

3 4 5 1 8 10 6 4 9 10   // Height of bars

10

10 4 3 3 4 9 10 6 5 10

10

3 5 7 10 7 10 5 6 5 9



### Output:
#1 24   // #Test case number, Largest rectangular area of histogram

#2 30

#3 45
