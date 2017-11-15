// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5074

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 100011;
int n;
map<int, int> mp;
const string invalid = "invalid";

bool balanced(string s) {
    stack<char> q;

    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            q.push(s[i]);
        }
        else {
            if(q.empty()) return false;
            q.pop();
        }
    }

    if(q.empty()) return true;
    return false;
}

string solve() {
    string ret = "";
    int prev = 0;

    for(int i=1; i<=n; i++) {
        if(mp[prev+1]) {
            prev++;
            ret += "(";
            mp[prev]--;
        }
        else if(mp[prev-1]) {
            prev--;
            ret += ")";
            mp[prev]--;
        }
        else return invalid;
    }

    if(balanced(ret)) return ret;
    else return invalid;
}

int main() {
    int T, caseno = 1;
    cin>>T;

    while(T--) {
        mp.clear();

        cin>>n;
        for(int i=1; i<=n; i++) {
            int temp;
            cin>>temp;
            mp[temp]++;
        }

        printf("Case %d: ", caseno++);
        cout<<solve()<<endl;
    }

    return 0;
}


/*

2
4
0 0 1 1
5
1 2 3 4 5

*/
