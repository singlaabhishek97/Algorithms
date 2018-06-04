/* 
	1	5	7
	6	10	4
	2	8	3
	
	The minimum cost to reach element [2][2] is 13 with path [0][0](1)-[0][1](5)-[1][2](4)-[2][2](3).
*/
#include <bits/stdc++.h>
using namespace std;
int cost[10][10];
int mincost[10][10];
int getmincost(int m, int n){
	if (mincost[m][n] == -1){
		mincost[m][n] = min(getmincost(m-1,n-1),min(getmincost(m-1,n),getmincost(m,n-1)))+cost[m][n];
	}
	return mincost[m][n];
}
int main(){
	int n,r,c,m;
	cin>>r>>c;
	for (int i = 0; i < r; ++i)	{
		for (int j = 0; j < c; ++j)	{
			cin>>cost[i][j];
		}
	}
	for (int i = 0; i < r; ++i)	{
		for (int j = 0; j < c; ++j)	{
			mincost[i][j] = -1;
		}
	}
	mincost[0][0] = cost[0][0];
	for (int i = 1; i < r; ++i){
		mincost[i][0] = mincost[i-1][0] + cost[i][0];
	}
	for (int j = 1; j < c; ++j){
		mincost[0][j] = mincost[0][j-1] + cost[0][j];
	}
	cout<<endl;
	cin>>m>>n;
	cout<<getmincost(m, n)<<endl;
} 
