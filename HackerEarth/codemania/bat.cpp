    #include <stdio.h>
 
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
     
    #define S(a,b,c) (b=(a)?(b+c):(b-c))
    #define E(a) if(a)return
    #define K r(1,0,0)
    #define U(a) {printf("%lld\n",a);return;}
    #define LL long long
     
    int k;
    LL a[100], X1, X2, a1, a2;
     
    void r(int s, int i, int p)
    {
    E(s>X1&&s>X2);
    if(i==k)
    	{
    	E(s==1);
    	S(p,a2,X2/s);
    	S(p,a1,X1/s);
    	return;
    	}
    r(s*a[i],i+1,1-p);
    r(s,i+1,p);
    }
     
    void q()
    {
    int i, j, y, w, v;
    LL o;
    if(scanf("%d %d %d",&y,&w,&v)&&!(y=y>=0?y:-y))U((w<=-1&&-1<=v)+(w<=0&&0<=v)+(w<=1&&1<=v));
    if(y==1)U(v-w+1);
    for(k=!(i=2); i*i<=y; i++)
    	if(!(y%i))
    		for(a[k++]=i; !(y%i); y/=i);
    if(y!=1)
    	a[k++]=y;
    X1=(w)>0?w:-w;
    X2=(v)>0?v:-v;
    if(!(a1=a2=0)&&(!w||!v)){K;U(X1+X2-a1-a2);}
    if((w>0&&v<0)||(w<0&&v>0)){K;o=a1+a2+1;}
    else
    	{
    	if(X2<X1)
    		{
    		X2--;
    		K;
    		o=a1-a2;
    		}
    	else
    		{
    		X1--;
    		K;
    		o=a2-a1;
    		}
    	}
    printf("%lld\n",v-w+1-o);
    }
     
    main()
    {
    int fall;
    for(scanf("%d",&fall); fall--; q());
    return 0;
    } 