// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5075

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxi = 1000001;
int n, vis[maxi], taken[maxi], tkn[maxi];
vector<int> adj[maxi];
vector<int> primes;

inline void reset() {
    for(int i=0; i<maxi; i++) {
        adj[i].clear();
        vis[i] = 0;
        tkn[i] = 0;
    }
}

inline void sieve() {
    memset(taken, 0, sizeof(taken));
    int lim = sqrt(1000000*1.0);

    primes.push_back(2);
    for(int i = 2; i < maxi; i += 2) taken[i] = 1;

    for(int i = 3; i <= lim; i += 2) {
        if(!taken[i]) {
            for(int j = i*i; j < maxi; j += 2*i) {
                taken[j] = 1;
            }
        }
    }

    for(int i = 3; i < maxi; i += 2) {
        if(!taken[i]) primes.push_back(i);
    }

}

inline void construct(int num) {
    int lim = sqrt(maxi), u = num;

    for(int i=0; primes[i] <= lim && i<primes.size(); i++) {
        int val = primes[i];
        if(num % val == 0) {
            adj[u].push_back(val);
            adj[val].push_back(u);
        }
        while(num % val == 0) num /= val;
        lim = sqrt(num);
    }

    if(num > 1) {
        adj[u].push_back(num);
        adj[num].push_back(u);
    }
}

void dfs(int node) {
    vis[node] = 1;

    for(int i=0; i<adj[node].size(); i++) {
        int u = adj[node][i];
        if(!vis[u]) dfs(u);
    }

}

inline void test(vector<int> given) {
    cout<<" *********** Test Program ************ "<<endl;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(__gcd(given[i], given[j]) > 1) cout<<given[i]<<" "<<given[j]<<endl;
        }
    }

    cout<<endl;
}

int main() {
    sieve();
    int T, caseno = 1;
    scanf("%d", &T);

    while(T--) {
        reset();
        vector<int> given;
        int cmp = 0, one = 0;
        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            int temp;
            scanf("%d", &temp);
            if(temp == 1) one++;
            if(!tkn[temp]) {
                construct(temp);
                given.push_back(temp);
            }
            tkn[temp] = 1;
        }

        //test(given);

        for(int i=0; i<given.size(); i++) {
            if(!vis[given[i]]) {
                if(given[i]==1) cmp += one;
                else cmp++;
                dfs(given[i]);
            }
        }

        printf("Case %d: %d\n", caseno++, cmp);
    }

    return 0;
}

/*

1
5
1 1 1 2 4

-> 4

*/
