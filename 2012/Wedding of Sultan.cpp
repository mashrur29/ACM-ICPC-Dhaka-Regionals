// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4027

#include<bits/stdc++.h>
using namespace std;

const int maxi = 30;
vector<int> adj[maxi];

inline void reset() {
    for(int i=0; i<maxi; i++) {
        adj[i].clear();
    }
}

void solve(string s) {
    stack<char> q;

    for(int i=0; i<s.size(); i++) {
        if(q.empty()) q.push(s[i]);
        else if(q.top() == s[i]) q.pop();
        else {
            int u = q.top() - 'A';
            int v = s[i] - 'A';
            adj[u].push_back(v);
            adj[v].push_back(u);
            q.push(s[i]);
        }
    }

    return;
}

int main() {
    int T, caseno = 1;
    cin>>T;

    while(T--) {
        reset();
        string s;
        cin>>s;
        solve(s);
        cout<<"Case "<<caseno++<<endl;
        for(int i=0; i<26; i++) {
            if(adj[i].size()) {
                char ch = i + 'A';
                cout<<ch<<" = "<<adj[i].size()<<endl;
            }
        }
    }

    return 0;
}
