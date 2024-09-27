## level09:

In this level, I found two files: one of them is a binary file, and the other is a token. I tried to execute the binary file, and the output was:

```bash
level09@SnowCrash:~$ ls
level09  token
level09@SnowCrash:~$ ./level09
You need to provied only one arg.
level09@SnowCrash:~$ ./level09  token
tpmhr
level09@SnowCrash:~$
```

The approach I am describing is a form of simple 'shift decoding,' where each ASCII code is adjusted by subtracting its position in the sequence to reveal the original values

```c
level09@SnowCrash:~$ ./level09 a
a
level09@SnowCrash:~$ ./level09 ab
ac
level09@SnowCrash:~$ ./level09 abd
acf
level09@SnowCrash:~$ ./level09 1
1
level09@SnowCrash:~$ ./level09 12
13
level09@SnowCrash:~$ ./level09 16
17
level09@SnowCrash:~$
```

I can implement this in C by adjusting the ASCII values as I iterate through the characters:

```c
#include <stdio.h>

int main(int ac, char **av)
{
    const char *encoded;
    int i = 0;

    if (ac != 2)
    {
        printf("You need to provied only one arg.\n");
        return 1;
    }

    encoded = av[1];

    while (encoded[i])
    {
        printf("%c", encoded[i] - i);
        i++;
    }
    printf("\n");
    return 0;
}
```

Now, let's run this program and pass the token as an argument file to get the password for flag09.

```c
level09@SnowCrash:~$ vim /tmp/decode.c
level09@SnowCrash:~$ cd /tmp
level09@SnowCrash:/tmp$ gcc decode.c -o decode
level09@SnowCrash:/tmp$ cd 
level09@SnowCrash:~$ /tmp/decode $(cat token)
f3iji1ju5yuevaus41q1afiuq
```

Then, I got the password for the next level.

```c
level09@SnowCrash:~$ su flag09
Password:f3iji1ju5yuevaus41q1afiuq
Don't forget to launch getflag !
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
flag09@SnowCrash:~$
```

##