#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[110];
	for(int i=1;i<=n;i++) cin>>arr[i];
	int L,R;
	cin>>L>>R;
	int ans=0;
	for(int i=L;i<=R;i++) ans+=arr[i];
	
	cout<<ans<<endl;
	return 0;
}
