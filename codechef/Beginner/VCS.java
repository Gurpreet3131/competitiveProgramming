import java.util.*;
import java.io.*;
class VCS
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
            int n=Integer.parseInt(st.nextToken());
            int m=Integer.parseInt(st.nextToken());
            int k=Integer.parseInt(st.nextToken());
            int ignored[]=new int[m+1];
            int tracked[]=new int[k+1];
            int unignored[]=new int[n-m+1];
            //int untracked[]=new int[n-k+1];
            int iat=0,uiaut=0,index=1;
            for(int i=1;i<=m;i++)
            {
                ignored[i]=Integer.parseInt(st2.nextToken());
            }
            
            for(int i=1;i<=k;i++)
            {
                tracked[i]=Integer.parseInt(st3.nextToken());
            }
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=k;j++)
                {
                    if(ignored[i]==tracked[j]) 
                    {
                        iat++;
                        break;
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                int counter=0;
                for(int j=1;j<=m;j++)
                {
                    if(ignored[j]==i)
                    {
                        counter=1;
                        break;
                    }
                }
                if(counter==0) {
                    unignored[index]=i;
                    index++;
                }         
            }
            for(int i=1;i<index;i++)
            {
                int counter=0;
                for(int j=1;j<=k;j++)
                {
                    if(unignored[i]==tracked[j])
                    {
                        counter=1;
                        break;
                    }
                    
                }
                if(counter==0) uiaut++;
            }
            ps.println(iat+" "+uiaut);
            t--;
        }
        ps.close();
    }
}

