import java.util.*;
import java.io.*;
class FLOW008
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            if(Integer.parseInt(br.readLine())<10)  ps.println("What an obedient servant you are!");
            else ps.println(-1);
            t--;
        }
        ps.close();
    }
}

