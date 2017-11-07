#include<stdio.h>
#include<string.h>
#define mod 1000000007
long long int exp(long long b,long long p)
{
    if(p==0)
        return 1;
    else if(p%2==0)
        return exp(((b%mod)*(b%mod))%mod,p/2)%mod;
    else if(p%2==1)
        return ((b%mod)*exp(((b%mod)*(b%mod))%mod,(p-1)/2)%mod)%mod;
}
int main()
{
 
    long long int t,i,l,j,den,total,nsim,one,two,three,four,nal,threesub,foursub,twosub,twoid,threeid,fourid;
    char str[100005];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s",str);
        twosub=0;
         l=strlen(str);
        long long int a[26]={0};
        for(i=0;i<l;++i)
            a[str[i]-97]++;
 
        long long int num=1;
         for(i=1;i<=l;++i)  // n factorial
         {num=(num*i)%mod;}
 
        den=1;
         for(i=0;i<26;++i)
         {
             one=1;
             for(j=1;j<=a[i];++j)  //denominator= factorial of repeated terms
                one=(one*j)%mod;
             den=(den*one)%mod;
         }
 
         den=exp(den,mod-2)%mod;
 
         total=(num*den)%mod;
 
 
        one=1;
        twoid=((l*(l-1))/2)%mod;
        for(i=0;i<26;++i)
            twosub=(twosub+((a[i]*(a[i]-1))/2)%mod)%mod;
        two=(twoid-twosub+mod)%mod;
        threeid=((l*(l-1)*(l-2))/3)%mod;
        threesub=0;
        for(i=0;i<26;++i)
            {
                if(a[i]>=2)
                    threesub=(threesub+((((a[i]*(a[i]-1))/2)%mod)*(l-a[i]))%mod)%mod;
                if(a[i]>=3)
                    threesub=(threesub+(((a[i]*(a[i]-1))%mod)*(a[i]-2)*exp(6,mod-2))%mod)%mod;
            }
        threesub=(2*threesub)%mod;
        three=(threeid-threesub+mod)%mod;
        fourid=((((((l*(l-1))/2)%mod)*((((l-2)*(l-3))/2)%mod))%mod)*exp(2,mod-2))%mod;
        foursub=0;
        long long count=0;
        for(i=0;i<26;++i)
            if(a[i]>=4)
               count=(count+(((((a[i]*(a[i]-1))%mod)*(a[i]-2))%mod)*(a[i]-3)*exp(24,mod-2))%mod)%mod;
        foursub=(foursub+(3*count)%mod)%mod;
        count=0;
        for(i=0;i<26;++i)
            if(a[i]>=3)
              {
                  count=(count+(((((a[i]*(a[i]-1))%mod)*(a[i]-2)*exp(6,mod-2))%mod)*(l-a[i]))%mod)%mod;
              }
        foursub=(foursub+(3*count)%mod)%mod;
       count=0;
        for(i=0;i<26;++i)
            if(a[i]>=2)
        {
            for(j=i+1;j<26;++j)
                if(a[j]>=2)
                   count=(count+((((a[i]*(a[i]-1))/2)%mod)*((((a[j])*(a[j]-1))/2)%mod))%mod)%mod;
        }
          foursub=(foursub+(2*count)%mod)%mod;
        long long X_,Y,count1;
        count=0;
        for(i=0;i<26;++i)
            if(a[i]>=2)
               {
                   count1=0;
                   X_=((a[i]*(a[i]-1))/2)%mod;
                   Y=l-a[i];
                   for(j=0;j<26;++j)
                   {
                       if(j!=i)
                       {Y-=a[j];
                       count1=(count1+(a[j]*Y)%mod)%mod;}
 
                   }
                   count=(count+(count1*X_)%mod)%mod;
               }
        foursub=(foursub+count)%mod;
        four=(fourid-foursub+mod)%mod;
        nsim=(total-((one+two+three+four)%mod)+mod)%mod;
        nsim=(nsim*total)%mod;
        printf("%lld\n",nsim);
    }
    return 0;
}
