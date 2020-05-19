#include"global.h"
void printDir(char *fixed)
{

int len = strlen(fixed);
   
    char cwd[1024];
    getcwd(cwd,sizeof(cwd));
 int len1 = strlen(cwd);
    

    int cnt=0;
  //  for(int i=0;i<len;i++)
   // {
int i=0;
while(i<len)
      {  if(fixed[i]==cwd[i])
            cnt++;
	else
	break;
i++;
    }

    int k=0;
    if(cnt!=len)
    {
         printf("%s",cwd);
    }

    else
      
 {cwd[k++]='~';
        
        for(int i=len;i<len1;i++)
        {
            cwd[k++] = cwd[i]; 
            
        }


        cwd[k]='\0';
        printf("%s",cwd);
}
}
