## Learn:
- Quick sort method:
  - Set a pivot element and partition elements (smaller or bigger) based on pivot elements.
    - Select first element as pivot. (Hoare partition scheme)
    - Select last element as pivot (Hoare partition scheme, OR Lomuto partition scheme).
    - Select random element as pivot.
    - Select median as pivot.
  - Do the sorting for each partition.
  - Partition Schemes:
    - [x] Lomuto partition scheme.
    - [x] Hoare partition scheme.

- Time Complexity: Best case: O(nlogn); Worst case: O(n<sup>2</sup>).

- Visualization link: https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

- Points to be noted (source: http://www.geeksforgeeks.org/quick-sort/):
  - Quick sort implemented with arrays does not require extra space as sorting is done on given input data area.
  - It is faster while implemented with Arrays rather than Linked List.
    - Unlike arrays, linked list nodes may not be adjacent in memory.
    - Unlike arrays, random access in linked list is not possible. Quick Sort requires a lot of this kind of access. In linked list to access i’th index, we have to travel each and every node from the head to i’th node as we don’t have continuous block of memory. Therefore, the overhead increases for quick sort.

- Lomuto Partition Scheme:

![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/quick-sort/quick_sort.png "Quick Sort")

- Hoare Partition Scheme:

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
