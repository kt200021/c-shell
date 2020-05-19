#include"global.h"

int takeInput(char* s,char *dir)
{
    size_t bufsize = 1000;
int flag_up=0;
    int count1=0;
    int count2=0;
    int count3=0;
    getline(&buffer,&bufsize,stdin);

    char buff[100000];
    
    long int len = strlen(buffer);

int v=0;
    while(v<len-1)
    {
        if((int)buffer[v]==27) 
            count1++;
        if( (int)buffer[v+1]==91 && (v+1)<len-1) 
            count2++;
        if((v+2)<len-1 && (int)buffer[v+2]==65) 
            count3++;
	v+=3;
    }

    if(!count1 && !count2 && !count3 && strlen(buffer) != 0) 
    {
        strcpy(s, buffer);

     //   int s_len = strlen(s);
        s[strlen(s)-1]='\0';

        addhistory(s); 

        return 0; 
    }
    else if(3*count1==(len-1) &&  count1==count2 && count2==count3 )
    {
        flag_up=1;
    }
    else 
    {
        fprintf(stderr,"Error: Invalid command\n");
        return 1;
    }
 

    if(flag_up==1)
    {
        
        long int len = strlen(buffer)-1;
        char temp_str[1000];

        int no_of_ups = len/3;
 char ss[1000];
  strcpy(ss,tilda);
        strcat(ss,"/hell.txt");
        int fd = open(ss,O_RDONLY,0777);
        if(fd==-1)
            perror("not opened");

        else
        {
 int j;
            int c=0;
            int siz = read(fd,buff,100000);
            lseek(fd,0,SEEK_END);
           
	int i=siz-1;
while(i>=0)
            {
                if(buff[i]=='!')
                {
                    c++;
                    if(c==no_of_ups+1)
                    {
                        j=i+1;
                    }
                }
i--;           
 }

            int x=0;


            for(int k=j;k<siz;k++)
            {
                if(buff[k]=='!')
                {
                   
 temp_str[x]='\0';
                    x++;
                }
                else
                {
                    temp_str[x]=buff[k];
                    x++;
                }
            }
        }

        printf("%s\n",temp_str);
        strcpy(s, temp_str);
        addhistory(temp_str); 
        return 0;
    }
    else
        return 1; 
}
