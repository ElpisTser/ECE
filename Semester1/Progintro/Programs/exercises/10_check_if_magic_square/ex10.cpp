#include <iostream>
#include <cstdio>
using namespace std;


int main() {
    int squareSize;
    cin >> squareSize;

    if (squareSize> 150) {
        cout << "too big" << endl;
        return 0;
    }

    int availableNumbers = squareSize * squareSize;
    int numberUsed[availableNumbers]; // 0 value indicates that this number has already been used
    for (int i=0; i<availableNumbers; i++) {
        numberUsed[i] = 1;
    }

    int columnSum[squareSize + 1], rowSum[squareSize + 1];
    for (int i=1; i<=squareSize; i++) {
        columnSum[i] = rowSum[i] = 0;
    }

    int diagonal1 = 0;
    int diagonal2 = 0;

    int currentNum;

    for (int rowNum=1; rowNum<=squareSize; rowNum++) {
        for (int columnNum=1; columnNum<=squareSize; columnNum++) {
            cin >> currentNum;
            
            if ((currentNum >= availableNumbers) || (numberUsed[currentNum] == 0)) {
                cout << "no" << endl;
                return 0;
            }
            numberUsed[currentNum] = 0;

            rowSum[rowNum] += currentNum;
            columnSum[columnNum] += currentNum;

            if (rowNum == columnNum) diagonal1 += currentNum;
            if (rowNum + columnNum == squareSize + 1) diagonal2 += currentNum;
        }
    }
    
    int magicSum = rowSum[1];

    //Check rows and columns
    for (int i=1; i<=squareSize; i++) {
        if ((columnSum[i] != magicSum) || (rowSum[i] != magicSum)) {
            cout << "no" << endl;
            return 0;
        }
    }

    //Check diagonals
    if ((diagonal1 != magicSum) || (diagonal2 != magicSum)) {
        cout << "no" << endl;
        return 0 ;
    }
    
    cout << "Yes" << endl;
}