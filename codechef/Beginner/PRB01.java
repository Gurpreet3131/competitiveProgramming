import java.util.*;
import java.io.*;
class PRB01
{
    public static void main(String[] args) throws Exception
    {
        
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int T=Integer.parseInt(br.readLine());
        while(T>0)
        {
            int p=0;
            int N=Integer.parseInt(br.readLine());
            for(int i=2;i<Math.sqrt(N) ;i++)
            {
                if(N%i==0)
                {
                    p=1;
                    break;
                }    
            }
            if(p==1) ps.println("no");
            else ps.println("yes");
            T--;
                
        }
        ps.close();
    }
}