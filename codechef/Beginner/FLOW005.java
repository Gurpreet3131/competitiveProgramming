import java.util.*;
import java.io.*;
class FLOW005
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int T=Integer.parseInt(br.readLine());
        while(T>0)
        {
            int count=0;
            int N=Integer.parseInt(br.readLine());
            if(N>=100)
            {
                count=count+(N/100);
                N=N%100;
            }
            if(N>=50)
            {
                count+=N/50;
                N=N%50;
            }
            if(N>=10)
            {
                count+=N/10;
                N=N%10;
            }
            if(N>=5)
            {
                count+=N/5;
                N=N%5;
            }
            if(N>=2)
            {
                count+=N/2;
                N=N%2;
            }
            if(N>=1)
            {
                count+=N;
                N=0;
            }
            ps.println(count);
            T--;
        }
        ps.close();
        
    }
}