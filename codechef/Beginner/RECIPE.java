import java.util.*;
import java.io.*;

class RECIPE 
{
    public static int hcf(int m,int n)
    {
        if (n==0)
        return m;
        else
        return hcf(n,m%n);
    }
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            int n=Integer.parseInt(st.nextToken());
            int a[]=new int[n];
            int temphcf=1;
            for(int i=0;i<n;i++) 
            {
                a[i]=Integer.parseInt(st.nextToken());
                if(i==0) 
                {
                    temphcf=a[i];continue;
                }            
                temphcf=hcf(temphcf,a[i]);
            }    
            for(int i=0;i<n;i++)
            {
                a[i]/=temphcf;
                ps.print(a[i]+" ");
            }    
            ps.println();
            t--;
        }
        ps.close();
    }
}
