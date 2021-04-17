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

void fungsia();
void fungsiLanjutan();
void delSubStr(char *str, char *substr);
void folderMaker(char jenis[20], char path[]);
void movePhoto(char *namaFile, char jenis[20], char nama[20], char path[]);
void addKet(char jenis[20], char nama[20], char umur[10], char path[]);
void hapus(char *name, char path[]);


int main() 
{
	pid_t child_id;
	int status;
	child_id = fork();
    
	if (child_id < 0) 
    {
    	exit(EXIT_FAILURE);
  	}
  	if (child_id == 0)
      {
      	pid_t ch = fork();
      	int st;
      	if(ch<0){
          	exit(EXIT_FAILURE);
    	}
    	if(ch==0) //untuk membuat dirrektori baru petshop
        {
        	char *argv[] = {"mkdir", "-p", "/Users/didofabianfayed/Documents/modul2/petshop", NULL};
        	execv("usr/bin/mkdir", argv);
    	}
    	else {
        	while ((wait(&st)) > 0);
        	fungsia(); //unzip + hapus folder
    	}
  	}
	else 
    {
    	while((wait(&status)) > 0);
    	fungsiLanjutan();
  	}
}

void fungsia(){
	pid_t ch1 = fork();
	int status1;
    
	if(ch1<0)
    {
    	exit(EXIT_FAILURE);
	}
	if(ch1==0)
    {
    	pid_t ch2 = fork();
    	int status2;
   	 
    	if(ch2<0)
        {
        	exit(EXIT_FAILURE);
    	}
    	if(ch2==0) //extract zip pets.zip ke folder petshop 
        {
        	char *argv[] = {"unzip","-q","/Users/didofabianfayed/Documents/Praktikum M2/pets.zip","-d","/Users/didofabianfayed/Documents/modul2/petshop",NULL};
        	execv("/usr/bin/unzip",argv);
    	}
    	else //menghapus folder yang tidak diperlukan dengan mencari foldernya terlebih dahulu kemudian menghapusnya
        {
        	while ((wait(&status2)) > 0);
        	char *argv[] = {"find", "/Users/didofabianfayed/Documents/modul2/petshop/.","-type","d", "-exec", "rm", "-r","{}",";",NULL};
        	execv("/usr/bin/find", argv);
    	}
	}
	else //agar program tetap berjalan
    {
    	while ((wait(&status1)) > 0);
    	return;
	}
}

void fungsiLanjutan()
{
	DIR *dp;
	struct dirent *ep;
	char path[] = "/Users/didofabianfayed/Documents/modul2/petshop/";

	dp = opendir(path);

	if (dp != NULL)
	{
      	while ((ep = readdir (dp)))
        {
        	if(strcmp(ep->d_name, ".") !=0 && strcmp(ep->d_name, "..") !=0)
            {
            	char namafile[1000];
            	strcpy(namafile, ep->d_name);

            	delSubStr(namafile, ".jpg"); //hapus format foto (.jpg)
           	 
            	char jenis[20];
            	char nama[20];
            	char umur[10];

            	char *split;
            	split = strtok(namafile, "_;");
        	 
            	int flag = 0;
            	while(split != NULL) {
                	if(flag==0 | flag==3) {
                    	strcpy(jenis, split); //buat folder sesuai jenis hewan
                     	folderMaker(jenis, path);
                	}
                	if(flag==1 | flag==4) {
                     	strcpy(nama, split); //mindah foto sesuai kategori
                     	movePhoto(ep->d_name, jenis, nama, path);
                   	}
                   	if(flag==2 | flag==5) {
                     	strcpy(umur, split); //buat keterangan di tiap folder
                     	addKet(jenis, nama, umur, path);
                   	}
                   	split = strtok(NULL, "_;");
                   	flag++;
            	}
            	hapus(ep->d_name,path);
        	}
      	}
      	(void) closedir (dp);
	} else perror ("Couldn't open the directory");
}

void delSubStr(char *str, char *substr)
{
	char *sama;
	int pjg = strlen(substr);
	while ((sama = strstr(str, substr))) 
    {
      	*sama = '\0';
      	strcat(str, sama+pjg);
	}
}

void folderMaker(char jenis[20], char path[])
{
	//nentuin nama foldernya
	char namaFolder[200]="";
	strcpy(namaFolder, path);
	strcat(jenis, "/");
	strcat(namaFolder, jenis);
    
	pid_t child_id = fork();
	int status;

	if (child_id < 0) {
      	exit(EXIT_FAILURE);
	}

	if (child_id == 0) {
   	char *argv[] = {"mkdir", "-p", namaFolder, NULL};
   	execv("/bin/mkdir", argv);
	}
	else {
    	while((wait(&status)) > 0);
    	return;
	}
}

void movePhoto(char *namaFile, char jenis[20], char nama[20], char path[])
{
	char asli[100]="";
	strcat(asli, path);
	strcat(asli, namaFile);

	//nentuin path yg baru + ganti nama
	char baru[100]="";
	strcat(baru, path);
	strcat(baru, jenis);
	strcat(baru, "/");
	strcat(baru, nama);
	strcat(baru, ".jpg");
    
	pid_t child_id = fork();
	int status;

	if (child_id < 0) 
    {
  	exit(EXIT_FAILURE);
	}

	if (child_id == 0) 
    {
   	char *argv[] = {"cp", asli, baru, NULL};
   	execv("/bin/cp", argv);
	}
	else 
    {
    	while((wait(&status)) > 0);
    	return;
	}
}
//fungsi untuk menambah keterangan
void addKet(char jenis[20], char nama[20], char umur[10], char path[])
{
	FILE *fp;
	char pathket[100] = "";

	strcat(pathket, path);
	strcat(pathket, jenis);
	strcat(pathket, "/keterangan.txt");

	fp = fopen (pathket, "a");
	fprintf(fp, "nama: %s\numur: %s tahun\n\n", nama, umur);
	fclose(fp);
	return;
}
//fungsi untuk menghapus file asli 
void hapus(char *name,char path[])
{
	char asli[100] = "";
	strcat(asli, path);
	strcat(asli, name);
    
	pid_t child_id = fork();
	int status;

	if (child_id < 0) 
    {
    	exit(EXIT_FAILURE);
	}
	if (child_id == 0) {
    	char *argv[] = {"rm",asli, NULL};
    	execv("/bin/rm", argv);
	}
	else 
    {
    	while((wait(&status)) > 0);
    	return;
	}
}