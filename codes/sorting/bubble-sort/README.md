## Learn:
- **Bubble sort method:**
  - Sequentially move large elements to last position.
  - Once last position is reached, element is sorted.
  - Repeat from the beginning for next element.

- **Implementation method:**
  - [x] Iteration with array.
  - [ ] Iteration with doubly linked list.

- **Time Complexity:**
    - Best case: **O(n)**
    - Worst case: **O(n<sup>2</sup>)**.

- **Visualization link:** https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

- **Points to be noted (source: wikipedia):**
  - Very tiny code to understand.
  - Bubble sort implementation does not require extra space as sorting is done on given input data area.
  - Bubble sort should be avoided in the case of large collections. It will not be efficient in the case of a reverse-ordered collection, as there are many comparisons and writing done in the process.

![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/bubble-sort/bubble_sort.gif "Bubble Sort")
![picture alt](https://github.com/ami-arkhan/study-materials/blob/master/codes/sorting/bubble-sort/bubble_sort_2.gif "Bubble Sort 2")



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
#1 1 3 4 5 9    // #Test case number, Sorted data using bubble sort

#2 0 1 2 3 4

#3 5 6 7 8 9

#4 0 1 2 3 4 5 6 7 8 9

#5 0 1 2 3 4 5 6 7 8 9
