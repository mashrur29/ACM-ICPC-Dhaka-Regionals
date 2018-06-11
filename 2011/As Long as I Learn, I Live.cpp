#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 111;
ll w[maxi];
int n;
vector<int> adj[maxi];

inline void reset() {
    for(int i=0; i<maxi; i++) {
        w[i] = -1;
        adj[i].clear();
    }
}

pair<ll, int> lol(int pos) {
    pair<ll, int> ret = make_pair(0, 0);
    pair<ll, int> curr = make_pair(INT_MIN, 0);

    while(true) {
        ret.first += w[pos];
        ret.second = pos;
        if(!adj[pos].size()) break;
        curr.first = INT_MIN;

        for(int i=0; i<adj[pos].size(); i++) {
            int u = adj[pos][i];
            if(w[u] > curr.first) {
                curr.first = w[u];
                curr.second = u;
            }
        }     

        pos = curr.second;   
    }

    return make_pair(ret.first, ret.second);
}

int main() {
    int T, caseno = 1;
    cin>>T;

    while(T--) {
        reset();
        int m;
        cin>>n>>m;
        
        for(int i=0; i<n; i++) {
            cin>>w[i];
        }

        for(int i=0; i<m; i++) {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        pair<ll, int> res = lol(0);
        cout<<"Case "<<caseno++<<": "<<res.first<<" "<<res.second<<endl;
    }

    return 0;
}
