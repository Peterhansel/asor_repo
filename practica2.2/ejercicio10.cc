// AAAAAAAAAAAAAAAAAAAAAAAAA

//[cursoredes@localhost practica2.2]$ mkdir directorio
//[cursoredes@localhost practica2.2]$ touch fichero
//[cursoredes@localhost practica2.2]$ ln -s directorio a
//[cursoredes@localhost practica2.2]$ ln -s fichero b
//[cursoredes@localhost practica2.2]$ ls -l
//total 60
//lrwxrwxrwx 1 cursoredes cursoredes   10 Dec 20 22:26 a -> directorio
//lrwxrwxrwx 1 cursoredes cursoredes    7 Dec 20 22:28 b -> fichero
//drwxr-x--- 2 cursoredes cursoredes    6 Dec 20 22:21 directorio
//...
//...
//[cursoredes@localhost practica2.2]$ ls -i
//33974027 a              34139002 ejercicio5     33974024 ejercicio9.cc
//33974030 b              34139001 ejercicio5.cc  34138996 ejercico2.cc
//17153310 directorio     33974016 ejercicio6.cc  33974026 fichero
//34138995 ejercicio1.cc  33974017 ejercicio7.cc  34144044 prueba
//34138997 ejercicio3.cc  33974018 ejercicio8.cc
//34138998 ejercicio4.cc  33974025 ejercicio9


// BBBBBBBBBBBBB

[cursoredes@localhost practica2.2]$ ln directorio Ar
ln: ‘directorio’: hard link not allowed for directory
[cursoredes@localhost practica2.2]$ ln fichero Br
[cursoredes@localhost practica2.2]$ ls -li
total 60
33974027 lrwxrwxrwx 1 cursoredes cursoredes   10 Dec 20 22:26 a -> directorio
33974030 lrwxrwxrwx 1 cursoredes cursoredes    7 Dec 20 22:28 b -> fichero
33974026 -rw-r----- 2 cursoredes cursoredes    0 Dec 20 22:21 Br
17153310 drwxr-x--- 2 cursoredes cursoredes    6 Dec 20 22:21 directorio
34138995 -rw-r--r-- 1 root       root        410 Dec 15 23:19 ejercicio1.cc
34138997 -rw-r--r-- 1 root       root         57 Dec 16 01:09 ejercicio3.cc
34138998 -rw-r--r-- 1 root       root        197 Dec 16 01:15 ejercicio4.cc
34139002 -rwxr-xr-x 1 root       root       8448 Dec 18 19:55 ejercicio5
34139001 -rw-r--r-- 1 root       root        152 Dec 18 19:54 ejercicio5.cc
33974016 -rw-rw-rw- 1 root       root        244 Dec 19 20:35 ejercicio6.cc
33974017 -rw-rw-rw- 1 root       root        253 Dec 19 20:53 ejercicio7.cc
33974018 -rw-rw-rw- 1 root       root        326 Dec 19 21:00 ejercicio8.cc
33974025 -rwxr-x--- 1 root       root       8776 Dec 20 18:38 ejercicio9
33974024 -rw-r----- 1 root       root       1038 Dec 20 22:19 ejercicio9.cc
34138996 -rw-r--r-- 1 root       root        164 Dec 16 00:37 ejercico2.cc
33974026 -rw-r----- 2 cursoredes cursoredes    0 Dec 20 22:21 fichero
34144044 -rw-r----- 1 cursoredes cursoredes    0 Dec 19 19:28 prueba


//		CCCCCCCC

// Si eliminas un enlace rigido se decrementa el numero de enlaces al nodo
// y la informacion sigue siendo accesible desde el resto de enlaces
//Si eliminas el enlace simbolico el contador de enlaces se queda igual y
// el enlace actua como un puntero
//Si se borra el fichero original el enlace simbolico queda roto,
// ya que apunta al fichero original ("acceso directo") en cambio el rigido
// apunta directamente al nodo y por lo tanto puede seguir accediendo a la informacion
