FROM ubuntu:latest

COPY flags /usr/bin/

RUN \
    apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install less && \
    apt-get -y install sudo && \
    useradd -m jon && \
    chown root:root /usr/bin/dpkg && \
    chmod o-x /usr/bin/dpkg && \
    flags -n dpkg_less

COPY jon_duties /etc/sudoers.d/

USER jon
WORKDIR /home/jon

