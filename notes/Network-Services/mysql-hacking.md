# MySQL 

Client-server, not first option when hacking a network, works on the standardized 
language SQL (structured query language) used to communicate with an sql server. 
Mostly used on back-end of big websites (social networks)

## Tools

    1. metasploit for enum or nmap mysql enum script
    2. default-mysql-client (apt)
    3. mysql_sql metasploit module that lets u use sql language
        against a IP specified mysql server. (get the databases or the version
        set SQL to "show databases" to see the list of schemas
    4. mysql_schemadump to dump info of a schema, get tables and columns
        of each schema or specificed one (maybe) (~database)
    5. mysql_hashdump : extracts usernames and encrypted password hashes from
        a mysql server and stores them for later cracking (reversing the hash
        to get to the original input)
    6. JohnTheRipper to crack those hashes

## Useful commands

    1. Connect to mysql server: mysql -h IP -u username -p
