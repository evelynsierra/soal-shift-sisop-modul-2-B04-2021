#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

//2A
int main() 
{
    char sourcefile[10000]= "/Users/didofabianfayed/Documents/Praktikum M2/pets.zip";
    char newdest[10000]= "/Users/didofabianfayed/Documents/modul2/petshop";

    int func;
    pid_t pchild;

    pchild = fork();
    // if (pchild < 0){
    //     exit (EXIT_FAILURE);
    //}
    if (pchild==0) 
    {
        char *createnew[] = {"mkdir", "-p", newdest, NULL};

        execv("/usr/bin/mkdir", createnew);
    }
    else 
    {
        char *unzipfile[] = {"unzip", sourcefile, "-d", newdest, "*.jpg" , newdest, NULL};
        execv("/usr/bin/unzip", unzipfile);
    }
}