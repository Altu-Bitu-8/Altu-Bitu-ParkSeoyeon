#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getWordCount(string& s){
    vector<int> count(26, 0);
    for(int i=0; i<s.length(); i++){
        count[s[i] - 'A']++;
    }

    return count;
}

bool isSimilar(vector<int>& standard, vector<int>& new_word){

    int plus=0;
    int minus=0;

    for(int i=0; i<26; i++){
        int diff = standard[i] - new_word[i];
        if(diff > 0){
            minus += abs(diff);
        }else if(diff < 0){
            plus += abs(diff);
        }
    }

    return (plus==0 && minus==0) || (plus==1 && minus==0) || (plus==0 && minus==1) || (plus==1 && minus==1);


}

int main(){

    int n;
    cin >> n;

    int similar_count = 0;
    string first_word;
    cin >> first_word;

    vector<int> standard_word_count = getWordCount(first_word);

    for(int i=0; i<n-1; i++){
        string new_word;
        cin >> new_word;

        vector<int> new_word_count = getWordCount(new_word);

        if(isSimilar(standard_word_count, new_word_count)){
            similar_count++;
        }

    }

    cout << similar_count;


    return 0;
}