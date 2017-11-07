import java.util.*;
import java.io.*;
class SPALNUM
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int l=Integer.parseInt(st.nextToken());
            int r=Integer.parseInt(st.nextToken());
            int sum=0;
            for(int i=l;i<=r;i++)
            {
                int num=0,n=i;
                while(n>0)
                {
                    num=num*10+(n%10);
                    n=n/10;
                }
                if(i==num) sum+=i; 
            }
            ps.println(sum);
            t--;
        }
        ps.close();
    }
}