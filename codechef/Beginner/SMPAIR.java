import java.util.*;
import java.io.*;
class SMPAIR
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
            int a[]=new int[n];
            int min=1000001,min2=1000001;
            for(int i=0;i<n;i++)
            {
                a[i]=Integer.parseInt(st2.nextToken());
                if(a[i]<min) 
                {
                    min2=min;
                    min=a[i];
                }
                else if(a[i]<min2)
                {
                    min2=a[i];
                }
            }
            ps.println(min+min2);
            t--;
        }
        ps.close();
    }
}
