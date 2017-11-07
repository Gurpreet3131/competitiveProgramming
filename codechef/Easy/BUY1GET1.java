import java.util.*;
import java.io.*;
class BUY1GET1
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            String jewel=br.readLine();
            int color[]=new int[53];
            int buy=0;
            int minus=96;
            for(int i=0;i<jewel.length();i++)
            {
                int ascii=(int)jewel.charAt(i);
                
                if(ascii>96)
                {
                   minus=96;
                }
                else
                {
                    minus=38;
                }
                if(color[ascii-minus]%2==0)
                {
                    buy++;
                }
                color[ascii-minus]++;
            }
            ps.println(buy);
            t--;
        }
        ps.close();
    }
}
