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
Fuzzing, `gobuster` use, `wfuzz` use, <br>
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
