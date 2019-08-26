l = []
with open('14.txt') as f:
	for x in f:
		l.append(int(x))

l.sort()
c = 0
fib = [0,1]
j = 1
x = 0
for i in l :
	x+=1
	if x%10000 == 0:
		print(x)
	if fib[j] == i :
		c+=1
	elif i > fib[j] :
		while(fib[j]<i):
			j=j+1
			fib.append(fib[j-1]+fib[j-2])
		if fib[j]==i:
			c+=1
print(c)
