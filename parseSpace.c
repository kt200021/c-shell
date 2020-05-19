#include"global.h"
int parseSpace(char* str, char** parsed)
{
    int i=0;

    while(i<3001)
    { parsed[i] = strsep(&str, " ");
        if (parsed[i] == NULL)
            break;
        long int len=strlen(parsed[i]);

        if ( len== 0)
            i--;

        i++;
    }
return i;
}
