# Sorting-Algorithms-C-
 A program of sorting algorithms that tests the performance for operations on vectors of integers of growing sizes, for example: 10, 100, 1000, 5000, 10000, 25000, etc.
 1) BubbleSort
 2) InsertionSort
 3) MergeSort
 4) Non-Recursive MergeSort (IterativeMergeSort)
 5) QuickSort
 6) ShellSort


#Execution
Your program, called sorter, will read two required arguments and one optional argument from the command
line
1) sort type as a string of characters, for instance, BubbleSort
2) a vector size as an integer, for instance, 100 for a vector of size 100
3) Optional third argument string, Print, which will print out the vector before and after sorting
Your program will create and sort a vector<int> of the size with the specified sort: MergeSort, BubbleSort,
InsertionSort, QuickSort, ShellSort or IterativeMergeSort. The input argument will be these sorting names
exactly as shown in the previous sentence.
Example Execution
Creates a 100 element vector, sorts it with the specified algorithm, prints the list (unsorted and sorted) and the
execution time.
./sorter BubbleSort 100 Print
Creates a 1000000 element vector, sorts it with BubbleSort, prints the execution time.
./sorter BubbleSort 1000000
Creates a 1000000 element vector, sorts it with MergeSort, prints the execution time.
./sorter MergeSort 1000000

