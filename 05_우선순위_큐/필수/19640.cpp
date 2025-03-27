#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Info {
    int work, emer, num, line_num;
};

struct cmp {
    bool operator()(const Info& child, const Info& parent){
        if(child.work != parent.work) return child.work < parent.work;
        if(child.emer != parent.emer) return child.emer < parent.emer;
        return child.line_num  > parent.line_num;
    }
};

int findMyTurn(vector<queue<Info>>& line, int m, int k){

    priority_queue<Info, vector<Info>, cmp> max_heap;

    for (int i = 0; i < m; i++) {
        if (!line[i].empty()) {
            max_heap.push(line[i].front());
            line[i].pop();
        }
    }

    int count = 0;

    while(true){
        
        Info pp = max_heap.top();
        max_heap.pop();
        if(pp.num == k){
            break;
        }else{
            int next_line = pp.line_num;
            if(!line[next_line].empty()){
                max_heap.push(line[next_line].front());
                line[next_line].pop();
            }
 
        }
        count++;

    }

    return count;
}

int main(){

    int n, m, k;
    cin >> n >> m >> k;

    int row = m;
    vector<queue<Info>> line(row);

    for(int i=0; i<n; i++){
        Info info;
        cin >> info.work >> info.emer;
        info.num = i;
        info.line_num = i % m;
        line[i % m].push(info);
    }   

    int count = findMyTurn(line, m, k);

    cout << count;

    return 0;
}