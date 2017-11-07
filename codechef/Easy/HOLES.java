import java.util.*;
import java.io.*;
class HOLES
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            String s=br.readLine();
            int holes=0;
            for(int i=0;i<s.length();i++)
            {
                if(s.charAt(i)=='B') holes+=2;
                else if(s.charAt(i)=='A' || s.charAt(i)=='D' || s.charAt(i)=='O' || s.charAt(i)=='P' || s.charAt(i)=='Q' || s.charAt(i)=='R')
                {
                    holes++;
                }
            }
            ps.println(holes);
            t--;    
        }
        ps.close();
    }
}

