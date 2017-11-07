//short method
import java.io.*;
import java.util.*;
class stepsm 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(in.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n=Integer.parseInt(st.nextToken());
            int arr[][]=new int[n][n];
            int count=0;
            int x[]=new int[n*n];
            int y[]=new int[n*n];
            for(int i=0;i<n;i++)
            {
                StringTokenizer st2 = new StringTokenizer(in.readLine());
                for(int j=0;j<n;j++)
                {
                    arr[i][j]=Integer.parseInt(st2.nextToken());
                    x[arr[i][j]-1]=i;
                    y[arr[i][j]-1]=j;
                }
            }
            for(int i=0;i<n*n-1;i++)
            {
                count+=Math.abs(x[i]-x[i+1])+Math.abs(y[i]-y[i+1]);
            }
            System.out.println(count);
            t--;
        }
    }
}
