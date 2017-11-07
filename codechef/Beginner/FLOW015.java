import java.util.*;
import java.io.*;
class FLOW015
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
        int t=Integer.parseInt(br.readLine());
        String days[]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
        while(t>0)
        {
            int year=Integer.parseInt(br.readLine());
            int num=leap(2001,year);
            int i=0;
            if(year<2001)
            {
                i=2001-year+num;
                if(i%7==0) i=0;
                else i=7-(i%7);
                
            }
            else if(year>2001)
            {
                i=year-2001+num;
                i=i%7;
            }
            else i=0;
            ps.println(days[i]);
            t--;
        }
        ps.close();
    }
}

