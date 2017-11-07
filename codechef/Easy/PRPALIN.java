import java.util.*;
import java.io.*;
import java.math.*;
class PRPALIN
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
            int N=Integer.parseInt(br.readLine());
            for(int i=N;i<1000000000;i++)
            {
                int prime=1;
                if(N>5 && (i%10==1 || i%10==3 || i%10==7 || i%10==9))
                {
                    int tempi=i;
                    
                    int num=0;
                    while(tempi>0)
                    {
                        num=num*10+(tempi%10);
                        tempi/=10;
                    }
                    
                    if(i!=num) continue; 
                   
                    for(int j=2;j<=Math.sqrt(i);j++)
                    {
                        if(i%j==0)
                        {
                            prime=0;
                            break;
                        }
                    }
                    if(prime==1) 
                    {
                        ps.println(i);
                        break;
                    }
                }
                
                
                if(N<=5)
                {
                    for(int j=N;j<=5;j++)
                    {
                        if(j==2 || j==3 || j==5)
                        {
                            ps.println(j);
                            prime=1;
                            break;
                        }
                        
                    }
                    if(prime==1) break;
                }
            }

       ps.close();
    }
}
