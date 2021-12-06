#include <bits/stdc++.h>
using namespace std;

// Trust this function
// 1 2 3 4 5 6 7 
// 0 1 1 2 3 5 8

int fib(int n) {
	if (n <= 2) return n-1;
	return fib(n-1) + fib(n-2);
}

int main() {
	int n;
	cin >> n;
	cout << fib(n) <<endl;
}