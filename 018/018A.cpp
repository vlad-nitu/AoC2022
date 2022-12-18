#pragma once
#define NMAX 1001
#define ll long long

#include <bits/stdc++.h>

using namespace std;
ifstream f("018A.in");
ofstream g("018A.out");

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

int x, y, z;
bool a[40][40][40];
int ans = 0;
string line, token;
int main() {

    while (getline(f, line)) {
        stringstream ss(line);
        getline(ss, token, ',');
        x = stoi(token);

        getline(ss, token, ',');
        y = stoi(token);

        getline(ss, token, ',');
        z = stoi(token);

        a[x][y][z] = true;
        ans += 6;
        if (a[x-1][y][z])
            ans -= 2;
        if (a[x+1][y][z])
            ans -= 2;
        if (a[x][y-1][z])
            ans -= 2;
        if (a[x][y+1][z])
            ans -= 2;
        if (a[x][y][z-1])
            ans -= 2;
        if (a[x][y][z+1])
            ans -= 2;


    }

    g << ans << '\n';
    return 0;
}