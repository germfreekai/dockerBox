# Docker boxes
This repo aims to provide docker boxes with some vulnerabilities.

The README files at each directory might contain details about the vulnerability and the flag itself, but I encourage you to try the hack first, before reading any file.

I believe in being clear, and knowing how a lab or exploit was created for him to practice. For this reason everything can be found at this repo, from the flag generator to the boxes.

I might add some file with the solution per lab (at least the one I was thinking of), but I am still thinking about it.

## How to run the box?
Copy the desired box and run:
```bash
$ docker pull ubuntu:latest
$ docker build -t myhack .
$ docker run -it myhack
```

> NOTE: Created this repo to learn more about docker and system exploits, I expect for my Dockerfiles and exploits to get better over time. Maybe not showing the actual flag at the Dockerfile would be a good next step.

## How to find the flag?
Flags will be located on different spaces.
But at all boxes you will be able to find and compare the flag runnig:
```bash
$ flags -c dpkg_less_7AHF4NgTPJU5QGXV4VljJzAuyj7jrvEpTbSNOYutxembJaUDT
Check flag
[+] Flag matches!
$ flags -c found_a_wrong_flag
Check flag
[X] Wrong flag: found_a_wrong_flag
```

## Disclaimer

This repository is publicly available and contains information about various security exploits and knowledge. By accessing and using this repository, you acknowledge that:

- *You are responsible for your actions*: The author of this repository shall not be held liable for any misuse or illegal use of the knowledge and exploits presented here. It is your responsibility to ensure that your actions comply with applicable laws and regulations.
- *Security by ignorance is not security*: This repository is intended to educate and inform security professionals about potential vulnerabilities and exploits. It is essential to acknowledge that ignorance of these exploits does not equal security. Instead, professionals should familiarize themselves with this information to better protect against threats.
- *Fair use and helping others is encouraged*: This repository is meant to be a resource for the greater good. We encourage responsible use of this information to help others, improve security, and promote a safer digital environment.

Important Notes

    This repository is not intended to facilitate or promote illegal or harmful activities.
    The author does not condone or encourage the misuse of the information presented here.
    By using this repository, you agree to use the information responsibly and in compliance with applicable laws and regulations.

