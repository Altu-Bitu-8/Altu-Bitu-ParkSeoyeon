#include <iostream>
#include <vector>
#include <deque>

using namespace std;

string checkCard(deque<int>& doDummy, deque<int>& suDummy){
    if(!doDummy.empty() && !suDummy.empty() && (doDummy.front() + suDummy.front() == 5)){
        return "suyeon";
    }else if ((!doDummy.empty() && doDummy.front() == 5) || (!suDummy.empty() && suDummy.front() == 5)) {
        return "dodo";
    }else{
        return "";
    }
}

void addCards(deque<int>& deq, deque<int>& dummy){
    
    while (!dummy.empty())
    {
        deq.push_back(dummy.back());
        dummy.pop_back();
    }

}

string findWinner(int game, deque<int>& dodo, deque<int>& suyeon){

    deque<int> doDummy, suDummy;

    for(int i=0; i<game; i++){

        if(i % 2 == 0){

            doDummy.push_front(dodo.front());
            dodo.pop_front();

            if(dodo.empty()) return "su";
            if(suyeon.empty()) return "do";
    
            string res1 = checkCard(doDummy, suDummy);
            
            if(res1 == "dodo"){
                addCards(dodo, suDummy);
                addCards(dodo, doDummy);
            }else if(res1 == "suyeon"){
                addCards(suyeon, doDummy);
                addCards(suyeon, suDummy);
            }
    
            
    
    
        } else{
            
            suDummy.push_front(suyeon.front());
            suyeon.pop_front();

            if(dodo.empty()) return "su";
            if(suyeon.empty()) return "do";
    
            string res2 = checkCard(doDummy, suDummy);
            
            if(res2 == "dodo"){
                addCards(dodo, suDummy);
                addCards(dodo, doDummy);
            } else if(res2 == "suyeon"){
                addCards(suyeon, doDummy);
                addCards(suyeon, suDummy);
            }
    
        }

    }

    if (dodo.size() == suyeon.size()){
        return "dosu";
    } 
    return (dodo.size() > suyeon.size()) ? "do" : "su";
}

int main(){

    int card_num, game;
    cin >> card_num >> game;

    deque<int> dodo;
    deque<int> suyeon;

    for(int i=0; i<card_num; i++){
        int d, s;
        cin >> d >> s;
        dodo.push_front(d);
        suyeon.push_front(s);
    }

    string result = findWinner(game, dodo, suyeon);
    cout << result;


    return 0;
}