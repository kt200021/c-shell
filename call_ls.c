#include"global.h"
void call_ls(char **parsed,int time,int freq)
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
    char curd[1024];
    getcwd(curd,sizeof(curd));

    if(parsed[1]==NULL && parsed[2]==NULL)
    {

        char *pointer=curd;
        DIR *dp=opendir((char*)pointer);
        struct dirent *sd=NULL;

        while(1)
        {
            if((sd=readdir(dp))==NULL)
                break;
            if(sd->d_name[0]=='.') continue;
            printf("%s\n",sd->d_name);
        }
    }

    else if(parsed[1]!=NULL && parsed[2]==NULL)
    {
        //    printf("%s\n",parsed[1]);
        int x1=!strcmp(parsed[1],"-la");
        int x2=!strcmp(parsed[1],"-al");
        int yy=(x1 || x2);
        DIR *thedirectory;
        struct dirent *thefile;
        struct stat thestat;
        if(!strcmp(parsed[1],"-a"))
        {

            char buf[512];

            thedirectory = opendir(curd);

            while(1)
            {
                if((thefile = readdir(thedirectory)) == NULL)
                    break;
                sprintf(buf, "%s/%s", curd, thefile->d_name);
                stat(buf, &thestat);

                printf("%s  ", thefile->d_name);
            }
            closedir(thedirectory);
        }
        else if(!strcmp(parsed[1],"-l"))
        {


            char buf[512];

            thedirectory = opendir(curd);

            while(1)
            {

                if((thefile = readdir(thedirectory))== NULL)
                    break;

                if(thefile->d_name[0]!='.')
                {
                sprintf(buf, "%s/%s", curd, thefile->d_name);
                stat(buf, &thestat);

                int xyz=(thestat.st_mode & S_IFMT);
                if(xyz==S_IFBLK)
                {
                    printf("b ");
                }
                else if(xyz==S_IFCHR)
                {
                    printf("c ");
                }
                else if(xyz==S_IFDIR)
                {
                    printf("d ");
                }
                else if(xyz==S_IFIFO)
                {
                    printf("p ");
                }
                else if(xyz==S_IFLNK)
                {
                    printf("l ");
                }
                else if(xyz==S_IFSOCK)
                {
                    printf("s ");
                }
                else
                {
                    printf("- ");
                }

                if(thestat.st_mode & S_IRUSR)
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IWUSR))
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IXUSR))
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IRGRP))
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IWGRP))
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IXGRP))
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IROTH))
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IWOTH))
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IXOTH))
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }

                struct passwd *tf  = getpwuid(thestat.st_uid);
                struct group *gf = getgrgid(thestat.st_gid);
                printf("\t%lu \t%s", thestat.st_nlink,tf->pw_name);
                printf("%zu %s %s",thestat.st_size,thefile->d_name,ctime(&thestat.st_mtime));

            }
                }
                
            closedir(thedirectory);
        }
        else if(yy)
        {

            char buf[512];

            thedirectory = opendir(curd);

            while(1)
            {
                if((thefile = readdir(thedirectory))== NULL)
                    break;
                sprintf(buf, "%s/%s", curd, thefile->d_name);
                stat(buf, &thestat);

                int xyz=(thestat.st_mode & S_IFMT);
                if(xyz==S_IFBLK)
                {
                    printf("b ");
                }
                else if(xyz==S_IFCHR)
                {
                    printf("c ");
                }
                else if(xyz==S_IFDIR)
                {
                    printf("d ");
                }
                else if(xyz==S_IFIFO)
                {
                    printf("p ");
                }
                else if(xyz==S_IFLNK)
                {
                    printf("l ");
                }
                else if(xyz==S_IFSOCK)
                {
                    printf("s ");
                }
                else
                {
                    printf("- ");
                }

                if(thestat.st_mode & S_IRUSR)
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IWUSR))
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IXUSR))
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IRGRP))
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IWGRP))
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IXGRP))
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IROTH))
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IWOTH))
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IXOTH))
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }

                struct passwd *tf  = getpwuid(thestat.st_uid);
                struct group *gf = getgrgid(thestat.st_gid);
                printf("\t%lu \t%s", thestat.st_nlink,tf->pw_name);
                printf("%zu %s %s",thestat.st_size,thefile->d_name,ctime(&thestat.st_mtime));

            }
            closedir(thedirectory);
        }
        else
        {
           
            struct dirent *dir;
            DIR *directory;
            char buf[1001],dir_name[1001];
            directory=opendir(curd);
            while(  (dir=readdir(directory))   != NULL)
            {
                printf("%s ",dir->d_name );
            }
            closedir(directory);

        }

    }

    else if(parsed[1]!=NULL && parsed[2]!=NULL)
    {   int x1=!strcmp(parsed[1],"-la");
        int x2=!strcmp(parsed[1],"-al");
        DIR *thedirectory;
        struct dirent *thefile;
        struct stat thestat;
        int yy=(x1 || x2);
        if(strcmp(parsed[1],"-a")==0)
        {
          

            char buf[512];

            thedirectory = opendir(parsed[2]);

            while(1)
            {
                if((thefile = readdir(thedirectory)) == NULL)
                    break;
                sprintf(buf, "%s/%s", parsed[2], thefile->d_name);
                stat(buf, &thestat);

                printf("%s  ", thefile->d_name);
            }


            closedir(thedirectory);
        }
        else if(yy)
        {

            struct passwd *tf;
            struct group *gf;

            char buf[512];

            thedirectory = opendir(parsed[2]);

            while(1)
            {
                if((thefile = readdir(thedirectory)) == NULL)
                    break;
                sprintf(buf, "%s/%s", parsed[2], thefile->d_name);
                stat(buf, &thestat);

                int xyz=(thestat.st_mode & S_IFMT);
                if(xyz==S_IFBLK)
                {
                    printf("b ");
                }
                else if(xyz==S_IFCHR)
                {
                    printf("c ");
                }
                else if(xyz==S_IFDIR)
                {
                    printf("d ");
                }
                else if(xyz==S_IFIFO)
                {
                    printf("p ");
                }
                else if(xyz==S_IFLNK)
                {
                    printf("l ");
                }
                else if(xyz==S_IFSOCK)
                {
                    printf("s ");
                }
                else
                {
                    printf("- ");
                }
                
                if(thestat.st_mode & S_IRUSR)
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IWUSR))
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IXUSR))
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IRGRP))
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IWGRP))
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IXGRP))
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IROTH))
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IWOTH))
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if((thestat.st_mode & S_IXOTH))
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }


                struct passwd *tf  = getpwuid(thestat.st_uid);
                struct group *gf = getgrgid(thestat.st_gid);
                printf("\t%lu \t%s", thestat.st_nlink,tf->pw_name);
                printf("%zu %s %s",thestat.st_size,thefile->d_name,ctime(&thestat.st_mtime));
            }
            closedir(thedirectory);
        }


    }
    printf("\n");
int xx=freq-(time*(ii+1));
        if(xx<time)
            sleep(xx);
        
        ii++;
    }
}
