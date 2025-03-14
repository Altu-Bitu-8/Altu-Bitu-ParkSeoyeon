#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 1000000;
vector<bool> is_prime(MAX_N + 1, true);

void IsPrime(){
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i<= sqrt(MAX_N); i++){
        if(is_prime[i]){
            for(int j=i*i; j<=MAX_N; j += i){
                is_prime[j] = false;
            }
        }
    }
}

void GoldbachTest(int n){

    int a, b;
    for(int i=3; i <= n/2; i+=2){
        a=i;
        b=n-i;
        if(is_prime[a] && is_prime[b]){
            cout << n  << " = " << a << " + " << b << '\n';
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong." << '\n';
}

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    IsPrime();
    
    int n;

    while(true){
        cin >> n;
        if(n == 0) break;
       
         GoldbachTest(n);
        
    }

    return 0;
}