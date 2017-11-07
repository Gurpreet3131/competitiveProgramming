t = int(raw_input())
lst = [0]*2000004
lst[0] = 1
i = int(1)
mod = int(1000000007)
while i < 2000002:
	lst[i] = (i*lst[i-1]) % mod
	i += 1


while t>0:
	n, m, k = map(int, raw_input().split())
	ans = int(0);
	while k > 0:
		x, y, h = map(int, raw_input().split())
		k-=1
		tempans = lst[x+y]/(lst[x]*lst[y])
		tempans %= mod
		tempans = (tempans * h) % mod
		ans += tempans
		ans %= mod

	print ans
	t-=1
