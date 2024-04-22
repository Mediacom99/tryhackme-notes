# Web server/apps: bypass client/server side filtering when uploading a file

There are many types of filtering, both can be client or server side like: MIME, file content filtering, file extensions, magic number checking (Unix magic numbers).

## Client-side filtering

How can I prevent it:

1. turn off javascript
2. intercept and modify incoming page (with BurpSuite we can disable the js filtering)
3. intercept and modify file upload
4. send the file directly to the upload endpoint

The last one can be used with a command like this:

curl -X POST -F "submit:<value>" -F "<file-parameter>:@<path-to-file>" <site>

after having intercepted the endpoint upload on BurpSuite, and adding the relevant paramters to the 
above command. 


