import java.util.*;
import java.io.*;
import java.math.*;
class COOLING
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
            int N=Integer.parseInt(st.nextToken());
            int pies[]=new int[N];
            int racks[]=new int[N];
            for(int i=0;i<N;i++)
            {
                pies[i]=Integer.parseInt(st2.nextToken());
            }
            for(int i=0;i<N;i++)
            {
                racks[i]=Integer.parseInt(st3.nextToken());
            }
            Arrays.sort(pies);
            Arrays.sort(racks);
            int count=0,start=0;
            for(int i=0;i<N;i++)
            {
                    if(pies[i]<=racks[start])
                    {
                        count++;
                    }
                    else
                    {
                        i--;
                    }
                    start++;
                    if(start==N) break;
            }
            ps.println(count);
            t--;
	 }
        ps.close();
    }
}
