#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 16;
std::vector<ll> fib;
int n;

void pre() {
    fib.push_back(1);
    fib.push_back(2);
    int pos = 2;
    
    while(true) {
        if(fib[pos - 1] > 2000000000) break;
        fib.push_back(fib[pos - 1] + fib[pos - 2]);
        pos++;
    }
    
}

ll do_(ll temp) {
    ll ret = 0;
    
    for(int i = fib.size() - 1; i>=0; i--) {
        ll x = fib[i];
        if(!temp) break;
        while(temp - x >= 0) {
            temp -= x;
            ret++;
        }
    }
    
    return ret;
}

int main() {
    pre();
    int T, caseno = 1;
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d", &n);
        ll temp, res = 1;
        
        for(int i=0; i<n; i++) {
            scanf("%lld", &temp);
            ll x = do_(temp);
            if(x) res *= x;
        }
        
        printf("Case %d: %lld\n", caseno++, res);
    }
    
    return 0;
}
