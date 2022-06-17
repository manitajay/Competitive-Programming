// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    s+='*';
    ll c=1;
    ll mx=0;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            c++;
        }else{
            mx=max(mx,c);
            c=1;
        }
    }
    cout<<mx<<endl;
    return 0;
}
