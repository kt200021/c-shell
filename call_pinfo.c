#include"global.h"
void call_pinfo(char **args,int time,int freq)
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
int pid,dirlen;char Name[600];char d[20]; char d1[20];
char line[500];
    char Status[50];
    char Size[300];
    int state_p=0;
    int size_p=0;
    char dir[1021];
    getcwd(dir,sizeof(dir));
    
    
    if(!args[1])
        pid=getpid();
    else
        pid=atoi(args[1]);
dirlen=strlen(dir);
    //char Name[600];
    char c[20]="/proc/\0";
    
    snprintf(d,20,"%d",pid);
    char *f=strcat(c,d);
char zz[20]="/status\0";
//strcat(zz,);
  
  f=strcat(f,zz);

    char c1[20]="/proc/\0";
   
    snprintf(d1,20,"%d",pid);
    char* abc=strcat(c1,d1);
char xx[20]="/exe\0";
//strcat(xx,);
    abc=strcat(abc,xx);
    int ret=readlink(abc,Name,(size_t)sizeof(Name));

    FILE* file=fopen(f,"r");
    if(file==0)
    {
        perror("ERROR : ");
        return;
    }
    
    while(fgets(line,sizeof(line),file))
    {
        if(strncmp(line,"State\0",5)==0)
        {
            strcpy(Status,line+7);
            state_p=1;
        }
        else if(strncmp(line,"VmSize\0",6)==0)
        {
            strcpy(Size,line+10);
            size_p=1;
           goto bb;
        }
    }
bb:
    printf("\npid-> %d\n",pid);
    if(state_p!=0)
        printf("Process Status-> %s",Status);
    if(size_p!=0)
        printf("Memory-> %s",Size);
    if(ret!=-1)
    {
        Name[ret]='\0';
        if( (strncmp(Name,dir,dirlen)==0) && dirlen<strlen(Name))
        {
            printf("Executable Path-> ~%s\n\n",&Name[dirlen]);
        }
        else
            printf("Executable Path-> %s\n\n",Name);
    }
    else
        printf("\n");
int xxx=freq-(time*(ii+1));
        if(xxx<time)
            sleep(xxx);
        
        ii++;

}
}
