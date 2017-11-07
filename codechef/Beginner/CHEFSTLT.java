import java.util.*;
import java.io.*;
class CHEFSTLT
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            String s1=br.readLine();
            String s2=br.readLine();
            int min=0,max=0;
            for(int i=0;i<s1.length();i++)
            {
                if((s1.charAt(i)=='?' || s2.charAt(i)=='?'))
                {
                        max++;
                }
                else
                {
                    if(s1.charAt(i)!=s2.charAt(i))
                    {
                        min++; max++;
                    }
                }
            }
            ps.println(min+" "+max);
            t--;
        }
        ps.close();
    }
}

