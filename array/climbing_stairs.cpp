#include <bits/stdc++.h>
using namespace std;

//  Climbing Stairs. You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// constraints 1 <= n <= 45


// i => i+1 and i+2
// i+1 => i+2 and i+3

// no of ways to reach step x => dp(x)

// reverse
// recursive case => no of ways to reach step x are no of ways to reach x -1 step + no of ways to reach step x-2
// dp(x) = dp(x-1) + dp(x-2)

// assuming initially at 0 step
// base case => dp(1) = 1 we can reach 1 step only by a single way that is go from step 0 to step 1
// base case => dp(2) = 2 we can reach 2nd step by two ways 0 => 1 => 2 or 0 => 2

int main() {
	// number of steps
	int n;
	cin>>n;

	vector<int> dp(n+1,0);
	dp[1] = 1;
	dp[2] = 2;

	// if n <=2
	for (int i=3;i<=n;i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n] << "\n";
	return 0;
}