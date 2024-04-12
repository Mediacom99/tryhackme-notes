# Web Enumeration


## Gobuster

Gobuster is a tool written in Go that does web enumeration.

Gobuster modes:

	1. dir -> enumerate websites directory from a wordlist (with status and list files with the addition of a flag to the command)
			(-k flag to bypass invalid certificate stuff with https websites, check also other flags that are useful)
	2. dns -> bruteforce sub-domains (provide starting domain and wordlist)
	3. vhost -> bruteforce virtual hosts (different domains from the same machine as different virtual hosts)

	You can do so much more with it!

## WPScan

The best tool for WordPress websites scanning and bruteforce-attack. (Remember to update the database with wpscan --update)