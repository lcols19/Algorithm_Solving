<h1 align="center">Advent of Cyber 2</h1>

# Days
|[1](a-christmas-crisis)|[2](#the-elf-strikes-back!)|[3](christmas-chaos)|[4]()|[5]()|
|:-:|:-:|:-:|:-:|:-:|:-:|

# A Christmas Crisis
## Topic and concepts
Web exploitation, Web, HTTPS, Cookies.<br>
* Finding cookies name in Developer Tools
* Recognizing data formats
* Creating hexadecimal data
* JSON
## Ressources
[Cyberchef](https://gchq.github.io/CyberChef/) : Decoding strings

# The Elf Strikes Back!
## Topic and concepts
Web exploitation, GET parameters and URLs, File uploads, Reverse shells, Reverse shells listeners.<br>
* Bypassing file upload filters
* Uploading reverse shells
* Finding uploaded files directories
* Netcat
## Ressources
[php-reverse-shell.php](https://raw.githubusercontent.com/pentestmonkey/php-reverse-shell/master/php-reverse-shell.php) : PHP reverse shell script found in Kali Linux

# Christmas Chaos
## Topic and concepts
Authentication, Default credentials, Dictionary attacks using BurpSuite.<br>
* Intercepting traffic
* Automating customize web attacks
* Brute forcing a login form
* BurpSuite Community
* Payloads
## Ressources
[SecLists](https://github.com/danielmiessler/SecLists/) : Collection of common lists including usernames, passwords, URLs and so on.

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
[gobuster man](http://manpages.ubuntu.com/manpages/cosmic/man1/gobuster.1.html): man page of ``gobuster``
`/usr/share/wordlists`: Default location for wordlists on Kali Linux<br>
[wfuzz](https://github.com/xmendez/wfuzz): GitHub webpage<br>
[wfuzz man](https://github.com/xmendez/wfuzz): man page of `wfuzz`<br>
[AoC-Advent2020](https://assets.tryhackme.com/additional/cmn-aoc2020/day-4/wordlist): Advent of Cyber wordlist (containg among other things YYYYDDMM datestamps)<br>

# Someone stole Santa's gift list! 
## Topic and concepts
SQL injection, Login bypass with SQL injection, Blind SQL injection, Union SQL injection, SQLMap, SQLMap & BurpSuite.<br>
* Dumping a file
* Possibilities of a SQL injection
* Main SQL injection commands
* 1=1
* Common comments for SQLi payloads
* Different SQL login queries
* Yes or No questions to the database
* SUBSTR() SQL function
* Payloads with SQL injections
* Database enumeration
* Stages of an UNION SQLi attack
* ORDER BY queries
* Determining the number of columns required in a SQLi UNION attack
* UNION SELECT
* Meaning of no error when determining number of columns
* Finding columns with useful data in SQLi UNION attack
* UNION SELECT payloads
* Meaning of no error when finding useful data type
* Retrieving interesting data with SQLi UNION attack
* Common options for SQLMap
* WAF
## Walkthroughs
Bypass the login:
```
username: )' or true; --
```
Finding 
* the number of entries
* what Paul asked for
* the flag
* the admin password
```
python sqlmap.py -r ./request --dbms=sqlite --tamper=space2comment --dump-all
```
## Ressources
[SQL commands](https://www.codecademy.com/articles/sql-commands): List of SQL commands<br>
`git clone --depth 1 https://github.com/sqlmapproject/sqlmap.git sqlmap-dev` : SQLMap installation
[SQL injection](https://github.com/swisskyrepo/PayloadsAllTheThings/tree/master/SQL%20Injection): SQL injection cheatsheet
[SQL injection payloads list](https://github.com/payloadbox/sql-injection-payload-list): Payloads list

# Be careful with what you wish on a Christmas night 
## Topic and concepts
XSS, XSS detection, Mitigating XSS.<br>
* Cross-site Scripting
* Types of XSS attacks
* OWASP ZAP
## Walkthrough
## Ressources
[XSS mitigation](https://github.com/OWASP/CheatSheetSeries/blob/master/cheatsheets/Input_Validation_Cheat_Sheet.md): OWASP's guide towards mitigating XSS attacks

# The Grinch Really Did Steal Christmas
## Topic and concepts
IP address, Protocols 101, Three-way handshake, TCP reassembling data, 
Monitoring network traffic.<br>
* TCP/IP
* PCAPs
* Basic Wireshark filtering
* HTTP
* SMB
* NATting
* UDP/IP
* Routing
* SYN
* ACK
* Wireshark
* Wireshark filters
* Filter operators
* Data exportation from Wireshark
* Filter to see HTTP GET requests
## Walkthroughs
Filter to identify the IP address initiating a specific protocol:
```
icmp
```
Filter to get the name of an article an IP address visited:
```
http.request.method == GET
```
Filter to see a leaked password during the login process with FTP traffic:
```
ftp.request
```
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
[]()