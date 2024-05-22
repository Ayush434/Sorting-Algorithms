//
// Created by ayush on 5/7/2024.
//

#ifndef PROGRAM5_SORTINGALGORITHMS_SORTS_H
#define PROGRAM5_SORTINGALGORITHMS_SORTS_H

#include <vector>
#include <iostream>

class sorts{

public:

    // Bubble Sort
    void BubbleSort(std::vector<int>& vec);

    //Insertion Sort
    void InsertionSort(std::vector<int>& vec);

    //Merge Sort
    void MergeSort(std::vector<int>& vec, int left, int right);

    // Iterative Merge Sort
    void IterativeMergeSort(std::vector<int>& vec);

    // Quick Sort
    void QuickSort(std::vector<int>& arr, int low, int high);

    // Shell Sort
    void ShellSort(std::vector<int>& arr);

private:
    //Merge Sort Helper
    void MergeHelper(std::vector<int>& vec, int left, int mid, int right);

    // Iterative Merge Sort Helper
    void IterativeMergeSortHelper(std::vector<int>& vec, int start, int mid, int end);

    // Quick Sort Helper
    int Partition(std::vector<int>& arr, int low, int high);

    // Shell Sort Helper
    int GetNextGap(int gap);



};

#endif //PROGRAM5_SORTINGALGORITHMS_SORTS_H
