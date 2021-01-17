[cursoredes@localhost ~]$ echo $$
2099
[cursoredes@localhost ~]$ sudo renice -n -10 -p 2099
2099 (process ID) old priority 0, new priority -10
[cursoredes@localhost ~]$ sudo chrt -p 2099
pid 2099's current scheduling policy: SCHED_OTHER
pid 2099's current scheduling priority: 0
[cursoredes@localhost ~]$ sudo chrt -f -p 12 2099
[cursoredes@localhost ~]$ sudo chrt -p 2099
pid 2099's current scheduling policy: SCHED_FIFO
pid 2099's current scheduling priority: 12

