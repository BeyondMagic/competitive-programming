#include<iostream>
#include <vector>

using namespace std;

using ll = long long;

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
		vector<long long> x(n);
		for(j=0;j<n;j++){
			cin>>x[j];
		}

		//cout<<"input complete"<<endl;
		i=0;pos=0;
		//cout<<"First char-"<<s[0]<<endl;
		long long int totalcount=0;
		int flag=0;
		//cout<<"i="<<i<<"\ns.length()="<<s.length()<<endl;
		while(i<ll(s.length())){
				//cout<<"while loop begin"<<endl;
		   if(s[i]=='1'){
				//cout<<"1 found. IF Satisfied"<<endl;
				pos=i;
				//cout<<"pos="<<pos<<endl;
				if(pos>0 && flag==0){
					for(j=pos;j>0;j--){
						//cout<<"pre-count in process"<<endl;
						totalcount+=x[j]-x[j-1];
						flag=1;
					}
					//cout<<"Totalcount after pre-count"<<totalcount<<endl;
				}
				flag=1;
				j=i;
				while(s[j+1]!='1' && j<ll(s.length())-1){
					//cout<<"AFTER-1 Count in progress"<<endl;
					totalcount+=x[j+1]-x[j];
					j++;
				}
				if(i!=j) i=j;
				else i++;
		   }
		   else i++;
		}
		cout<<totalcount<<endl;
	}
}
