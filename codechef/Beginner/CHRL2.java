import java.util.*;
import java.io.*;
class CHRL2
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        String str=br.readLine();
        int c=0,h=0,e=0,f=0;
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)=='C') c++;
            if(str.charAt(i)=='H' && c>h) h++;
            if(str.charAt(i)=='E' && c>=h && h>e) e++;
            if(str.charAt(i)=='F' && c>=h && h>=e && e>f) f++;
        }
        ps.println(f);
        ps.close();
    }
}

