#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}

int range(int dd, int mm, int yy, int qy) {
    int ret = 0;
    for(int i = yy; i<=qy; i++) {
        if(isLeapYear(i)) ret++;
    }
    return ret-1;
}

int main() {
    int T, caseno = 1;
    
    scanf("%d", &T);
    
    while(T--) {
        int dd, mm, yy, qy;
        scanf("%d %d %d %d", &dd, &mm, &yy, &qy);
        
        if(dd==29 && mm==2) printf("Case %d: %d\n", caseno++, range(dd, mm, yy, qy));
        else printf("Case %d: %d\n", caseno++, abs(yy - qy));
    }
    
    return 0;
}
