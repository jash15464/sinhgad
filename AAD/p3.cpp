#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator function to sort items by value-to-weight ratio in descending order
bool compare(pair<double, double> a, pair<double, double> b)
{
    return a.second > b.second;
}

int main()
{
    int n;    // Number of items
    double w; // Available weight in the knapsack

    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the available weight in the bag: ";
    cin >> w;

    // Validate input
    if (n <= 0 || w <= 0)
    {
        cout << "The number of items and weight must be positive." << endl;
        return 1;
    }

    vector<pair<double, double>> items; // Vector to store (weight, value per weight)

    for (int i = 0; i < n; i++)
    {
        double itemValue, itemWeight;
        cout << "Enter the item value: ";
        cin >> itemValue;
        cout << "Enter the item weight: ";
        cin >> itemWeight;

        if (itemWeight <= 0)
        {
            cout << "Item weight must be positive." << endl;
            return 1;
        }

        // Calculate value-to-weight ratio and store with weight
        items.push_back({itemWeight, itemValue / itemWeight});
    }

    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    // Calculate the maximum value that can be carried in the knapsack
    double result = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].first <= w)
        {
            // Take the entire item
            result += items[i].first * items[i].second;
            w -= items[i].first;
        }
        else
        {
            // Take the fraction of the remaining weight
            result += w * items[i].second;
            w = 0;
            break; // Knapsack is full
        }
    }

    cout << "Maximum value in the knapsack: " << result << endl;
    return 0;
}
