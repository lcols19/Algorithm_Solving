# Days
|[1](#a-christmas-crisis)|[2](#the-elf-strikes-back!)|[3](#christmas-chaos)|[4](#santa's-watching)|[5](#someone-stole-santa's-gift-list!)|
|:-:|:-:|:-:|:-:|:-:|:-:|
|[6](#be-careful-with-what-you-wish-on-a-christmas-night)|[7](#the-grinch-really-did-steal-christmas)|[8](#what's-under-the-christmas-tree?)|[9](#anyone-can-be-santa)|[10](#don't-be-so-selfish)|
|[11](#the-rogue-gnome)|[12](#ready,-set,-elf)|[13](#coal-for-christmas)|[14](#where's-rudolph?)|[15](#there's-a-python-in-my-stocking!)|
|[16](#help!-where-is-santa?)|[17](#reverseelfneering)|[18](#the-bits-of-christmas)|[19](#the-naughty-or-nice-list)|[20](#powershelf-to-the-rescue)|
|[21](#time-for-some-elforensics)|[22](#elf-mceager-becomes-cyberelf)|[23](#thegGrinch-strikes-again!)|[24](#the-trialbBefore-christmas)|

# Help! Where is Santa?
## Topic and concepts
Scripting.<br>
## Walkthrough
Find the hidden link: Extract all links on a webpage with this code snippet
```
# Import the libraries we downloaded earlier
# if you try importing without installing them, this step will fail
from bs4 import BeautifulSoup
import requests 

# replace testurl.com with the url you want to use.
# requests.get downloads the webpage and stores it as a variable
html = requests.get('testurl.com') 

# this parses the webpage into something that beautifulsoup can read over
soup = BeautifulSoup(html, "lxml")
# lxml is just the parser for reading the html 

# this is the line that grabs all the links # stores all the links in the links variable
links = soup.find_all('a href') 
for link in links:      
    # prints each link    
    print(link)
```
with `#!/usr/bin/env python3` on top of the script. Paste the IP address in 
`requests.get` function, edit the variable in `BeautifulSoup`to 
`html.text, "lxml"`, the one in `find_all` to `a`, add an if statement in the 
loop looking for href in a link (`if "href" in link.attrs`) and lastly, add 
a `print` in the if whose argument is `link[href]` to print only the link. 
Additionally, as there may be too many results, `uniq` will do the trick to 
print unique lines (trick by John Hammond).<br>
Find the API key: Create a code snippet with `requests` library, an `html` 
variable and a loop. `html` is equal to `requests.get` with argument
 `(f'<IP>\{api_key})` and then print `html`.
## Ressources
None.

# ReverseELFneering
## Topic and concepts
x86-64 assembly, Analysis, Registers, Instructions, Workflow.<br>
* `radare2`
* movl
* pushq
* movq
* subq
* breakpoints
## Walkthrough
Connecting to a ssh instance:
```
ssh <username>@<machine_ip>
```
Opening a binary in debugging mode:
```
r2 -d ./<filename>
```
Analyse a program:
```
aa
```
List of the functions run:
```
afl
```
Examine assembly code:
```
pdf @<function-name>
```
Set a breakpoint:
```
db <memory-address>
```
Ensure breakpoint is set:
```
pdf @<function>
```
Continue process execution:
```
dc
```
Print out the function once the program is run:
```
pdf
```
View the content of a variable:
```
px @ <memory-address>
```
Step instruction:
```
ds
```
See the value of a register:
```
dr
```
Reload the program:
```
ood
```
## Ressources
[Radare2 Cheatsheet](https://scoding.de/uploads/r2_cs.pdf)<br>
[The Official Radare2 Book](https://book.rada.re/first_steps/commandline_flags.html): Radare2 material<br>

# The Bits of Christmas
## Topic and concepts
Application disassembling.<br>
* .NET Framework
* ILSpy
* Dotpeek
* Remote Desktop Protocol
* Remmina
## Walkthrough
Check if the application is a .NET one: The second element in the bracket should
state `.NETFramework`. <br>
Deploy an instance with `Remmina`: Open `Remmina`, fill in server, username and 
password.<br>
## Ressources
None.

# The Naughty or Nice List
## Topic and concepts
Server-Side Request Forgery.<br>
* Remote File Inclusion
* Denial of Service
* URL decoder
* Enumerating open ports via SSRF
* SSH port number
* HTTP port number
* Domain restriction bypass
## Walkthrough
Fetch the root of a website with GET/POST request: Remove the part after the 
request in the URL.<br>
Access services running locally on server: Replace GET parameter by 
localhost/127.0.0.1/example.com.<br>
Bypass hostname check: Add `list.hohoho` before localhost/etc. .<br>
"Recv failure: Connection reset by peer" suggests the port is open but doesn't
understand what is went.<br>
It is possible to detect which ports are open vs closed by measuring the time 
each request takes to complete.<br>
## Ressources
None.

# PowershELF to the rescue
## Topic and concepts
Powershell.<br>
* cmdlets
## Walkthrough
Launching Powershell:
```
powershell
```
Navigate to a folder:
```
Set-Location -Path <folder>
```
List content of current directory/specific directory/only directories/only 
files/recursively/hidden items/without error messages:
```
Get-ChildItem
Get-ChildItem -Path
Get-ChildItem -Directory
Get-ChildItem -File
Get-ChildItem -Recurse
Get-ChildItem -Hidden
Get-ChildItem -ErrorAction SilentlyContinue
```
Read content of a file:
```
Get-Content -Path <path-of-file>
```
Count words in a file:
```
Get-Content -Path <file> | Measure-Object -word
```
Get string at a specific position in a file:
```
(Get-Content -Path <file>)[index]
```
Search a string in a file:
```
Select-String -Path <file> -Pattern "string"
```
Get explanation for cmdlet:
```
Get-Hep <cmdlet>
```
## Ressources
None.