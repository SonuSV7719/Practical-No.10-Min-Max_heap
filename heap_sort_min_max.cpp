#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int n);

void heapifyMax(int arr[], int n, int root)
{
    int largest = root;
    int start = root;
    int leftIndex = 2 * root + 1; 
    int rightIndex = 2 * root + 2;

    // check whether left child of root is smaller or not 
    if (leftIndex < n && arr[leftIndex] < arr[largest])
        largest = leftIndex;
 
    // check whether right child of root is smaller or not
    if (rightIndex < n && arr[rightIndex] < arr[largest])
        largest = rightIndex;
    
    //base condition to stop recursion
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapifyMax(arr, n, largest);
    }


}

void heapifyMin(int arr[], int n, int root)
{
    int smallest = root;
    int start = root;
    int leftIndex = 2 * root + 1; 
    int rightIndex = 2 * root + 2;

    // check whether left child of root is smaller or not 
    if (leftIndex < n && arr[leftIndex] > arr[smallest])
        smallest = leftIndex;
 
    // check whether right child of root is smaller or not
    if (rightIndex < n && arr[rightIndex] > arr[smallest])
        smallest = rightIndex;
    
    //base condition to stop recursion
    if (smallest != root) {
        swap(arr[root], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }


}

void heapSortMin(int arr[], int n)
{
    for (int i = n/2-1; i>=0; i--)
    {
        heapifyMin(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }

}

void heapSortMax(int arr[], int n)
{
    for (int i = n/2-1; i>=0; i--)
    {
        heapifyMax(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }

}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    
    cout << "Enter how many elements you want to enter: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i<n; i++)
    {
        cout << "Enter Element: ";
        cin >> arr[i];
    }

    heapSortMax(arr, n);
    cout << "Sorted array is: ";
    display(arr, n);
    cout << endl;
    cout << "Maximum value from heap is: " << arr[0] << endl;
    heapSortMin(arr, n);
    cout << "Sorted array is: ";
    display(arr, n);
    cout << endl;
    cout << "Minimum value from heap is: " << arr[0] << endl;
    return 0;
}