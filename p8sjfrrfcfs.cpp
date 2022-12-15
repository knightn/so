//--fcfs
#include <iostream>
using namespace std;
int main()
{
cout<<"--FCFS Scheduling Algorithm--\n";
int turn =0, n,wait,r=0,s=0,w=0,t=0;
cout<<"\nEnter the no. of Processor:- ";
cin>>n;
cout<<endl;
int b[n];
for(int i=0;i<n;i++)
{
cout<<"\nBurst Time for Process P"<<i+1<<" : ";
cin>>b[i];
}
cout<<"\nWaiting time for Process P1 = 0 ms";
for(int i=1;i<n;i++)
{
r=r+b[i-1];
cout<<"\nWaiting time for Process P"<<i+1<<" = "<<r<<"ms";
t=t+r;
}
for(int i=0;i<n;i++)
{
s=s+b[i];
cout<<"\nTurnaround Time for Process P"<<i+1<<" = "<<s<<"ms";
w=w+s;
}
cout<<"\nAverage Turnaround time :-"<<w/n<<"ms";
cout<<"\nAverage Waiting time :-"<<t/n<<"ms";
}
//sjf
##include <iostream>
using namespace std;
int main()
{
cout<<"--SJF Scheduling Algorithm--\n";
int n,tmp,tt=0,min,d,i,j;
float at=0,aw=0,st=0,sw=0;
cout<<"\nEnter no. of processes:- ";
cin>>n;
int a[n],b[n],e[n],t[n],w[n];
for (i=0;i<n;i++)
{
cout<<"Arrival time of P"<<i+1<<":- ";
cin>>a[i];
}
for (i=0;i<n;i++)
{
cout<<"Enter Burst time of P"<<i+1<<":- ";
cin>>b[i];
}
for (i=0;i<n;i++)
{
for (j=i+1;j<n;j++)
{
if (b[i]>b[j])
{
swap(a[i],a[j]);
swap(b[i],b[j]);
}
}
}
min=a[0];
for (i=0;i<n;i++)
{
if (min>a[i])
{
Page | 11
min=a[i];
d=i;
}
}
tt=min;
e[d]=tt+b[d];
tt=e[d];
for (i=0;i<n;i++)
{
if (a[i]!=min)
{
e[i]=b[i]+tt;
tt=e[i];
}
}
for (i=0;i<n;i++)
{
t[i]=e[i]-a[i];
st=st+t[i];
w[i]=t[i]-b[i];
sw=sw+w[i];
}
at=st/n;
aw=sw/n;
cout<<"Process Arrival-time(ms) Burst-time(ms) Waiting-time(ms)
Turnaround-time(ms)\n";
for(i=0;i<n;i++)
{
cout<<"P"<<i+1<<" "<<a[i]<<" "<<b[i]<<"
"<<w[i]<<" "<<t[i]<<endl;
}
cout<<"\nAverage Waiting Time= "<<aw<<"\nAverage Turnaround Time=
"<<at;
}
//roundrobin
#include <iostream>
using namespace std;
void Wait(int p[],int n,int b[], int w[], int q)
{
int bt[n];
for (int i = 0; i<n; i++)
bt[i] = b[i];
int t = 0;
while(1)
{
bool done = true;
for (int i=0;i<n;i++)
{
if (bt[i]>0)
{
done=false;
if (bt[i]>q)
{
t += q;
bt[i] -= q;
}
else
{
t=t+bt[i];
w[i]=t-b[i];
bt[i]=0;
}
} }
if (done == true)
break;
} }
void Turn(int p[],int n,int b[],int w[],int t[])
{
for (int i=0;i<n;i++)
t[i] = b[i]+w[i];
}
void avg(int p[],int n,int b[],int q)
{
int w[n],t[n],total_w=0,total_t=0;
Wait(p,n,b,w,q);
Turn(p,n,b,w,t);
cout<<" Processes "<<" Burst time "<<" Waiting time "<<" Turn
around time\n";
for (int i=0;i<n;i++)
{
total_w=total_w+w[i];
total_t=total_t+t[i];
cout<<" "<<i+1<<"\t\t"<<b[i]<<"\t "<<w[i]<<"\t\t "<<t[i]<<endl;
}
cout<<"Average waiting time = "<<(float)total_w/(float)n;
cout<<"\nAverage turn around time = "<<(float)total_t/(float)n;
}
int main()
{
cout<<"--Round Robin Scheduling Algorithm--\n";
int n;
cout<<"\nEnter the no. of processes:- ";
cin>>n;
int p[n];
for (int i=0;i<n;i++)
{
p[i]=i+1;
}
int b[n];
for (int i=0;i<n;i++)
{
cout<<"\nEnter the Burst Time for P"<<i+1<<":- ";
cin>>b[i];
}
int q;
cout<<"\nEnter the Time Quantum:- ";
cin>>q;
avg(p,n,b,q);
return 0;
}
