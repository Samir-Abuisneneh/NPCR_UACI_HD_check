#include <iostream>
#include<vector>
#include <fstream>
using namespace std;
int R = 4, C = 4;
vector<vector<int>> mat1(R, vector<int>(C, 0));
vector<vector<int>> mat2(R, vector<int>(C, 0));

void printMatrix(vector<vector<int>> vec) //prints 2d matrix values
{
    cout << '\n';
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void fillVec() // reads file and fills matrices with data from file
{
    ifstream file;
    file.open("matrix.txt");
    if (!file)
    {
        cout << "File error";
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int temp;
            file >> temp;
            mat1[i][j] = temp;
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int temp;
            file >> temp;
            mat2[i][j] = temp;
        }
    }
}

double HD() // calculate hamming distance which is the sum of 1s after xor
{
    int hammingSum = 0;
    double HD;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            hammingSum += __builtin_popcount(mat1[i][j] ^ mat2[i][j]);
        }
    }
    HD = ((1 / (R * C * 8.0)) * hammingSum) * 100;
    return HD;
}

double NPCR() // calculates NPCR 
{
    int sum = 0;
    double NPCR;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat1[i][j] != mat2[i][j])
                sum++;
        }
    }
    NPCR = ((1.0 / (R * C * 1)) * sum) * 100;
    return NPCR;
}

double UACI() // calculates UACI
{
    int sum = 0;
    double UACI;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            sum += abs(mat1[i][j] - mat2[i][j]);
        }
    }
    UACI = ((1.0 / (R * C * 1 * 8)) * sum) * 100;
    return UACI;
}


int main()
{
    fillVec();
    printMatrix(mat1);
    printMatrix(mat2);
    cout << "\nIf you wish to change the matrix values you can do do in the matrix.txt file\n";
    cout << "HD: " << HD() << "%\n";
    cout << "NPCR: " << NPCR() << "%\n";
    cout << "UACI: " << UACI() << "%\n";
    return 0;
}