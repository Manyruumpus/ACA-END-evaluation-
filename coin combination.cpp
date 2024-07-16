#include <iostream>
#include <vector>
using namespace std;
// to return the ans in required form
const int mod = 1e9 + 7;

//function to solve the question 
int coin_comb(int n , int x,vector <int> doms){
	int ans=0;
	vector<int> dp(x+1, 0);
	// dp is used to store the make each sum from 0 to x
	dp[0]=1;
	for( int i=0;i<n;i++){
		// iterates over the vector of dom
		for( int j=doms[i];j<=x ; j++){
			//iterates from doms[i] to x 
			// formula based on sum to j= sum without current domination and with only current domination 
			dp[j]=(dp[j] + dp[j-doms[i]])%mod;// takin mod to prevent overflow from int data type
			
		}
	}
	ans=dp[x];
	return ans;
}
int main(){
	// taking input
	int n,x;
//	cout << "Enter the number of dominations(n) and sum required (x)" << endl;
	cin >> n >> x;
	vector<int> dom(n,0);
//	cout << "enter the dominations one by one "<< endl;
	for( int i=0;i<n;i++){
		int m;
		cin >> m;
		dom[i]=m;
	}
	int ans=coin_comb(n,x,dom);
	cout << ans ;
}