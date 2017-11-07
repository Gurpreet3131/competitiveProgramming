import java.util.*;
import java.io.*;
class FLOW006 
{
    public static void main(String[] args)throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int num=Integer.parseInt(br.readLine());
            int sum=0;
            while(num>0)
            {
                sum+=num%10;
                num/=10;
            }
            ps.println(sum);
            t--;
        }
        ps.close();
    }
}
