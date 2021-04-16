#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>

char *drive[] = {"https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download"};
char *nama[] = {"Musik_for_Stevany.zip","Film_for_Stevany.zip","Foto_for_Stefany.zip"};
char *dir[] = {"Musyik","Fylm","Pyoto"};
char *empty[] = {"MUSIK","FILM","FOTO"};
    
void fungsi1(){
	pid_t lala = fork();
	int statuslala;
    
	if(lala<0) exit(EXIT_FAILURE);
    
    	if(lala==0){
        	pid_t anu = fork();
        	int statusanu;
       	 
        	if(anu<0) exit(EXIT_FAILURE);
       	 
        	if(anu==0){
            	char *argv[]={"mkdir","-p",dir[0], dir[1], dir[2], NULL};
            	execv("/usr/bin/mkdir",argv);
        	}
        	else{
            	while((wait(&statusanu)) > 0);
            	pid_t ch1 = fork();
            	int status1;
           	 
            	if(ch1<0) exit(EXIT_FAILURE);
           	 
            	if(ch1==0){
                	pid_t ch2 = fork();
                	int status2;
               	 
                	if(ch2<0) exit(EXIT_FAILURE);
               	 
                	if(ch2==0){
                    	pid_t ch3 = fork();
                    	int status3;
                   	 
                    	if(ch3<0) exit(EXIT_FAILURE);
                   	 
                    	if(ch3==0){//downlod + unzip musik
                        	pid_t ch4 = fork();
                        	int status4;
                       	 
                        	if(ch4<0) exit(EXIT_FAILURE);
                       	 
                        	if(ch4==0){
                               	char *argv[] = {"wget","-q","--no-check-certificate",drive[0],"-O",nama[0], NULL};
                            	execv("/usr/bin/wget",argv);
                        	}
                        	else{
                            	while((wait(&status4)) > 0);
                            	char *argv[] = {"unzip", nama[0], NULL};
                            	execv("/usr/bin/unzip", argv);
                        	}
                    	}
                    	else{//downlod + unzip film
                        	while((wait(&status3)) > 0);
                        	pid_t ch5 = fork();
                        	int status5;
                       	 
                        	if(ch5<0) exit(EXIT_FAILURE);
                       	 
                        	if(ch5 == 0){
                            	char *argv[] = {"wget","-q","--no-check-certificate",drive[1],"-O",nama[1], NULL};
                            	execv("/usr/bin/wget", argv);
                        	}
                        	else{
                            	while((wait(&status5)) > 0);
                            	char *argv[] = {"unzip", nama[1], NULL};
                            	execv("/usr/bin/unzip", argv);
                        	}
                    	}
                	}//punyaif2
                	else{//downlod + unzip foto
                    	while((wait(&status2)) > 0);
                    	pid_t ch6 = fork();
                    	int status6;
                   	 
                    	if(ch6<0) exit(EXIT_FAILURE);
                   	 
                    	if(ch6 == 0){
                        	char *argv[] = {"wget","-q","--no-check-certificate",drive[2],"-O",nama[2], NULL};
                           	execv("/usr/bin/wget", argv);
                    	}
                    	else{
                        	while((wait(&status6)) > 0);
                        	char *argv[] = {"unzip", nama[2], NULL};
                        	execv("/usr/bin/unzip", argv);
                    	}
                	}
               	}//punyaif1
               	else{
                   	while((wait(&status1)) > 0);
                   	pid_t ch7 = fork();
                   	int status7;
                  	 
                   	if(ch7<0) exit(EXIT_FAILURE);
                  	 
                   	if(ch7==0){
                       	pid_t ch8 = fork();
                       	int status8;
                      	 
                       	if(ch8<0) exit(EXIT_FAILURE);
                      	 
                    	if(ch8==0){//mindah musik
                        	char *argv[] = {"find", "/home/zo/Documents/sisop/m2/MUSIK", "-type","f","-exec","mv","{}","/home/zo/Documents/sisop/m2/Musyik",";", NULL};
                        	execv("/usr/bin/find", argv);
                    	}
                    	else{//mindah film
                        	while((wait(&status8)) > 0);
                        	char *argv[] = {"find", "/home/zo/Documents/sisop/m2/FILM", "-type","f","-exec","mv","{}","/home/zo/Documents/sisop/m2/Fylm",";", NULL};
                        	execv("/usr/bin/find", argv);
                    	}
                	}
                	else{//mindah foto
                    	while((wait(&status7)) > 0);
                    	char *argv[] = {"find","/home/zo/Documents/sisop/m2/FOTO","-type","f","-exec","mv","{}","/home/zo/Documents/sisop/m2/Pyoto",";", NULL};
                    	execv("/usr/bin/find", argv);
                	}
            	}
        	}//punyaelseanu
    	}//punyalala
    	else{
        	while((wait(&statuslala)) > 0);
        	return;
    	}
}

void fungsi2(){
	pid_t lili = fork();
	int statuslili;
    
	if(lili<0) exit(EXIT_FAILURE);
    
	if(lili==0){
    	pid_t ch9 = fork();
        	int status9;
       	 
        	if(ch9<0) exit(EXIT_FAILURE);

        	if(ch9==0){//ngezip
            	char *argv[]={"zip","-mr","/home/zo/Documents/sisop/m2/Lopyu_Stevany",dir[0], dir[1], dir[2], NULL};
               	execv("/usr/bin/zip",argv);
        	}
        	else{//buang folder kosong
            	while((wait(&status9)) > 0);
            	char *argv[]={"rm","-r",empty[0], empty[1], empty[2], NULL};
            	execv("/usr/bin/rm",argv);
        	}   
	}
	else{
    	while((wait(&statuslili)) > 0);
    	return;
	}
}

int main() {
	pid_t pid, sid;   // Variabel untuk menyimpan PID
	pid = fork(); 	// Menyimpan PID dari Child Process
    
	/* Keluar saat fork gagal
 	* (nilai variabel pid < 0) */
	if (pid < 0) {
    	exit(EXIT_FAILURE);
	}
    
	/* Keluar saat fork berhasil
	* (nilai variabel pid adalah PID dari child process) */
	if (pid > 0) {
    	exit(EXIT_SUCCESS);
	}
    
	umask(0);
    
	sid = setsid();
	if (sid < 0) {
    	exit(EXIT_FAILURE);
	}
    
	if ((chdir("/home/zo/Documents/sisop/m2")) < 0) {
    	exit(EXIT_FAILURE);
	}
    
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
    
	while(1){
    	time_t waktu;
      	struct tm* tm_skrg;

      	waktu = time(NULL);
      	tm_skrg = localtime(&waktu);
     	 
      	if(tm_skrg->tm_mon==3 && tm_skrg->tm_mday==9 && tm_skrg->tm_hour==16 && tm_skrg->tm_min==22 && tm_skrg->tm_sec==0){
        	fungsi1();
    	}
    	else if(tm_skrg->tm_mon==3 && tm_skrg->tm_mday==9 && tm_skrg->tm_hour==22 && tm_skrg->tm_min==22 && tm_skrg->tm_sec==0){
        	fungsi2();        	 
    	}
	}sleep(1);
}



