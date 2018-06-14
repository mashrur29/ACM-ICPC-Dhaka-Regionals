#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 111;
int n, m;
int a[maxi], c[maxi];
int dp[maxi][maxi];

int lol(int L, int R) {
    if(L > R) return 0;
    if(dp[L][R] != -1) return dp[L][R];
    
    int ret = 1 + lol(L+1, R);
    for(int i=L+1; i<=R; i++) {
        if(c[i] == c[L]) {
            ret = min(ret, lol(L+1, i) + lol(i+1, R));
        }
    }
    
    return dp[L][R] = ret;
}

int main() {
    int T, caseno = 1;
    scanf("%d", &T);
    
    while(T--) {
        int n1 = 0;
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &n, &m);
        a[0] = -1;
        
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);
        
        for(int i=1; i<=n; i++) {
            if(a[i] != a[i-1]) c[++n1] = a[i];
        }
        n = n1;
        
        printf("Case %d: %d\n", caseno++, lol(1, n));
    }
    
    return 0;
}
