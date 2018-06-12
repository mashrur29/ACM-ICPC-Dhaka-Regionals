#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 11;
int n;
int a[maxi];
int taken[maxi];
std::vector<int> v;

inline void pre(int num) {
    while(num) {
        if(!taken[num%10]) v.push_back(num%10);
        taken[num%10] = 1;
        num /= 10;
    }
}

bool existing(int num) {
    for(int i=0; i<10; i++) {
        int x = num - i;
        if(x>=0 && x<10 && x != i && taken[x] && taken[i]) return true;
    }
    return false;
}

int main() {
    int caseno = 1;
    
    while(scanf("%d", &n) == 1 && n) {
        memset(taken, 0, sizeof(taken));
        v.clear();

        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        for(int i=0; i<n; i++) {
            if(a[i] > 17 || a[i] < 10) pre(a[i]);
        }
        
        for(int i=0; i<n; i++) {
            if(a[i] >= 10 && a[i] <= 17) {
                if(existing(a[i])) a[i] = 19;
            }
        }
        
        int mxx = INT_MIN;
        
        for(int i=0; i<n; i++) {
            if(a[i] >= 10 && a[i] <= 17) {
                mxx = max(mxx, a[i]);
            }
        }
        
        if(mxx == 17 || mxx == 16) mxx = 9;
        else if(mxx == 15 || mxx == 14) mxx = 8;
        else if(mxx == 13 || mxx == 12) mxx = 7;
        else if(mxx != INT_MIN) mxx = 6;
        
        if(mxx != INT_MIN) {
            taken[mxx] = 1;
            for(int i=0; i<n; i++) {
                if(a[i] >= 10 && a[i] <= 17) {
                    int x = a[i] - mxx;
                    taken[x] = 1;
                }
            }
        }
        
        cout<<"Case "<<caseno++<<": ";
        for(int i=9; i>=0; i--) {
            if(taken[i]) cout<<i;
        }
        cout<<endl;
        
    }

    return 0;
}
