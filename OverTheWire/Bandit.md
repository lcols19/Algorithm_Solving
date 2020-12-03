<h1 align= "center">Bandit</h1>

# Levels
|[0](#level-0)|[1](#level-1)|[2](#level-2)|[3](#level-3)|[4](#level-4)|
|:-:|:-:|:-:|:-:|:-:|:-:|

# Level 0
## Description
The goal of this level is to log into the game using SSH.
## Concepts
* ssh
## Walkthrough
```
```

# Level 1
## Description
The password is stored in a file called readme located in the home directory. 
## Concepts
* Printing the content of a file on the standard output
## Walkthrough
```
```

# Level 2
## Description
The password is stored in a file called - located in the home directory.
## Concepts
* Reading dash files
## Walkthrough
```
```

# Level 3
## Description
The password is stored in a file called spaces in this filename located in the home directory.
## Concepts
* Reading space files
## Walkthrough
```
```

# Level 4
## Description
The password is stored in the only human-readable file in the inhere directory.
## Concepts
* Identifying human-readable files
## Walkthrough
```
```

# Level 5
## Description
The password is stored in a file somewhere under the inhere directory and has all of the following properties:

    human-readable
    1033 bytes in size
    not executable.
## Concepts
* Finding files of a specific size
* Finding non-executable files
## Walkthrough
```
```

# Level 6
## Description
The password is stored somewhere on the server and has all of the following properties:

    owned by user bandit7
    owned by group bandit6
    33 bytes in size.
## Concepts
* Finding files owned by a specific user
* Finding files owned by a specific group
## Walkthrough
```
```

# Level 7
## Description
The password is stored in the file data.txt next to the word millionth.
## Concepts
## Walkthrough
```
```

# Level 8
## Description
The password is stored in the file data.txt and is the only line of text that occurs only once.
## Concepts
* Finding line occuring once
## Walkthrough
```
```

# Level 9
## Description
The password is stored in the file data.txt in one of the few human-readable strings, preceded by several ‘=’ characters.
## Concepts
* Finding human-readable strings in a string
* Finding string preceded by a specific character in a string
## Walkthrough
```
```

# Level 10
## Description
The password is stored in the file data.txt, which contains base64 encoded data.
## Concepts
* Identifying data of a file
## Walkthrough
```
```

# Level 11
## Description
The password is stored in the file data.txt, where all lowercase (a-z) and uppercase (A-Z) letters have been rotated by 13 positions.
## Concepts
## Walkthrough
```
```

# Level 12
## Description
The password is stored in the file data.txt, which is a hexdump of a file that has been repeatedly compressed.
## Concepts
* Decompression methods
* Decompressing files
## Walkthrough
```
```

# Level 13
## Description
The password is stored in /etc/bandit_pass/bandit14 and can only be read by user bandit14. For this level, you don’t get the next password, but you get a private SSH key that can be used to log into the next level.
## Concepts
## Walkthrough
```
```

# Level 14
## Description
The password can be retrieved by submitting the password of the current level to port 30000 on localhost.
## Concepts
## Walkthrough
```
```

# Level 15
## Description
The password can be retrieved by submitting the password of the current level to port 30001 on localhost using SSL encryption.
## Concepts
## Walkthrough
```
```