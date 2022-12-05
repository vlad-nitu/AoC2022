//
// Created by Vlad Nitu on 04.12.2022.
//
#pragma once
#define NMAX 2002
#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stack>
using namespace std;
ifstream f ("05A.in");
ofstream g ("05A.out");

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
string s;
stringstream ss;
int main() {


    vector<deque<char>> v(10);
    int line = 0;
    int Max = -1;

    while (getline(f, s)){
        if (!s.empty() && s[1] != '1') {
            line ++;
            int el = 0;
            for (int i = 0; i < s.size(); i += 4) {
                el ++;
                string x = s.substr(i, i + 4);
                if (x.empty())
                    continue;
                else if (s[i+1] != ' '){
                    v[el].push_front(s[i + 1]);
                    Max = max(el, Max);
                }

            }
        }
        else
            break;

    }







    while (getline(f, s)){
        if (!s.empty()) {

            stringstream ss(s);
            string first, second, third;
            string token;
            ss >> token;
            ss >> first;
            int count = stoi(first);
            ss >> token;
            ss >> second;
            int from = stoi(second);
            ss >> token;
            ss >> third;
            int to = stoi(third);

            for (int i = 0; i < count; ++i) {
                char el = v[from].back();
                v[from].pop_back();
                v[to].push_back(el);
            }

        }

    }

    for (int i = 1; i <= Max; ++i)
        g << v[i].back();

    return 0;
}