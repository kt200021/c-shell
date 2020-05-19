#include"global.h"

void call_cronjob(char **karsh,int len,char *dir,char *path_h)
{
    int idx1=0;
	
  int idx2=0;
  int cnt1=0;
  int cnt2=0;
  int cnt3=0;
char *parsed1[40];

    for(int i=0;i<len;i++)
{
        if(!strcmp(karsh[i],"-c"))
            cnt1 = 1;
        else if(!strcmp(karsh[i],"-t"))
            cnt2 = 1;
        else if(!strcmp(karsh[i],"-p"))
            cnt3 = 1;
       
    }

    if(cnt1==1 && cnt2==1 && cnt3==1)
    {
       

          for(int i=0;i<len;i++)
{
            if(!strcmp(karsh[i],"-c"))
                idx1 = i;
            else if(!strcmp(karsh[i],"-t"))
                idx2 = i;
            
        }

        int h=0;
        
        for(int k=idx1+1;k<idx2;k++)
        {
            parsed1[h]=karsh[k];
            h++;
        }

int ti,fr;
sscanf(karsh[idx2+1],"%d",&ti);
 sscanf(karsh[idx2+3],"%d",&fr);
      /*  int ti;
        char tem[100];
        strcpy(tem,karsh[idx2+1]);
        sscanf(tem,"%d",&ti);

        int fr;
        strcpy(tem,karsh[idx2+3]);
        sscanf(tem,"%d",&fr);
*/

        Check(parsed1,dir,idx2-idx1-1,path_h,ti,fr);
    }

    else
        fprintf(stderr,"Error: command not found\n");
}
