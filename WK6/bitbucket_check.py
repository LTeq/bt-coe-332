import requests

response = requests.get(url="https://api.bitbucket.org/2.0/repositories")

# let's look at the response code

print(response.status_code)
print(response.json())
