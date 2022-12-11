#pragma once
#define NMAX 1001
#define ll long long

#include <bits/stdc++.h>

using namespace std;
ifstream f("011A.in");
ofstream g("011A.out");

struct monk {
    vector<int> holds;
    string op;
    int test;
    int true_to;
    int false_to;

};

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

int x;
string s;
vector<monk> v;
ll MOD = 1;

int main() {

    while (getline(f, s)) {

        monk curr;

        getline(f, s);

        stringstream ss(s);
        string word;
        while (ss >> word) {
            if (word[word.size() - 1] == ',')
                word = word.substr(0, word.size() - 1);
            curr.holds.push_back(stoi(word));
        }

        getline(f, s);
        stringstream ss_op(s);
        ss_op >> word >> word;
        string first, operation, second;
        ss_op >> first >> operation >> second;

        if (second != "old")
            curr.op = operation + " " + second;
        else
            curr.op = "* 2";

        getline(f, s);
        stringstream ss1(s);
        ss1 >> word;
        curr.test = stoi(word);

        MOD *= curr.test;

        getline(f, s);
        stringstream ss2(s);
        ss2 >> word;
        curr.true_to = stoi(word);

        getline(f, s);
        stringstream ss3(s);
        ss3 >> word;
        curr.false_to = stoi(word);

        v.push_back(curr);

        getline(f, s); // empty line
    }


//
//    for (int i = 0; i < v.size(); ++i) {
//        for (int j = 0; j < v[i].holds.size(); ++j)
//            g << v[i].holds[j] << ' ';
//        g << '\n';
//        g << v[i].op << '\n' << v[i].test << ' ' << v[i].true_to << ' ' << v[i].false_to;
//        g << '\n';
//    }

//for (int i = 0; i < v.size(); ++i) {
//        g << v[i].true_to << ' ' << v[i].false_to << '\n';
//    }

    vector<int> ans(v.size(), 0);
//    for (int i = 0; i < v.size(); ++i)
//        ans[i].second = i;




    for (int i = 0; i < 20; ++i) { // rounds

//        vector<vector<int>> new_holds(v.size());

            for (int k = 0; k < v.size(); ++k) {
                monk item = v[k];
                ans[k] += item.holds.size();
//                g << item.holds.size() << '\n';

               for (int j = 0; j < item.holds.size(); ++j) {

                   int curr = item.holds[j];
                   stringstream ss(item.op);
                   char oper;
                   int val;
                   ss >> oper >> val;

                   if (oper == '*')
                    curr = (curr * val) % MOD;
                   else if (oper == '+')
                   curr = (curr + val) % MOD;

                   curr = (curr / 3) % MOD;

                       if (curr % item.test == 0)
                           v[item.true_to].holds.push_back(curr);
                       else
                           v[item.false_to].holds.push_back(curr);

               }
               v[k].holds.clear();

            }

//            g << "After round " << i << ": ";
//        for (int k = 0; k < v.size(); ++k)
//            g << v[k].holds.size() << ' ';
//        g << '\n';



    }

//    for (int k = 0; k < v.size(); ++k)
//        g << v[k].holds.size() << ' ';


    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i)
        g << ans[i] << ' ';
    g << '\n';

    g << (ans[0]) * (ans[1]) << '\n';

    return 0;
}