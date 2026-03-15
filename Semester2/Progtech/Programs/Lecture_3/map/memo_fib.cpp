#include <iostream>
#include <map>

using namespace std;

int memo_fib(int n) {
    // static map acts as a cache that persists across recursive calls
    // Key = n, Value = Fibonacci number at position n
    static map<int, int> cache;

    // Base cases
    if (n < 2) return n;

    // Check if value is already computed
    map<int, int>::iterator p = cache.find(n);
    if (p != cache.end()) return p->second;

    // Compute value recursively if not in cache
    int v = memo_fib(n -1) + memo_fib(n-2);

    // Store the computed value in the cache for future calls
    cache[n] = v;
    
    return v;
}

int main() {
    int n;
    cin >> n;

    cout << memo_fib(n) << endl;
}

/*
Notes about this method (Memoization with std::map):

- Memoization is a technique to **store previously computed results** of a function
  so that they can be reused instead of recalculated.

- Here, we use a static std::map<int, int> as the cache:
    - The key is the Fibonacci number index (n)
    - The value is the corresponding Fibonacci number

- How it works:
    1. If n < 2, return n directly (base case)
    2. Check if n is already in the cache:
        - If yes, return the cached value (avoids redundant computation)
    3. Otherwise, compute recursively: memo_fib(n-1) + memo_fib(n-2)
    4. Store the result in the cache for future calls
    5. Return the computed value
*/