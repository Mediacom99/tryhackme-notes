
# Connecting to TryHackMe OpenVPN server:

Run this command: 

```
sudo openvpn ~/Downloads/Mediacom.ovp

```

In order to ssh into a tryhackme machine (NOT network, need different vpn config in that case):

```
ssh tryhackme@<ip-address> (passw = tryhackme)

```


# Useful tools

    1. Traceroute (traces hops to get to target ip address)
    2. whois (displays a lot of information about registration and such of a certain domain)
    3. dig (manually query recursive DNS servers for info about domains)
    4. nmap
    5. enum4linux, smbclient (SMB Shares Hacking)
    6. tcpdump (used to check for incoming packets that uses tcp protocol)
    7. msfvenom (used to generate the command that runs a reverse shell in target machine)
        it's a payload generator for different platforms and for different actions.
    8. nc (tcp/ip swiss army knife)(netcat) (to listen for that reverse shell on the attacker       machine)
    9. Hydra (online password cracking tool for a lot of different protocol/services)


# Other random tools

    1. pdfarranger (combines more pdfs or pngs into single file)
    2. 



# Steps in analyzing a network:

    1. Enumeration (understand the networks structure, which hosts are up 
                    and which ports are open and their relative services)

# Useful commands cheat sheet:

    1. ssh -v -i <private-rsa-id> user@<ip-address>
