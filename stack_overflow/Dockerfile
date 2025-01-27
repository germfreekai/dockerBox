FROM ubuntu:latest

RUN mkdir -p /src
RUN mkdir -p /src/bin
RUN mkdir -p /src/src
WORKDIR /src

COPY src/password_vuln.c src/integrity_vuln.c /src/src
COPY Makefile /src
COPY flags checksec /usr/bin/

RUN \
    apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install file openssl sudo build-essential && \
    make && \
    make stacksafe && \
    useradd -m jon && \
    cp -r /src/bin/* /home/jon && \
    chown -R jon:jon /home/jon/* && \
    make clean && \
    flags -n stack_overflow

COPY jon_duties /etc/sudoers.d/

USER jon
WORKDIR /home/jon
