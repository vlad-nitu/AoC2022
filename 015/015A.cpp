#define NMAX 1e9
#define ll long long
#define mkp make_pair

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
ifstream f("015A.in");
ofstream g("015A.out");


struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }

};


string s, token;
int sx, sy, bx, by;
int Y = 2000000;

void parseLine() {
    stringstream ss(s);

    ss >> token;
    ss >> token;
    ss >> token;

    token = token.substr(2, token.size() - 3);
    sx = stoi(token);
    ss >> token;
    token = token.substr(2, token.size() - 3);
    sy = stoi(token);

    ss >> token >> token >> token >> token;

    ss >> token;
    token = token.substr(2, token.size() - 3);
    bx = stoi(token);
    ss >> token;
    token = token.substr(2, token.size() - 2);
    by = stoi(token);

    // dbg(sx, sy, bx, by);
}

int main() {

    unordered_set<pair<int, int>, hash_pair> v;

    while (getline(f, s)) {
        parseLine();

        int distance = abs(sx - bx) + abs(sy - by); // Manhattan
        for (int x = sx + 1; x <= sx + distance; ++x)
            for (int y = sy + 1; y <= sy + distance; ++sy)
                if (abs(sx - x) + abs(sy - y) <= distance && sy == Y)
                    v.insert({x, y});

        v.erase({bx, by});
    }

    g << v.size() << '\n';
    return 0;
}