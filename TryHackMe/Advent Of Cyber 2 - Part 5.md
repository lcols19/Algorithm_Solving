# Days
|[1](#a-christmas-crisis)|[2](#the-elf-strikes-back!)|[3](#christmas-chaos)|[4](#santa's-watching)|[5](#someone-stole-santa's-gift-list!)|
|:-:|:-:|:-:|:-:|:-:|:-:|
|[6](#be-careful-with-what-you-wish-on-a-christmas-night)|[7](#the-grinch-really-did-steal-christmas)|[8](#what's-under-the-christmas-tree?)|[9](#anyone-can-be-santa)|[10](#don't-be-so-selfish)|
|[11](#the-rogue-gnome)|[12](#ready,-set,-elf)|[13](#coal-for-christmas)|[14](#where's-rudolph?)|[15](#there's-a-python-in-my-stocking!)|
|[16](#help!-where-is-santa?)|[17](#reverseelfneering)|[18](#the-bits-of-christmas)|[19](#the-naughty-or-nice-list)|[20](#powershelf-to-the-rescue)|
|[21](#time-for-some-elforensics)|[22](#elf-mceager-becomes-cyberelf)|[23](#thegGrinch-strikes-again!)|[24](#the-trialbBefore-christmas)|

# Time for some ELForensics
## Topic and concepts
Database connector file.<br>
* File hash
* Binary (.exe) file
* Alternate Data Streams
* New Technology File System
* Windows Management Instrumentation
## Walkthrough
Obtain the hash of a file:
```
Get-Hash -Algorithm MD5 <file-name>
```
Check if a file is authentic: Compare the file hash wiht the current one.<br>
Inspect within a binary:
```
c:\Tools\strings64.exe -accepteula <file>
```
View ADS:
```
Get-Item -Path <file> -Stream *
```
Launcg a hidden executable hiding within ADS:
```
wmic process call create $(Resolve-Path <file>:<streamname>)
```
## Ressources
None.

# Elf McEager becomes CyberElf
## Topic and concepts
* Decoding values
* Charcode
## Walkthrough
None.
## Ressources
None.

# The Grinch strikes again!
## Topic and concepts
Ransomware.<br>
* Volume Shadow Copy Service
* Shadow copy
* Task Scheduler
* Task Scheduler Library
* Triggers
* Actions
* Volume ID
* `vssadmin`
* Disk Management
## Walkthrough
List volumes/shadows:
```
vssadmin list volumes
vssadmin list shadows
```
View volume in Windows Explorer: ?.<br>
Restore a file to a previous version: Right-click the file, select 'Properties',
select 'Previous versions', select the shadow copy then click 'Restore'.<br>
Get a shadow copy volume ID: ?<br>
## Ressources
None.

# The Trial Before Christmas 
## Topic and concepts
Client-Side Filters, Shell upgrading and stabilisation, MySQL, Online password
cracking, PrivEsc with LXD.<br>
* NUC
* Client-side filters bypass
* 
## Walkthrough
:
```

```
## Ressources
[](): <br>

search "apache 9.0"
dir flag1.txt
type flag1.txt
/bin/bash -p then cat /root/flag.txt
cat /etc/passwd
curl -s -X GET http://<ip>:8000/api/{1..100..2} | jq .