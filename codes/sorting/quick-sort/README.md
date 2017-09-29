## Learn:
- Quick sort method:
  - Set a pivot element and partition elements (smaller or bigger) based on pivot elements.
    - Select first element as pivot.
    - Select last element as pivot (Implemented here).
    - Select random element as pivot.
    - Select median as pivot.
  - Pivot element position will be between two partition.
  - Do the sorting for each partition.

- Time Complexity: Best case: O(nlogn); Worst case: O(n<sup>2</sup>).

- Visualization link: https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

- Points to be noted (source: http://www.geeksforgeeks.org/quick-sort/):
  - Counting sort is efficient with arrays.if the range of input data is not significantly greater than the number of objects to be sorted. Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K.
  - It is not a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data.
  - It is often used as a sub-routine to another sorting algorithm like radix sort.
  - Counting sort uses a partial hashing to count the occurrence of the data object in O(1).
  - Counting sort can be extended to work for negative inputs also.

![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/quick-sort/quick_sort.png "Quick Sort")
![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/quick-sort/quick_sort_animation.gif "Quick Sort Animation")



### Input:
5   // Total test cases

5   // Number of data

4 9 5 1 3   // Data

5

0 4 3 2 1

5

9 7 5 6 8

10

0 2 4 6 8 1 3 5 7 9

10

9 8 7 6 5 4 3 2 1 0



### Output:
#1 1 3 4 5 9    // #Test case number, Sorted data using quick sort

#2 0 1 2 3 4

#3 5 6 7 8 9

#4 0 1 2 3 4 5 6 7 8 9

#5 0 1 2 3 4 5 6 7 8 9
