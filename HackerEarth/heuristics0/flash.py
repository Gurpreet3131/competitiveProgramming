t = int(raw_input())
lst = [0]*204
lst[0] = 1
i = int(1)
while i<202:
	lst[i] = i*lst[i-1]
	i+=1


while t>0:
	x,y = map(int, raw_input().split())
	ans = lst[x+y]/(lst[x]*lst[y])
	ans = ans % 1000000007
	print ans
	t-=1
