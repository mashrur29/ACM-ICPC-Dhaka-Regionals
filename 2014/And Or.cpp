// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4763

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;

string to_bin(ll x) {
    string ret = "";

    while(x) {
        ret += (x%2) + '0';
        x /= 2;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

ll toInt(string x) {
    ll ret = 0, mul = 1;

    for(int i=x.size()-1; i>=0; i--) {
        if(x[i] == '1') ret += mul;
        mul *= 2;
    }

    return ret;
}

ll bitOr(string a, string b) {
    string str = "";
    bool f = true;
    if(a.size() != b.size()) {
        int len = max(a.size(), b.size());
        for(int i=1; i<=len; i++) str += '1';
        return toInt(str);
    }

    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i]) f = false;
        if(f) str += a[i];
        else str += '1';
    }

    return toInt(str);
}

ll bitAnd(string a, string b) {
    if(a.size() != b.size()) return 0;
    string str = "";
    bool f = true;

    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i]) f = false;
        if(f) str += a[i];
        else str += '0';
    }

    return toInt(str);
}

int main() {
    int T, caseno = 1;
    cin>>T;

    while(T--) {
       cin>>A>>B;
       string stra = to_bin(A), strb = to_bin(B);
       cout<<"Case "<<caseno++<<": "<<bitOr(stra, strb)<<" "<<bitAnd(stra, strb)<<endl;
    }

    return 0;
}
