
import java.util.*;
import java.io.*;
class doughnuts 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            long n=Integer.parseInt(st.nextToken());
            int m=Integer.parseInt(st.nextToken());
            int tempm=m;
            int a[]=new int[m];
            int counta[]=new int[100001];
            int count=0,mini=0;
            for(int i=0;i<m;i++)
            {
                a[i]=Integer.parseInt(st2.nextToken());
                if(a[i]<mini) mini=a[i];
                counta[a[i]]++;
            }
            
            if(m==n) 
            {
                count=(tempm/2);
                System.out.println(count);
                t--;
                continue;
            }
            if(m==1) count=0;
            else
            {
                for(int i=mini;tempm!=1;i++)
                {
                    if(counta[i]==0) continue;
                    else
                    {
                            if(tempm>(i))
                            {
                                count+=i;
                                if(tempm==i+1)  tempm-=i;
                                else tempm-=(i+1);
                                counta[i]--;
                                if(tempm==1) break;
                            }
                            else 
                            {
                               count+=(tempm-1);
                               break;
                            }
                            
                        
                        if(counta[i]!=0) i--;
                    }
                }
            }    
            
            System.out.println(count);
            t--;
        }
    }
     
}
