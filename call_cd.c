#include"global.h"

void call_cd(char **karsh,char *dir,int time,int freq)
{
     int y;

    if(time==-1 || freq==-1)
    {
        time=0;
        freq=0;
        y=1;
    }
else
{

y = (freq/time);
}

int ii=0;
while(ii<y)
{sleep(time);
        if(karsh[1]!=NULL)
        {
char temp[1000];
            if(strcmp(karsh[1],"-")==0)
            {
                
                strcpy(temp,prev1);
                getcwd(prev1,1000);
                chdir(temp);
                return ;
            }
        }

        getcwd(prev1,1000);
        if(karsh[1]==NULL)
        {
            if(chdir(dir)==0)
            {
		}
		else
		{
                perror("Cannot access");
            }	
		
        }
else if(karsh[1][0]=='~')
        {
int len2 = strlen(karsh[1]);
            char d[100];
            strcpy(d,dir);
            int len3 = strlen(d);
            
            for(int i=1;i<len2;i++)
            {
		len3++;
                d[len3-1]=karsh[1][i];
                
            }

            if(chdir(d)!=0)
            {
                perror("Cannot access");
            }
        }
        else if(strcmp(karsh[1],"~")==0)
        {
            if(chdir(dir)!=0)
            {
                perror("Cannot access");

            }
        }
        
        else
        {
            if(chdir(karsh[1])!=0)
            {
                perror("Cannot access");
            }
        }
       int xxx=freq-(time*(ii+1));
        if(xxx<time)
            sleep(xxx);
        
        ii++;


    }
}
