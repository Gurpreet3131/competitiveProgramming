t= int(raw_input())
while t>0:
	q = int(raw_input())
	ct = int(0)
	five = int(0)
	two = int(0)

	flag = int(1)
	while q!=1:
		if(q%2==0):
			q /=2
			two +=1
		elif (q%5==0):
			q/=5
			five+=1
		else :
			flag = 0
			break
			
	if flag==1:
		print max(two,five)
	else:
		print '0'

	t-=1