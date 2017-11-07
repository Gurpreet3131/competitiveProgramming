import java.util.*;
import java.io.*;
class FLOW016 
{
    public static int hcf(int a,int b)
    {
        if (b==0)
        return a;
        else
        return hcf(b,a%b);
    }
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
            ps.println(hcf(a,b)+" "+((a*b)/hcf(a,b)));
            t--;
        }
        ps.close();
    }
}

