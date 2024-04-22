# Webshell

When you can't get a direct reverse/bind shell on the target, maybe the web server can do 
the work for you!


Simple webshell that takes the GET parameter and runs it as a command:

<?php
    echo system($_GET["cmd"]);
?>

should be uploaded as a .php (like webshell.php) file on a PHP server. 
Now once uploaded use a GET request to the webshell.php like so:

...whatever/webshell.php?cmd=ls
and see what happens!


Or we can use a reverse shell by injecting first php code into the webapplication:
(You can get a bunch of webshells with the 'webshells' command on Kali),
then you upload the php code with the reverse shell on the website, then you do a 
GET request on that php code and, if you are listening on the correct port, you will 
get back a shell! Not as root probably, but still!

I used php-reverse-shell in webshells on Kali!

