#include"global.h"
void call_pwd()
{
    char cwd[1024];
    getcwd(cwd,sizeof(cwd));
    printf("%s\n",cwd);
}
