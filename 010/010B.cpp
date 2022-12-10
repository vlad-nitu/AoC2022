#pragma once
#define NMAX 1001
#define ll long long

#include <bits/stdc++.h>

using namespace std;
ifstream f("010B.in");
ofstream g("010B.out");

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
int C = 0, V = 1;
ll sum = 0;
int sprite = 0;
string ans{};

int main() {

    while (getline(f, s)) {
        stringstream ss(s);
        string cmd, val;
        ss >> cmd;


        if (sprite - 1 <= ans.size() && ans.size() <= sprite + 1)
            ans.push_back('#');
        else
            ans.push_back('.');

        if (C % 40 == 0 && C != 0) {
            g << ans << '\n';
            sprite = 0;
            ans.clear();
        }

        if (cmd == "noop") {
            C += 1;
        } else {
            ss >> val;
            C += 1;


            if (C % 40 == 0 && C != 0)  {
                g << ans << '\n';
                sprite = 0;
                ans.clear();
            }

            if (sprite - 1 <= ans.size() && ans.size() <= sprite + 1)
                ans.push_back('#');
            else
                ans.push_back('.');

            C += 1;
            sprite += stoi(val);
        }

    }

    if (C % 40 == 0 && C != 0) {
        g << ans << '\n';
        sprite = 0;
        ans.clear();
    }

    return 0;
}