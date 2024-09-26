## level02:

After logging in to **level02**, I found a file named `level02.pcap`. This file is a packet capture file, which contains network traffic data captured by tools such as Wireshark, tcpdump, or other network packet capture utilities

**Wireshark:** 

is a powerful network protocol analyzer that allows you to capture and inspect data packets traveling through a network

```jsx
root@debian:/home/yoyo# scp -P 4242 level02@10.13.100.141:/home/user/level02/level02.pcap .
The authenticity of host '[10.13.100.141]:4242 ([10.13.100.141]:4242)' can't be established.
ECDSA key fingerprint is SHA256:4A6WreWhwmO33dtmc3AULc7YmCQ99b0dmww1TBysJoQ.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '[10.13.100.141]:4242' (ECDSA) to the list of known hosts.
	   _____                      _____               _
	  / ____|                    / ____|             | |
	 | (___  _ __   _____      _| |     _ __ __ _ ___| |__
	  \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
	  ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
	 |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          10.13.100.141
level02@10.13.100.141's password:f2av5il02puano7naaf6adaaf
level02.pcap                                                                                100% 8302     1.2MB/s   00:00
root@debian:/home/yoyo# ls
Desktop  Documents  Downloads  ft_shield  level02.pcap	Music  mypasswd  pass  Pictures  Public  SecLists  Templates  Videos
root@debian:/home/yoyo#
```

After copying `level02.pcap` from `level02` to another machine, I opened the file in Wireshark. Upon analyzing the network traffic, I found a packet containing the word '`Password`', as shown in the following image:

<img width="535" alt="Screen Shot 2024-09-17 at 6 09 58 PM" src="https://github.com/user-attachments/assets/2ddda762-173e-4585-9531-0170ee9e2948">
<img width="647" alt="Screen Shot 2024-09-17 at 6 12 30 PM" src="https://github.com/user-attachments/assets/de98b585-9ead-4c3f-880f-f3c51611b82c">

<img width="778" alt="Screen Shot 2024-09-17 at 6 12 59 PM" src="https://github.com/user-attachments/assets/3218f6f6-eee2-4677-b19f-13fbbd9a9531">
<img width="662" alt="Screen Shot 2024-09-17 at 6 14 21 PM" src="https://github.com/user-attachments/assets/38e8b2f1-c4c2-4963-a860-2c20e9f869ea">

The password is `ft_wandr...NDRel.L0L`. Now, I need to remove the dots (`.`) from the password because they represent non-printable data.

### Initial Input

1. **User Types:**
    - `f` (0x66)
    - `t` (0x74)
    - `_` (0x5f)
    - `w` (0x77)
    - `a` (0x61)
    - `n` (0x6e)
    - `d` (0x64)
    - `r` (0x72)
    
    Result: "ft_wandr"
    

### Deletion

1. **User Presses Delete (0x7f) Three Times:**
    - The `Delete` key removes the last character each time it is pressed. So, pressing it three times removes "ndr" from "ft_wandr".
    
    Result: "ft_wa"
    

### Further Input

1. **User Types:**
    - `N` (0x4e)
    - `D` (0x44)
    - `R` (0x52)
    - `e` (0x65)
    - `l` (0x6c)
    
    Result: "ft_waNDRel"
    

### Final Deletion and Input

1. **User Presses Delete (0x7f) Once More:**
    - This removes the last character "l" from "ft_waNDRel".
    
    Result: "ft_waNDRe"
    
2. **User Types:**
    - `L` (0x4c)
    - `0` (0x30)
    - `L` (0x4c)
    
    Result: "ft_waNDReL0L"
    

### Final Password

Combining all the steps, the final password is **"ft_waNDReL0L"**.

```jsx
level02@SnowCrash:~$ su flag02
Password:ft_waNDReL0L
Don't forget to launch getflag !
flag02@SnowCrash:~$
```

The password for level03 is: `kooda2puivaav1idi4f57q8iq`

```bash

flag02@SnowCrash:~$ cat README.txt
Don't forget to launch getflag!
flag02@SnowCrash:~$ getflag
Check flag. Here is your token: kooda2puivaav1idi4f57q8iq
flag02@SnowCrash:~$
```

Now I move to **level03**:

```bash
flag02@SnowCrash:~$ su level03
Password: kooda2puivaav1idi4f57q8iq
level03@SnowCrash:~$
```
