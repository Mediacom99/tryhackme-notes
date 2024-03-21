# NFS - Network File System 

Mounts a portion (or whole) filesystem on a server which can be accessed by different clients.

The way it works is that a client asks the server to mount a directory from the server onto the client's local machine. The server checks if the user has permission to mount the certain
folder. It will return a file handle which uniquely identifies each file and directory that is on the server. 
If someone wants to access a file using NFS, an RPC (Remote Procedure Call protocol) call 
is placed to NFSD (the NFS daemon on the server).
RPC is the protocol used to communicate between server and client in an NFS share. 

Useful Links:

https://www.datto.com/library/what-is-nfs-file-share

http://nfs.sourceforge.net/

https://wiki.archlinux.org/index.php/NFS


Key Applications:

    1. nfs-common (main tool to interact with NFS share on local machines)


Other Notes:

    1. showmount command lets you list the nfs shares.
    2. An NFS share poorly configured can be used to 
        escalate privileges on an already existing low privilege
        shell. To do this we need to turn off Root-Squashing.
        Withouth this we can allow the creation of SUID bit files. 
        By doing this we are able to upload files to the NFS share 
        and change their permissions accordingly. Thus we only need
        to upload an executable that escalates privileges, we give
        it the right SUID bit and it will be able to run on the 
        NFS share. 

Review of the process of using poorly configured NFS Share with 
disabled Root Squash to get a root shell into host machine:

    1. Check on which port NFS share is running
    2. use showmount on NFS share to see which folders are available        to mount
    3. Mount a folder, insert bash executable owned by root 
        with SUID bit set so that whoever runs that executable
        it will always run as root.
    4. Login using ssh to the host machine and run bash
    5. Now you are root. 
