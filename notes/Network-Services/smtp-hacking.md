
# Simple Mail Transfer Protocol SMTP 

## Tools

    1. smtp_version module in MetaSploit (scan network for mail servers w/ version)
    2. smtp_enum
    3. smtp_user_enum (inspecting responses to main SMTP commands like VRFY, EXPN, RCPT TO)
    4. Hydra to bruteforce ssh password having found the user through smtp

## Notes

SMTP service has two commands:
        1. VRFY : confirms the names of valid users 
        2. EXPN : reveals the actual address of users aliases and mailing lists. 

I installed with apt `seclists` a collection of wordlists to use with
smtp\_enum in to list all users and mailing lists.
Then I used hydra to bruteforce a psw for ssh login of user administrator found
on the smtp server.
