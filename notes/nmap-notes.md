
# Nmap Notes

## TCP Connect Scans

-sT

tcp = SYN -> ACK/SYN -> SYN (three way handshake, SYN = synchronize, ACK = acknowledge, syn and ack are called flags). thus a TCP connect scan works by performing the three way 
handshake. So nmap sends a syn segment to the target address, if the chosen port is closed the target sends back a RST (reset) flag which tells nmap the port is closed, 
otherwise it sends the ACK/SYN flag for the three way handshake, meaning the port is open. If nothing comes back to nmap after the SYN segment nmap considers the port 
to be filtered, since it is probable it is behind a firewall. (pretty easy to overcome this from the target perspective, just tell the firewall to send a RST flag instead of nothing)

## TCP-SYN Scans

-sS

called half-open/stealth scans. Basically instead of completing the handshake, nmap responds to the target ACK/SYN flag with a RST flag, interrupting the handshake.
Faster and better on older firewalls or software that checks for three way handkshakes.
Require sudo (need to create raw packets, unstable services are brought down by SYN scans)


## UDP Scans

-sU

since UDP is basically sending packets and hoping something comes back eventually, its much slower to scan UDP connections. Nmap sends a UDP packet, if something comes back
then the port is open, if no response, nmap sends a second packet and if nothing comes back it marks the port as open|filtered. If the port is closed the target should
send back an ICMP (ping) packet containing a message that the port is unreachable. This port is marked as closed. 

Tip: nmap -sU --top-ports N so that nmap scans the first N most commonly used UDP ports on the target. 

## Other TCP Scans

-sN -> NULL scans, nmap sends a TCP request with no flags, the target should respond with a RST if the port is closed. 
-sF -> FIN scans, namp sends a TCP request with only the FIN flag up, needed to gracefully close the connection.
-sX -> XMas scans, nmaps sends a TCP request with three flags up (PSH, URG, FIN) (looks like a christmas tree in wireshark)

If the port is open nothing is expected back with these scans, but since nmap cant tell if theres a firewall than with these scans the result is always open|filtered. 


## ICMP Scans - Ping Sweep

-sn <ip-range> (sends a ping to every host and marks the responding IP's as alive)  (it uses ARP request on local network)
this command also checks TCP SYN on 443 and 80



## Scripting engine

NSE = nmap scripting engine, write NSE plugins in LUA, many useful categories available:
    1. safe = wont affect target
    2. intrusive = not safe, will affect target prolly
    3. vuln = scan for vulnerabilities 
    4. exploit = attempt to exploit a vulnerability
    5. auth = attempt to bypass authentication for running services (like login into FTP anonimously)
    6. brute = bruteforce credentials for running services
    7. discovery = query running services

Full list on: https://nmap.org/book/nse-usage.html

Linux dir for NSE scripts: usr/share/nmap/scripts


Download a script from the internet, put it in that folder and run `nmap --script-updatedb` which updates the script.db file with the new installed scripts.



## Firewall Evasion

-Pn -> tells nmap not to bother pinging the host before scanning it. Bypasses the ICMP block that some firewall might add. It should probably better to use an ARP 
request to determine host activity if connected direclty to the local network. 
Check nmap documentation on firewall evasion options.


-f; --mtu <val>: fragment packets (optionally w/given MTU)
             -D <decoy1,decoy2[,ME],...>: Cloak a scan with decoys
             -S <IP_Address>: Spoof source address
             -e <iface>: Use specified interface
             -g/--source-port <portnum>: Use given port number
             --proxies <url1,[url2],...>: Relay connections through HTTP/SOCKS4 proxies
             --data <hex string>: Append a custom payload to sent packets
             --data-string <string>: Append a custom ASCII string to sent packets
             --data-length <num>: Append random data to sent packets
             --ip-options <options>: Send packets with specified ip options
             --ttl <val>: Set IP time-to-live field
             --spoof-mac <mac address/prefix/vendor name>: Spoof your MAC address
             --badsum: Send packets with a bogus TCP/UDP/SCTP checksum




## Examples

Xmas scan, triple verbose of the most used 100 ports, prints only the open ports:

```
sudo nmap -sX -vvv -sV -Pn --top-ports 100 --open 

```

Triple handshake TCP Scan with same parameters as before:

```
sudo nmap -sT -vvv -sV -Pn --top-ports 100 --open 

```


For example here we first do a stealth XMas scan to see which ports are open
then we do an actual tcp handshake to see if we can and lastly we find services 
on open ports, their version, on which OS they're running and even the -A scripts.


Stealth Xmas scan:

```
sudo nmap -sX -vvv -Pn -p- --open 10.10.46.60

```

Three way TCP Handshake test scan:

```
sudo nmap -sT -vvv -Pn -p 8012 10.10.46.60   

```

Scan for services, OS version, -A scripts on the open ports:

```
sudo nmap -sT -vvv -Pn -sV -A -O -p 8012 10.10.46.60

```
