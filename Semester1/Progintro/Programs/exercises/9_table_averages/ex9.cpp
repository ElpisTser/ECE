#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    double rowAverageSum = 0;
    
    double colSum[cols];
    for (int col=0; col<cols; col++) {
        colSum[col] = 0;
    }
    
    for (int row=0; row<rows; row++) {
        double rowSum = 0;
        
        for (int col=0; col<cols; col++) {
            double num;
            cin >> num;

            rowSum += num;
            colSum[col] += num;
        }
        
        rowAverageSum += rowSum / cols;
    }
    
    double colAverageSum = 0;
    for (int col=0; col<cols; col++) {
        colAverageSum +=  colSum[col] / rows;
    }

    double averageOfRowAverages = rowAverageSum / rows;
    double avergaeOfColAverages = colAverageSum / cols;

    printf("%.3f\n", averageOfRowAverages);
    printf("%.3f", avergaeOfColAverages);
}