#include"global.h"

void call_setenv(char **karsh,int len,int time,int freq)
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
        if(len>=2 && len<=3)
        {
            if(karsh[2]==NULL)
                setenv(karsh[1],"",1);
            else
                setenv(karsh[1],karsh[2],1);
        }
        else if(len<2)
            fprintf(stderr,"Error: Too few arguements\n");
else if(len>3)
            fprintf(stderr,"Error: Too many arguements\n");

        
int xx=freq-(time*(i+1));
        if(xx<time)
            sleep(xx);

        i++;
    }
}
