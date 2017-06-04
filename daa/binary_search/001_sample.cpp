#include <iostream>
#include <cmath>
#include <vector>


//! \brief A more generic binary search using C++ templates and iterators
//! \param begin Iterator pointing to the first element
//! \param end Iterator pointing to one past the last element
//! \param key The value to be searched for
//! \return An iterator pointing to the location of the value in the given
//! vector, or one past the end if the value was not found.
template<typename Iterator, typename T>
Iterator binary_search(Iterator& begin, Iterator& end, const T& key)
{
    // Keep halving the search space until we reach the end of the vector
    const Iterator NotFound = end;

    while(begin < end)
    {
        // Find the median value between the iterators
        const Iterator Middle = begin + (std::distance(begin, end) / 2);

        // Re-adjust the iterators based on the median value
        if(*Middle == key)
        {
            return Middle;
        }
        else if(*Middle > key)
        {
            end = Middle;
        }
        else
        {
            begin = Middle + 1;
        }
    }

    return NotFound;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int main(){
    int arr[]={5,3,5};
    mergeSort(arr,0,2);
    for(int i=0;i<3;i++){
        std::cout << arr[i] << std::endl;
    }
}
