//50 points

import java.util.*;
import java.io.*;
class SUBINC2
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
            int arr[]=new int[n];
            int count=n,countg=2;
            for(int i=0;i<n;i++)
            {
                arr[i]=Integer.parseInt(st2.nextToken());
            }
            int gp=2;
            while(gp<=n)
            {
                if(countg<=1) break;
                countg=0;
                for(int i=0;i<=n-gp;i++)
                {
                    int counter=0;
                    for(int j=i;j<i+gp-1;j++)
                    {
                        if(arr[j]>arr[j+1])
                        {
                            counter=1;
                            break;
                        }
                    }
                    if(counter==0)
                    {
                        countg++; count++;
                    }
                }
                gp++;
            }
            ps.println(count);
            t--;
        }
        ps.close();
    }
}
