#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char *argv[])
{
  //char check[100];

  //the killer
  if(argc != 2 || argv[1][1] != "-z" & argv[1][1] != "-x")
  {
    printf("There are only -z and -x\n");
  }

  else if (argc == 2)
  {
    FILE *kill = fopen("kill.sh", "w");
    if(argv[1][1] == "-z")
    {
          fprintf(kill,"#!/bin/bash\nkillall -9 /Users/evelynsierra/ITS/Semester_4/Sisop/soal3/soal-shift-sisop-modul-2-B04-2021/soal3/soal3.c");
          //fputs(perintah_kill, kill);
          fclose(kill);
        //strcpy(check, "#!/bin/bash")
    }
    else if(argv[1][1] == "-x")
    {
      fprintf(kill,"#!/bin/bash\nkill %s /Users/evelynsierra/ITS/Semester_4/Sisop/soal3/soal-shift-sisop-modul-2-B04-2021/soal3/soal3.c", getpid());
      fclose(kill);
    }
  }

  while(1)
  {
     pid_t child1, child2;
     int status;

    //membuat direktori setiap 40 detik

      char tanggal[100];                                                      
      time_t now = time(NULL);                                          
      struct tm *t = localtime(&now); 
      strftime (tanggal, sizeof (tanggal) - 1, "%Y-%m-%d_%H:%M:%S", t);

      child1 = fork();

      if(child1 < 0)
      {
        exit(EXIT_FAILURE);
      }

      if(child1 == 0)
      {
        if(fork() == 0)
        {
          char *argv[3] = {"mkdir", tanggal, NULL};
          execv("/bin/mkdir", argv);
        }
      }

      else
      {
        sleep(1);
        for(int i = 0; i < 10 ; i++)
        //download 10 gambar dengan looping
        { 
                if(fork() == 0) 
                { 
                    unsigned long get_time = (unsigned long)time(NULL);
                    get_time = (get_time % 1000) + 50;

                    char link[50];
                    sprintf(link, "https://picsum.photos/%lu", get_time);
                    
                    time_t filet;
                    struct tm * fileti;
                    char files [50] = "";
                    char down_dir[100];
                    
                    filet = time(0);
                  //  time (&filet);
                    fileti = localtime (&filet);

                    strftime (files, sizeof(files) - 1 ,"%Y-%m-%d_%H:%M:%S",fileti);
                    sprintf(down_dir, "%s/%s", tanggal, files);

                //    strcat(down_dir,tanggal); //cocokkin path file dengan direktori
                //    strcat(down_dir,"/"); //untuk memberi nama file
                 //   strcat(down_dir, files); 
                    
    
                    printf("%s\n", down_dir);
                    char *argv[] = {"wget", "-q" , "-O", down_dir, link, NULL};
                    execv("/usr/local/bin/wget", argv);
                    exit(0);
                } 
                sleep(5);
        }   
  //      for(int i = 0; i < 10; i++)
  //      {
  //        wait(NULL);
  //      } 

          //Membuat zip dan teks
          char kata[50] = "Download Success";
          char word;

          //Caesar Cipher
          for(int i = 0; i < strlen(kata); i++)
          {
              word = kata[i];
              if(word == ' ')
              {
                  continue;
              }
              if(word >= 'a' && word <= 'z')
              {
                  word += 5;

                  if(word > 'z')
                  {
                      word = word - 'z' + 'a' - 1;
                  }
                  kata[i] = word;
              }
              else if(word >= 'A' && word <= 'Z')
              {
                  word += 5;
                  if(word > 'Z')
                  {
                      word = word - 'Z' + 'A' - 1;
                  }
                  kata[i] = word;
              }
          }
        
          char file_location[100];
          sprintf(file_location,"%s/status.txt" , tanggal);
          FILE *status = fopen(file_location, "w");
          fputs(kata, status);
          fclose(status);
          
          //Zip file
            child2 = fork();

            if(child2 < 0)
            {
                exit(EXIT_FAILURE);
            }
            if(child2 == 0)
            {
                char zip_name[100];
                sprintf(zip_name, "%s.zip", tanggal);

                char *argv[] = {"zip", zip_name, "-rm",  tanggal, NULL};
                execv("/usr/bin/zip", argv);
                exit(0);
            }  
      }
  //   while (wait(&status)>0);
       
        

//      else
//      {
//          char *arg[5] = {"cp", "-r", "/Users/evelynsierra/ITS/Semester_4/Sisop/soal3/", tanggal, NULL};
//          execv("/bin/cp", arg);
//      }
       time_t first = time(0), second ;
        while (difftime(second, first) != 40) {
            second = time(0) ;
        }
  }
  
}
