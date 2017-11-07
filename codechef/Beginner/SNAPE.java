import java.util.*;
import java.io.*;
class SNAPE
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double b=Double.parseDouble(st.nextToken());
            double ls=Double.parseDouble(st.nextToken());
            ps.println(Math.sqrt((ls*ls)-(b*b))+" "+Math.sqrt((ls*ls)+(b*b)));
            t--;
        }
        ps.close();
    }
}
