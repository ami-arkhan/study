## Learn:
- **Selection sort method:**
  - Start from initial index and exchange with lowest element.
  - Element is sorted, increase index and repeat for remaining elements.

- **Implementation method:**
    - [x] Iteration with array.
    - [x] Iteration with linked list.

- **Time Complexity:** **O(n<sup>2</sup>)**.

- **Visualization link:** https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

- **Points to be noted (source: wikipedia):**
  - Selection sort implementation does not require extra space as sorting is done on given input data area.
  - Each **k+1<sup>th</sup>** element requires comparison with all remaining **n-k** elements to find minimum element to replace with, which is opposite of **Insertion Sort**.
  - Using **linked list** makes add and remove efficient. In this case minimum element is removed from the remainder of the list, and then insert it at the end of the values sorted so far. So no need to traverse list from head or tail to find proper location to insert, as insertion is done sequentially from start position.
  - As elements are entered from start position, **doubly linked list** is not required to improve performance, which is opposite of **Insertion Sort**.

![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/selection-sort/selection_sort.gif "Selection Sort")
![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/selection-sort/selection_sort_2.gif "Selection Sort 2")
![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/selection-sort/selection_sort_3.gif "Selection Sort 3")



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
