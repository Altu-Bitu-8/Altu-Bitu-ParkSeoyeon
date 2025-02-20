#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void bmrNotChange(int W0, int I0, int A, int I, int D){
    int weight = W0;
    for(int i=0; i<D; i++){
        int daily_energy_out = I0 + A;
        weight += (I - daily_energy_out);
    }
    if( weight <= 0){
        cout << "Danger Diet" << '\n';
    }
    else{
        cout << weight << " " << I0 << '\n';
    }
}

void bmrChange(int W0, int I0, int A, int I, int D, int T){
    int weight = W0;
    int bmr_after = I0;

    for(int i=0; i<D; i++){
        int daily_energy_out = bmr_after + A;
        int weight_change = I - daily_energy_out;
        weight += weight_change;
        if(abs(weight_change) > T){
            bmr_after += floor((double)weight_change / 2);
        }
        if(weight <= 0){
            cout << "Danger Diet" << '\n';
            return;
        }
        if(bmr_after <= 0){
            cout << "Danger Diet" << '\n';
            return;
        }
    }

    if(bmr_after < I0){
        cout << weight << " " << bmr_after << " YOYO" << '\n';
    }else{
        cout << weight << " " << bmr_after << " NO" << '\n';
    }

}

int main() {
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T;
    cin >> D >> I >> A;

    bmrNotChange(W0, I0, A, I, D);
    bmrChange(W0, I0, A, I, D, T);

    return 0;

}