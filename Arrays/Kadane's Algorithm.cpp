#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long best = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum = max((long long)arr[i], sum + arr[i]);
        best = max(best, sum);
    }
    return best;
}
