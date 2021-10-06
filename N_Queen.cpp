//Most optimised code for famous N-queen Problem

//The N Queen is the problem of placing N chess queens on 
//an N×N chessboard so that no two queens attack each other

#include <bits/stdc++.h>
using namespace std;

//global variable for size of board (n>=4)
int n;

//isSafe function to check is placing queen at particular place is safe or not
bool isSafe(int row, int col, vector<vector<int>> &vec, vector<int> &rowHash,
            vector<int> &upDiagonalHash, vector<int> &downDiagonalHash)
{
    if (vec[row][col] == 1 || rowHash[row] == 1 || upDiagonalHash[n - 1 + row - col] == 1|| downDiagonalHash[row +col])
        return false;
    else
        return true;
}

//function
bool nQueen( int col, vector<vector<int>> &vec, vector<int> &rowHash,
             vector<int> &upDiagonalHash, vector<int> &downDiagonalHash)
{
    if (col == n)
    {
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j <= n - 1; j++)
                cout << vec[i][j] << " ";
            cout << endl;
        }
        return true;
    }

    for (int row = 0; row <= n - 1; row++)
    {
        if (isSafe(row, col, vec, rowHash, upDiagonalHash, downDiagonalHash))
        {
            vec[row][col] = 1;   //marked visited
            rowHash[row] = 1;
            downDiagonalHash[row + col] = 1;
            upDiagonalHash[n - 1 + row - col] = 1;
            if (nQueen( col + 1, vec, rowHash, upDiagonalHash, downDiagonalHash) == true)
            {
                return true;
            }
            vec[row][col] = 0;     //ummarked visited
            rowHash[row] = 0;
            downDiagonalHash[row + col] = 0;
            upDiagonalHash[n - 1 + row - col] = 0;
        }
    }
    return false;
}

int32_t main()
{
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    vector<int> rowHash(n,0);      //for checking rows previous column
    vector<int> upDiagonalHash(2*n-1,0);    //for checking top diagonal
    vector<int> downDiagonalHash(2*n-1,0);     //for checking bottom diagonal
    nQueen( 0, vec, rowHash, upDiagonalHash, downDiagonalHash);
    return 0;
}
