def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b,a%b)

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
	print "1 1"
else:
	num1 = ct-1
	den1 = ct
	num2 = int(5)
	den2 = 6*ct	
	lcm = gcd(den1,den2)
	lcm = (den1*den2)/lcm

	num1*= lcm/den1
	num2*= lcm/den2
	num1 = num1+num2
	den1 = lcm
	lcm = gcd(num1, den1)
	num1/=lcm
	den1/=lcm
	print num1,den1