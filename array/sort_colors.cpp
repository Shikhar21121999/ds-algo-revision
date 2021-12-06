#include <bits/stdc++.h>
using namespace std;

// Problem: Sort Colors. Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively. You must solve this problem without using the library's sort function.
// input: n size of array followed by n numbers elements of the array

int main() {
	int n;
	cin>>n;
	vector <int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	// using inbuilt sort
	sort(a.begin(), a.end());
	
	for(auto x: a) {
		cout<<x<<" ";
	}
	return 0;
}