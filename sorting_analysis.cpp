#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<fstream>

using namespace std;

/**
 * @brief generates random sized array contaning random elements.
 * 
 * @param max_size maximum size of array
 * @param max_element maximum element present in array
 * @return random array 
 */
int* gen_array(unsigned int n, int max_element){
    
    static int* randArr = (int*)malloc(sizeof(int)*n);
    
    for(int i = 0; i < n; i++)
        randArr[i] = (rand()%max_element + 1);
    
    return randArr;
}

/**
 * @brief prints the passed array
 * 
 * @param ar array, int*
 * @param n size of array
 */
void print_arr(int *ar, int n){
    for(int i = 0; i < n; i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}


void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
  
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
 

int main(){
    srand(time(0));

    //#define PRINT_ARRAY   // uncomment this line to see generated arrays

    int test_case = 10;
    int max_element = 1000;
    int max_size = 1000;
    int min_size = 100;
    vector<pair<int, pair<double, double>>> size_n_time;

    while(test_case--){
        int n = rand()%max_size + min_size; 
        int *ar = gen_array(n, max_element), copyAr[n];
        
        for(int i = 0; i < n; i++)
            copyAr[i] = ar[i]; //copy for quicksort
        
        #ifdef PRINT_ARRAY  
        cout<<"Array before sorting : ";
        print_arr(ar, n);
        #endif

        clock_t m_begin = clock();
        mergeSort(ar, 0, n-1);
        clock_t m_end = clock();
        
        clock_t q_begin = clock();
        quickSort(ar, 0, n-1);
        clock_t q_end = clock();

        #ifdef PRINT_ARRAY 
        cout<<"Array after sorting : ";
        print_arr(ar, n);
        cout<<"\n\n";
        #endif

        double merge_time = (double)(1000000)*(m_end - m_begin) / CLOCKS_PER_SEC; //time in microseconds
        double quick_time = (double)(1000000)*(q_end - q_begin) / CLOCKS_PER_SEC; //time in microseconds
        size_n_time.push_back(make_pair
                        (n, make_pair(merge_time, quick_time)));
        
    }

    cout<<"Array Size\t\tMergeSort\t\tQuickSort\n";
    for(auto x : size_n_time){
        cout<<x.first<<setw(27)<<x.second.first<<setw(27)<<x.second.second<<endl;
    }
    
    ofstream fout("time_analysis.txt");
    fout<<"Array Size,MergeSort (µs),QuickSort (µs)\n";
    for(auto x : size_n_time){
        fout<<x.first<<","<<x.second.first<<","<<x.second.second<<endl;
    }

}