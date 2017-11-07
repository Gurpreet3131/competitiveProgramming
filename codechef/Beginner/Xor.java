import java.util.*;
import java.io.*;
class Xor
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            //StringTokenizer st2 = new StringTokenizer(br.readLine());
            int k=Integer.parseInt(st.nextToken());
            String p[][]=new String [k][];
            for(int i=0;i<k;i++)
            {
                StringTokenizer st2 = new StringTokenizer(br.readLine());
                int l=1,j=0;
                while(j<l)
                {
                    if(j==0) l=Integer.parseInt(st2.nextToken());
                    p[i][j]=st2.nextToken();
                    j++;
                }
            }
            ps.println();
            t--;
        }
        ps.close();
    }
}

