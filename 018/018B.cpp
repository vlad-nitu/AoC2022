#pragma once
#define NMAX 1001
#define ll long long
#define mkp make_pair
#define mkt make_tuple

#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V, typename W>
void __print(const std::tuple<T, V, W> &x) {cerr << '{'; __print(std::get<0>(x)); cerr << ','; __print(std::get<1>(x)); cerr << ','; __print(std::get<2>(x)); cerr << '}';}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

ifstream f("018B.in");
ofstream g("018B.out");

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

struct hash_tuple{
    size_t operator()(const tuple<int,int, int>&x)const{
        return hash<long long>()(((long long)std::get<1>(x)^(((long long)std::get<2>(x))^(long long)std::get<2>(x)))<<32);
    }
};

int x, y, z;
ll ans = 0;
string line, token;
int maxX, maxY, maxZ;
unordered_set<std::tuple<int, int, int>, hash_tuple> SET;
unordered_set<std::tuple<int, int, int>, hash_tuple> vis;

bool DFS(const std::tuple<int, int, int>& point) {

    auto [x, y, z] = point;
    vis.insert(point);
    dbg(point);

    if (x == 0 || y == 0 || z == 0 || x == 30 || y == 30 || z == 30)
        return true;

    bool canGetOut = false;

    if (SET.find(mkt(x-1, y, z)) == SET.end() && vis.find(mkt(x-1, y, z)) == vis.end())
        canGetOut |= DFS(mkt(x-1, y, z));

    if (SET.find(mkt(x+1, y, z)) == SET.end() && vis.find(mkt(x+1, y, z)) == vis.end())
        canGetOut |= DFS(mkt(x+1, y, z));

    if (SET.find(mkt(x, y-1, z)) == SET.end() && vis.find(mkt(x, y-1, z)) == vis.end())
        canGetOut |= DFS(mkt(x, y-1, z));

    if (SET.find(mkt(x, y+1, z)) == SET.end() && vis.find(mkt(x, y+1, z)) == vis.end())
        canGetOut |= DFS(mkt(x, y+1, z));

    if (SET.find(mkt(x, y, z-1)) == SET.end() && vis.find(mkt(x, y, z-1)) == vis.end())
        canGetOut |= DFS(mkt(x, y, z-1));

    if (SET.find(mkt(x, y, z+1)) == SET.end() && vis.find(mkt(x, y, z+1)) == vis.end())
        canGetOut |= DFS(mkt(x, y, z+1));

    return canGetOut;

}

int main() {

    while (getline(f, line)) {
        stringstream ss(line);
        getline(ss, token, ',');
        x = stoi(token);

        getline(ss, token, ',');
        y = stoi(token);

        getline(ss, token, ',');
        z = stoi(token);

        auto point = make_tuple(x, y, z);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
        maxZ = max(maxZ, z);
        SET.insert(point);
    }

    dbg(SET.size());

    for (const std::tuple<int, int, int>& point: SET)
    {
        vis.clear();

        auto [x, y, z] = point;

        if (DFS(point))
            ans ++;
    }

    g << ans << '\n';
    return 0;
}