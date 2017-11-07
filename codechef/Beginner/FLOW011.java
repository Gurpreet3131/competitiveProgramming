import java.util.*;
import java.io.*;
class FLOW011
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            int salary=Integer.parseInt(br.readLine());
            if(salary<1500) ps.printf("%g\n",salary+(0.1)*salary+(0.9)*salary);
            else ps.printf("%g\n",salary+500+(0.98)*salary);
            t--;
        }
        ps.close();
    }
}

