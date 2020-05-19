#include"global.h"
void call_nightswatch(char **karsh)
{

clear();
    if(strcmp(karsh[3],"interrupt")==0)
    {
        int n=atoi(karsh[2]);
int y_co=0;
        initscr();
        noecho();
        curs_set(FALSE);
        nodelay(stdscr,TRUE);
        

char a = getch();
        
        while(1)
        {
   nodelay(stdscr,TRUE);
            noecho();
           
	 a = getch();

            if(a=='q')
            {
                endwin();
                return;
            }
            int fd;char buf[100001];char *ans[1001];
		
            fd=open("/proc/interrupts",O_RDONLY);
            read(fd,buf,100001);
            char *ft=strtok(buf," ");
            int x=0;
            while(ft!=NULL)
            {
                ans[x]=ft;
                x++;
                ft=strtok(NULL," ");
            }
	 int x_co=0;
for(int i=22;i<=29;i++)
{mvprintw(y_co , x_co , "CPU %d -- %s\n",i-22,ans[i]);
            x_co +=20;
}


  clock_t t = clock();

            while(1)
            {
		if(((clock()-t)/CLOCKS_PER_SEC)>=n)
			break;
	                nodelay(stdscr,TRUE);
                noecho();
                a = getch();

                if(a=='q')
                {
                    endwin();
                    return;
                }
            }
            y_co+=2;
            //sleep(n);
        }
    }
    if(strcmp(karsh[3],"dirty")==0)
    {

            int n=atoi(karsh[2]);
int y_co=0;  
        initscr();
        noecho();
        curs_set(FALSE);
        nodelay(stdscr,TRUE);
        char a = getch();
        
        int flag1=0;
        char *key;
        while(1)
        {
 nodelay(stdscr,TRUE);
            noecho();
            a = getch();

            if(a=='q')
            {
                endwin();
                return;
            }
           
char bu[1000000];char *stored[5000];char *di[5000]; 
   int fd5 = open("/proc/meminfo",O_RDONLY);

            
            read(fd5,bu,1000000);
 char *del = strtok(bu,"\n");
            
            int f=0;
           
            while(del!=NULL)
            {
                stored[f]=del;
                f++;
			if(f>16)
			break;
                del = strtok(NULL,"\n");
            }

            char *dirt = strtok(stored[16]," ");
            

            int g=0;
            while(dirt!=NULL)
            {
                di[g] = dirt;
                g++;
		if(g>2)
		 break;
                dirt = strtok(NULL," ");
            }

            int x_co=0;

            mvprintw(y_co , x_co , "Dirty -- %s %s\n",di[1],di[2]);
        clock_t t = clock();

            while(1)
            {
		if(((clock()-t)/CLOCKS_PER_SEC)>=n)
			break;
	                nodelay(stdscr,TRUE);
                noecho();
                a = getch();

                if(a=='q')
                {
                    endwin();
                    return;
                }
            }
            y_co+=2;
        }

    }
   

}
