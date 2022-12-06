#pragma once
#define NMAX 2002
#include <bits/stdc++.h>
using namespace std;
ifstream f ("06A.in");
ofstream g ("06A.out");

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
string s;
int main()
{
    std::queue<char> q;
    f >> s;

    string x;

    for (int i = 0; i < s.size(); ++i){

        x = s.substr(i, 14);
        unordered_set<char> set;
        for (char a: x)
            set.insert(a);

        if (set.size() == x.size())
        {
            g << i + 14;
            break;
        }
        x.clear();

    }
    return 0;
}