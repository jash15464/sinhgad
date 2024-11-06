#include <iostream>
#include <vector>
using namespace std;

#define N 8

// Recursive function to solve the N-Queens problem
bool solve(vector<vector<int>> &board, int x, vector<bool> &row, vector<bool> &col, vector<bool> &rightDiag, vector<bool> &leftDiag)
{
    if (x == N) // All queens are placed
        return true;

    if (!row[x])
    { // If the row doesn't already contain a queen
        for (int i = 0; i < N; i++)
        {
            if (!col[i] && !rightDiag[x + i] && !leftDiag[i - x + (N - 1)])
            {
                // Place queen at (x, i)
                col[i] = true;
                rightDiag[x + i] = true;
                leftDiag[i - x + (N - 1)] = true;
                board[x][i] = 1;

                // Recur to place queens in the next row
                if (solve(board, x + 1, row, col, rightDiag, leftDiag))
                    return true;

                // Backtrack: remove the queen from (x, i)
                col[i] = false;
                rightDiag[x + i] = false;
                leftDiag[i - x + (N - 1)] = false;
                board[x][i] = 0;
            }
        }
        return false; // No valid position found in this row
    }
    else
    {
        // Skip this row if a queen is already placed
        return solve(board, x + 1, row, col, rightDiag, leftDiag);
    }
}

int main()
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<bool> rightDiag(2 * N - 1, false);
    vector<bool> leftDiag(2 * N - 1, false);
    vector<bool> col(N, false);
    vector<bool> row(N, false);

    int x, y;
    cout << "Enter the location of the first Queen (x y): ";
    cin >> x >> y;

    // Validate input
    if (x < 0 || x >= N || y < 0 || y >= N)
    {
        cout << "Invalid coordinates. Please enter values between 0 and " << N - 1 << "." << endl;
        return 1;
    }

    // Place the first queen on the board
    board[x][y] = 1;
    row[x] = true;
    col[y] = true;

    // Update diagonal control
    rightDiag[x + y] = true;
    leftDiag[y - x + (N - 1)] = true;

    // Solve the N-Queens problem starting from the next row after the initial queen
    if (solve(board, 0, row, col, rightDiag, leftDiag))
    {
        cout << "\nFirst Possible Solution:\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << (board[i][j] ? " Q " : " . ");
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
