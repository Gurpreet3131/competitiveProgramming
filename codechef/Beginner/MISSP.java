import java.util.*;
import java.io.*;
class MISSP
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int n=Integer.parseInt(br.readLine());
            int type=0;
            for(int i=0;i<n;i++)
            {
                int doll=Integer.parseInt(br.readLine());
                type=type^doll;
            }
            ps.println(type);
            t--;
        }
        ps.close();
    }
}

