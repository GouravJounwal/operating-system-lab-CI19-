#include <iostream>
#include <cmath>
using namespace std;

int main()
{
cout<<"Disk Scheduling\n";
int ar[8]={65,5,14,89,20,90,72,7},n=8;
int cur=53,d,td=0,i;
cout<<"\n1. FCFS:";
for(i=0;i<n;i++)
{
d=abs(cur-ar[i]);
td=td+d;
cur=ar[i];
}
cout<<"\tTotal Distance: "<<td;
cout<<"\n2. SSTF:";
int br[9]={5,7,14,20,53,65,72,89,90},l,r,j,pre,nex,li,ri;
td=0;
int k=4;
for(i=0;i<n;i++)
{
for(j=k-1;j>=0;j--)
{
if(br[j]>0)
    {pre=br[j];
    li=j;
    break;}
}
for(j=k+1;j<=9;j++)
{
if(k==8)
    {
        nex=1000;
        break;}
else
    if(br[j]>0)
    {nex=br[j];
    ri=j;
    break;}
}
l=abs(br[k]-pre);
r=abs(nex-br[k]);
br[k]=-1;
if(l<r)
    {k=li;
    d=l;}
else
    {k=ri;
    d=r;}
td=td+d;
}
cout<<"\tTotal Distance: "<<td;
cout<<"\n3. SCAN: ";
int cr[9]={5,7,14,20,53,65,72,89,90};
k=4;
l=abs(cr[k]-cr[k-1]);
r=abs(cr[k+1]-cr[k]);
if(l<r)
    td=cr[k]+199;
else
    td=199+(199-cr[k]);
cout<<"\tTotal Distance: "<<td;
cout<<"\n4. CSCAN: ";
k=4;
l=abs(cr[k]-cr[k-1]);
r=abs(cr[k+1]-cr[k]);
if(l>r)
    td=(cr[k-1])+(199-cr[k]);
else
    td=(199-cr[k+1])+cr[k];
cout<<"\tTotal Distance: "<<td;

cout<<"\n5. LOOK: ";
k=4;
l=abs(cr[k]-cr[k-1]);
r=abs(cr[k+1]-cr[k]);
if(l<r)
    td=(cr[k]-cr[0])+(cr[8]-cr[0]);
else
    td=(cr[8]-cr[k])+(cr[8]-cr[0]);
cout<<"\tTotal Distance: "<<td;

cout<<"\n6. CLOOK: ";
k=4;
l=abs(cr[k]-cr[k-1]);
r=abs(cr[k+1]-cr[k]);
if(l<r)
    td=(cr[k]-cr[0])+(cr[8]-cr[k+1]);
else
    td=(cr[8]-cr[k])+(cr[k-1]-cr[0]);
cout<<"\tTotal Distance: "<<td;
cout<<"\n";
return 0;
}


