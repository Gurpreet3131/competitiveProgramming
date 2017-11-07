import java.util.*;
import java.io.*;
class CARVANS
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
            int speed[]=new int[n];
            int maxspeed=0;
            int countmax=1;
            for(int i=0;i<n;i++)
            {
                speed[i]=Integer.parseInt(st2.nextToken());
                if(i==0) 
                {
                    maxspeed=speed[i];continue;
                }
                if(speed[i]<=maxspeed)
                {
                    countmax++;
                    maxspeed=speed[i];
                }
            }
            ps.println(countmax);
            t--;
        }
        ps.close();
    }
}
