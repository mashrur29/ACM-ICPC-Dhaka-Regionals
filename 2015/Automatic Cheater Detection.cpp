// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4922

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, pair<int, char> >
#define mp(a, b, c) make_pair(a, make_pair(b, c))

const int maxi = 51111;
int cnt[maxi], n;
vector<pii> a;

inline void reset() {
    a.clear();
    memset(cnt, 0, sizeof(cnt));
}

int main() {
    int T;
    cin>>T;

    while(T--) {
        int res = 0;
        reset();
        cin>>n;

        for(int i=1; i<=n; i++) {
            int d, s;
            char r;
            cin>>d>>s>>r;
            a.push_back(mp(d, s, r));

            if(s && r=='c') cnt[d]++;
        }

        for(int i=0; i<a.size(); i++) {
            int d, s;
            char r;
            d = a[i].first;
            s = a[i].second.first;
            r = a[i].second.second;

            if(!s && r=='i') {
                for(int j = d+1; j<=10; j++) res += cnt[j];
            }
        }

        cout<<res<<endl;
    }

    return 0;
}
