#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand() with time

using namespace std;

// Deterministic partition function using the last element as pivot
int deterministicPartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized partition function that chooses a random pivot
int randomizedPartition(vector<int> &arr, int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    return deterministicPartition(arr, low, high);
}

// Deterministic Quick Sort
void deterministicQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main()
{
    srand(time(0)); // Seed for random number generation

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Deterministic Quick Sort
    vector<int> arr1 = arr;
    deterministicQuickSort(arr1, 0, n - 1);
    cout << "Deterministic Quick Sort Result:\n";
    for (int x : arr1)
        cout << x << " ";
    cout << endl;

    // Randomized Quick Sort
    vector<int> arr2 = arr;
    randomizedQuickSort(arr2, 0, n - 1);
    cout << "Randomized Quick Sort Result:\n";
    for (int x : arr2)
        cout << x << " ";
    cout << endl;

    return 0;
}
