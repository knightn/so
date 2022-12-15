#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;
int main()
{
cout<<"The Kernal Version:-\n";
system("cat/proc/sys/kernel/osrelease");
cout<<"\nThe CPU info:-\n";
system("cat/proc/cpuinfo |awk 'NR==3,NR==4{print}'\n");
return 0;
}
