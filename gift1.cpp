/*
ID: sxlai2
PROG: gift1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int n;
    fin >> n;
    string array[n];
    string name;
    unordered_map<string, int> memo;
    for(int i=0; i<n; i++){ //this loop is initializing everyone's values to 0
        fin >> name;
        array[i]  = name;
        memo[name] = 0;
    }

    int buy, num; 
    for(int i=0; i<n; i++){
        string boss;
        fin >> boss;        //taking in input, this is the person that is currently buying gifts
        fin >> buy >> num; 
        int dist = buy/num;
        memo[boss] -= (dist*num);  //this is the owe -ing part where the person spends money
        string frend;
        for(int i=0; i<num; i++){
            fin >> frend;
            memo[frend] += dist;   //this is where the friends get presents
        }
    }
    for(int i=0; i<n; i++){
        fout << array[i] << " " << memo[array[i]] << "\n"; //printing output
    }
}