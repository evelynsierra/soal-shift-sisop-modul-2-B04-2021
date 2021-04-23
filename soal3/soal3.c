#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t main_process_id = getpid(),
          session_id = getsid(main_process_id);

    if (argc == 2) {
        FILE *kills = fopen("kill.sh", "w");

        if (!strcmp(argv[1], "-z")) {
            fprintf(kills, "#!/bin/bash\npkill -s %d\n", session_id);
        } else if (!strcmp(argv[1], "-x")) {
            fprintf(kills, "#!/bin/bash\nkill -SIGTERM %d\n\n", main_process_id);
        }
        fprintf(kills, "rm -f kill.sh");

        fclose(kills);
    }

    while (1) {
        pid_t make_dir_child_id;
        int status;

        //membuat direktori setiap 40 detik

        char tanggal[100];
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        strftime(tanggal, sizeof(tanggal) - 1, "%Y-%m-%d_%H:%M:%S", t);

        make_dir_child_id = fork();

        if (make_dir_child_id < 0) {
            exit(EXIT_FAILURE);
        }

        if (make_dir_child_id == 0) {
            char *argv[3] = {"mkdir", tanggal, NULL};
            execv("/bin/mkdir", argv);
        }

        else {
            sleep(1);
            for (int i = 0; i < 10; i++)
            //download 10 gambar dengan looping
            {
                pid_t download_picture_child_id = fork();

                if (download_picture_child_id < 0)
                    exit(EXIT_FAILURE);

                if (download_picture_child_id == 0) {
                    unsigned long get_time = (unsigned long)time(NULL);
                    get_time = (get_time % 1000) + 50;

                    char link[50];
                    sprintf(link, "https://picsum.photos/%lu", get_time);

                    time_t filet;
                    struct tm *fileti;
                    char files[50] = "";
                    char down_dir[100];

                    filet = time(0);
                    //  time (&filet);
                    fileti = localtime(&filet);

                    strftime(files, sizeof(files) - 1, "%Y-%m-%d_%H:%M:%S", fileti);
                    sprintf(down_dir, "%s/%s", tanggal, files);

                    //    strcat(down_dir,tanggal); //cocokkin path file dengan direktori
                    //    strcat(down_dir,"/"); //untuk memberi nama file
                    //   strcat(down_dir, files);

                    // printf("%s\n", down_dir);
                    char *argv[] = {"wget", "-q", "-O", down_dir, link, NULL};
                    execv("/bin/wget", argv);
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
            for (int i = 0; i < strlen(kata); i++) {
                word = kata[i];
                if (word == ' ') {
                    continue;
                }
                if (word >= 'a' && word <= 'z') {
                    word += 5;

                    if (word > 'z') {
                        word = word - 'z' + 'a' - 1;
                    }
                    kata[i] = word;
                } else if (word >= 'A' && word <= 'Z') {
                    word += 5;
                    if (word > 'Z') {
                        word = word - 'Z' + 'A' - 1;
                    }
                    kata[i] = word;
                }
            }

            char file_location[100];
            sprintf(file_location, "%s/status.txt", tanggal);
            FILE *status = fopen(file_location, "w");
            fputs(kata, status);
            fclose(status);

            //Zip file
            char zip_name[100];
            sprintf(zip_name, "%s.zip", tanggal);

            char *argv[] = {"zip", zip_name, "-rm", tanggal, NULL};
            execv("/bin/zip", argv);
        }

        sleep(40);
    }
}
