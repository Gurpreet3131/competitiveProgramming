
def KMPSearch(pat, txt):
    M = len(pat)
    N = len(txt)
    flag2 = 0
    lps = [0]*M
    j = 0 # index for pat[]
    computeLPSArray(pat, M, lps)
 
    i = 0 # index for txt[]
    while i < N:
        if pat[j] == txt[i]:
            i+=1
            j+=1
 
        if j==M:
            print "YES at index " + str(i-j)
            flag2 = 1
            j = lps[j-1]
 
        elif i < N and pat[j] != txt[i]:
            if j != 0:
                j = lps[j-1]
            else:
                i+=1

    return flag2
 
def computeLPSArray(pat, M, lps):
    len = 0 # length of the previous longest prefix suffix
 
    lps[0] # lps[0] is always 0
    i = 1
    while i < M:
        if pat[i]==pat[len]:
            len+=1
            lps[i] = len
            i+=1
        else:
            if len!=0:
                len = lps[len-1]
            else:
                lps[i] = 0
                i+=1

t = int(raw_input())
big=''
small=''
while t>0:
	big = str(raw_input())
	small = str(raw_input())
	s2=''
	for i in range(0,len(small)):
		if(small[i]=='T'): s2+='A';
		elif(small[i]=='A'): s2+='T';
		elif(small[i]=='C'): s2+='G';
		elif(small[i]=='G'): s2+='C';
		else : s2+=small[i]
	flag= KMPSearch(s2,big)

	if flag==0: print 'NO'
	t-=1

