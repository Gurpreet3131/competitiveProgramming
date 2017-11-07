import java.util.*;
import java.io.*;
class TWOSTER
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
            String result="Yes";
            for(int i=0;i<s1.length();i++)
            {
                if(s1.charAt(i)!=s2.charAt(i) && (s1.charAt(i)!='?' && s2.charAt(i)!='?'))
                {
                    result="No";
                    break;
                }
            }
            ps.println(result);
            t--;
        }
        ps.close();
    }
}

