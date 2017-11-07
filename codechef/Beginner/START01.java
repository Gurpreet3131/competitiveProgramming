import java.util.*;
import java.io.*;
class START01 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        ps.println(Integer.parseInt(br.readLine()));
        ps.close();
    }
}

