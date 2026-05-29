#include <iostream>

bool check(int a[], int b[], int n, int m, int x) {
        if (x == 0) {
            if (a[0] == 0 || b[0] == 0) return true;
            else return false;
        }
    
    for (int i = 0; i < n; i++) {
        if (a[i] > x) return false;

        if (a[i] == 0) continue;

        if (x % a[i] != 0) continue;

        int target = x / a[i];

        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (b[mid] == target) return true;
            else if (b[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
    }
    return false;
}