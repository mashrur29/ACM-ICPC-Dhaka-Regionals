// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4925

#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, caseno = 1;
    cin>>T;

    while(T--) {
        int uni = 0, res = INT_MAX;
        string s;
        map<char, int> mp;

        cin>>s;
        for(int i=0; i<s.size(); i++) {
            if(!mp[s[i]]) {
                uni++;
            }
            mp[s[i]]++;
        }

        cout<<"Case "<<caseno++<<": ";
        if(uni < 26) cout<<"0"<<endl;
        else {
            for(char ch = 'a'; ch<='z'; ch++) res = min(res, mp[ch]);
            cout<<res<<endl;
        }
    }

    return 0;
}
