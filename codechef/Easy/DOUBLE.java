import java.util.*;
import java.io.*;
import java.math.*;
class DOUBLE
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int length=Integer.parseInt(br.readLine());
            if(length%2==0) ps.println(length);
            else ps.println(length-1);
            t--;
	 }
        ps.close();
    }
}
