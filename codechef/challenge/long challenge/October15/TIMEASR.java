import java.util.*;
import java.io.*;
import java.math.*;
class time
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        double check=(1.0/120.0);
        while(t>0)
        {
            double A=Double.parseDouble(br.readLine());
            double h=0;
            int index=0;
            if(A==180)
            {
                ps.printf("%02d:%02d\n",6,0);
                t--;continue;
            }
            while(h<6)
            {
                for(double m=0;m<60;m++)
                {
                    double houra=(30*h)+(m/2.0);
                    double mina=6*m;
                    double angle=Math.abs(houra-mina);
                    if(Math.abs(angle-A)<check || Math.abs(angle-(360-A))<check)
                    {
                        ps.printf("%02d:%02d\n",(int)h,(int)m);
                        int minute=((int)(360-(mina)))/6;
                        int hour=((int)(360-houra))/30;
                        if(hour==12) hour=0;
                        if(minute==60) minute=0;
                        if(hour!=(int)h || minute!=(int)m)
                        {
                            ps.printf("%02d:%02d\n",hour,minute);
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
        ps.close();
    }
}
