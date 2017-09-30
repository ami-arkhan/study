## Learn:
- **Insertion sort method:**
  - Read an element and compare with all previous elements to insert into correct position.
  - All intermediate elements need to be shifted to make space for the inserting element.

- **Implementation method:**
  - [x] Iteration with array.
  - [ ] Iteration with array and binary search.
  - [x] Iteration with doubly linked list.

- **Time Complexity:**
  - Best case: **O(n)**.
  - Worst case: **O(n<sup>2</sup>)**.

- **Visualization link:** https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

- **Points to be noted (source: wikipedia +** http://www.geeksforgeeks.org/insertion-sort/**):**
  -  Insertion sort is used when number of elements is small. It can also be useful when input **array** is almost sorted, only few elements are misplaced in complete big **array**.
  - Insertion sort implementation does not require extra space as sorting is done on given input data area.
  - Each **k+1<sup>th</sup>** element requires comparison with already sorted **k** elements to insert, which is opposite of **Selection Sort**.
  - It is faster while implemented with **array** rather than **linked list**.
    - Unlike arrays, linked list nodes may not be adjacent in memory.
    - Unlike arrays, random access in linked list is not possible. Insertion Sort requires a lot of this kind of access. In linked list to access i’th index, we have to travel each and every node from the head to i’th node as we don’t have continuous block of memory. Therefore, the overhead increases for insertion sort.
    - But overhead can be reduced if new sorted list is created after reading each data. Requires extra spaces for new sorted list.
  - If **doubly linked list** is used, it is easy to compare with previous value (using previous node connecting link) and move the node to correct position. Similar like **array**, but random access to list is still an issue. As a result search like **binary search** can not be performed on list, each element has to be traversed from head or tail.
  - When there are large amount of data to compare, time can be reduced by using **binary search** in **array** to find the correct location in the sorted portion, instead of comparing all previous data.

![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/insertion-sort/insertion_sort.png "Insertion Sort")
![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/insertion-sort/insertion_sort.jpg "Inserion Sort")



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
