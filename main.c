#include"global.h"
void sigintHandler(int sig_num)
{
int xxx=ctrl_c_cond;
if(xxx==1)
{
	signal(SIGINT, sigintHandler);

	int get_idx=0;

	for(int l=0;l<size;l++)
	{
		if( runn_proc[l].pid!=-1 && (runn_proc[l].pid==curr_fg_pid) )
		{
			get_idx=l;
			break;
		}
	}
 kill(curr_fg_pid,SIGINT);

	if(get_idx<size && get_idx>=0)
	{

		runn_proc[get_idx].pid=-1;
	}
}
}

void sigintHandler1(int sig_num) 
{
	int xxx=ctrl_z_cond;
	if(xxx==1)
	{
	signal(SIGTSTP, sigintHandler1);

	printf("%s\n",curr_fg_proc_name);
	int ff=0;
	for(int l=0;l<size;l++)
	{
		if((runn_proc[l].pid==curr_fg_pid)  && runn_proc[l].pid!=-1)
		{
			ff=1;
			break;
		}
	}

	if(ff==0)
	{
		//printf("hello\n");
		runn_proc[size].si=size+1;
		runn_proc[size].pid=curr_fg_pid;
		strcpy(runn_proc[size].proc_name,curr_fg_proc_name);


		size++;
	}

	printf("%d\n",curr_fg_pid);
	kill(curr_fg_pid,SIGTSTP);
	}
	}

int main()
{

	char* parsedArgs[256];
	char* parsedArgsPiped[256]; int len; 
	char **wow;
	if(fork()==0)
		execvp("clear",wow);
	else
		wait(NULL);


	int execFlag;char hostbuffer[256];


	int hostname = gethostname(hostbuffer, sizeof(hostbuffer));

	if (hostname == -1)
	{
		perror("gethostname");
		exit(1);
	}
	struct hostent *host_entry = gethostbyname(hostbuffer);

	if (host_entry == NULL)
	{
		perror("gethostbyname");
		exit(1);
	}
	getcwd(prev1,1000);
	char dir[100];char path_h2[100];


	getcwd(dir,sizeof(dir));
	//i// char dir[100];
	// getcwd(tilda,sizeof(tilda));
	strcpy(tilda,dir);

	strcpy(path_h2,dir);
	strcat(path_h2,"/h2.txt");

	signal(SIGINT,sigintHandler);   
	signal(SIGTSTP,sigintHandler1);   

	while(1)
	{
		char inputString[1000]; val=0;
		flag=0;
		parsedArgs[0] = NULL;
		parsedArgs[1] = NULL;
		parsedArgs[2] = NULL;

		int pid,pid_status;



		//	printf("\e[1;32m");
		printf("%s",getenv("USER")); 
		//     printf("\e[m");
		printf("@"); 
		//    printf("\e[1;32m");
		printf("%s:", hostbuffer); 

		//   printf("\e[1;34m");
		printDir(dir);
		//   printf("\e[m");
		printf("  "); 


		while((pid = waitpid(-1, &pid_status, WNOHANG | WUNTRACED)) > 0){
			char *proc_name;
			if(WIFEXITED(pid_status)!=0)
			{
				for(int i=0;i<size;i++)
				{
					if(runn_proc[i].pid==pid)
					{
						runn_proc[i].pid=-1;
						proc_name = runn_proc[i].proc_name;

						// printf("hello\n");
						fprintf(stderr, "%s with pid %d exited normally.\n",proc_name,(int)pid);
						break;
					}
				}
			}

			else if(WIFSIGNALED(pid_status))
			{
				int i=0;
				while(i<size)
				{
					if(runn_proc[i].pid==pid)
					{
						proc_name = runn_proc[i].proc_name;
						runn_proc[i].pid = -1;
						//  printf("hello\n");

						fprintf(stderr,"%s with %d pid terminated by a signal.\n",proc_name,(int)pid);
						break;
					}
					i++;
				}

			}
		}

		if(takeInput(inputString,path_h2))
			continue;   
		char* store[1000];
		int k=0;

		char ss[2]=";";
		char* arg = strtok(inputString,ss);

		while(1)
		{	
			if(arg==NULL)
				break;
			store[k]=arg;
			k++;
			arg = strtok(NULL,ss);
		}	

		int i=0;

		while(i!=k)
		{
			int m=0;
			char* piped_args[1000];
			// int ii=0;
			int redir=0;




			char* token = strtok(store[i],"|");

			while(1)
			{
				if(token==NULL)
					break;
				piped_args[m]=token;
				m++;
				token= strtok(NULL,"|");
			}   
			int ddd=m;
			if(m==1)
			{
				len = parseSpace(store[i],parsedArgs);

				for(int ii=0;ii<len;ii++)
				{
					if(!(strcmp(parsedArgs[ii],">")) || !(strcmp(parsedArgs[ii],"<")) || !(strcmp(parsedArgs[ii],">>")))
					{
						redir=1;
					}
					//  ii++;
				}

				if(redir!=1)
				{

					Check(parsedArgs,dir,len,path_h2,-1,-1);
					i++;
				}

				else
				{ call_redirection(parsedArgs,len);
					i++;

				}
			}
			else
			{
				int z=0;
				int std_in_fd = dup(0);
				int std_out_fd = dup(1);

				while(z!=m)
				{
					int status;
					int fdd[2];
					len = parseSpace(piped_args[z],parsedArgs);
					// printf("%d",len); 



					if(z==m-1)
					{
						close(fdd[1]);
						std_in_fd=dup(0);
						int var11=0;

						if(dup2(fdd[0],0)==-1)
							fprintf(stderr,"Error: dup2 failed");
						close(fdd[0]);
					}
					else if(!z)
					{
						pipe(fdd);
						std_out_fd = dup(1);

						if(dup2(fdd[1],1)==-1)
							fprintf(stderr,"Error: dup2 failed");
					}

					else
					{
						close(fdd[1]);
						std_in_fd=dup(0);
						int fd2;
						int dd1=dup2(fdd[0],0);
						if(dd1==-1)
							fprintf(stderr,"Error: dup2 failed");
						close(fdd[0]);

						pipe(fdd);
						std_out_fd = dup(1);
						int dd2=dup2(fdd[1],1);
						if(dd2==-1)
							fprintf(stderr,"Error: dup2 failed");
					}

					int pipe_pid = fork();

					if(!pipe_pid)
					{
						// ii=0;
						redir=0;

						for(int ii=0;ii<len;ii++)

						{
							if(!(strcmp(parsedArgs[ii],">")) || !(strcmp(parsedArgs[ii],"<")) || !(strcmp(parsedArgs[ii],">>")))
							{
								redir=1;
							}
							ii++;
						}

						if(redir!=1)
						{

							Check(parsedArgs,dir,len,path_h2,-1,-1);
						}

						else
						{
							call_redirection(parsedArgs,len);
						}
						exit(0);
					}

					else
					{
						waitpid(pipe_pid,&status,WUNTRACED);
						dup2(std_in_fd,0);
						dup2(std_out_fd,1);
					}

					z++;
				}
				i++;
			}
		}
	}


	/*
	   char* parsedArgs[256];
	   char* parsedArgsPiped[256];
	   int len;
	   while(1)
	   {
	   flag=0;
	   char inputString[1000]; parsedArgs[0] = NULL;
	   parsedArgs[1] = NULL;
	   parsedArgs[2] = NULL;

	//	printf("\e[1;32m");
	printf("%s",getenv("USER")); 
	//     printf("\e[m");
	printf("@"); 
	//    printf("\e[1;32m");
	printf("%s:", hostbuffer); 

	//   printf("\e[1;34m");
	printDir(dir);
	//   printf("\e[m");
	printf("  "); 

	char ss[4]=";";

	if(takeInput(inputString))
	continue;   

	int k=0;
	char* store[1000];
	char* arg = strtok(inputString,ss);

	while(arg!=NULL)
	{
	store[k]=arg;
	k++;
	arg = strtok(NULL,ss);
	}

	int i=0;

	while(i!=k)
	{
	len = parseSpace(store[i],parsedArgs);
	Check(parsedArgs,dir,len);
	i++;
	}

	}
	*/
}
