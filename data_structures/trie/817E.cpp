#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

int MAX_BIT = 31;

class trieNode {
public:
    int count = 0;
    trieNode* next[2];
};

void insert(trieNode* head, int val, int type){
    trieNode* cur = head;
    for(int i=MAX_BIT;i>=0;i--){
        int b = (val>>i)&1;

        if(cur->next[b] == NULL){
            cur->next[b] = new trieNode();
        }
        cur = cur->next[b];

        cur->count += type;
    }
}

int calc(trieNode* head, int val, int xor_comp){
    trieNode* cur = head;
    int ans = 0;
    for(int i=MAX_BIT;i>=0;i--){
        int xor_bit = (xor_comp>>i)&1;
        int mine_bit = (val>>i)&1;

        if(xor_bit == 0){
            if(mine_bit == 0){
                cur = cur->next[0];
            } else {
                cur = cur->next[1];
            }
        } else {
            if(mine_bit == 0){
                if(cur->next[0] != NULL){
                    ans += cur->next[0]->count;
                }
                cur = cur->next[1];
            } else {
                if(cur->next[1] != NULL){
                    ans += cur->next[1]->count;
                }
                cur = cur->next[0];
            }
        }


        if(cur == NULL) break;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    trieNode* head = new trieNode();

    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            insert(head, x, 1);
        } else if(type == 2){
            int x; cin >> x;
            insert(head, x, -1);
        } else {
            int val, xor_comp; cin >> val >> xor_comp;
            cout << calc(head, val, xor_comp) << "\n";
        }
    }


}
