#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ass 1e18
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(x) cout << #x << ": " << x << endl;
#define debug2(x,y) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<< endl;
#define debug3(x,y,z) cout<<#x<<": "<< x<< ", "<< #y<< ": "<< y<<" "<<#z<<" : "<<z<< endl;
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
string str;
struct link
{
    struct link* c[28];
    int end;
};
typedef struct link node;

node* newnode(ll n)
{
    node *head=(node *)malloc(sizeof(node));
    head->c[n]=NULL;
    head->end=0;
    return head;
}

void insert(node* head,ll x)
{
    if(x==str.size())
    {
        head->end=1;
        return ;
    }
    ll t=str[x]-'a';
    if(head->c[t]==NULL)
        head->c[t]=newnode(t);
    insert(head->c[t],x+1);
}

ll find(node* head,ll x)
{
    ll t=str[x]-'a';
    if(x==str.size())
    {
        if(head->end==1)
            return 1;
        return 0;
    }
    if(head->c[t]==NULL)
        return 0;
    return find(head->c[t],x+1);
}

int main()
{
    boost
    ll i,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        node* head=newnode(26);
        for(i=1;i<=n;i++)
        {
            cin>>str;
            insert(head,0);
        }
        cin>>str;
        if(find(head,0))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }    
    return 0;
}