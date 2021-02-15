import json

with open('animals.json', 'r') as f:
        data = json.load(f)

print(data)