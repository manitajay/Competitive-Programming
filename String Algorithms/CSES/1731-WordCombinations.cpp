// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain , give me another chacne to grow up once again....

// sab moh maya hai....

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define mod 1000000007

struct TrieNode{
    struct TrieNode *child[26];
    bool isend;

    TrieNode(){
        isend=false;

        for(ll i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};



void insert(string s,struct TrieNode *root){
    struct TrieNode *curr= root;

    ll n=s.length();
    for(ll i=0;i<n;i++){
        ll in=s[i]-'a';
        if(curr->child[in]==NULL){
            curr->child[in]=new TrieNode();
        }

        curr=curr->child[in];

    }

    curr->isend=true;
}




int main(){
    
    string s;
    cin>>s;
    ll n=s.length();

    ll k;
    cin>>k;
    struct TrieNode *root = new TrieNode();
    for(ll i=0;i<k;i++){
        string dic;
        cin>>dic;
        reverse(dic.begin(),dic.end());
        insert(dic,root);


    }


    vector<ll> dp(n+1,0);
    dp[0]=1;

    for(ll i=1;i<=n;i++){
        string ss="";
        struct TrieNode *curr =root;

        for(ll j=i;j>=1;j--){
            char ch=s[j-1];
            // cout<<ss<<endl;
            // cout<<ch<<endl;

            ll in=ch-'a';

            if(curr->child[in]==NULL){
                break;
            }
            curr=curr->child[in];
            if(curr->isend){
                // cout<<"YES"<<endl;
                // cout<<j<<endl;
                dp[i]+=dp[j-1];
                dp[i]%=mod;
            }


        }


    }
    cout<<dp[n]<<endl;
}
