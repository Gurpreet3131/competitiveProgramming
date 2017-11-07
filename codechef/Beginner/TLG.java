import java.util.*;
import java.io.*;

class TLG 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int N=Integer.parseInt(br.readLine());
        int l=0,w=0,p1t=0,p2t=0;
        while(N>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s=Integer.parseInt(st.nextToken());
            int t=Integer.parseInt(st.nextToken());
            p1t=p1t+s;
            p2t=p2t+t;
            if(Math.abs(p1t-p2t)>Math.abs(l))
            {    
                l=Math.abs(p1t-p2t);
                if((p1t-p2t)>0) w=1;
                else    w=2;
                
            }
            N--;
        }
        ps.println(w+" "+l);
        ps.close();
    }
}
