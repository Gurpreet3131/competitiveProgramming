import java.util.*;
import java.io.*;
class HS08TEST 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x=Integer.parseInt(st.nextToken());
        double y=Double.parseDouble(st.nextToken());;
        if(x%5==0 && x+0.5<=y)
        {
            y=y-x-0.50;
        }
        ps.printf("%.2f",y);
        ps.close();
    }
}
