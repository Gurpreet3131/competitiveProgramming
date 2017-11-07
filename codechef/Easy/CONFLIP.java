import java.util.*;
import java.io.*;
class CONFLIP
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int g=Integer.parseInt(br.readLine());
            while(g>0)
            {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int i=Integer.parseInt(st.nextToken());
                int n=Integer.parseInt(st.nextToken());
                int q=Integer.parseInt(st.nextToken());
                int head=0,tail=0;
                if(n%2==0)
                {
                    head=(n/2);
                    tail=head;
                }
                else
                {
                    if(i==1)
                    {
                        tail=(n+1)/2;
                        head=n-tail;
                    }
                    else
                    {
                        head=(n+1)/2;
                        tail=n-head;
                    }
                }
                if(q==1) ps.println(head);
                else ps.println(tail);
                g--;
            }
            t--;
        }
        ps.close();
    }
}
