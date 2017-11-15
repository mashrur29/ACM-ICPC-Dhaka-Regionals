// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4923

#include<bits/stdc++.h>
using namespace std;

map<string, int> mp, st;
int a[10][10];

inline void init() {
    mp["JAN"] = 31;
    mp["FEB"] = 28;
    mp["MAR"] = 31;
    mp["APR"] = 30;
    mp["MAY"] = 31;
    mp["JUN"] = 30;
    mp["JUL"] = 31;
    mp["AUG"] = 31;
    mp["SEP"] = 30;
    mp["OCT"] = 31;
    mp["NOV"] = 30;
    mp["DEC"] = 31;


    st["SUN"] = 1;
    st["MON"] = 2;
    st["TUE"] = 3;
    st["WED"] = 4;
    st["THU"] = 5;
    st["FRI"] = 6;
    st["SAT"] = 7;
}

int main() {
    init();
    int T;
    cin>>T;

    while(T--) {
        memset(a, 0, sizeof(a));
        string s1, s2;
        cin>>s1>>s2;
        int day = mp[s1];
        int j = st[s2], cnt = 0;

        for(int i = 1; ; i++) {
            for(; j<=7; j++) {
                if(day) {
                    a[i][j] = 1;
                    day--;
                }
                else break;
            }
            j = 1;
            if(!day) break;
        }

        for(int i=1; i<10; i++) {
            for(int j=1; j<=7; j++) {
                if(j==6 || j==7) cnt += a[i][j];
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}
