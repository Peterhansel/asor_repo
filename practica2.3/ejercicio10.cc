//TERMINAL SLEEP

[cursoredes@localhost practica2.3]$ sleep 600
Terminated

//TERMINAL KILL

[cursoredes@localhost practica2.3]$ ps -a
  PID TTY          TIME CMD
 8469 pts/2    00:00:00 man
 8479 pts/2    00:00:00 less
 8503 pts/0    00:00:00 sleep
 8511 pts/1    00:00:00 ps
[cursoredes@localhost practica2.3]$ kill 8503

