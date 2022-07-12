#include<stdio.h> 
#include<unistd.h> 
int main() 
{ 
int pipe1fds[2],pipe2fds[2],returnstatus1,returnstatus2,pid; 
char p1writemessages[10] ="HELLO",p2writemessages[10] ="WORLD",readmessage[10]; returnstatus1 = pipe(pipe1fds); 
if(returnstatus1 == -1) 
{ 
printf("Unable to create pipe\n"); 
return 1; 
} 
returnstatus2 = pipe(pipe2fds); 
if(returnstatus2 == -1) 
{ 
printf("Unable to create pipe\n"); 
return 1; 
} 
pid = fork(); 
if(pid!=0) 
{ 
close(pipe1fds[0]); 
close(pipe2fds[1]); 
printf("IN PARENT PROCESS - WRITING TO PIPE 1 - MESSAGE 1 %s\n",p1writemessages); write(pipe1fds[1],p1writemessages,sizeof(p1writemessages)); 
read(pipe2fds[0],readmessage,sizeof(readmessage)); 
printf("IN PARENT PROCESS - READING FROM PIPE 2 - MESSAGE 1 %s\n",readmessage); } 
else 
{ 
close(pipe1fds[1]);
close(pipe2fds[0]); 
read(pipe1fds[0],readmessage,sizeof(readmessage)); 
printf("IN CHILD PROCESS - READING FROM PIPE 1 - MESSAGE 2 %s\n",readmessage); printf("IN CHILD PROCESS - WRITING TO PIPE 2 - MESSAGE 2 %s\n",p2writemessages); write(pipe2fds[1],p2writemessages,sizeof(p2writemessages)); 
} 
return 0; 
}
