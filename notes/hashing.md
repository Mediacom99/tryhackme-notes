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