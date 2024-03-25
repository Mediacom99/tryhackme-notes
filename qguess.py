import requests


url = "http://10.10.135.78:85/resetpass1.php"


questions = requests.post(url, data = {"user": "joseph"})


print(questions.text)


