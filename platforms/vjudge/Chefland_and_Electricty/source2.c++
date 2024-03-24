/**
	*	author:		beyondmagic, paulo
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

#define ENERGISED '1'

int main()
{
	ios::sync_with_stdio(false);
	int t;

	long long int n,i,j,pos;
	string s;
	cin >> t;

	while (t--)
	{
		cin>>n;
		cin>>s;
		vector<long long> X(n);
		for (auto &x : X)
			cin >> x;

		//cout<<"input complete"<<endl;
		i=0;pos=0;
		//cout<<"First char-"<<s[0]<<endl;
		long long int totalcount=0;
		int flag=0;
		//cout<<"i="<<i<<"\ns.length()="<<s.length()<<endl;
		while(i < s.length() )
		{
		   if(s[i]=='1'){
				pos=i;
				if(pos>0 && flag==0){
					for(j=pos;j>0;j--){
						totalcount+=x[j]-x[j-1];
						flag=1;
					}
				}
				flag=1;
				j=i;
				while(s[j+1] != '1' && j < s.length() - 1){
					totalcount+=x[j+1]-x[j];
					j++;
				}
				if (i != j)
					i=j;
				else
					i++;
		   }
		   else i++;
		}
		cout << totalcount << endl;
	}
}
