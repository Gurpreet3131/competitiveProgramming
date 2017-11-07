import java.util.*;
import java.io.*;
class WDTBAM
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
            StringTokenizer st3 = new StringTokenizer(br.readLine());
            StringTokenizer st4 = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            String correct=st2.nextToken();
            String answer=st3.nextToken();
            long win=0,max=0;
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(correct.charAt(i)==answer.charAt(i)) 
                {
                    count++;
                }
            }
            for(int i=0;i<=n;i++)
            {
                win=Long.parseLong(st4.nextToken());
                if(count==n && i==n)
                {
                    max=win; break;
                }
                if(i==0) 
                {
                    max=win;
                    continue;
                }
                
                if(i<=count)
                {
                    if(max<win) max=win;
                }
            }
            ps.println(max);
            t--;
        }
        ps.close();
    }
}
