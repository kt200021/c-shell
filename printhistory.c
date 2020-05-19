#include"global.h"
void printhistory(char **karsh)
{
	
	int  num;
	if(karsh[1]==NULL)
		num=10;
	else
	sscanf(karsh[1],"%d",&num);char ss[1000];
strcpy(ss,tilda);
	strcat(ss,"/hell.txt");
//	printf("%s",ss);
    int fd1=open(ss,O_RDWR);
if(fd1==-1)
        perror("not opened");
char arr[10000];
    int sz=read(fd1,arr,100000);
    int j=0,c=0;
 
int i=sz-1;
    	while(i>=0)
{
char ch=arr[i];
 if(ch=='!')
        {
            c++;
            if(c>num)
            {
                j=i+1;
                break;
            }
	
        }

i--;
}
    for(int i=j;i<sz;i++)
    {
        if(arr[i]!='!')
             printf("%c",arr[i]);
        else
	 printf("\n");
           
    }
//    printf("\n******\n");

    close(fd1);
    
    return ;
}
