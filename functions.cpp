#include <vector>
#include <iostream>
#include <emscripten.h>
#include <emscripten/bind.h>

using namespace std;

extern "C"{
    int main();
    void collecting(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, vector<vector<int>>& A, vector<vector<int>>& B);
    void multiplying(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, const vector<vector<int>>& A, const vector<vector<int>>& B);
    void displaying(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, const vector<vector<int>>& A, const vector<vector<int>>& B);
}

int main()
{
    int rowsizeA;
    int colsizeA;
    int rowsizeB;
    int colsizeB;
    vector<vector<int>> A;
    vector<vector<int>> B;

    cout << "\n";
    cout << "give row size of Matrix A" << endl;
    cin >> rowsizeA;
    cout << "\n";
    cout << "give col size of Matrix A" << endl;
    cin >> colsizeA;
    cout << "\n";

    cout << "give row size of Matrix B" << endl;
    cin >> rowsizeB;
    cout << "\n";
    cout << "give col size of Matrix B" << endl;
    cin >> colsizeB;
    cout << "\n";

    collecting(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);
    displaying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);
    multiplying(rowsizeA, colsizeA, rowsizeB, colsizeB, A, B);

    return 0;
}

void collecting(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, vector<vector<int>>& A, vector<vector<int>>& B)
{
    int num1;
    int num2;

    for (int i = 0; i < rowsizeA; i++)
    {
        cout << "For A give the values for row " << i + 1 << "." << endl;
        vector<int> v1;
        for (int j = 0; j < colsizeA; j++)
        {
            cin >> num1;
            v1.push_back(num1);
        }
        A.push_back(v1);
    }

    cout << endl;

    for (int i = 0; i < rowsizeB; i++)
    {
        cout << "For B give the values for row " << i + 1 << "." << endl;
        vector<int> v2;
        for (int j = 0; j < colsizeB; j++)
        {
            cin >> num2;
            v2.push_back(num2);
        }
        B.push_back(v2);
    }

    cout << endl;
}

void displaying(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, const vector<vector<int>>& A, const vector<vector<int>>& B)
{
    cout << endl;
    cout << "Your vector A" << endl;
    cout << endl;

    for (int i = 0; i < rowsizeA; i++)
    {
        for (int j = 0; j < colsizeA; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Your vector B" << endl;
    cout << endl;

    for (int i = 0; i < rowsizeB; i++)
    {
        for (int j = 0; j < colsizeB; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void multiplying(int rowsizeA, int colsizeA, int rowsizeB, int colsizeB, const vector<vector<int>>& A, const vector<vector<int>>& B)
{
    vector<vector<int>> C;
    for (int i = 0; i < rowsizeA; i++)
    {
        vector<int> x;
        for (int j = 0; j < colsizeA; j++)
        {
            x.push_back(0);
        }
        C.push_back(x);
    }

    for (int n = 0; n < rowsizeB; n++)
    {
        int y = 0;
        for (int m = 0; m < colsizeB; m++)
        {
            int x = 0;
            for (int i = 0; i < rowsizeB; i++)
            {
                x = x + A[n][i] * B[i][y];
            }
            C[n][m] = x;
            y++;
        }
    }

    cout << "multiplied vector C: " << endl;

    for (int i = 0; i < rowsizeA; i++)
    {
        for (int j = 0; j < colsizeA; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}





