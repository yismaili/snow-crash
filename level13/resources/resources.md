## **level13:**

In this level, I found a binary file:

```
level13@SnowCrash:~$ ls -la
total 20
[...]
-rwsr-sr-x 1 flag13  level13 7303 Aug 30  2015 level13
[...]
level13@SnowCrash:~$
```

The s in the permissions (e.g., rwsr-sr-x) indicates that the binary is a setuid binary. This means when it's executed, it runs with the permissions of its owner (flag13), regardless of who actually runs the file.

- When i run the binary with my user (UID 2013), it checks the UID and prints the message:

```
level13@SnowCrash:~$ ./level13
UID 2013 started us but we we expect 4242
level13@SnowCrash:~$
```

This meaning the binary expects to be run by a user with UID 4242, not 2013. If the UID isn't 4242, it won’t continue and exit early

```
gdb ./level13
```

I disassembled the program's main function using GDB:

```
disas main
```

The important part of the disassembly is here:

```
0x08048595 <+9>:  call   0x8048380 getuid@plt       # Call getuid to get the current UID
0x0804859a <+14>: cmp    $0x1092,%eax                # Compare the returned UID with 4242 (0x1092)
0x0804859f <+19>: je     0x80485cb <main+63>         # If UID is 4242, continue to the token generation
0x080485a1 <+21>: call   0x8048380 getuid@plt       # Otherwise, print the error and exit
0x080485c6 <+58>: call   0x80483a0 exit@plt
```

- **getuid function**: This function returns the UID of the user running the program.

After calling `getuid`, the program compares the returned value (stored in the register `EAX`) with `4242` (which is `0x1092` in hexadecimal). If the UID is not `4242`, the program exits.

This is the key part of the binary's logic. To bypass this check, we need to **manipulate the return value of `getuid`** so that it always returns `4242`, regardless of the actual UID.

**GDB** is a powerful tool that allows you to debug programs by stepping through the assembly instructions, examining memory, and even modifying register values during execution.

Set a **breakpoint** at the `getuid` function to stop the program's execution right after it fetches the UID:

```
b getuid
```

Then, i ran the program, and it stopped at the getuid call:

```
run
step
```

After stepping forward, i checked the value in the `EAX` register, which contained the actual UID (in my case, `2013`):

```
print $eax
```

Then modified the value in the EAX register to 4242 (the expected UID):

```
set $eax=4242
print $eax
step
```

After modifying the register, i continued stepping through the program. Since the program now saw 4242 in the EAX register, it bypassed the UID check and proceeded to the next section where it prints the token:

```
(gdb) print $eax
$2 = 4242
(gdb) step
Single stepping until exit from function main,
which has no line number information.
your token is 2A31L79asukciNyi8uppkEuSx
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
(gdb)
```

The password of this next level (level14)is :

```
level13@SnowCrash:~$ su level14
Password: 2A31L79asukciNyi8uppkEuSx
level14@SnowCrash:~$
```