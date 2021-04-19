# soal-shift-sisop-modul-2-B04-2021
## Anggota Kelompok ##

NRP | NAMA
------------- | -------------
05111940000111  | Evelyn Sierra
05111940000059  | Dido Fabian Fayed
05111940000139  | Zahrotul Adillah

## Soal 1
Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. 
(a) Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg 
(b) untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :). 
(c) Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu meng-extract-nya setelah didownload serta 
(d) memindahkannya ke dalam folder yang telah dibuat (hanya file yang dimasukkan).
(e) Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany). 
(f) Setelah itu pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya menyisakan .zip).
Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!

Note:
- Ulang Tahun Stevany : 09 April Pukul 22.22 WIB
- Semua poin dijalankan oleh 1 script di latar belakang, termasuk mendownload file zip-nya. Jadi cukup jalankan script 1x serta ubah time dan date untuk check hasilnya.
- Tidak boleh menggunakan fungsi system(), mkdir(), dan rename() (Yang di bahasa C) .... FORBIDDENNN!!
- Tidak boleh pake cron !!!
- Menggunakan fork dan exec.

Link :
  - Foto : https://drive.google.com/file/d/1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD/view
  - Musik : https://drive.google.com/file/d/1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J/view
  - Film : https://drive.google.com/file/d/1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp/view

Tips :
- Gunakan fungsi wait() dan sleep() untuk memperlancarrr..
- Untuk mendownload zip yang dibutuhkan bisa menggunakan command : wget --no-check-certificate "https://drive.google.com/uc?id=ID-FILE&export=download" -O Nama_untuk_filenya.ext

**Pertama-tama, inisiasi link dan nama-nama folder/file sebagai berikut :**
``` c
char *drive[] = {"https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download"};
char *nama[] = {"Musik_for_Stevany.zip","Film_for_Stevany.zip","Foto_for_Stefany.zip"};
char *dir[] = {"Musyik","Fylm","Pyoto"};
char *empty[] = {"MUSIK","FILM","FOTO"};
```
Karena soal ini membutuhkan progran yang berjalan secara otomatis pada waktu tertentu, maka diperlukan **daemon** yaitu program yang berjalan di background secara terus menerus tanpa adanya interaksi secara langsung dengan user yang sedang aktif.
``` c
int main() {
    pid_t pid, sid;   // Variabel untuk menyimpan PID
    pid = fork();     // Menyimpan PID dari Child Process
    
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
```
Nah, loop utama di atas mengandung pengecekan waktu sekarang apakah sama dengan request soal.
Waktu yang pertama adalah 6 jam sebelum waktu ulang tahun Stevany yaitu pada 9 April jam 16:22:00 **(e)**. Lalu dipanggillah `fungsi1()` yang berisi :
``` c
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
```
**Fungsi di atas memerlukan banyak fork yang sudah mencakup :**
- Membuat folder `Musyik`, `Fylm`, dan `Pyoto` **(a)**
- Mendownload file-file zip dari link yang telah disediakan **(b)**
- Ekstrak file-file zip tersebut **(c)**
- Memindahkan file-file yang ada dalam folder hasil ekstrak zip **(d)**

**Penjelasannya sebagai berikut :**
- Membuat folder `Musyik`, `Fylm`, dan `Pyoto` **(a)**
``` c
char *argv[]={"mkdir","-p",dir[0], dir[1], dir[2], NULL};
execv("/usr/bin/mkdir",argv);
```
Jadi `mkdir` digunakan untuk membuat folder, `-q` adalah quiet, dir[0], dir[1], dan dir[2] adalah `char *dir[] = {"Musyik","Fylm","Pyoto"};`

- Mendownload file-file zip dari link yang telah disediakan **(b)**
- Ekstrak file-file zip tersebut **(c)**
``` c
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
```
Untuk mendownload lalu mengekstrak diperlukan fork dimana child yang berfungsi untuk mendownload dan parent yang berfungsi untuk mengekstrak.
Jadi untuk mendownload file dari drive menggunakan `wget`, `--no-check-certificate`, `drive[0]` merupakan sumber link, `-O` untuk rename nama file, dan `nama[0]` yang merupakan nama yang diinginkan untuk rename, sedangkan `-q` adalah quiet. 
Implementasi di atas merupakan implementai untuk musik/mp3, untuk yang lainnya hanya menyesuaikan link, nama, dan penempatan forknya.

- Memindahkan file-file yang ada dalam folder hasil ekstrak zip **(d)**
```
char *argv[] = {"find", "/home/zo/Documents/sisop/m2/MUSIK", "-type","f","-exec","mv","{}","/home/zo/Documents/sisop/m2/Musyik",";", NULL};
execv("/usr/bin/find", argv);
```
Jadi, alur dari implementasi di atas adalah `find` yaitu mencari/menemukan dari `/home/zo/Documents/sisop/m2/MUSIK`, `-type` yang bertipe `f` (file) lalu dipindahkan menggunakan `-exec`, `mv`, `{}` yang telah dicari tadi ke `/home/zo/Documents/sisop/m2/Musyik`.
Implementasi di atas merupakan implementai untuk musik/mp3, untuk yang lainnya hanya menyesuaikan link, nama, dan penempatan forknya.


**Nah, persiapan sudah selesai saatnya menunggu waktu ulang tahun Stevany...**
Pada ulang tahun Stevany tepatnya 9 April jam 22:22:00 akan menjalankan `fungsi2()` yang berfungsi untuk zip semua folder yang telah dibuat dan diisi file-file dengan nama Lopyu_Stevany.zip dan folder lainnya(kosong) akan di delete(sehingga hanya menyisakan .zip)
``` c
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
```
Untuk mengerjakan soal **(f)** tersebut digunakan fork() dimana child diisi dengan proses zipping dan parent diisi dengan menghapus folder kosong

**Penjelasannya sebagai berikut :**
- Zipping
``` c
char *argv[]={"zip","-mr","/home/zo/Documents/sisop/m2/Lopyu_Stevany",dir[0], dir[1], dir[2], NULL};
execv("/usr/bin/zip",argv);
```
Nah, disini digunakan `zip`, dan `-r` yaitu format untuk zip folder, `-m` digunakan untuk move folder ke zip dan otomatis menghapus folder di OS, `/home/zo/Documents/sisop/m2/Lopyu_Stevany` yaitu penamaan zip beserta _path_nya, yang berisi `dir[0]`, `dir[1]`, dan `dir[2]` yaitu `char *dir[] = {"Musyik","Fylm","Pyoto"};`

- Hapus folder
``` c
char *argv[]={"rm","-r",empty[0], empty[1], empty[2], NULL};
execv("/usr/bin/rm",argv);
```
Digunakan `rm` dan `-r` untuk format menghapus folder dengan nama `empty[0]`, `empty[1]`, dan `empty[2]` yaitu `char *empty[] = {"MUSIK","FILM","FOTO"};`

**Note :** 
- `while((wait(&status4)) > 0);` berfungsi untuk menunda pekerjaan yang ada dibawahnya sampai proses sebelumnya selesai.
- fork terluar pada fungsi digunakan supaya program utama tetap berjalan dengan child adalah proses dari fungsi, sedangkan parent berisi `wait()` dan `return`



## Soal 2



## Soal 3



## Kendala :
- Mengecek program daemon agak susah karena berjalan pada background sehingga tidak memunculkan pesan error dan terkadang membuat terminal menjadi error dan operating sistem juga menjadi stuck
- 


