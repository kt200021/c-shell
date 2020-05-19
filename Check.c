#include"global.h"

void Check(char** karsh,char *dir,int len,char *path_h,int time,int freq)
{
int varr=0;
	
 if(karsh[1]!=NULL)
    {
	
	int xx=strcmp(karsh[len-1],"&");
        if(!xx)
        {

            strcpy(karsh[len-1],"\0");
            flag=1;
            int pid = fork();
            if(!pid)
            {
                setpgid(0,0);
                close(STDERR_FILENO);

                if(execvp(karsh[0],karsh)==-1)
                    perror("Invalid command");

                exit(0);
            }
else
{
 runn_proc[size].pid=pid;
                strcpy(runn_proc[size].proc_name,karsh[0]);
                
printf("%d\n",pid);
                runn_proc[size].si=size+1;
                size++;



}
        } 
    }
    int x1=strcmp(karsh[0],"ls");
    int x2=strcmp(karsh[0],"cd");
    int x3=strcmp(karsh[0],"history");
    int x4=strcmp(karsh[0],"pwd");
    int x5=strcmp(karsh[0],"echo");
    int x6=strcmp(karsh[0],"nightswatch");
    int x7=strcmp(karsh[0],"pinfo");
int x8=strcmp(karsh[0],"exit");
int x9=strcmp(karsh[0],"setenv");
int x10=strcmp(karsh[0],"unsetenv");
int x11=strcmp(karsh[0],"jobs");
int x12=strcmp(karsh[0],"kjob");
int x13=strcmp(karsh[0],"overkill");
int x14=strcmp(karsh[0],"fg");
int x15=strcmp(karsh[0],"bg");
int x16=strcmp(karsh[0],"quit");
int x17=strcmp(karsh[0],"cronjob");
if(!x8)
	exit(0);
else if(!x1)
        call_ls(karsh,time,freq);
    else if(!x2)
        call_cd(karsh,dir,time,freq);
    else if(!x3)
        printhistory(karsh);
    else if(!x4)
        call_pwd();
    else if(!x5)
        call_echo(karsh,time,freq);
    else if(!x6)
        call_nightswatch(karsh);
    else if(!x7)
        call_pinfo(karsh,time,freq);
 else if(!x9)
        call_setenv(karsh,len,time,freq);
    else if(!x10)
        call_unsetenv(karsh,len,time,freq);
    else if(!x11)
        call_jobs(time,freq);
    else if(!x12)
        call_kjob(karsh,len);
    else if(!x13)
        call_overkill();
    else if(!x14)
        call_fg(karsh);
    else if(!x15)
        call_bg(karsh);
    else if(!x16)
        exit(0);
    else if(!x17)
        
{
int piddd=fork();
if(piddd==0)
{
call_cronjob(karsh,len,dir,path_h);     
 exit(0);
}
}
else
    {
	//	printf("hii1\n");
        if(flag!=1)
        {
             int pidd = fork();
       
            if(!pidd)
            {
                val = call_exec(karsh);
                if(val==-1)
                    fprintf(stderr,"Error:command not found\n");
                exit(0);
            }
            else if(pidd>0)
            {
		    int val1=val;
		//    	printf("%d",val);
                if(val!=-1)
                {curr_fg_pid = pidd;


			strcpy(curr_fg_proc_name,karsh[0]);
                }

                int status;
       
ctrl_c_cond=1;
ctrl_z_cond=1;
int xxxx=0;
		waitpid(pidd,&status,WUNTRACED);
int df=0;
		ctrl_c_cond=0;
ctrl_z_cond=0;
            }
       	}
    }
}
