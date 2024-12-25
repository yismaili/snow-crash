## **level14:**

In this level (level 14), I couldn't find any files. I tried using the find command, but I couldn't locate any flag:

```
level14@SnowCrash:~$ find / -name flag14 2>/dev/null
level14@SnowCrash:~$ find / -user flag14 2>/dev/null
level14@SnowCrash:~$
```

After too many attempts to find something, I couldn’t find anything. Ah, I’m just kidding!

**Reversing the Binary:**

I decided to reverse the binary file of `getflag`. I used the command `disas main` to show the functions used in the binary:

```
level14@SnowCrash:~$ gdb /bin/getflag
[..]
(gdb) b main
Breakpoint 1 at 0x804894a
(gdb) run
Starting program: /bin/getflag

Breakpoint 1, 0x0804894a in main ()
(gdb) disas main
[...]
   0x08048de5 <+1183>:	mov    0x804b060,%eax
   0x08048dea <+1188>:	mov    %eax,%ebx
   0x08048dec <+1190>:	movl   $0x8049220,(%esp)
   0x08048df3 <+1197>:	call   0x8048604 <ft_des>
   0x08048df8 <+1202>:	mov    %ebx,0x4(%esp)
   0x08048dfc <+1206>:	mov    %eax,(%esp)
   0x08048dff <+1209>:	call   0x8048530 <fputs@plt>
   [...]
End of assembler dump.
(gdb)
```

**Explanation:**

- Each line represents an instruction that the CPU executes.
- The addresses (e.g., `0x08048de5`) indicate where in memory these instructions are located.
- The instructions involve moving values into registers (like `%eax` and `%ebx`) and calling functions (like `<ft_des>`), which likely performs some operation related to retrieving the flag.

- **GDB (GNU Debugger):** i opened the `getflag` binary in GDB, which is a powerful tool for debugging and reverse engineering.
- **Setting a Breakpoint:** The command `b main` sets a breakpoint at the beginning of the `main()` function. When run the program, it will stop execution right at that point.
- **Disassembling the Main Function:** The `disas main` command disassembles the `main` function, showing you the assembly code. This code reveals what the program is doing at the lower level, which can help identify how it retrieves or calculates the flag.

After many attempts, I found the right address: `0x08048de5`. Now, let's jump to this address to get the token:

```
level14@SnowCrash:~$ gdb /bin/getflag
[..]
(gdb) b main
Breakpoint 1 at 0x804894a
(gdb) run
Starting program: /bin/getflag
Breakpoint 1, 0x0804894a in main ()
(gdb) ju *0x08048de5
Continuing at 0x8048de5.
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
[..]
Program received signal SIGABRT, Aborted.
0xb7fdd428 in __kernel_vsyscall ()
(gdb)
```

**Explanation:**

- The `ju` command in GDB jumps to the specified address and continues execution from there.
- By doing this, you're bypassing any checks or conditions that might prevent you from getting the flag.

Then I found the token to switch to **flag14**:

```
level14@SnowCrash:~$ su flag14
Password:7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
flag14@SnowCrash:~$
```