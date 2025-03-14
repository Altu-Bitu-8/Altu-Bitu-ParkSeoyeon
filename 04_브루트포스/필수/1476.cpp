#include <iostream>

using namespace std;

int calculateYear(int E, int S, int M){
    
    int year = 1;
    
    while (true)
    {
        int mod_E = (year - E) % 15;
        int mod_S = (year - S) % 28;
        int mod_M = (year - M) % 19;

        if(mod_E == 0 && mod_S == 0 && mod_M == 0){
            return year;
        }else{
            year++;
        }
    }
    
}

int main(){

    int E, S, M, year;
    cin >> E >> S >> M;

    year = calculateYear(E, S, M);

    cout << year;

    return 0;
}