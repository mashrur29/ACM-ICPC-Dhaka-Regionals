#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int caseno = 1;
    int n;
    
    while(scanf("%d", &n) == 1 && n) {
        int a = 0, b = 0, x;
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            if(!x) b++;
            else a++;
        }
        printf("Case %d: %d\n", caseno++, a - b);
    }

    return 0;
}
