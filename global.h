#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <sys/socket.h> 
#include <string.h> 
#include <sys/wait.h> 
#include <readline/readline.h> 
#include <readline/history.h> 
#include <fcntl.h> 
#include <dirent.h> 
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <curses.h>
#include <ncurses.h>
#include <time.h>

struct P{
    char proc_name[128];
    int pid;
    int si;
}proc;


struct P runn_proc[2048];


int size;
int curr_fg_pid;
char curr_fg_proc_name[400];
char bbuffer[100000];
int flag;
int val;
char prev1[1000];
int ctrl_z_cond;
int ctrl_c_cond;
char *buffer;
char tilda[1000];
void addhistory(char *argu);
void printhistory(char **karsh);
int takeInput(char* s,char *dir);
void call_fg(char **parsed);
void call_unsetenv(char **parsed,int len,int time,int freq);

int parseSpace(char* str, char** karsh);
int processString(char* str, char** karsh);
void call_cd(char **karsh,char *dir,int time,int freq);
void call_echo(char **karsh,int time,int freq);
void call_pwd();
void call_ls(char **karsh,int time,int freq);
void call_pinfo(char **karsh,int time,int freq);
void call_kjob(char **parsed,int len);
void call_nightswatch(char **karsh);
void printDir(char *fixed);

void call_cronjob(char** parsed,int len,char *dir,char *path_h);
int call_exec(char **karsh);
void call_bg(char **parsed);
void call_overkill();

void call_setenv(char **parsed,int len,int time,int freq);
void call_jobs(int time,int freq);
void call_redirection(char **parsed,int len);


void Check(char** parsed,char *dir,int len,char *path_h,int time,int freq);
