import java.util.*;
import java.io.*;
class CHRL4
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int k=Integer.parseInt(st.nextToken());
        int sp[]=new int[n+1];
        for(int i=1;i<=n;i++)
        {
            sp[i]=Integer.parseInt(st2.nextToken());
        }
        long p=sp[n];
        long temp=sp[n];
        int lane=n;
        while(lane!=1)
        {
            int min=sp[lane-1];
            int templane=lane-1;
            for(int j=lane-1;j>=lane-k && j>0;j--)
            {
                if(j==1) 
                {
                    min=sp[j];
                    templane=j;
                    break;
                }
                if(sp[j]<=min)
                {
                    min=sp[j];
                    templane=j;
                }
            }
            p*=min;
            p=p%1000000007;
            lane=templane;
        }
        for(int i=n;i!=1;)
        {
            i=i-k;
            if(i<=0) i=1;
            temp*=sp[i];
            temp=temp%1000000007;
        }
        p=(p<temp)?p:temp;
        ps.println(p);
        ps.close();
    }
}

