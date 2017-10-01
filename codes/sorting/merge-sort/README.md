## Learn:
- **Merge sort method:**
  - Find middle point to divide elements into two halves.
  - Recursively call for merge sort for both halves.
  - Merge the two sorted halves.

- **Divide linked list:**
  - Throw 2 pointers, one slower and one faster till faster one reaches the end point.
  - Slower pointer marks the end of 1st slice and beginning of 2nd slice of linked list.

- **Implementation method:**
    - [x] Recursive with array.
    - [x] Recursive with linked list.

- **Time Complexity:** **O(nlogn)**.

- **Visualization link:** https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

- **Points to be noted (source: wikipedia +** http://www.geeksforgeeks.org/merge-sort/**):**
  - Merge sort implemented with **linked list** does not require extra space as sorting is done on given input data area. But implemented with **array** requires extra spaces.
  - Merge Sort is useful for sorting **linked lists** in **O(nLogn)** time. In case of **linked lists** the case is different mainly due to difference in memory allocation of **arrays** and **linked lists**.
    - Unlike arrays, linked list nodes may not be adjacent in memory.
    - Unlike arrays, we can not do random access in linked list.
    - But, unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time. Therefore merge operation of merge sort can be implemented without extra space for linked lists.
    - Merge sort accesses data sequentially and the need of random access is low.
  - As of ***Perl 5.8***, **merge sort** is its default sorting algorithm (it was **quicksort** in previous versions of ***Perl***). In ***Java***, the ***Arrays.sort()*** methods use **merge sort** or a **tuned quicksort** depending on the datatypes and for implementation efficiency switch to **insertion sort** when fewer than seven array elements are being sorted. The ***Linux kernel*** uses **merge sort** for its linked lists. ***Python*** uses **Timsort**, another **tuned hybrid of merge sort and insertion sort**, that has become the standard sort algorithm in ***Java SE 7***, on the ***Android platform***, and in ***GNU Octave***.

![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/merge-sort/merge_sort.gif "Merge Sort Animation")

![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/merge-sort/merge_sort.png "Merge Sort")



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
#1 1 3 4 5 9    // #Test case number, Sorted data using merge sort

#2 0 1 2 3 4

#3 5 6 7 8 9

#4 0 1 2 3 4 5 6 7 8 9

#5 0 1 2 3 4 5 6 7 8 9
