#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> numbers(11);
vector<int> operators(4);
int res_min = 1000000001;
int res_max = -1000000001;

void getMinMax(int result, int index){

    if(index == n){
        if(result > res_max) {res_max = result;}
        if(result < res_min) {res_min = result;}
        return;
    }

    for(int i=0; i<4; i++){
        if(operators[i] > 0){
            operators[i]--;
            switch(i){
                case 0 : getMinMax(result + numbers[index], index+1); break;
                case 1 : getMinMax(result - numbers[index], index+1); break;
                case 2 : getMinMax(result * numbers[index], index+1); break;
                case 3 : 
                        if(result < 0 && numbers[index] > 0){
                            int next_res = -(-result / numbers[index]);
                            getMinMax(next_res, index+1);
                        }
                        else{
                            getMinMax(result / numbers[index], index+1); break;
                        }
                
            }
            operators[i]++;
            
        }
    }

    return;
    

}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        numbers[i] = num;
    }

    for(int i=0; i<4; i++){
        cin >> operators[i];
    }


    getMinMax(numbers[0], 1);

    cout << res_max << "\n" << res_min;

    return 0;
}