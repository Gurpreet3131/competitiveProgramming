import java.util.*;
import java.io.*;
class KSPHERES
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        StringTokenizer st3 = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        int c=Integer.parseInt(st.nextToken());
        int U[]=new int[n];
        int L[]=new int[m];
        long D[]=new long[c+1];
        int countU[]=new int[c+1];
        int countL[]=new int[c+1];
        long totalcount[]=new long[c+1];
        
        
        
        for(int i=0;i<n;i++)

        {
            U[i]=Integer.parseInt(st2.nextToken());
            countU[U[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            L[i]=Integer.parseInt(st3.nextToken());
            countL[L[i]]++;
        }
        for(int i=1;i<=c;i++)
        {
            totalcount[i]=countU[i]*countL[i];
        }
        long pr[][]=new long[c+1][c+1];
        for(int i=1;i<c;i++)
        {
            for(int j=i+1;j<=c;j++)
            {
                pr[i][j]=totalcount[i]*totalcount[j];
                pr[i][j]%=1000000007;
                D[1]+=pr[i][j];
            }
        }
        int gp=2;
        long p=1;
        while(gp+1<=c)
        {
              
                long p1[][]=new long[c+1][c+1];
                for(int i=1;i<c;i++)
                {
                    for(int j=i+1;j<=c;j++)
                    {
                        p1[i][j]=pr[i][j]*totalcount[j+gp-1];
                    }
                }
                for(int i=1;i<=c-gp;i++)
                {
                    for(int k=1;k<=c-i;k++)
                    {
                            p1[k][i]=totalcount[i]*totalcount[i+k];
                            p1[k][i]=p1[k][i]%1000000007;
                    }
                    
                    p=totalcount[i];
                    p=p%1000000007;
                    if(i<gp)
                    {
                        for(int j=i+1;j<i+gp;j++)
                        {
                            p=p*totalcount[j];
                            p=p%1000000007;
                            start=j+1;
                        }
                        
                    }
                    else start=i+1;
                    
                    
                        for(int j=start;j<=c;j++)
                        {
                            D[gp]+=p*totalcount[j];
                            D[gp]%=1000000009;
                        }
                    
                }
                gp++;
        }
        for(int i=1;i<=c;i++) ps.print(countU[i]+" ");
        ps.println();
        for(int i=1;i<=c;i++) ps.print(countL[i]+" ");
        ps.println();
        for(int i=1;i<=c;i++) ps.print(totalcount[i]+" ");
        ps.println();
        for(int i=1;i<=c;i++) ps.print(D[i]+" ");
        ps.close();
    }
}
