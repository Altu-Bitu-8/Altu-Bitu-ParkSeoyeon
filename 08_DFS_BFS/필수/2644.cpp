#include <iostream>
#include <vector>

using namespace std;

int calculate(const vector<int>& relatives, int p1, int p2){
    vector<int> p1_rel;
    int pp = p1;

    while (pp != 0)
    {
        p1_rel.push_back(pp);
        pp = relatives[pp];
    }

    pp = p2;
    int count = 0;

    while (pp != 0)
    {
        for(int i = 0; i<p1_rel.size(); i++){
            if(pp == p1_rel[i]){
                return i + count;
            }
        }
        pp = relatives[pp];
        count++;      
    }

    return -1;

}

int main(){

    int n, p1, p2, m;
    cin >> n >> p1 >> p2 >> m;

    vector<int> relatives(n+1, 0);

    for(int i=0; i<m; i++){
        int parent, child;
        cin >> parent >> child;
        relatives[child] = parent;
    }

    int res = calculate(relatives, p1, p2);
    cout << res;

    return 0;
}