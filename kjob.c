#include"global.h"

void call_kjob(char **karsh,int len)
{
  
    if(len==3)
    {
        int num1;
        sscanf(karsh[1],"%d",&num1);
  int num2;
            sscanf(karsh[2],"%d",&num2);

        
       if(num1<=size)
        {
          
            kill(runn_proc[num1-1].pid,num2);
            printf("%d\n",runn_proc[num1-1].pid);
            
        }
	else
	{
            fprintf(stderr,"Error: No such job\n");
	}
    }
else
{


        fprintf(stderr,"Error: invalid input\n");
}
}
