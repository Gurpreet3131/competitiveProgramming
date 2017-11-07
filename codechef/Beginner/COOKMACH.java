import java.util.*;
import java.io.*;
class COOKMACH 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int T=Integer.parseInt(br.readLine());
        while(T>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            int count=0;
            
            while(a!=b)
            {   
                int p=a;
                boolean pow=false;
                while(p>0 && p!=1)
                {
                    if(p%2!=0)
                    {
                        pow=false;
                        break;
                    }
                    p=p/2;
                    if(p==1) pow=true;
                }
                if(pow==false && a!=1)
                {
                    if(a%2==0)
                    {
                        a/=2;
                    }
                    else a=(a-1)/2;
                    count++;
                }
                else
                {
                    if(a>b)
                    {
                        a/=2;
                    }
                    else 
                    {
                        a*=2;
                    
                    }
                    count++;
                }    
            }  
            ps.println(count);
            T--;
        }
        ps.close();
    }
}