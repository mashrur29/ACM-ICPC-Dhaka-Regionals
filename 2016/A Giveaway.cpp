#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 111;
int n;
int a[30] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121};

bool is(int num) {
    for(int i=0; i<21; i++) {
        if(a[i] == num) return true;
    }
    return false;
}

int main() {
    int T, caseno = 1;
    
    while(scanf("%d", &n) == 1 && n) {
        if(is(n)) printf("Special\n");
        else printf("Ordinary\n");
    }
    
    return 0;
}
