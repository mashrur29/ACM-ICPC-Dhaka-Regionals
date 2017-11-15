// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4926

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 20000011;
ll divi[maxi];

inline void __divisor() {
    int lim = 20000001;

    for(int i=1; i<=lim; i++) {
        for(int j=i; j<=lim; j += i) {
            divi[j] += i;
        }
    }

    for(int i=1; i<=lim; i++) divi[i] += divi[i-1];
}

int main() {
    __divisor();
    int n;

    while(scanf("%d", &n)==1 && n) {
        printf("%lld\n", divi[n] - divi[1]);
    }

    return 0;
}
