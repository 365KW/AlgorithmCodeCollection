#include<bits/stdc++.h>

using namespace std;

int n;
string a;

bool cmp (const string& a, const string& b) {
    return (a+b > b+a);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)cout<<a[i];
    return 0;
}
