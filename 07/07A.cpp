#pragma once
#define NMAX 2002
#include <bits/stdc++.h>
using namespace std;
ifstream f ("07A.in");
ofstream g ("07A.out");

int main();
long long updateScore(string curr_dir);

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

int x;
string s, first, second, child;
string curr_dir;
std::unordered_map<string, long long> score;
std::unordered_map <string, vector<string>> G;
std::unordered_map<string, string> parent;
long long ans = 0;

 long long updateScore(string curr_dir) {

        vector<string>& children = G[curr_dir];
        if (children.empty()) {
            return score[curr_dir];
        }

        for (string& child: children)
        {
            long long upd = updateScore(child);
            if (score[curr_dir] + upd > 100000)
            {
                score[curr_dir] = 100001;
                continue;
            }
            else
                score[curr_dir] += upd;

        }

        return score[curr_dir];
}


int main() {

    while (getline(f, s)){
        stringstream ss(s);
        ss >> first;
        if (first == "$") // cmd
        {
            ss >> second;
            if (second == "cd")
            {
                ss >> child;
                if (child == "..")
                    curr_dir = parent[curr_dir];
                else
                    curr_dir = child;
            }

        }
        else {
            ss >> second;
            if (first == "dir")
                G[curr_dir].push_back(second);
            else {
                G[curr_dir].push_back(second);
                score[second] += stol(first);
            }
        }
    }


    string curr_dir = "/";
    updateScore(curr_dir);

//    for (const auto& [k, v]: score)
//        g << k << ' ' << v << '\n';

    for (const auto& [k, v]: score)
        if (v >= 0 && !G[k].empty())
            ans += v;

    g << ans << '\n';
    return 0;
}
