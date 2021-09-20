#include<iostream>
using namespace std;
int main() {
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
	cout<<"Enter total number of processes(maximum 20):";
	cin>>n;
	cout<<"Enter Process Burst Time"<<endl;
	for (i=0;i<n;i++) {
		cout<<"P["<<i+1<<"]:";
		cin>>bt[i];
	}
	wt[0]=0;
	
	for (i=1;i<n;i++) {
		wt[i]=0;
		for (j=0;j<i;j++)
		            wt[i]+=bt[j];
	}

	for (i=0;i<n;i++) {
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i];
	}
	avwt/=i;
	avtat/=i;
	cout<<"Average Waiting Time:"<<avwt<<endl;
	cout<<"Average Turnaround Time:"<<avtat;
	return 0;
}
