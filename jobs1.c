#include"global.h"

void call_jobs(int time,int freq)
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


    int i=0;

    while(i<y)
    {
        sleep(time);
int d=0; 
      while(d<size)
{
//            printf("%s %d\n",runn_proc[d].proc_name,runn_proc[d].pid);
            if(runn_proc[d].pid!=-1)
            {
			 char pid_str[100];int va=runn_proc[d].pid;char stat_buffer[2000];  char *stat[10000];
 int v=0;
                char status[40];


                char pat[100]="/proc/";
               
                sprintf(pid_str,"%d",va); 

                strcat(pat,pid_str);
                strcat(pat,"/status");

                int  fdd = open(pat,O_RDONLY);

                
                read(fdd,stat_buffer,2000);

                char *args = strtok(stat_buffer,"\n");

                int g=0;
              
                while(args!=NULL)
                {
                    stat[g] = args;
                    g++;
                    args = strtok(NULL,"\n");
                }

                int leng = strlen(stat[2]);
                int idx1,idx2;
int nn=0; 
              while(nn<leng)
{
	char ch=stat[2][nn];

                    if(ch==')')
                        idx2=nn;
                    else if(ch=='(')
                        idx1=nn;
nn++;
                }

               
                for(int n=idx1+1;n<idx2;n++)
                {
                    
                    if(v!=0)
                        status[v] = stat[2][n];
else
                        status[v] = toupper(stat[2][n]); 
                   
v++;
                }

                status[idx2-(idx1+1)]='\0';

                printf("[%d]%s %s[%d]\n",runn_proc[d].si,status,runn_proc[d].proc_name,runn_proc[d].pid);
            }
d++;
        }
int xx=freq-(time*(i+1));
        if(xx<time)
            sleep(xx);
        
        i++;
    }
}







#include"global.h"

void call_jobs(int time,int freq)
{
    int y ;

    if(time==-1 || freq==-1)
    {
        time=0;
        freq=0;
        y=1;
    }
else
{
y=(freq/time);
}
    int i=0;

    while(i<y)
    {
        sleep(time);
        for(int d=0;d<size;d++)
        {
//            printf("%s %d\n",runn_proc[d].proc_name,runn_proc[d].pid);
            if(runn_proc[d].pid!=-1)
            {
                char pat[100]="/proc/";
                char pid_str[100];
                sprintf(pid_str,"%d",runn_proc[d].pid); 

                strcat(pat,pid_str);
                strcat(pat,"/status");

                int  fdd = open(pat,O_RDONLY);

                char stat_buffer[2000];
                read(fdd,stat_buffer,2000);

                char *args = strtok(stat_buffer,"\n");

                int g=0;
                char *stat[10000];

                while(args!=NULL)
                {
                    stat[g] = args;
                    g++;
                    args = strtok(NULL,"\n");
                }

                int leng = strlen(stat[2]);
                int idx1,idx2;
                
                for(int n=0;n<leng;n++)
                {
                    if(stat[2][n]=='(')
                        idx1=n;
                    else if(stat[2][n]==')')
                        idx2=n;
                }

                int v=0;
                char status[40];

                for(int n=idx1+1;n<idx2;n++)
                {
                    if(v==0)
                        status[v] = toupper(stat[2][n]);
                    else
                        status[v] = stat[2][n];
                    v++;
                }

                status[v]='\0';

                printf("[%d]%s %s[%d]\n",runn_proc[d].si,status,runn_proc[d].proc_name,runn_proc[d].pid);
            }
        }
        if(freq-time*(i+1)<time)
            sleep(freq-time*(i+1));
        i++;
    }
}




#include"global.h"

void call_jobs(int time,int freq)
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


    int i=0;

    while(i<y)
    {
        sleep(time);
int d=0; 
      while(d<size)
{
//            printf("%s %d\n",runn_proc[d].proc_name,runn_proc[d].pid);
            if(runn_proc[d].pid!=-1)
            {
			 char pid_str[100];int va=runn_proc[d].pid;char stat_buffer[2000];  char *stat[10000];
 int v=0;
                char status[40];


                char pat[100]="/proc/";
               
                sprintf(pid_str,"%d",va); 

                strcat(pat,pid_str);
                strcat(pat,"/status");

                int  fdd = open(pat,O_RDONLY);

                
                read(fdd,stat_buffer,2000);

                char *args = strtok(stat_buffer,"\n");

                int g=0;
              
                while(args!=NULL)
                {
                    stat[g] = args;
                    g++;
                    args = strtok(NULL,"\n");
                }

                int leng = strlen(stat[2]);
                int idx1,idx2;
int nn=0; 
              while(nn<leng)
{
	char ch=stat[2][nn];

                    if(ch==')')
                        idx2=nn;
                    else if(ch=='(')
                        idx1=nn;
                }

               
                for(int n=idx1+1;n<idx2;n++)
                {
                    
                    if(v!=0)
                        status[v] = stat[2][n];
else
                        status[v] = toupper(stat[2][n]); 
                   
v++;
                }

                status[v]='\0';

                printf("[%d]%s %s[%d]\n",runn_proc[d].si,status,runn_proc[d].proc_name,runn_proc[d].pid);
            }
d++;
        }
int xx=freq-(time*(i+1));
        if(xx<time)
            sleep(xx);
        
        i++;
    }
}







#include"global.h"

void call_jobs(int time,int freq)
{
    int y ;

    if(time==-1 || freq==-1)
    {
        time=0;
        freq=0;
        y=1;
    }
else
{
y=(freq/time);
}
    int i=0;

    while(i<y)
    {
        sleep(time);
int d=0;
        while(d<size)
{
//            printf("%s %d\n",runn_proc[d].proc_name,runn_proc[d].pid);
            if(runn_proc[d].pid!=-1)
            {
                char pat[100]="/proc/";
                char pid_str[100];   char stat_buffer[2000];    char *stat[10000];   int v=0;
                char status[40];
                sprintf(pid_str,"%d",runn_proc[d].pid); 

                strcat(pat,pid_str);
                strcat(pat,"/status");

                int  fdd = open(pat,O_RDONLY);

             
                read(fdd,stat_buffer,2000);

                char *args = strtok(stat_buffer,"\n");

                int g=0;
            

                while(1)
                {
			if(args==NULL)
			break;
                    stat[g] = args;
                    g++;
                    args = strtok(NULL,"\n");
                }

                int leng = strlen(stat[2]);
                int idx1,idx2;
                int n=0;
                while(n<leng)
                {
                    if(stat[2][n]=='(')
                        idx1=n;
                    else if(stat[2][n]==')')
                        idx2=n;
n++;
                }

             

                for(int n=idx1+1;n<idx2;n++)
                {
                    if(!v)
                        status[v] = toupper(stat[2][n]);
                    else
                        status[v] = stat[2][n];
                    v++;
                }

                status[v]='\0';

                printf("[%d]%s %s[%d]\n",runn_proc[d].si,status,runn_proc[d].proc_name,runn_proc[d].pid);
            }
d++;
        }
        int xx=freq-(time*(i+1));
        if(xx<time)
            sleep(xx);
        i++;
    }
}


