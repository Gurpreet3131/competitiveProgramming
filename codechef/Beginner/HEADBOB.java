import java.util.*;
import java.io.*;
class HEADBOB 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int n=Integer.parseInt(br.readLine());
            int count=0;
            String gest=br.readLine();
            for(int i=0;i<gest.length();i++)
            {
                if(gest.charAt(i)=='I') 
                {
                    ps.println("INDIAN");
                    break;
                }
                else if(gest.charAt(i)=='Y')
                {
                    ps.println("NOT INDIAN");
                    break;
                }
                else
                {
                    count++;
                    if(count==n) ps.println("NOT SURE");
                }
                

            }
            t--;
        }
        ps.close();
    }
}
