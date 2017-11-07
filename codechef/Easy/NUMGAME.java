import java.util.*;
import java.io.*;
import java.math.*;
class NUMGAME
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int N=Integer.parseInt(br.readLine());
            if(N%2==0) ps.println("ALICE");
            else ps.println("BOB");
            t--;
	 }
        ps.close();
    }
}
