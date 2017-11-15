// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4456

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 1111;
int sz;
char s[maxi];

bool isDromicpalin(int cnt[]) {
    int odd = 0;
    for(int i=0; i<26; i++) {
        if(cnt[i] & 1) odd++;
        if(odd >= 2) return false;
    }
    return true;
}

int main() {
    int T, caseno = 1;
    scanf("%d", &T);

    while(T--) {
        ll res = 0;
        scanf("%s", s);
        sz = strlen(s);

        for(int i=0; i<sz; i++) {
            int cnt[26] = {0};
            for(int j=i; j<sz; j++) {
                int val = s[j] - 'a';
                cnt[val]++;
                if(isDromicpalin(cnt)) res++;
            }
        }

        printf("Case %d: %lld\n", caseno++, res);
    }

    return 0;
}
