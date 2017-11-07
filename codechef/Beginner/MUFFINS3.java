import java.util.*;
import java.io.*;

class MUFFINS3 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            ps.println((Integer.parseInt(br.readLine())/2)+1);
            t--;
        }
        ps.close();
    }
}
