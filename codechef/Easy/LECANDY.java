import java.util.*;
import java.io.*;
import java.math.*;
class LECANDY
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int N=Integer.parseInt(st.nextToken());
            int C=Integer.parseInt(st.nextToken());
            int sum=0;
            for(int i=0;i<N;i++)
            {
                sum+=Integer.parseInt(st2.nextToken());
            }
            if(sum<=C) ps.println("Yes");
            else ps.println("No");
            t--;
        }
       ps.close();
    }
}
