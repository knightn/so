#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
using namespace std;
int main(int argc,char*argv[])
{
struct stat s;
if(argc<2){
cout<<"\nEnter the filename:-\n";
}
for(int i=1;i<argc;i++)
{
cout<<"File:- "<<argv[i]<<"\n";
if(stat(argv[i],&s)<0)
{
cout<<"Error";
}
else{
cout<<"Owner UID:- "<<s.st_uid<<"\n";
cout<<"Group UID:- "<<s.st_gid<<"\n";
cout<<"Permission:- "<<s.st_mode<<"\n";
cout<<"Access Time:- "<<s.st_atime<<"\n";
cout<<"Size:- "<<s.st_size<<endl;
}
}
return 0;
}
