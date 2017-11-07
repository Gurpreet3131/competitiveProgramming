import java.util.*;
import java.io.*;
class LCH15JAB 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            String str=br.readLine();
            int counter=0;
            for(int i=0;i<str.length();i++)
            {
                int count=0;
                for(int j=0;j<str.length();j++)
                {
                    if(str.charAt(i)==str.charAt(j)) count++;
                }
                if(count==(str.length()-count))
                {
                       counter=1;
                       break;
                }
            }
            if(counter==1) ps.println("YES");
            else ps.println("NO");
            t--;
        }
        ps.close();
    }
}

