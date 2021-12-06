// Problem: First Missing Positive. Given an unsorted integer array nums, return the smallest missing positive integer. You must implement an algorithm that runs in O(n) time and uses constant extra space.
// trick / observation: first missing positive integer will lie in the range 1, arr.size()
// reason if all such positive integers are present then array is of the form 1 -> 2 -> 3 -> 4 .... n in this case missing positive integer is n+1

// so question can be boiled down to finding the number which is missing in the range 1 -> n in the array
// brute force solution can be => use hash maps to store numbers found and then traverse and see missing number

// solution  => we can use constant extra space
// therefore we can create an index array of size 5*10^5 initialize with 0
// now for each element if its positive and lesser than 5*10^5 mark as found 1
// we can safely ignore other elements since we have to find the missing
// at the end we traverse the array to see the missing number in the array

// input:
// first line of input denotes the length of the array => n
// second line of input contains n space seprated integers (long long)

#include <bits/stdc++.h>
using namespace std;

int LENGTHLIM = 5*10^5+1;
vector <int> indMap(5, 0);

int main() {
	int n;
	cin>>n;
	vector <long long> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if (a[i] > 0 and a[i] < LENGTHLIM) {
			// mark as encountered
			indMap[a[i]] = 1;
		}
	}

	// traverse the indMap till the size of the array
	for(int i=1;i<=n;i++) {
		if(indMap[i] == 0) {
			cout<<i<<endl;
			return 0;
		}
	}
	// all the elements are present from 1,2,3,4 ......n
	// obser the index adjustment
	// therefore answer is LENGTHLIM
	cout<<n+1<<endl;
	return 0;


}