Here dir/ means a Directory path

The takeInput.c file takes command input from user .

addhistory.c:adds commands to history list .(it is called in takeInput.c)
printhistory:prints history of commands

call_cd: handles the cd command 


echo:
    The call_echo.c file handles the echo command
    This supports echo abc which prints abc and if we do echo "abc" it prints "abc"

ls:
    The call_ls.c file handles the various types of ls commands
    This supports:
        ls
        ls -l
        ls -la
        ls -al
        ls -a
        ls dir/
        ls -l dir/
        ls -la dir/
        ls -al dir/
        ls -a dir/

nightswatch:
    The call_nightswatch.c handles the command nightswatch with "interrupt" and "dirty" being possible arguments
    format: here i is time in seconds
        nightswatch -n i interrupt
        nightswatch -n i dirty 

pinfo:
    The call_pinfo.c file handles the pinfo command
    The format is:
        pinfo
        pinfo procnum


pwd:
    The call_pwd.c handles the pwd command

The Check.c file checks the command input and then calls a function appropriately. 
The printDir.c file prints the current Directory of the shell while replacing the place where the shell is located by with ~
