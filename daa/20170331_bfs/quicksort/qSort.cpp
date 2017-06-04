#include <iostream>
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,    low  --> Starting index,   high  --> Ending index
*/
/* This function takes last element as pivot, places  the pivot element 
   at its correct position in sorted  array, and places all smaller (smaller
   than pivot) to left of pivot and all greater elements to right  of pivot */
/*template<typename T>
void swap(T & i, T & j){
    T tmp=i;
    i=j;
    j=tmp;
}
*/
void swap(int* a, int* b)
{
	    int t = *a;
	    *a = *b;
	    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = ( low-1 );
	for (int j =low; j < high; j++)
    {
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }   
    }
    swap( &arr[i+1], &arr[high] );
    return (i+1);
}



void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(){
	int n=5;
	int arr[5]={ 4, 2, 1,5, 6 };
	quickSort(arr, 0, n-1);
	for(int i =0;i<5;i++){
		std::cout << arr[i] << std::endl;
	}
	return 0;

}
