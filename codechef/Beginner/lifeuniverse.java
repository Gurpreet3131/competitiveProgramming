import java.util.*;
import java.io.*;
class lifeuniverse 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int N=Integer.parseInt(br.readLine());
        while(N!=42)
        {
           ps.println(N);
           N=Integer.parseInt(br.readLine());
            
        }
        
        ps.close();
    }
}

 
 
 
   
