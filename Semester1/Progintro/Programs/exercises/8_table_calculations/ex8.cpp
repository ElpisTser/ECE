#include <iostream> 
#include <climits> 
using namespace std; 
int main() { 
    int rows, cols; 
    cin >> rows >> cols; 
    
    int maxOfRowMin = INT_MIN; 
    int minOfColMax = INT_MAX; 
    
    int colMax[cols]; 
    for (int col=0; col<cols; col++) { 
        colMax[col] = INT_MIN; 
    } 
    
    for (int row=0; row<rows; row++) { 
        int rowMin = INT_MAX; 
        for (int col=0; col<cols; col++) { 
            int num; 
            cin >> num; 
            
            if (num > colMax[col]) { 
                colMax[col] = num; 
            } 
            
            if (num < rowMin) { 
                rowMin = num; 
            } 
        } 
        
        if (rowMin > maxOfRowMin) { 
            maxOfRowMin = rowMin; 
        } 
    }

    for (int col=0; col<cols; col++) { 
        if (colMax[col] < minOfColMax) {
             minOfColMax = colMax[col]; 
        } 
    } 
    
    cout << minOfColMax << endl << maxOfRowMin; 
}