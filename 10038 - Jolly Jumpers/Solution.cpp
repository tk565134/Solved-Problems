#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	while(cin>>n){
		int a[n]={0};
		int x;
		cin>>x;
		a[0]=1;
		for(int i=1;i<n;i++){
			int y;
			cin>>y;
			if(abs(y-x)<n and abs(y-x)>0){
				a[abs(y-x)]=1;
			}
			x=y;
		}
		int f=1;
		for(int i=0;i<n;i++){
			if(a[i]!=1){
				f=0;
				break;
			}
		}
		if(f) cout<<"Jolly"<<endl;
		else cout<<"Not jolly"<<endl;
	}
	return 0;
}
