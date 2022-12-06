#pragma once
#define NMAX 2002

#include <bits/stdc++.h>

using namespace std;
ifstream f("06B.in");
ofstream g("06B.out");

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

int main() {
    unordered_map<char, int> map;
    unordered_set<char> set;
    f >> s;

    for (char &ch: s.substr(0, 13)) {
        map[ch]++;
        set.insert(ch);
    }

    for (int i = 13; i < s.size(); ++i) {

        map[s[i]]++;
        set.insert(s[i]);

        if (set.size() == 14) {
            g << i + 1 << '\n';
            break;
        }

        map[s[i-13]] --;
        if (map[s[i-13]] == 0)
            set.erase(s[i-13]);

    }
    return 0;
}