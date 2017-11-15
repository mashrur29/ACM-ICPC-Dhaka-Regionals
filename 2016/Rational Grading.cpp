// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5073

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll toInt(string s) {
    stringstream geek(s);
    ll x = 0;
    geek >> x;
    return x;
}

ll ToDecimal(string s, ll base) {
    ll ret = 0, mul = 1;
    for(int i=s.size()-1; i>=0; i--) {
        ll t;
        if(base == 16 && s[i] >= 'A' && s[i] <= 'F') {
            t = s[i] - 'A' + 10;
        }
        else t = s[i] - '0';

        ret += mul*t;
        mul*=base;
    }
    return ret;
}

int main() {
    string s;
    int t;

    while(1) {
        ll num = 0, marks = 0;
        bool f = true;
        cin>>s>>t;
        if(s=="0" && !t) break;

        if(s[0] == '0' && s[1] == 'x') num = ToDecimal(s.substr(2, s.size()-2), 16);
        else if(s[0] == '0') num = ToDecimal(s.substr(1, s.size()-1), 8);
        else num = toInt(s);

       // cout<<num<<endl;

        string op;
        ll val;
        for(int i=1; i<=t; i++) {
            cin>>op>>val;
            
            if(op.size()==1) {
                if(num == val) marks++;
                else num = val;
            }
            else if(op[0]=='+' && op[1]=='+') {
                num++;
                if(num==val) marks++;
                else num = val;
            } else if(op[1]=='+' && op[2]=='+') {
                if(num==val) marks++;
                else num = val;
                num++;
            } else if(op[0]=='-' && op[1]=='-') {
                num--;
                if(num==val) marks++;
                else num = val;
            } else {
                if(num==val) marks++;
                else num = val;
                num--;
            }

        }

        cout<<marks<<endl;
    }

    return 0;
}
