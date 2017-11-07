import java.util.*;
import java.io.*;
class FLOW002 
{
    public static void main(String[] args)throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            System.out.println(Integer.parseInt(st.nextToken())%Integer.parseInt(st.nextToken()));
            t--;
        }
    }
}
