[cursoredes@localhost practica2.3]$ ps -F
UID        PID  PPID  C    SZ   RSS PSR STIME TTY          TIME CMD
cursore+  2099  2065  0 29150  3296   0 18:17 pts/0    00:00:00 bash
cursore+  3698  2099  0 38831  1844   0 19:30 pts/0    00:00:00 ps -F
[cursoredes@localhost practica2.3]$ ps -o pid,pgid,sess,state,cmd
  PID  PGID  SESS S CMD
 2099  2099  2099 S bash
 3739  3739  2099 R ps -o pid,pgid,sess,state,cmd

Comparten la misma sesion. El pgid del proceso creadp es el mismo que su pid 
