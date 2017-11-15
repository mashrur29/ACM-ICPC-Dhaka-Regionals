// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4447

#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9

const double g = 9.8;

double _calculate(double h) {
    double ret = 1.0 - (1.0/(2.0 * h));
    return ret;
}

int volume(int L, int W, int H) {
    return (L * W * H);
}

int main() {
    int n;

    while(cin>>n && n) {
        double res = -10000000000.0;
        int ans;

        for(int i=1; i<=n; i++) {
            int L, W, H;
            cin>>L>>W>>H;
            double tmp = _calculate(H);
            if(tmp + eps >= res) {
                if(tmp == res) ans = max(ans, volume(L, W, H));
                else ans = volume(L, W, H);
                res = tmp;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
