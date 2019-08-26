#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
using namespace std::chrono;
using namespace std;
// method to check number n is palindrome in binary or not
bool binaryPalindrome(int n){
	string s="";
	while(n>0){
		if(n%2==1){
			s="1"+s;
		}
		else s ="0"+s;
		n/=2;
	}
	int x=s.length()/2;
	int y=s.length();
	for(int i=0;i<x;i++){
		if(s[i]!=s[y-1-i]) return false;
	}
	return true;
	
}
//method to check number n is palindrome in octal or not
bool octalPalindrome(int n){
	string s="";
	while(n>0){
		s = to_string(n%8)+s;
		n/=8;
	}
	int x=s.length()/2;
	int y=s.length();
	for(int i=0;i<x;i++){
		if(s[i]!=s[y-1-i]) return false;
	}
	return true;
}
//method to check number n is palindrome in hexadecimal or not
bool hexadecimalPalindrome(int n){
	string s="";
	while(n>0){
		if(n%16 < 10) s=to_string(n%16)+s;
		else{
			s= (char)(n%16+55) + s;
		}
		n/=16;
	}
	int x=s.length()/2;
	int y=s.length();
	for(int i=0;i<x;i++){
		if(s[i]!=s[y-1-i]) return false;
	}
	return true;
}

int main() {
	auto start = high_resolution_clock::now(); 
	int n=1000000000;
	int ans=0;
	for(int i=0;i<n;i++){
		if(hexadecimalPalindrome(i)){
			if(octalPalindrome(i)){
				if(binaryPalindrome(i)){
					ans+=i;
				}
			}
		}
		
	}
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	//running time is around 1150.5 seconds
	cout <<"running time of this program is "<< duration.count()/pow(10,6) << " seconds"<<endl; 
	// answer is 2124805300
	cout<<"sum of numbers which are palindromes in binary, octal and hexadecimal less than 1000000000 is "<<ans<<endl;
	return 0;
}
