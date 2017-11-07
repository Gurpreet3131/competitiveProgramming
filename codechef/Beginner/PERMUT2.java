import java.util.*;
import java.io.*;
class PERMUT2
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int counter=0;
        while(true)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            if(n==0) break;
            counter=0;
            int per[]=new int[n];
            int perinv[]=new int[n];
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int i=0;i<n;i++)
            {
                per[i]=Integer.parseInt(st2.nextToken());
                perinv[per[i]-1]=i+1;
            }
            for(int i=0;i<n;i++)
            {
                if(per[i]!=perinv[i])
                {
                    counter=1;
                    break;
                }
            }
            if(counter==1) ps.println("not ambiguous");
            else ps.println("ambiguous");
            
        }
        ps.close();
    }
}
