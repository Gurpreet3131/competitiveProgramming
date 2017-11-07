import java.util.*;
import java.io.*;
class FLOW017 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            int c=Integer.parseInt(st.nextToken());
            int max=0;
            if((a>=c && a<=b) || (a<=c && a>=b))
            {
                max=a;
            }
            else 
            {
                if(a>=c && a>=b) max=(b>c)?b:c;
                if(a<=c && a<=b) max=(b>c)?c:b;
            }
            ps.println(max);
            t--;
        }
        ps.close();
    }
}

