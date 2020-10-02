#include<bits/stdc++.h>
using namespace std;

int coinChange_MEM(int *input, int n, int sum) {
	int dp[n+1][sum+1];
	memset(dp, -1, sizeof(dp));
	if(n == 0 && sum == 0) {
		return 1;
	} 
	if(n == 0 && sum != 0) {
		return 0;
	}
	if(dp[n][sum] != -1) {
		return dp[n][sum];
	}
	int a, b;
	if(input[0] > sum) {
		return dp[n][sum] = coinChange_MEM(input+1, n-1, sum);
	} else {
		a = coinChange_MEM(input, n, sum-input[0]);
		b = coinChange_MEM(input+1, n-1, sum);
		dp[n][sum] = a + b;
	}
	return dp[n][sum];
}

int coinChange_Recursion(int *input, int n, int sum) {
	if(n == 0 && sum == 0) {
		return 1;
	}
	if(n == 0 && sum != 0) {
		return 0;
	}
	int a, b;
	if(input[0] > sum) {
		return coinChange_MEM(input+1, n-1, sum);
	} else {
		a = coinChange_MEM(input, n, sum-input[0]);
		b = coinChange_MEM(input+1, n-1, sum);
		return a+b;
	}
}

int coinChange(int *input, int n, int sum) {
	int dp[n+1][sum+1];
	for(int j=0;j<=sum;j++) {
		dp[0][j] = 0;
	}
	for(int i=0;i<=n;i++) {
		dp[i][0] = 1;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sum;j++) {
			if(input[i-1] <= j) {
				dp[i][j] = dp[i-1][j] + dp[i][j-input[i-1]];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

int main() {
	int n, input[100], sum;
	cout<<"Enter the number of coins:"<<endl;
	cin>>n;
	cout<<"Enter the coins:"<<endl;
	for(int i=0;i<n;i++) {
		cin>>input[i];
	}
	cout<<"Enter the sum:"<<endl;
	cin>>sum;
	int ans = coinChange(input, n, sum);
	cout<<"Number of ways of coin change using Dynamic Programming approach::"<<ans<<endl;
	int ans1 = coinChange_Recursion(input, n, sum);
	cout<<"Number of ways of coin change using Recursion appraoch:"<<ans1<<endl;
	int ans2 = coinChange_MEM(input, n, sum);
	cout<<"Number of coins chage using Memoization approach:"<<ans2<<endl;
	return 0;
}
