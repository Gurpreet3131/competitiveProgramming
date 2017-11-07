import java.util.*;
import java.io.*;
class REMISS 
{
    public static void main(String[] args) throws Exception
    {
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            ps.println(((a>b)?a:b)+" "+(a+b));
            t--;
        }
        ps.close();
    }
}
