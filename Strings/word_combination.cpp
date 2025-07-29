#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int K = 26;
struct node{
    vector<node*> next;
    int en = 0;
    node() : next(K, nullptr) {}
    void insert(const string& s) {
        node* cur = this;
        for(char c : s) {
            int i = c - 'a';
            if(cur->next[i] == nullptr) {
                cur->next[i] = new node();
            }
            cur = cur->next[i];
        }
        cur->en++;
    }
};
