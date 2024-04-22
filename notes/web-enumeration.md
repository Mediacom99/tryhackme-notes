# Web Enumeration


## Gobuster - DNS/Directories-File Enumerating and other stuff

Gobuster is a tool written in Go that does web enumeration.

Gobuster modes:

	1. dir -> enumerate websites directory from a wordlist (with status and list files with the addition of a flag to the command)
			(-k flag to bypass invalid certificate stuff with https websites, check also other flags that are useful)
	2. dns -> bruteforce sub-domains (provide starting domain and wordlist)
	3. vhost -> bruteforce virtual hosts (different domains from the same machine as different virtual hosts)

	You can do so much more with it!

## WPScan - Word Press destroyer

The best tool for WordPress websites scanning and bruteforce-attack. (Remember to update the database with wpscan --update)
By using the '-v' option after --enumerate is possible to see which vulnerabilities are present.
Actually like 46% of websites are made with wordpress LOL

## Nikto - general webserver scanning tool

With Nikto you can scan for sensitive files, misconfigured programs/servers and outdated server and programs with possible vulnerabilities	
I cant seem to find the correct info about nikto. Anyway you can redirect nmap input using -oG - | into nikto.
nikto --list-plugins
nikto -Plugin <plugin-name>

Overall pretty great tool to find a lot about a webserver, with vulnerabilities and stuff!

