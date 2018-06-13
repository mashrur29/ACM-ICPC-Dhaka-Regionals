#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 50;
int row, col, lcol, rcol;
char a[maxi][maxi], res[maxi][maxi];
map<char, ll> mp;
ll lweight = 0, rweight = 0, lhead, ltail, rhead, rtail;

ll toBin(int num) {
    ll ret = 0;
    
    while(num) {
        if(num&1) ret += 500;
        else ret += 250;
        num /= 2;
    }
    
    return ret;
}

inline void pream() {
    row = 7;
    col = 18;
    lcol = 8;
    rcol = 11;
    
    for(char ch = 'A'; ch <= 'Z'; ch++) {
        mp[ch] = toBin((int)ch);
    }
}

void drawless() {
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=lcol; j++) {
            res[i][j] = a[i+lhead-1][j];
        }
    }
    
    for(int i=3; i<=7; i++) {
        for(int j=rcol; j<=18; j++) {
            res[i][j] = a[i+rhead-3][j];
        }
    }
}

void drawgreater() {
    for(int i=3; i<=7; i++) {
        for(int j=1; j<=lcol; j++) {
            res[i][j] = a[i+lhead-3][j];
        }
    }
    
    for(int i=1; i<=5; i++) {
        for(int j=rcol; j<=18; j++) {
            res[i][j] = a[i+rhead-1][j];
        }
    }
}

void drawequal() {
    for(int i=2; i<=6; i++) {
        for(int j=1; j<=lcol; j++) {
            res[i][j] = a[i+lhead-2][j];
        }
    }
    
    for(int i=2; i<=6; i++) {
        for(int j=rcol; j<=18; j++) {
            res[i][j] = a[i+rhead-2][j];
        }
    }
}

void solve() {
    lweight = 0;
    rweight = 0;
    
    for(int i=1; i<=row; i++) {
        for(int j=1; j<=col; j++) res[i][j] = '.';
    }
    
    for(int i=1; i<=row; i++) {
        for(int j=lcol + 1; j<rcol; j++) res[i][j] = '|';
    }
    
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= lcol; j++) {
            lweight += mp[a[i][j]];
            if(a[i][j] == '/' && j<lcol && a[i][j+1] == '\\') lhead = i;
            if(a[i][j] == '\\' && j<lcol && a[i][j+1] == '_') ltail = i;
        }
    }
    
    
    for(int i = 1; i <= row; i++) {
        for(int j = rcol; j <= 18; j++) {
            rweight += mp[a[i][j]];
            if(a[i][j] == '/' && j<18 && a[i][j+1] == '\\') rhead = i;
            if(a[i][j] == '\\' && j<18 && a[i][j+1] == '_') rtail = i;
        }
    }
    
    
    if((lweight == rweight && lhead == rhead && lhead == 2) || (lweight < rweight && lhead == 1 && rhead == 3) || (lweight > rweight && lhead == 3 && rhead == 1)) {
        printf("The figure is correct.\n");
        return;
    }
    else if(lweight < rweight) drawless();
    else if(lweight > rweight) drawgreater();
    else drawequal();
    
    for(int i=1; i<=row; i++) {
        for(int j=1; j<=col; j++) printf("%c", res[i][j]);
        printf("\n");
    }
    
    return;
}

int main() {
    pream();
    int T, caseno = 1;
    scanf("%d", &T);
    
    while(T--) {
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin>>a[i][j];
            }
        }
        
        for(int i=1; i<=col; i++) {
            cin>>a[row+1][i];
        }
        
        printf("Case %d:\n", caseno++);
        solve();
    }
    
    return 0;
}
