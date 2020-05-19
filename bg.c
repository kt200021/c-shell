#include"global.h"

void call_bg(char **karsh)
{
    int num;
    sscanf(karsh[1],"%d",&num);

    if(num>size)
    {
        fprintf(stderr,"Error: Given job number does not exist\n");
        return;
    }

int pg;
    pg = runn_proc[num-1].pid;

  
       
     if(pg!=-1)
    {
        printf("%s\n",runn_proc[num-1].proc_name);
        kill(pg, SIGCONT);
    }
else
{
 fprintf(stderr,"Error: Given job number does not exist\n");}
}

