import java.util.*;
import java.io.*;
class CHEFSQ
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
            int n=Integer.parseInt(st.nextToken());
            int nar[]=new int[n];
            String result="No";
            for(int i=0;i<n;i++)
            {
                nar[i]=Integer.parseInt(st2.nextToken());
            }
            int f=Integer.parseInt(st3.nextToken());
            int far[]=new int[f];
            for(int i=0;i<f;i++)
            {
                far[i]=Integer.parseInt(st4.nextToken());
            }    
            int j=0;
            for(int i=0;i<n;i++)
            {
                    if(nar[i]!=far[j]) continue;
                    j++;
                    if(j==f) 
                    {
                        result="Yes";break;
                    }
                    
            }
            ps.println(result);
            t--;
        }
        ps.close();
    }
}

