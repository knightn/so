#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
pid_t pid,pr;
pr=fork();
pid=getpid();
if(pr<0)
{
cout<<"Failed!!!\n";
return 1;
}
cout<<"The output of Fork="<<pr<<end1;
cout<<"Process Id= "<<pid<<endl;
return 0;
}
(b)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
int main(){
int pid =fork();
if (pid<0)
{
cout<<"Failed"<<endl;
exit(1);
}
else if(pid==0)
  if(pid==0)
{
cout<<"Child Process"<<endl;
cout<<"Child Process ID = "<<getpid()<<endl;
exit(0);
}
else
{
cout<<"Parent Process "<<endl;
cout<<"Parent Process ID = "<<getpid()<<endl;
exit(1);
} }

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main() {
int pid =fork();
if (pid<0)
{
cout<<"Failed"<<endl;
exit(1);
}
else if(pid==0)
{
cout<<"Child Process"<<endl;
cout<<"Child Process ID = "<<getpid()<<endl;
exit(0);
}
else
{
cout<<"Parent Process "<<endl;
cout<<"Parent Process ID = "<<getpid()<<endl;
wait(NULL);
exit(1);
} }
