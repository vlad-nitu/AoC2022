#pragma once
#define NMAX 1001
#define ll long long

#include <bits/stdc++.h>

using namespace std;
ifstream f("010A.in");
ofstream g("010A.out");

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

string s;
int C = 1, V = 1;
unordered_set<int> m;
ll sum = 0;

int main() {
    unordered_set<int> pos;
    pos.insert(20);
    pos.insert(60);
    pos.insert(100);
    pos.insert(140);
    pos.insert(180);
    pos.insert(220);

    while (getline(f, s)) {
        stringstream ss(s);
        string cmd, val;
        ss >> cmd;


        if (pos.find(C) != pos.end()) {
            sum += C * V;
//            g << C << ' ' << V << '\n';
        }


        // g << sum << '\n';

        if (cmd == "noop") {
            C += 1;
        } else {
            ss >> val;
            C += 1;
            if (pos.find(C) != pos.end()) {
                sum += C * V;
//                g << C << ' ' << V << '\n';
            }
            C += 1;
            V += stoi(val);
        }

    }


    g << sum << '\n';
    return 0;
}