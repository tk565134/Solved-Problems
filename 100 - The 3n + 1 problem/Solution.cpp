#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int a,b;
	while(cin>>a>>b){
		int m=0;
		for(int i=min(a,b);i<=max(a,b);i++){
			int t=1;
			int x = i;
			while(x!=1){
				if(x%2==0) x/=2;
				else x= 3*x + 1;
				t++;
			}
			if(t>m) m=t;
		}
		cout<<a<<" "<<b<<" "<<m<<endl;
	}
	return 0;
}

