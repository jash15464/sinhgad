#include <iostream>
#include <vector>
using namespace std;

int factRecu(int n, vector<int> &result)
{
    if (n <= 1)
        return result[n] = n;
    return result[n] = factRecu(n - 2, result) + factRecu(n - 1, result);
}
int factRecuMemo(int n, vector<int> &memo)
{
    if (n <= 1)
        return memo[n] = n;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = factRecuMemo(n - 2, memo) + factRecuMemo(n - 1, memo);
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << "\n\nRecursion Method O(2^n)" << endl;
    vector<int> result(n + 1);
    factRecu(n, result);
    for (int i = 0; i < n; i++)
        cout << result[i] << "  ";
    cout << endl;

    cout << "\n\nRecursion + Memoration Method O(n^2)" << endl;
    vector<int> memo(n + 1, -1);
    factRecuMemo(n, memo);
    for (int i = 0; i < n; i++)
        cout << memo[i] << "  ";
    cout << endl;

    cout << "\n\nTabulation Method O(n)" << endl;
    int first = 0;
    int second = 1;
    cout << first << "  " << second << "  ";
    for (int i = 0; i < n - 2; i++)
    {
        int third = first + second;
        cout << third << "  ";
        first = second;
        second = third;
    }
    cout << endl;

    return 0;
}