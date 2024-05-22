//
// Created by ayush on 5/7/2024.
//
#include "sorts.h"

void sorts::BubbleSort(std::vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - 1-i; j++) {
            if (vec.at(j) > vec.at(j + 1)) {

                int tmp = vec.at(j);
                vec[j] = vec.at(j + 1);
                vec[j + 1] = tmp;

            }
        }
    }

}


void sorts::InsertionSort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i - 1;

        // Move elements of vec[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}


void sorts::MergeHelper(std::vector<int>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = vec[mid + 1 + j];

    // Merge the temp arrays back into vec[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            ++i;
        } else {
            vec[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        vec[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        vec[k] = R[j];
        ++j;
        ++k;
    }
}

void sorts::MergeSort(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        MergeSort(vec, left, mid);
        MergeSort(vec, mid + 1, right);

        // Merge the sorted halves
        MergeHelper(vec, left, mid, right);
    }
}




void sorts::IterativeMergeSortHelper(std::vector<int>& vec, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<int> temp(n1 + n2); // Temporary vector to hold merged data

    int i = start, j = mid + 1, k = 0;

    // Merge elements from the two halves into temp
    while (i <= mid && j <= end) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    // Copy remaining elements from the first half
    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    // Copy remaining elements from the second half
    while (j <= end) {
        temp[k++] = vec[j++];
    }

    // Copy merged elements back to original vector
    for (int idx = start; idx <= end; ++idx) {
        vec[idx] = temp[idx - start];
    }
}

void sorts::IterativeMergeSort(std::vector<int>& vec) {
    int n = vec.size();
    std::vector<int> temp(n); // Temporary vector to hold merged data

    // Start with merging subarrays of size 1, then double the size in each iteration
    for (int size = 1; size < n; size *= 2) {
        for (int start = 0; start < n - 1; start += 2 * size) {
            int mid = std::min(start + size - 1, n - 1);
            int end = std::min(start + 2 * size - 1, n - 1);
            IterativeMergeSortHelper(vec, start, mid, end);
        }
    }
}


int sorts::Partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the pivot element (last element in this case)
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the position of the pivot
}

void sorts::QuickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = Partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

int sorts::GetNextGap(int gap) {
    // Using the sequence proposed by Marcin Ciura
    static const int ciuraGaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    static int currentGapIndex = 0;

    if (gap == -1) {
        currentGapIndex = 0; // Reset the gap sequence
        return ciuraGaps[currentGapIndex++];
    }

    if (currentGapIndex < sizeof(ciuraGaps) / sizeof(ciuraGaps[0])) {
        return ciuraGaps[currentGapIndex++];
    }

    return gap / 2; // Reduce the gap by half
}

void sorts::ShellSort(std::vector<int>& arr) {
    int n = arr.size();
    int gap = GetNextGap(-1); // Initialize the gap size

    // Start with a large gap and reduce it until the gap is 1
    while (gap > 0) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // Keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i++) {
            // Add arr[i] to the elements that have been gap sorted
            // Save arr[i] in temp and make a hole at position i
            int temp = arr[i];
            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
        // Get the next gap
        gap = GetNextGap(gap);
    }
}