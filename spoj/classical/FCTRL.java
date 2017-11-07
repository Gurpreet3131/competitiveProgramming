import java.util.*;
import java.io.*;
class FCTRL 
{
   public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        for(int j=0;j<t;j++)
        {
            int z=0;
            int n=Integer.parseInt(br.readLine());
            for(int i=5;n/i>=1;i*=5)
            {
               z+=n/i;
                
            }
            ps.println(z);
        }
        ps.close();
    }
}
