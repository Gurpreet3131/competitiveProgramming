import java.util.*;
import java.io.*;
class MARCHA1
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            int m=Integer.parseInt(st.nextToken());
            int notes[]=new int[n];
            int sum=0,sumall=0;
            for(int i=0;i<n;i++)
            {
                notes[i]=Integer.parseInt(br.readLine());
                sumall+=notes[i];
            }
            if(sumall<m) 
            {
                ps.println("No");
                t--;continue;
            }
            if(sumall==m)
            {
                ps.println("Yes");
                t--;continue;
            }
            int ilimit=(int)Math.pow(2,n);
            for(int i=1;i<ilimit;i++)
            {
                sum=0;
                for(int j=0;j<n;j++)
                {
                    int set= ((i) & (1<<j));
                    if(set!=0)
                    {
                        sum+=notes[j];
                    }
                }
                if(sum==m)
                {
                    ps.println("Yes");
                    break;
                }
            }
            if(sum!=m) ps.println("No");
            t--;
	 }
        ps.close();
    }
}
