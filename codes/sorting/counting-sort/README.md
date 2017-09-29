## Learn:
- Counting sort method:
  - Count all the data first, each index represents the input data.
  - Sum counted data to set sorted index locations.
  - Output data as per index locations.

- Drawbacks:
  - If input data values are large, count array should also be large, as count array index represents the input number.
  - There could be many unused indexes in count array.
    - For input data: 0 & 999
      - Count array size will be: 1000.
      - Array traversal required for unused indexes: 1~998.

- Time Complexity: O(n+k), where n is the number of elements in input array and k is the range of input.

- Points to be noted (source: http://www.geeksforgeeks.org/counting-sort/):
  - Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K.
  - It is not a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data.
  - It is often used as a sub-routine to another sorting algorithm like radix sort.
  - Counting sort uses a partial hashing to count the occurrence of the data object in O(1).
  - Counting sort can be extended to work for negative inputs also.

![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/counting-sort/counting_sort.gif "Counting Sort")



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
#1 1 3 4 5 9    // #Test case number, Sorted data using counting sort

#2 0 1 2 3 4

#3 5 6 7 8 9

#4 0 1 2 3 4 5 6 7 8 9

#5 0 1 2 3 4 5 6 7 8 9
