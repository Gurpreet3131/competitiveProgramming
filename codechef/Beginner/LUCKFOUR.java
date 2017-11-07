import java.util.*;
import java.io.*;
class LUCKFOUR
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            String num=br.readLine();
            int count=0;
            for(int i=0;i<num.length();i++)
            {
                if(num.charAt(i)=='4') count++;
            }
            ps.println(count);
            t--;
        }
        ps.close();
    }
}
