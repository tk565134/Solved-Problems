#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;
// Function to calculate the sum of digits of a number
int dSum(int n){
	int s=0;
	while(n>0){
		s+=n%10;
		n/=10;
	}
	return s;
}

int main() {
	auto start = high_resolution_clock::now(); 
	long n = pow(10,9);
	long ans=2;
	//vector to store all the prime numbers found less than the sqrt(n)
	vector<int> v;
	int s = 0; //to store the size of vector
	for(int i=3;i<=sqrt(n);i+=2){
		int f=1;
		int t=sqrt(i);
		for(int j=0;j<s;j++){
			// i can be divided by any previous prime number then break loop
			if(i%v[j]==0){
				f=0;
				break;		
			}
			// if prime numbers which we are using to divide the number become the
			// greater than sqrt(i) break	
			if(v[j] > t) break;	
		}
		if(f){
			v.push_back(i);
			ans+= dSum(i);
			s++;
		}			
	}
	//now we will find all the prime numbers above sqrt(n) to n
	// i is set to odd number next or equal to sqrt(n)
	
	for(int i=sqrt(n)+1;i<n;i+=2){
		int f=1;
		int t = sqrt(i);
		for(int j=0;j<s;j++){
			if(i%v[j]==0){
				f=0;
				break;			
			}
			if(v[j] > t) break;
		}
		if(f) ans+=dSum(i);

	}
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	//running time is around 1124.425481 seconds
	cout <<"running time of this program is "<< duration.count()/pow(10,6) << " seconds"<<endl; 
	//answer is 2076414728
	cout<<"Sum of digits of prime numbers less than 10^9 is "<< ans <<endl;
	
	return 0;
}
