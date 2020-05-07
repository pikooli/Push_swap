import os

f = open("500")
text = ""
lines = f.readlines() 
for i in lines:
	i = i.strip()
	text = text + i + " "
print(text)
f.close()
