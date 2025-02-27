#include <iostream>
#include <queue>

using namespace std;

void throwCards(queue<int>& q){
    while (q.size() > 1)
    {
        q.pop();
        int second = q.front();
        q.pop();
        q.push(second);

    }
    int final = q.front();
    cout << final;
}

int main(){

    int size;
    cin >> size;

    queue<int> cards;
    for(int i=1; i<size+1; i++){
        cards.push(i);
    }

    throwCards(cards);

    return 0;
}