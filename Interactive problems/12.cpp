// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....



/*
bascially the problem is about find out a string which length is <=1000 
we can perform 2 kind of queries

query1(i)--> which returns us the ith char of string,       no of queries we can ask <=26;
query2(l,r)--> which returns us no of distinct char between index [l,r],    no of queries we can ask<=6000;


case - I (char is occuring first time in string):-
now by looking at maximum no of queries we can assure that query one will ask for finding distinct element which does not occurs in the string before that index,
for ex- guess
now let's consider we have find out "gu" now we are on index 3 now we know that particular char does not exist before so we can use (query1);
but now que is how can we know that particular char exist or not before?
it's simple we can run query2(1,i+1) and maintain a variable which cnt distinct char, now if previous index 

cnt +1 == query2(l,i+1)
then we can say char is distinct and we can return;

Case-II: (char is occured before in string);
let's consider wrost case scenario, if all the 26 char exist before ith index in string then?
brute force:- we can just store every char 's last pos in array and sort it pos wise; and can iterate over array from first index , and when it gives no of distinct 
char is equal to no of (sz-j)+1 means that element is distinct and we can break at that index now can simply write the ans char as (j-1)th char;
but max no of queries will be more then 25000;
how to optimise?
just look at max no of queries constraint we can think about binary search?
can we? yes.


bcs pos array is sorted we can simply use binary search for finding first index on which that current char is distinct;

for binary search implementation you can look at code;





*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long



char query1(ll i){
    cout<<"? 1 "<<i<<endl;
    char ch;
    cin>>ch;
    return ch;
}



ll query2(ll l,ll r){
    cout<<"? 2 "<<l<<" "<<r<<endl;
    ll ch;
    cin>>ch;
    return ch;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        ll n;
        cin>>n;

        string s="";
        vector<ll> pos(26,0);
        char ch=query1(1);
        s+=ch;

        ll val=(s[0]-'a');
        pos[val]=1;
        vector<pair<ll,ll>> pr;

        for(ll i=1;i<n;i++){
            pr.clear();
            for(ll j=0;j<26;j++){
                if(pos[j]!=0){
                    pr.push_back({pos[j],j});
                }
            }


            ll sz=pr.size();
            sort(pr.begin(),pr.end());
            ll val=query2(1,i+1);

            if(val==sz+1){
                char cc=query1(i+1);
                s+=cc;
                ll v=s[i]-'a';
                pos[v]=i+1;
                continue;
            }


            ll l=0,r=sz-1;
            ll ans=0;
            while(r>=l){
                ll mid=(l+r)/2; 
                ll vll=query2(pr[mid].first,i+1);

                if(vll==(sz-mid+1)){
                    r=mid-1;
                }else{
                    ans=mid;
                    l=mid+1;
                }
            }
            s+=('a'+pr[ans].second);
            
            ll v=s[i]-'a';
            pos[v]=i+1;

            

        }
        cout<<"! "<<s<<endl;


    
    return 0;

}
