//100 points
import java.util.*;
import java.io.*;
class SUBINC
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
            long count=n;
            for(int i=0;i<n;i++)
            {
                arr[i]=Integer.parseInt(st2.nextToken());
            }
            for(int i=0;i<n-1;i++)
            {
                long countg=0;
                for(int j=i;j<n-1;j++)
                {
                    if(arr[j]<=arr[j+1])
                    {
                        countg++;
                        if(j==n-2) i=n;
                    }
                    else 
                    {
                        i=j;
                        break;
                    }
                      
                }
                count+=((countg*(countg+1))/2);
            }
            ps.println(count);
            t--;
        }
        ps.close();
    }
}
