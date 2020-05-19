#include"global.h"
void call_echo(char **karsh,int time,int freq)
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
    for(int j=1;;j++)
    {		if(karsh[j]==NULL)
            break;

        if(j!=1)
            printf(" ");
        printf("%s",karsh[j]);
        //j++;
    }
    printf("\n");
int xx=freq-(time*(ii+1));
        if(xx<time)
            sleep(xx);
        
        ii++;

}
}
