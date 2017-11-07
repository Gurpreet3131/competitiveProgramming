import java.util.*;
import java.io.*;
class threewaycommunication 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            StringTokenizer st3 = new StringTokenizer(br.readLine());
            StringTokenizer st4 = new StringTokenizer(br.readLine());
            int r=Integer.parseInt(st.nextToken());
            int x1=Integer.parseInt(st2.nextToken());
            int y1=Integer.parseInt(st2.nextToken());
            int x2=Integer.parseInt(st3.nextToken());
            int y2=Integer.parseInt(st3.nextToken());
            int x3=Integer.parseInt(st4.nextToken());
            int y3=Integer.parseInt(st4.nextToken());
            double d1=Math.sqrt((x2-x1)*(x2-x1)+((y2-y1)*(y2-y1)));
            double d2=Math.sqrt((x3-x2)*(x3-x2)+((y3-y2)*(y3-y2)));
            double d3=Math.sqrt((x3-x1)*(x3-x1)+((y3-y1)*(y3-y1)));
            if((d1<=r && d2<=r)||(d2<=r && d3<=r)||(d1<=r && d3<=r))
                ps.println("yes");
            else ps.println("no");
            t--;
        }
        ps.close();
    }
    
}
