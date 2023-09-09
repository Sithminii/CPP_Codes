//heap sort using max heap

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int Max = root;
   int Left = 2*root + 1;
   int Right = 2*root + 2;
   
   if ((n > Right) && (arr[Right] > arr[Max]))
       Max = Right;
   
   if ((n > Left) && (arr[Left] > arr[Max]))
       Max = Left;

   if (Max != root)
   {
       swap(arr[root], arr[Max]);
       heapify(arr, n, Max);
   }
}

  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
       heapify(arr, n, i);

   // extracting elements from heap one by one
   for (int j = n - 1; j >= 0; j--)
   {
       swap(arr[0], arr[j]);
       heapify(arr, j, 0);
   }
   
}

  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    int size = rand() % 25 + 1;
    int heap_arr[size];
    srand(time(0)); // seed the random number generator
    for (int i = 0; i < size; i++) {
        heap_arr[i] = rand() % 20 + 1; 
    }
    
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}
