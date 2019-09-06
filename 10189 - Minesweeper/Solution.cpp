#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n,m;
	int k = 1 ;

	cin>>n>>m;
	while(true){
		
		cout<<"Field #"<<k<<":\n";
		vector<string> v;
		string t ="";
		for(int i=0;i<m+2;i++){
			t+=".";
		}
		v.push_back(t);
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			v.push_back("."+s+".");
		}
		v.push_back(t);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(v[i][j]=='*') cout<<"*";
				else{
					int c=0;
					if(v[i-1][j-1]=='*') c++;
					if(v[i-1][j]=='*') c++;
					if(v[i-1][j+1]=='*') c++;
					if(v[i][j-1]=='*') c++;
					if(v[i][j+1]=='*') c++;
					if(v[i+1][j-1]=='*') c++;
					if(v[i+1][j]=='*') c++;
					if(v[i+1][j+1]=='*') c++;
					cout<<c;
				}
			}
			cout<<"\n";
		}
		k++;
		cin>>n>>m;
		if(n!=0 or m!=0) cout<<"\n";
		else break;
		
		
	}
	// your code goes here
	return 0;
}
