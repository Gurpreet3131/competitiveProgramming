import java.util.*;
import java.io.*;

class CEILRCPT 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int p=Integer.parseInt(br.readLine());
            int count=0,i=11;
            while(p!=0)
            {
                if(Math.pow(2.0,i)<=p)
                {
                    p-=Math.pow(2.0,i);
                    count++;
                }
                else i--;
                
            }
            ps.println(count);
            
            t--;
        }
        ps.close();
    }
}
