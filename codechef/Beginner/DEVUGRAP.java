import java.util.*;
import java.io.*;
class DEVUGRAP
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
            int n=Integer.parseInt(st.nextToken());
            long k=Long.parseLong(st.nextToken());
            long min=0,quo=0,low=0,upp=0;
            for(int i=0;i<n;i++)
            {
                int a=Integer.parseInt(st2.nextToken());
                quo=a/k;
                low=a-(quo*k);
                upp=((quo+1)*(k))-a;
                if(low<upp && (a-low)!=0)
                {
                    min+=low;
                }
                else min+=upp;
            }
            ps.println(min);
            t--;
        }
        ps.close();
    }
}

