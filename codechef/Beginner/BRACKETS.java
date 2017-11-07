import java.util.*;
import java.io.*;
class  BRACKETS
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            String line=br.readLine();
            int balance=0,max=0;
            for(int i=0;i<line.length();i++)
            {
                if(line.charAt(i)=='(') balance++;
                if(line.charAt(i)==')') balance--;
                max=(max>balance)? max:balance;
            }
            for(int i=0;i<max;i++)
            {
                ps.print("(");
            }
            for(int i=0;i<max;i++)
            {
                ps.print(")");
            }
            ps.println();
            t--;
        }
        ps.close();
    }
}

