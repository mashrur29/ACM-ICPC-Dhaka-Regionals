// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4769

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eps 1e-9

const int maxi = 11111;
int n, resa, resb, resc;
vector<int> v;
double res;

inline void __calculate(int a, int b, int c, double x) {
    x /= 4.0;
    int aa = upper_bound(v.begin(), v.end(), a) - v.begin();
    if(aa < v.size() && v[aa] > a) aa--;

    int bb = upper_bound(v.begin(), v.end(), b) - v.begin();
    if(bb < v.size() && v[bb] > b) bb--;

    int cc = upper_bound(v.begin(), v.end(), c) - v.begin();
    if(cc < v.size() && v[cc] > c) cc--;

    int a1, b1, c1, d1;
    a1 = aa + 1;
    b1 = bb - aa;
    c1 = cc - bb;
    d1 = n - (a1 + b1 + c1);

    double temp = fabs(x - a1) + fabs(x - b1) + fabs(x - c1) + fabs(x - d1);
    if(temp + eps< res) {
        res = temp;
        resa = a;
        resb = b;
        resc = c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T, caseno = 1;
    cin>>T;

    while(T--) {
        v.clear();
        cin>>n;
        res = 1000000000000.0;

        for(int i=1; i<=n; i++) {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        for(int a = 0; a <= 160; a++) {
            for(int b = a + 1; b <= 160; b++) {
                for(int c = b + 1; c <= 160; c++) {
                    __calculate(a, b, c, n);
                }
            }
        }

        cout<<"Case "<<caseno++<<": "<<resa<<" "<<resb<<" "<<resc<<endl;
    }

    return 0;
}
