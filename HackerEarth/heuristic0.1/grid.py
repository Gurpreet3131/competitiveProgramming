n,m = raw_input().split(" ")
n = int(n)
m = int(m)
s = ['']*502
for i in range(n):
	s[i] = raw_input()

ct = int(0)
for i in range(n-1):
	for j in range(i+1,n):
		z = int(0)
		for k in range(m):
			if (s[i][k] == '0' and s[j][k] == '0'):
				z+=1
		z-=1
		ct +=(z*(z+1))/2 

if ct == 0:
	print "-1"
else:
	print ct