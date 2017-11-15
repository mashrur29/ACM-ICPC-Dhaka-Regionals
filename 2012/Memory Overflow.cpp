// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4028

#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;

bool contains(deque<pair<char, int> > q, char ch) {
    deque<pair<char, int> >::iterator it;

    for(it = q.begin(); it != q.end(); it++) {
        pair<char, int> pp = (*it);
        if(pp.first == ch) return true;
    }

    return false;
}

int solve() {
    int cnt = 0;
    deque<pair<char, int> > q;

    for(int i=0; i<s.size(); i++) {
        while(!q.empty() && (abs(i - q.front().second)>k)) q.pop_front();
        if(contains(q, s[i])) cnt++;
        q.push_back(make_pair(s[i], i));
    }

    return cnt;
}

int main() {
    int T, caseno = 1;
    cin>>T;

    while(T--) {
        cin>>n>>k>>s;
        cout<<"Case "<<caseno++<<": "<<solve()<<endl;
    }

    return 0;
}
