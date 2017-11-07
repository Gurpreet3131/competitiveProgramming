t=int(raw_input())
mod = int(1000000007)
while t>0:
	l = int(raw_input())
	r = int(raw_input())
	sumr = int(r*(r+1)*(2*r+1)/6)
	suml = int((l-1)*(l)*(2*l-1)/6)
	print sumr, suml
	sumall = sumr-suml;
	print sumall
	if l%2!=0:
		if (r-l+1)%2==0:
			r= int(r/2)
		else :
			r = int(r/2)+1
		l=l-2;
		if(l>0): l= int(l/2)+1

		sumrodd = int( r*(2*r-1)*(2*r+1)/3 )
		if(l>0):sumlodd = int( l*(2*l-1)*(2*l+1)/3 )
		else : sumlodd=0
		sumdiff= sumrodd-sumlodd
		sumall -= 2*sumdiff
		print sumrodd, sumlodd,sumdiff,sumall

	else :
		if (r-l+1)%2= =0:
			r-=2
		l=l-2
		r= int(r/2)
		if(l>0): l= int(l/2)
		sumreven = int( 2*r*(r+1)*(2*r+1)/3 )
		if(l>0): sumleven = int( 2*l*(l+1)*(2*l+1)/3 )
		else : sumleven=0
		sumdiff= sumreven-sumleven
		sumall -= 2*sumdiff
		print sumreven, sumleven,sumdiff,sumall

	sumall%= mod
	print sumall
	t=t-1