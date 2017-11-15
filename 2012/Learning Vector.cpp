// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4034

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(T) scanf("%d", &T)

struct point {
    int x, y;
};

const int maxi = 55;
vector< point > v;
int n, k;
ll dp[maxi][maxi][2510];

bool compare(point a, point b) {
    return ((a.y * b.x) > (b.y * a.x));
}

ll lol(int pos, int taken, int h) {
    if(taken == k) return 0;
    if(pos >= n) return INT_MIN;

    ll &ret = dp[pos][taken][h];
    if(ret != -1) return ret;
    ret = INT_MIN;

    return ret = max(ret, max(lol(pos+1, taken, h), ((2 * h * v[pos].x) + (v[pos].x * v[pos].y) + lol(pos+1, taken+1, h + v[pos].y) )));
}

int main() {
    int T, caseno = 1;
    sc(T);

    while(T--) {
        memset(dp, -1, sizeof(dp));
        v.clear();
        sc(n), sc(k);
        for(int i=1; i<=n; i++) {
            point t;
            sc(t.x), sc(t.y);
            v.push_back(t);
        }

        sort(v.begin(), v.end(), compare);
        printf("Case %d: %lld\n", caseno++, lol(0, 0, 0));
    }

    return 0;
}
