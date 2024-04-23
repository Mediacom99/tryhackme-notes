# Everything about hashing

## Tools

    1. python3 - hashID module (identify hash types, has hashcat and Johns format for output,                               only reliable with prefixed hashes)
    2. hashcat
    3. John The Ripper

## Useful links

"https://hashcat.net/wiki/doku.php?id=example_hashes" --> list of hash types

## Commands

-- Jumbo John The Ripper:
       ``` john --format=[format] --wordlist=[path to wordlist] [path to file]```

-- Use John with /etc/shadow hashes:

    1. First use command 'unshadow' to turn file 
        into smth readable by John
    2. unshadow combines passwd and shadow file 
        to get a John output to crack an hash
-- John can be used in single crack mode in order to try 
    to crack the passwd by word mangling the username

    1. 'john --single --format= file.txt'
    the format is: username:hash

## Custom Rules

With John is possible to create custom rules to mangle words, this is done in the config file 'john.conf' which should be in /etc/john/john.conf

Wordlists custom rule syntax: https://www.openwall.com/john/doc/RULES.shtml

## Cracking ZIP and RAR archives 

Tools:
        a. zip2john 
        b. rar2john

## Cracking SSH private key hash

tools: ssh2john
