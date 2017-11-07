import java.util.*;
import java.io.*;
class test
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            int m=Integer.parseInt(st.nextToken());
            int set= ((n) & (1<<m));
            ps.println(m+"  " +(1<<m));
            ps.println(set);
            t--;
	 }
        ps.close();
    }
}
