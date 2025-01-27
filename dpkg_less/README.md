# dpkg less box

This Docker Image contains a simple sudo misconfiguration.

## dpkg
```dpkg``` is a package manager for Debian-based systems, such as Ubuntu and Linux Mint. It's used to:
- Install, remove, and manage software packages
- Handle dependencies and conflicts between packages
- Provide information about installed packages

In short, dpkg helps you easily manage and maintain the software on your Debian-based system.
## less
```less``` is a command-line utility that allows you to:
- View and navigate through text files or output
- Scroll up and down, and search for specific text
- Display a limited number of lines at a time, making it easier to read and analyze large files or output

In short, less is a convenient tool for browsing and searching through text data in a terminal.

## Case
Jon is a developer which is really picky about his ```.deb``` files, for this reason the system admin provided him with permissions to install and test packages using ```dpkg```.

What the system admin does not know is that he unintentionally introduced a vulnerability.

An attacker was able to spoof Jon's credentials to this system and used this permissions to gain ```root``` access.

Can you mimic what the attacker did?

## Flag
Find the flag when you gain ```root``` access.
Verify the flag:
```bash
$ flags -c <FLAG>
Check flag
[+] Flag matches!
```
