/*
Problem: Count Primes

LeetCode: https://leetcode.com/problems/count-primes/

Goal:
Count the number of prime numbers less than n.

Approach:
Sieve of Eratosthenes (Optimized)

- Create a boolean array to mark prime numbers
- Initially assume all numbers are prime
- Start from 2, and mark its multiples as non-prime
- Optimization:
    → Start marking from i*i (not 2*i)
    → Because smaller multiples are already handled

Key Insight:
If a number i is prime, then all multiples of i are not prime.

Time Complexity: O(n log log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2) return 0;

        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        // Only need to go till sqrt(n)
        for(int i = 2; i * i < n; i++){
            if(prime[i]){
                // Start from i*i (important optimization)
                for(int j = i * i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }

        int count = 0;

        for(int i = 2; i < n; i++){
            if(prime[i]) count++;
        }

        return count;
    }
};

int main(){
    Solution obj;

    int n = 10;

    cout << "Number of Primes less than " << n << ": "
         << obj.countPrimes(n) << endl;

    return 0;
}