#include"global.h"

void call_redirection(char **karsh,int len)
{
    
    int iter1=-1,iter2=-1,iter3=-1,iter4=-1;
    int x=len-1;
  while(x>=0)
{
        if(strcmp(karsh[x],">")==0)
        {
            iter1=x;
            break;
        }
x--;    
}
  x=len-1;
  while(x>=0)
{
        if(strcmp(karsh[x],"<")==0)
        {
            iter2=x;
            break;
        }
x--;    
}

  x=len-1;
  while(x>=0)
{
        if(strcmp(karsh[x],">>")==0)
        {
            iter4=x;
            break;
        }
x--;    
}

int new_flag=0;


    if(iter1<iter4)
    {
 new_flag=1;
        iter1=iter4;
       
    }
x=0;
    while(x<len)
    {
        if( strcmp(karsh[x],"<")==0 || strcmp(karsh[x],">")==0 || strcmp(karsh[x],">>")==0)
        {
            iter3=x;
            break;
        }
x++;
    }
char *new_parsed[40];

    int fd,fd1,fd2,fd3;
    
    int j=0;
x=0;
   while(x<iter3)
    {
        new_parsed[j]=karsh[x];
        j++;
x++;
    }

    new_parsed[j]=NULL;

int t=-1;

    if(iter1!=t)
    {
        
            
        if(new_flag!=0)
        {
            fd = open(karsh[iter1+1], O_WRONLY | O_CREAT , 0777);
            lseek(fd,0,SEEK_END);
        }
else
{
fd = open(karsh[iter1+1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
}

        fd1=dup(1);
        dup2(fd,1);
    }

    if(iter2!=t)
    {
        fd2 = open(karsh[iter2+1], O_RDONLY | O_CREAT , 0777);
        fd3=dup(0);
        dup2(fd2,0);
    }



    int pd = fork();

    if(!pd)
    {

        execvp(new_parsed[0],new_parsed);

        exit(0);
    }
    else if(pd>0)
    {
        int status;
    	int ddd;
    	waitpid(pd,&status,WUNTRACED);
    }

    if(iter1!=t)
        dup2(fd1,1);

    if(iter2!=t)
        dup2(fd3,0);
}
