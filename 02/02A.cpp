//
// Created by Vlad Nitu on 01.12.2022.
//
#pragma once
#define NMAX 2002
#include <bits/stdc++.h>
using namespace std;
ifstream f ("02A.in");
ofstream g ("02A.out");

int ans;
char opp, me;
string s;

int main() {

   unordered_map<char, char> map;
   map['A'] = 'X'; map['B'] = 'Y'; map['C'] = 'Z';
   while (f >> opp >> me) {

       char conv = me - 'X' + 'A';
       ans += me - 'X' + 1;

       char opponent_we_beat = conv + 2;
       if (opponent_we_beat > 'C')
           opponent_we_beat -= 3;

       if (conv == opp) // tie
           ans += 3;
       else if (opponent_we_beat == opp) // win
           ans += 6;

   }
   g << ans << '\n';
    return 0;
}