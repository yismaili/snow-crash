## **level00:**

in this level we have to find the **flag00** after file this flag we have to decepet password how can i decrept the password to login `su flag00` to git password of **level01:**

to find the fiel **flag00** use:

```jsx
find / -user flag00 2>/dev/null 
```

or

```jsx
find / -uid $(id -u flag00) 2>/dev/null
```

`find`:  *This is the command used to search for files and directories in a directory hierarchy*

`/`: *This specifies the starting directory for the `find` command*

**`-user flag00`**: *This is a search criterion for the `find` command. The `-user` option tells `find` to look for files owned by the user `flag00`*

**`2>/dev/null`**: This part of the command redirects error messages (file descriptor 2) to `/dev/null`

the outup of the cmd line `find`:

```
/usr/sbin/john
/rofs/usr/sbin/john
```

and then we need to `cat` the file:

```jsx
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```

or 

```jsx
level00@SnowCrash:~$ cat /rofs/usr/sbin/john
cdiiddwpgswtgt
```

we need to decode the password `cdiiddwpgswtgt` the first step we have to Analyze the Text, Check the characters used. For example: 

- **Base64**: Contains letters, numbers, `+`, `/`, and sometimes `=` padding.
- **Hexadecimal**: Contains characters `0-9` and `a-f`.
- **Binary**: Contains only `0` and `1`.

Second step Check Common Ciphers: 

- **Caesar Cipher (ROT-n)**: Commonly involves shifting letters by a fixed number. Try different shifts (ROT13, ROT15, etc.) if the text looks like it could be a simple substitution.
- **Substitution Cipher**: Each letter is replaced by another letter. Common if the text has an odd or uniform pattern.
- **Transposition Cipher**: Rearranges the characters in a systematic way.

Third step Use Online Tools: 

The result is a **Caesar Cypther**, more precisely it is a **ROT 15.**

you can easily decriptit by using an online tool such as

https://cryptii.com/

The result of the rot 11 is : `nottoohardhere`

```jsx
evel00@SnowCrash:~$ su flag00
Password: nottoohardhere
Don't forget to launch getflag !
```

Once we are in flag00 account, then get the next level password using the following command:

```jsx
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
```
