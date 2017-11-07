import java.util.*;
import java.io.*;
class FLOW009
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int q=Integer.parseInt(st.nextToken());
            int p=Integer.parseInt(st.nextToken());
            double total=q*p;
            if(q>=1000) total=(0.9)*total;
            ps.printf("%.6f\n",total);
            t--;
        }
        ps.close();
    }
}

