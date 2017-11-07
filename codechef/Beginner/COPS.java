import java.util.*;
import java.io.*;
class COPS
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
            int M=Integer.parseInt(st.nextToken());
            int x=Integer.parseInt(st.nextToken());
            int y=Integer.parseInt(st.nextToken());
            int range=x*y;
            int cop[]=new int[M];
            int cover[]=new int[101];
            int min=0,max=0;
            int count=100;
            for(int i=0;i<M;i++)
            {
                cop[i]=Integer.parseInt(st2.nextToken());
                min=((cop[i]-range)<1)?1:(cop[i]-range);
                max=((cop[i]+range)>100)?100:(cop[i]+range);
                for(int j=min;j<=max;j++)
                {
                    if(cover[j]==0)
                    {
                        cover[j]=1;
                        count--;
                    }
                }
            }
            for(int i=1;i<101;i++)
            {
                cover[i]=0;
            }
            ps.println(count);
            t--;
        }
        ps.close();
    }
}

