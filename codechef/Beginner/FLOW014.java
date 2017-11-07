import java.util.*;
import java.io.*;
class FLOW014 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int h=Integer.parseInt(st.nextToken());
            Double c=Double.parseDouble(st.nextToken());
            int ts=Integer.parseInt(st.nextToken());
            int grade=0;
            if(h>50 && c<0.7 && ts>5600) grade=10;
            else if(h>50 && c<0.7) grade=9;
            else if(c<0.7 && ts>5600) grade=8;
            else if(h>50 && ts>5600) grade=7;
            else if(h>50 || c<0.7 || ts>5600) grade=6;
            else grade=5;
            ps.println(grade);
            t--;
        }
        ps.close();
    }
}

