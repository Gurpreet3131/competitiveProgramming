import java.util.*;
import java.io.*;
class GDOG 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            int k=Integer.parseInt(st.nextToken());
            int max=0,tempn=n;
            for(int i=1;i<=k;i++)
            {
                tempn=n;
                tempn=tempn%i;
                max=(tempn>max)?tempn:max;
            }
            ps.println(max);
            t--;
        }
        ps.close();
    }
}
