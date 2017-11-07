import java.util.*;
import java.io.*;
class FSQRT 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            ps.println((int)Math.sqrt(Integer.parseInt(br.readLine())));
            t--;
        }
        ps.close();
    }
}
