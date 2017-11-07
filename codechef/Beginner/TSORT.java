import java.util.*;
import java.io.*;
import java.math.*;
class TSORT
{

    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int n=Integer.parseInt(br.readLine());
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=Integer.parseInt(br.readLine());
        }
        Arrays.sort(a);
        for(int i=0;i<n;i++)
        {
            ps.println(a[i]);
        }
        
        ps.close();
    }
}
