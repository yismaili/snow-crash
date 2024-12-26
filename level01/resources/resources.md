## level01:

In this level, we also need to find the token to log in to **level02**. After a few attempts, I decided to search for files that contain user information in Linux. I discovered the `/etc/passwd` file, which contains details about all the user accounts on the system.

```jsx
level01@SnowCrash:~$ cat /etc/passwd | grep "flag01"
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

and then here we can see the an encrypted string `42hDRfypTqqnw`

Files like `/etc/passwd` or  `/etc/shadow` store hashed passwords, and this is a typical scenario where **John the Ripper** is used.

Let's talk about **John the Ripper**. It is a tool used to crack password hashes.

```jsx
root@debian:~# echo "42hDRfypTqqnw" > password
root@debian:~# john password
Created directory: /root/snap/john-the-ripper/639/.john
Created directory: /root/snap/john-the-ripper/639/.john/opencl
Warning: detected hash type "descrypt", but the string is also recognized as "descrypt-opencl"
Use the "--format=descrypt-opencl" option to force loading these as that type instead
Using default input encoding: UTF-8
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 256/256 AVX2])
Proceeding with single, rules:Single
Press 'q' or Ctrl-C to abort, 'h' for help, almost any other key for status
Almost done: Processing the remaining buffered candidate passwords, if any.
Proceeding with wordlist:/snap/john-the-ripper/current/run/password.lst
Enabling duplicate candidate password suppressor
abcdefg          (?)
1g 0:00:00:00 DONE 2/3 (2024-09-13 16:12) 9.091g/s 6981p/s 6981c/s 6981C/s dance..bigman
Use the "--show" option to display all of the cracked passwords reliably
Session completed.
root@debian:~#
```

The password is: `abcdefg`

```jsx
level01@SnowCrash:~$ su flag01
Password: abcdefg
Don't forget to launch getflag !
```

Then use `getflag` to retrieve the flag:

```jsx
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
```

This is the token to pass to **level02**

```jsx
flag01@SnowCrash:~$ su level02
Password: f2av5il02puano7naaf6adaaf
level02@SnowCrash:~$
```

using **John the Ripper Docker image**

```
docker pull adamoss/john-the-ripper
docker run -it -v `pwd`/level01/flag:/crackme.txt adamoss/john-the-ripper /crackme.txt
```