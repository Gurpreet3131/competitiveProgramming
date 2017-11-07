import java.util.*;
import java.io.*;
class FLOW004 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            String n=br.readLine();
            ps.println((Integer.parseInt(""+n.charAt(0)))+Integer.parseInt(""+n.charAt(n.length()-1)));
            t--;
        }
    }
}
