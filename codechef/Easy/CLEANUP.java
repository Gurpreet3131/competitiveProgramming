import java.util.*;
import java.io.*;
import java.math.*;
class CLEANUP
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
            int m=Integer.parseInt(st.nextToken());
            int job[]=new int[n+1];
            for(int i=0;i<m;i++)
            {
                job[Integer.parseInt(st2.nextToken())]=1;
            }
            int chef[]=new int[n-m];
            int asis[]=new int[n-m];
            int turn=0,chefindex=0,asisindex=0;
            for(int i=1;i<=n;i++)
            {
                if(job[i]==1) continue;
                if(turn==0)
                {
                    chef[chefindex]=i;
                    chefindex++;
                    turn=1;
                }
                else if(turn==1)
                {
                    asis[asisindex]=i;
                    asisindex++;
                    turn=0;
                }
            }
            if(chefindex==0)
            {
                ps.println();ps.println();
            }
            else
            {
                for(int i=0;i<chefindex;i++)
                {
                    ps.print(chef[i]+" ");
                }
                ps.println();
                if(asisindex==0)
                {
                    ps.println();
                }
                else
                {
                    for(int i=0;i<asisindex;i++)
                    {
                        ps.print(asis[i]+" ");
                    }
                    ps.println();
                }
            }
            
            t--;
        }
       ps.close();
    }
}
