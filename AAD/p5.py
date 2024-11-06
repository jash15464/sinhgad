def solve(board, x, row, col, rightDiag, leftDiag):
    N = len(board)
    if x == N:  # All queens are placed
        return True

    if not row[x]:  # If the row doesn't already contain a queen
        for i in range(N):
            if not col[i] and not rightDiag[x + i] and not leftDiag[i - x + (N - 1)]:
                # Place queen at (x, i)
                col[i] = True
                rightDiag[x + i] = True
                leftDiag[i - x + (N - 1)] = True
                board[x][i] = 1

                # Recur to place queens in the next row
                if solve(board, x + 1, row, col, rightDiag, leftDiag):
                    return True

                # Backtrack: remove the queen from (x, i)
                col[i] = False
                rightDiag[x + i] = False
                leftDiag[i - x + (N - 1)] = False
                board[x][i] = 0
        return False  # No valid position found in this row
    else:
        # Skip this row if a queen is already placed
        return solve(board, x + 1, row, col, rightDiag, leftDiag)


if __name__ == "__main__":
    N = 8
    board = [[0] * N for _ in range(N)]
    rightDiag = [False] * (2 * N - 1)
    leftDiag = [False] * (2 * N - 1)
    col = [False] * N
    row = [False] * N

    x, y = map(int, input("Enter the location of the first Queen (x y): ").split())

    # Validate input
    if x < 0 or x >= N or y < 0 or y >= N:
        print(f"Invalid coordinates. Please enter values between 0 and {N - 1}.")
        exit()

    # Place the first queen on the board
    board[x][y] = 1
    row[x] = True
    col[y] = True

    # Update diagonal control
    rightDiag[x + y] = True
    leftDiag[y - x + (N - 1)] = True

    # Solve the N-Queens problem starting from the next row after the initial queen
    if solve(board, 0, row, col, rightDiag, leftDiag):
        print("\nFirst Possible Solution:")
        for i in range(N):
            for j in range(N):
                print(" Q " if board[i][j] else " . ", end=" ")
            print()
    else:
        print("No solution found.")
