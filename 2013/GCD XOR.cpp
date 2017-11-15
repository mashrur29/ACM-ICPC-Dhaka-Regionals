// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4454

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

2
7
20000000

*/

const int maxi = 30000011;
ll cnt[maxi];

inline void sieve() {
    int mx = 30000000;

    for(int i=1; i<=mx; i++) {
        for(int j=i*2; j<=mx; j+=i) {
            int t = j - i;
            if(i == (t^j)) cnt[j]++;
        }
    }

    for(int i=1; i<=mx; i++) cnt[i] += cnt[i-1];
}

int main() {
    sieve();
    int T, caseno = 1;
    scanf("%d", &T);

    while(T--) {
        ll n;
        scanf("%lld", &n);
        printf("Case %d: %lld\n", caseno++, cnt[n]);
    }

    return 0;
}
