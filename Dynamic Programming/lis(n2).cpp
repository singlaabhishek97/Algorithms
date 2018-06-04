#include<bits/stdc++.h>
using namespace std;
int n;
int getlis(int *arr){
	if(n == 1)
		return 1;	
	int *lis;
	lis = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i){
		lis[i] = 1;
	}
	for (int i = 1; i < n; ++i){
		for (int j = 0; j < i; ++j){
			if( arr[j] < arr[i] && lis[j]+1 > lis[i] )
				lis[i] = lis[j] + 1;
		}
	}
	int max;
	max = 1;
	for (int i = 0; i < n; ++i){
		if(max < lis[i])
			max = lis[i];
	}
	free(lis);
	return max;
}
int main(){
	int *arr,*lis;
	cin>>n;
	arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}
	cout<<getlis(arr)<<endl;
}