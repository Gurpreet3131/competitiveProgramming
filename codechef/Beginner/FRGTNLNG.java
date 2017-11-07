import java.util.*;
import java.io.*;
class FRGTNLNG
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
            
            int n=Integer.parseInt(st.nextToken());
            int k=Integer.parseInt(st.nextToken());
            String ex[]=new String[n];
            String result[]=new String[n];
            for(int i=0;i<n;i++)
            {
                ex[i]=st2.nextToken();
                result[i]="NO";
            }
            
            String p[][]=new String [k][50];
            for(int i=0;i<k;i++)
            {
                StringTokenizer st3 = new StringTokenizer(br.readLine());
                int l=Integer.parseInt(st3.nextToken());
                for(int j=0;j<l;j++)
                {
                    p[i][j]=st3.nextToken();
                    for(int z=0;z<n;z++)
                    {
                        if(p[i][j].compareTo(ex[z])==0 && result[z].compareTo("NO")==0)
                        {
                            result[z]="YES";
                        }
                    }  
                      
                }
            }
            for(int i=0;i<n;i++)
            {
                ps.print(result[i]+" ");
            }
            ps.println();
            t--;
        }
        ps.close();
    }
}

