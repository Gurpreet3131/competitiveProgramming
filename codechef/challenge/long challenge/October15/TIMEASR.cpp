#include<iostream>
#include<stdio.h>
#include<math.h>

    int main()
    {
        int t;scanf("%d",&t);
        double check=(1.0/120.0);
        while(t>0)
        {
            float A;scanf("%f",&A);
            double h=0;
            int index=0;
            if(A==180)
            {
                printf("%02d:%02d\n",6,0);
                t--;continue;
            }
            while(h<6)
            {
                
                for(double m=0;m<60;m++)
                {
                    double houra=(30*h)+(m/2.0);
                    double mina=6*m;
                    double angle=fabs(houra-mina);
                    if(fabs(angle-A)<check || fabs(angle-(360-A))<check)
                    {
                        printf("%02d:%02d\n",(int)h,(int)m);
                        int minute=((int)(360-(mina)))/6;
                        int hour=((int)(360-houra))/30;
                        if(hour==12) hour=0;
                        if(minute==60) minute=0;
                        if(hour!=(int)h || minute!=(int)m)
                        {
                            printf("%02d:%02d\n",hour,minute);
                        }
                
                        index=1;
                        break;
                    }
                }
                                    
                h+=1;
                if(index==1) break;
            }
            t--;
	 }
       
    }


