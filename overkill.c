#include"global.h"

void call_overkill()
{
int h=0;
while(h<size)       
{
        if(runn_proc[h].pid!=-1)
        {
            kill(runn_proc[h].pid,9);
        }
h++;
    }
}

