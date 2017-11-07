import java.util.*;
import java.io.*;
class test
{
    public static int leap(int current, int year)
    {
        int max=(current>year)?current:year;
        int min=(current<year)?current:year;
        int count=0;
        for(int i=min;i<max;i++)
        {
            if((i%400==0) ||(i%4==0 && i%100!=0))
                count++;
        }
        return count;
    }
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=1900;
        String days[]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
        while(t<2501)
        {
            int num=leap(2001,t);
            int i=0;
            if(t<2001)
            {
                i=2001-t+num;
                if(i%7==0) i=0;
                else i=7-(i%7);
                
            }
            else if(t>2001)
            {
                i=t-2001+num;
                i=i%7;
            }
            else i=0;
            ps.println(t+" "+days[i]);
            t++;
        }
        ps.close();
    }
}

