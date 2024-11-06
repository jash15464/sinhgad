#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    float weight;
    int value;
};

class Node {
public:
    int level, profit, bound;
    float weight;
};

// Comparison function to sort Items according to value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Returns the bound of profit in the subtree rooted with node u.
// This function mainly uses a greedy solution to find an upper bound on the maximum profit.
int bound(Node u, int n, int W, Item arr[]) {
    // If weight exceeds the knapsack capacity, return 0 as expected bound
    if (u.weight >= W)
        return 0;

    // Initialize profit_bound with the current profit
    int profit_bound = u.profit;

    // Start including items from the next index
    int j = u.level + 1;
    float totweight = u.weight;

    // Checking index condition and knapsack capacity condition
    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    // If j is not n, include the last item partially for upper bound on profit
    if (j < n)
        profit_bound += (W - totweight) * arr[j].value / arr[j].weight;

    return profit_bound;
}

// Returns the maximum profit we can get with capacity W
int knapsack(int W, Item arr[], int n) {
    // Sort items based on value per unit weight
    sort(arr, arr + n, cmp);

    // Create a queue for traversing the decision tree
    queue<Node> Q;
    Node u, v;

    // Initialize a dummy node at the start
    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    // Store the maximum profit so far
    int maxProfit = 0;

    // Traverse nodes in a breadth-first manner
    while (!Q.empty()) {
        // Dequeue a node
        u = Q.front();
        Q.pop();

        // If this is the starting node, assign level 0
        if (u.level == -1)
            v.level = 0;

        // If there's nothing on the next level, continue
        if (u.level == n - 1)
            continue;

        // Increment level for the next node
        v.level = u.level + 1;

        // Take the current level's item
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        // Update maxProfit if applicable
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        // Get the upper bound on profit to decide whether to add v to Q
        v.bound = bound(v, n, W, arr);

        // If the bound value is greater than maxProfit, push v into the queue
        if (v.bound > maxProfit)
            Q.push(v);

        // Consider the next possibility: without including the current item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

// Driver program to test the above function
int main() {
    int W = 10; // Weight of knapsack
    Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum possible profit = " << knapsack(W, arr, n) << endl;
    return 0;
}
