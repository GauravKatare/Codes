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

node* newnode()
{
    node *head=(node *)malloc(sizeof(node));
    head->c[0]=NULL;head->c[1]=NULL;
    return head;
}

void insert(node* head,int nums){
    for(int i=31;i>=0;i--){
        int a=((nums>>i)&1);
        if(head->c[a]==NULL)
            head->c[a]=newnode();
        head=head->c[a];
    }
}

int finds(node *head,int x,int m,int ind,int val){
    if(m<val)
        return -1;
    if(ind==-1)
        return x^val;
    int a=(x>>ind)&1;
    int ans1=-1,ans2=-1;
    if(head->c[1-a]!=NULL){
        ans2=finds(head->c[1-a],x,m,ind-1,(val|(1-a)<<ind));
        if(ans2>=0)
            return ans2;
    }
    if(head->c[a]!=NULL){
        ans1=finds(head->c[a],x,m,ind-1,val|(a<<ind));
        if(ans1>=0)
            return ans1;
    }
    return max(ans1,ans2);
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