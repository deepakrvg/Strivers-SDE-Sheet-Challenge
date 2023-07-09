#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	// find r^m by xoring all the elements in the array and numbers [1,n]
	int res = 0;
	for (int i = 0; i < n; i++) {
		res ^= arr[i];
	}
	for (int i = 1; i <= n; i++) {
		res ^= i;
	}
	
	// r = repeated_number and m = missing_number
	// find the last bit from the right that is different in r and m
	// i.e. first set bit from the right
	int k = (res & ~(res - 1));

	// cout << k << "\n";

	// divide all the numbers in the array and in range [1,n] in two groups
	// one group having all the numbers that have set bit on the same last position
	// and second group having numbers that differ on that bit position
	// xor each group elements and you will get two numbers one from xoring group 1 and the other from group 2
	int setBit = 0, offBit = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] & k) {
			setBit ^= arr[i];
		}
		else {
			offBit ^= arr[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i & k) {
			setBit ^= i;
		}
		else {
			offBit ^= i;
		}
	}
	// cout << setBit << " " << offBit << "\n";

	// finally to find out which is the missing and repeated in obtained two numbers
	// just check which number exists in the array and that is repeated number and the other is missing number
	int m, r;
	for (int i = 0; i < n; i++) {
		if (setBit == arr[i]) {
			r = setBit;
			m = offBit;
			break;
		}
		if (offBit == arr[i]) {
			r = offBit;
			m = setBit;
			break;
		}
	}
	return {m, r};
}
