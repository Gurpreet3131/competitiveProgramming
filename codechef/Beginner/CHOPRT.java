import java.util.*;
import java.io.*;
class CHOPRT
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
            if(a>b) ps.println(">");
            else if(a<b) ps.println("<");
            else ps.println("=");
            t--;
        }
        ps.close();
    }
}

