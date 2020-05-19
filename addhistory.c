#include"global.h"

void addhistory(char *argu)
{
   char ss[1000];
   long int lll=strlen(argu);
  strcpy(ss,tilda); 
	strcat(ss,"/hell.txt");
	int fd1=open(ss,O_WRONLY);
    if(fd1==-1)
        perror("not opened");
	
    lseek(fd1,0,SEEK_END);
  
    write(fd1,argu,lll);
    write(fd1,"!",1);
    close(fd1);
    
	int fd3=open(ss,O_RDWR);
    int sz=read(fd3,bbuffer,100000);
int i=sz-1; 
   int j=0,c=0;

	while(i>=0)
{
char ch=bbuffer[i];
 if(ch=='!')
        {
            c++;
            if(c>20)
            {
                j=i+1;
                break;
            }
	
        }

i--;
}

    truncate(ss,0);
    close(fd3);
    int fd2=open(ss,O_RDWR);
   
    write(fd2,bbuffer+j,sz-j);
    close(fd2);

}
