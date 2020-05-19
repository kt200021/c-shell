#include"global.h"
int call_exec(char **karsh)
{
   int x= execvp(karsh[0],karsh);
return x;
}
