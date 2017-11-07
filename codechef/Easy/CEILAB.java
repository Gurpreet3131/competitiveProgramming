import java.util.*;
import java.io.*;
class CEILAB
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A=Integer.parseInt(st.nextToken());
            int B=Integer.parseInt(st.nextToken());
            int diff=A-B;
            if(diff%10==9)      diff--;
            else diff++;
            ps.println(diff);
        ps.close();
    }
}
