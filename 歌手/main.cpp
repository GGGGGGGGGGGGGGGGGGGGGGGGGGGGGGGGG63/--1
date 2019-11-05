#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
#define inf 0x3f3f3f3f
#define LL long long
int main()
{
    int n,i,j,x;
    string ss;
    stack<int> s;
    vector<int> v;
    vector<int>::iterator it;
    cin>>n;
    while(n--)
    {
        cin>>ss;
        if(ss=="Pop")
        {
            if(s.empty())
                cout<<"Invalid"<<endl;
            else
            {
                cout<<s.top()<<endl;
                it = lower_bound(v.begin(),v.end(),s.top());
                v.erase(it);
                s.pop();
            }
        }
        else if(ss=="PeekMedian")
        {
            if(s.empty())
                cout<<"Invalid"<<endl;
            else
            {
                cout<<v[(s.size()-1)/2]<<endl;
            }
        }
        else
        {
            cin>>x;
            s.push(x);
            it = lower_bound(v.begin(),v.end(),x);
            v.insert(it,x);
        }
    }
    
}
