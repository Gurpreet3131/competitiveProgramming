import java.util.*;
import java.io.*;
class RECTSQ
{
    public static int hcf(int a,int b)
    {
        if(b==0)
            return a;
        else
        {
            return hcf(b,a%b);
        }
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
            int m=Integer.parseInt(st.nextToken());
            int p=hcf(m,n);
            int count=0;
            count+=(m*n)/(p*p);
            ps.println(count);
            t--;
        }
        ps.close();
    }
}

