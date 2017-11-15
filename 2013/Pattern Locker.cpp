// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4450

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 11111;
ll mod = 10000000000007;
ll f[maxi];

int main() {
    int T, caseno = 1;
    scanf("%d", &T);

    while(T--) {
        int n, mx, mn;
        scanf("%d %d %d", &n, &mn, &mx);

        ll res = 0LL;
        int tot = n*n;

        int lim = tot;
        f[lim] = lim;
        for(int i=lim-1; i>=1; i--) {
            f[i] = (i*f[i+1])%mod;
        }

        for(int i = mn; i <= mx; i++) {
            res = (res + f[tot - i + 1])%mod;
        }

        printf("Case %d: %lld\n", caseno++, res);
    }

    return 0;
}

/*

2
3 4 9
3 1 9

*/
