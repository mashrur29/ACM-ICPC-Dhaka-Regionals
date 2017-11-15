#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9
typedef long long ll;

const int maxi = 3111;
int n, q;
ll xx[maxi], yy[maxi], rad[1000001];

ll sqr_dis(int pos1, int pos2) {
    return (xx[pos1] - xx[pos2])*(xx[pos1] - xx[pos2]) + (yy[pos1] - yy[pos2])*(yy[pos1] - yy[pos2]);
}

double solve(double R) {
    double res = 0.0;

    res = (1.0*R) / ((double)n*1.0);

    return res;
}

int main() {
    ll R;

    while(scanf("%d %d", &n, &q)==2 && n && q) {
        memset(rad, 0, sizeof(rad));
        for(int i=1; i<=n; i++) {
            scanf("%lld %lld", &xx[i], &yy[i]);
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                ll dis = sqr_dis(i, j);
                double dd = dis;
                dd = ceil(sqrt(dd));
                int ind = dd;
                rad[ind]++;
            }
        }

        for(int i=1; i<1000001; i++) rad[i] += rad[i-1];

        for(int i=1; i<=q; i++) {
            int r;
            scanf("%d", &r);
            printf("%.2f\n", solve(rad[r]));
        }

        puts("");
    }

    return 0;
}
