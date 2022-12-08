#pragma once
#define NMAX 1001
#include <bits/stdc++.h>

using namespace std;
ifstream f("08B.in");
ofstream g("08B.out");

struct hash_pair {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }

};

int x, N, M;
long long curr, ans = -1;
string s;
bool vis[NMAX][NMAX];
vector<vector<int>> a;
const vector<int> dx{-1,1,0,0};
const vector<int> dy{0,0,-1,1};


bool valid (int i, int j) {

    return (i >= 0 && i < N && j >= 0 && j < M);
}

bool onEdge (int i, int j) {
    return (i == 0 || i == N - 1 || j == 0 || j == M - 1);
}

long long DFS (vector<vector<int>>& a, int i, int j) {

    if (onEdge(i, j))
        return 0;

   long long l,r,t,d;
   l = r = t = d = 0;

   int p = j+1;
   while (valid(i, p) && a[i][p] < a[i][j]) {
       p++;
   }

   if (!valid(i, p))
       p --;
   l = p - j;

    p = j-1;
    while (valid(i, p) && a[i][p] < a[i][j]) {
        p --;
    }
    if (!valid(i, p))
        p ++;
    r = j - p;

    p = i+1;
    while (valid(p, j) && a[p][j] < a[i][j]) {
        p ++;
    }
    if (!valid(p, j))
        p --;
    d = p - i;

    p = i-1;
    while (valid(p, j) && a[p][j] < a[i][j]) {
            p --;
        }
    if (!valid(p, j))
        p ++;
    t = i - p;

   return l * r * t * d;

}

int main() {

    N = 99;
    M = 99;

    a = vector<vector<int>>(N, vector<int>(M));
    int i = 0;
    while (f >> s) {
        int j = 0;
        for (char& ch: s)
            a[i][j++] = ch - '0';

        i ++;
    }


//    for (int i = 0; i < N; ++i){
//        for (int j = 0; j < M; ++j)
//            g << a[i][j];
//        g << '\n';
//    }


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            curr = DFS(a, i, j);
            ans = max(ans, curr);
        }

//        // reset(vis);
//        for (int i = 0; i < N; ++i)
//            for (int j = 0; j < M; ++j)
//                vis[i][j] = false;
    }


    g << ans << '\n';

    return 0;
}