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
- Untuk mendownload zip yang dibutuhkan bisa menggunakan command : `wget --no-check-certificate "https://drive.google.com/uc?id=ID-FILE&export=download" -O Nama_untuk_filenya.ext`

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
Untuk mengerjakan nomor 2 kita harus mengunduh file zip pada link berikut https://drive.google.com/file/d/1g5rehatLEkqvuuK_eooHJXB57EfdnxVD/view?usp=sharing
Pada soal ini kita diperintahkan untuk menolong Loba dalam mengolah foto-foto hewan peliharaan dalam folder miliknya. 

(a) Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Selanjutnya program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.

**Pertama adalah inisisasi fungsi dan variabel string yang digunakan**
```c
void fungsia();
void fungsiLanjutan();
void delSubStr(char *str, char *substr);
void folderMaker(char jenis[20], char path[]);
void movePhoto(char *namaFile, char jenis[20], char nama[20], char path[]);
void addKet(char jenis[20], char nama[20], char umur[10], char path[]);
void hapus(char *name, char path[]);
```
Pada fungsi main berikut terdapat fungsi untuk mengextract file pets.zip yang sudah diunduh kedalam “/home/[user]/modul2/petshop”
```c
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
    	if(ch==0)
        {
        	char *argv[] = {"mkdir", "-p", "/Users/didofabianfayed/Documents/modul2/petshop", NULL};
        	execv("usr/bin/mkdir", argv);
    	}
    	else 
        {
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
```
`if (child_id < 0)` terdapat 3 kondisi pada 
Pada kondisi `if(ch==0)` program akan membuat deriktori baru petshop dengan menggunakan `mkdir`. Direktori tujuan "/Users/didofabianfayed/Documents/modul2/petshop". 
Dan pada fungsi `else` akan memanggil fungsi `fungsiLanjutan` akan memanggil fungsi `fungsia` untuk meng-extract dan menghapus folder yang tidak diperlukan.

Didalam `fungsia` ini akan dilakukan extract zip pets.zip ke dalam folder petshop 
```c
if(ch2==0) 
        {
        	char *argv[] = {"unzip","-q","/Users/didofabianfayed/Documents/Praktikum M2/pets.zip","-d","/Users/didofabianfayed/Documents/modul2/petshop",NULL};
        	execv("/usr/bin/unzip",argv);
```
Yang selanjutnya `find` akan mencari file bertipe direktori (`d`) terlebih dahulu lalu kemudian menghapusnya `rm` `-r`
```c
else 
        {
        	while ((wait(&status2)) > 0);
        	char *argv[] = {"find", "/Users/didofabianfayed/Documents/modul2/petshop/.","-type","d", "-exec", "rm", "-r","{}",";",NULL};
        	execv("/usr/bin/find", argv);
```
Fungsi `fungsiLanjutan` yang dipanggil di fungsi main, akan menjalankan program untuk menyelasaikan soal b, c, d dan e.
Pada `fungsiLanjutan` akan dilakukan perulangan untuk membaca path dari direktori petshop 
```c
while ((ep = readdir (dp)))
        {
        	if(strcmp(ep->d_name, ".") !=0 && strcmp(ep->d_name, "..") !=0)
            {
            	char namafile[1000];
            	strcpy(namafile, ep->d_name);

            	delSubStr(namafile, ".jpg");
              
              char jenis[20];
            	char nama[20];
            	char umur[10];
```
`strcpy(namafile, ep->d_name);` fungsi ini digunakan untuk memasukkan nama file kedalam variabel `namafile`.
Fungsi `delSubStr` digunakan untuk menghapus nama foto, dengan menghapus nama formatnya saja (.jpg) dan menyisakan nama filenya. 

Selanjutnya adalah fungsi untuk split nama file. Dengan menggunakan `strtok` akan mengabaikan  "_ dan ;" pada penamaan file di folder petshop.
```c
            	char *split;
            	split = strtok(namafile, "_;");
```
```c
            	int flag = 0;
            	while(split != NULL) {
                	if(flag==0 | flag==3) {
                    	strcpy(jenis, split); 
                     	folderMaker(jenis, path);
                	}
```
`flag =0 dan flag=3` sebagai flg jenis hewan peliharaan
ketika flag==0 atau flag==1 akan memasukkan jenis heewan ke variabel `jenis` 
Akan memanggil fungsi `folderMaker` yang nantinya digunakan untuk membuat folder. 
Folder akan dibuat sesuai dengan jenis hewan peliharaan.
```c
void folderMaker(char jenis[20], char path[])
{
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
```
Lalu `flag =1 dan flag=4` sebagai flg nama hewan peliharaan
Ketika flag 1 atau 4 maka akan memasukkan nama peliharaan ke variable `nama`.

```c
                	if(flag==1 | flag==4) {
                     	strcpy(nama, split); 
                     	movePhoto(ep->d_name, jenis, nama, path);
                   	}
```
Akan dipanggil fungsi `movePhoto` yang digunakan untuk memindahkan foto sesuai dengan kategorinya, yaitu nama, jenis, dan umur hewan peliharaan.
```c
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
```
file akan di copy (`cp`) ke path yang baru, hal ini dilakukan karena ada daftar file yang mengadung lebih dari 1 hewan dalam 1 foto yang sama.

Selanjutnya `flag =2 dan flag=5` sebagai flg umur hewan peliharaan
Ketika flag 2 atau 5 maka akan memasukkan umur peliharaan ke variable `umur`.
Akan memanggil fungsi `addKet` yang digunakan untuk menambahkan folder keterangan pada setiap folder jenis hewan.
```c
                   	if(flag==2 | flag==5) {
                     	strcpy(umur, split); 
                     	addKet(jenis, nama, umur, path);
                   	}
                   	split = strtok(NULL, "_;");
                   	flag++;
            	}
```
Fungsi `addKet` akan menentukan path keterangan.txt lalu akan membuka filenya apabila belum dibuat. File ini akan berisi keterangan nama dan umur hewan peliharaan.
```c
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
```

Selanjutnya pada `fungsiLanjutan` aka memangggil fungsi `hapus` untuk menghapus file asli dalam folder petshop karena pada fungsi `movePhoto` file sudah diduplikat ke path yang baru.
```c
            	hapus(ep->d_name,path);
        	}
      	}
```
Terakhir ditutup dengan fungsi `closedir` untuk menutup direktori. 
```c
      	(void) closedir (dp);
	} else perror ("Couldn't open the directory");
}
```


## Soal 3
Pada soal no.3, diketahui bahwa kita harus membuat program C yang dimana setiap 40 detik membuat folder dengan format sesuai timestamp `[YYYY-mm-dd_HH:ii:ss]`. 

Berikut merupakan syntax untuk mendapatkan format timestamp
```c
 pid_t make_dir_child_id;
        int status;

        char tanggal[100];
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        strftime(tanggal, sizeof(tanggal) - 1, "%Y-%m-%d_%H:%M:%S", t);

        make_dir_child_id = fork();     
```
berikut merupakan syntax untuk membuat directory dengan nama folder timestamp
```c
if (make_dir_child_id < 0) {
            exit(EXIT_FAILURE);
        }

        if (make_dir_child_id == 0) {
            char *argv[3] = {"mkdir", tanggal, NULL};
            execv("/bin/mkdir", argv);
        }
```

Selanjutnya, di dalam folder tersebut terdapat 10 gambar yang di download dari link `https://picsum.photos/`, ketentuan gambar yang didownload harus mengikuti ukuran `(n%1000) + 50 pixel`, dimana n adalah detik Epoch Unix. 
Gunakan looping untuk mendownload 10 gambar, setiap gambar berselang waktu 5 detik untuk di download
```c
for (int i = 0; i < 10; i++)
            {
                pid_t download_picture_child_id = fork();

                if (download_picture_child_id < 0)
                    exit(EXIT_FAILURE);

                if (download_picture_child_id == 0) {
                    unsigned long get_time = (unsigned long)time(NULL);
                    get_time = (get_time % 1000) + 50;
```

Setelah mendapatkan nilai Epoch Unix, masukkan ke link `https://picsum.photos/` dan diberi sleep 5 detik.
```c
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

                    // printf("%s\n", down_dir);
                    char *argv[] = {"wget", "-q", "-O", down_dir, link, NULL};
                    execv("/usr/local/bin/wget", argv);
                }

                sleep(5);
            }
```
Setelah download 10 foto, akan dimasukkan file `status.txt` yang isinya adalah tulisan `Download Success` yang sudah dienkripsi menggunakan Caesar Cipher.

```c
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
```
Setelah kata `Download Success` telah dienkripsi, maka dimasukkan ke dalam folder dan di zip
```c
 char file_location[100];
            sprintf(file_location, "%s/status.txt", tanggal);
            FILE *status = fopen(file_location, "w");
            fputs(kata, status);
            fclose(status);

            //Zip file
            char zip_name[100];
            sprintf(zip_name, "%s.zip", tanggal);

            char *argv[] = {"zip", zip_name, "-rm", tanggal, NULL};
            execv("/usr/bin/zip", argv);
```
dan diberi `sleep(40)` agar jarak interval waktu antar folder 40 detik.

Untuk mempermudah pengendalian program, dibutuhkan program killer. Program killer tersebut nantinya harus merupakan program bash. Program utama ini nantinya akan dijalankan dalam 2 mode, yaitu `-z` dan `-x`. 
```c
 pid_t main_process_id = getpid();

     if (argc == 2) {
        FILE *kills = fopen("kill.sh", "w");

        if (!strcmp(argv[1], "-z")) {
            fprintf(kills, "#!/bin/bash\nkillall -9 soal3\nrm $0\n");
        } else if (!strcmp(argv[1], "-x")) {
            fprintf(kills, "#!/bin/bash\nkillall -9 %d\nrm $0\n",main_process_id);
        }
        //fprintf(kills, "rm -f kill.sh");

        fclose(kills);
    }
```
Jika menjalankan perintah `-z` maka program utama akan menghentikan seluruh operasinya, menggunakan syntax `killall -9 soal3`. Untuk syntax `rm $0` adalah untuk menghilangkan file killernya.
Sedangkan untuk perintah `-x`, program akan berhenti apabila telah menjalankan proses di direktori sampai selesai. Di dalam file killernya menggunakan syntax `killall -9 getpid()`. Menggunakan `getpid()` untuk mendapatkan proses yang sedang berjalan untuk di kill.

## Kendala :
- Mengecek program daemon agak susah karena berjalan pada background sehingga tidak memunculkan pesan error dan terkadang membuat terminal menjadi error dan operating sistem juga menjadi stuck
- Memunculkan file kill.sh agak susah karena menyesuaikan dengan argumennya
- Jika membuat ingin menggunakan wget, harus memperhatikan path wget nya
- getpid() harus disesuaikan karena bisa salah mengambil pid


