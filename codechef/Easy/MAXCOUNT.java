import java.util.*;
import java.io.*;
import java.math.*;
class MAXCOUNT
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
            int N=Integer.parseInt(st.nextToken());
            int a[]=new int[N];
            int count[]=new int[10001];
            int max=0;
            for(int i=0;i<N;i++) 
            {
                a[i]=Integer.parseInt(st2.nextToken());
                count[a[i]]++;
                if(a[i]>max)
                {
                    max =a[i];
                }
            }
            int number=0,countnum=0;
            for(int i=1;i<=max;i++)
            {
                if(i==1) 
                {
                    number=i; countnum=count[i];
                    continue;
                }
                if(countnum<count[i])
                {
                    countnum=count[i];
                    number=i;
                }
            }
            ps.println(number+" "+countnum);
            t--;
	 }
        ps.close();
    }
}
