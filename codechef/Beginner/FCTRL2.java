import java.util.*;
import java.io.*;
import java.math.*;
class FCTRL2 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            BigInteger fact=BigInteger.ONE;
            int n=Integer.parseInt(br.readLine());
            for(int i=2;i<=n;i++)
            {
                fact=fact.multiply(BigInteger.valueOf(i));
            }
            ps.println(fact);
            t--;
        }
        ps.close();
    }
}
