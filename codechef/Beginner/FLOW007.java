import java.util.*;
import java.io.*;
class FLOW007 
{
    public static void main(String[] args)throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int num=Integer.parseInt(br.readLine());
            int num2=0;
            while(num>0)
            {
                num2=(num2*10)+(num%10);
                num/=10;
            }
            ps.println(num2);
            t--;
        }
        ps.close();
    }
}
