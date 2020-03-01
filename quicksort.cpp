#include <iostream>
#include <string>
using namespace std;

//swap two elements (utilizes pointers)
void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

//takes last element as pivot, then reorders elements around it to correct location
//will return the index of pivot at the end (when it's in the correct position)
int partition (int arr[], int low, int high){
  int pivot = arr[high]; //this is the pivot element
  int i = (low - 1); //index of the next space for a smaller element to be swapped in to

  for(int j=low; j< high; j++){
    //the element in question is smaller than the pivot
    if(arr[j] < pivot){
        i++;
        swap(&arr[i], &arr[j]); //dereference pointers and pass to swap
    }
  }

  //at the end just increment and swap the pivot into its final position
  swap(&arr[i+1], &arr[high]);
  return (i+1);
}

void quickSort(int arr[], int low, int high){
  if(low < high){
    int pi = partition(arr, low, high); //find pivot and sort, then return the pivot's final position

    //sort left
    quickSort(arr, low, pi - 1);
    //sort right
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size){
  int i;
  for(i = 0; i<size; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n - 1);
  cout << "Sorted array: \n";
  printArray(arr, n);
  return 0;

}
