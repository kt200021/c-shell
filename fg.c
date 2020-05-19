#include"global.h"

void call_fg(char **karsh)
{
    printf("fg\n");
    int num;
    sscanf(karsh[1],"%d",&num);

    if(num>size)
    {
        fprintf(stderr,"Error: Given job number does not exist\n");
        return;
    }
int pg,status;
    pg = runn_proc[num-1].pid;
    printf("%d\n",pg);
       
    if(pg!=-1)
    {
        printf("%s",runn_proc[num-1].proc_name);
	printf("\n");
        kill(pg, SIGCONT);
        strcpy(curr_fg_proc_name,runn_proc[num-1].proc_name);
        curr_fg_pid = pg;
ctrl_c_cond=1;
ctrl_z_cond=1;
        waitpid(pg, &status, WUNTRACED);
int ss=0;
ss++;
ctrl_c_cond=0;
ctrl_z_cond=0;
    }
else
{ fprintf(stderr,"Error: Given job number does not exist\n");

}


}
