import java.util.*;
import java.io.*;
class MNMX 
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
            int a[]=new int[n];
            long min=0;
            for(int i=0;i<n;i++)
            {
                a[i]=Integer.parseInt(st2.nextToken());
                if(i==0)
                {
                    min=a[0];
                    continue;
                }
                if(min>a[i])
                {
                    min=a[i];
                }
            }
            ps.println(((long)(n-1))*min);
            t--;
        }
        ps.close();
    }
}

