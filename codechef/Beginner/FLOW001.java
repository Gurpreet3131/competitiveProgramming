import java.util.*;
import java.io.*;
class FLOW001 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            ps.println(Integer.parseInt(st.nextToken())+Integer.parseInt(st.nextToken()));
            t--;
        }
        ps.close();
    }
}
