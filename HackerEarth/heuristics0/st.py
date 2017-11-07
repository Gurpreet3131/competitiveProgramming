n,m = raw_input().split(" ")
n = int(n)
m = int(m)
s1 = raw_input()
s2 = raw_input()
while m>0:
	a,b,c,d = raw_input().split(" ")
	a = int(a)
	b = int(b)
	c = int(c)
	
	if a==1 :
		b-=1
		c-=1
		d = int(d)
		if b+d>n or c+d>n:
			print 'NO'
		else:
			one = s1[b:b+d]
			two = s2[c:c+d]
			#print one,two
			if one == two:
				print "YES"
			else : 
				print "NO"

	else :
		c -=1
		if b == 1:
			one = s1[:c] + d +  s1[c+1:]
			s1 = one
		else:
			two = s2[:c] +d + s2[c+1:]
			s2 = two
	m = m-1