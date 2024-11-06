import random

# Deterministic partition function using the last element as pivot
def deterministic_partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap elements

    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Swap pivot to its correct position
    return i + 1

# Randomized partition function that chooses a random pivot
def randomized_partition(arr, low, high):
    random_index = random.randint(low, high)
    arr[random_index], arr[high] = arr[high], arr[random_index]  # Swap random pivot with the last element
    return deterministic_partition(arr, low, high)

# Deterministic Quick Sort
def deterministic_quick_sort(arr, low, high):
    if low < high:
        pi = deterministic_partition(arr, low, high)
        deterministic_quick_sort(arr, low, pi - 1)
        deterministic_quick_sort(arr, pi + 1, high)

# Randomized Quick Sort
def randomized_quick_sort(arr, low, high):
    if low < high:
        pi = randomized_partition(arr, low, high)
        randomized_quick_sort(arr, low, pi - 1)
        randomized_quick_sort(arr, pi + 1, high)

# Main function to test the sorting algorithms
if __name__ == "__main__":
    n = int(input("Enter the number of elements in the array: "))
    arr = list(map(int, input("Enter the elements of the array:\n").split()))

    # Deterministic Quick Sort
    arr1 = arr[:]
    deterministic_quick_sort(arr1, 0, n - 1)
    print("Deterministic Quick Sort Result:")
    print(" ".join(map(str, arr1)))

    # Randomized Quick Sort
    arr2 = arr[:]
    randomized_quick_sort(arr2, 0, n - 1)
    print("Randomized Quick Sort Result:")
    print(" ".join(map(str, arr2)))
