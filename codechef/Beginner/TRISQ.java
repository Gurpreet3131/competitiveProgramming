import java.util.*;
import java.io.*;
class TRISQ
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int b=Integer.parseInt(br.readLine());
            int n=(b/2)-1;
            ps.println((n*(n+1)/2));
            t--;
        }
        ps.close();
    }
}

