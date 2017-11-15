// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4762

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin>>T;

    while(T--) {
        int r;
        map<char, char> mp;
        string s;
        cin>>s>>r;

        for(int i=0; i<s.size(); i++) mp[s[i]] = s[i];

        for(int i=1; i<=r; i++) {
            char u, v;
            cin>>u>>v;
            for(char ch = 'A'; ch <= 'Z'; ch++) {
                if(mp[ch] == v) mp[ch] = u;
            }
        }

        for(int i=0; i<s.size(); i++) cout<<mp[s[i]];
        cout<<endl;
    }

    return 0;
}
