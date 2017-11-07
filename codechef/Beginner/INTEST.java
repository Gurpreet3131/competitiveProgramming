import java.util.*;
import java.io.*;
class INTEST {
   public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int count=0;
        int n=Integer.parseInt(st.nextToken());
        int k=Integer.parseInt(st.nextToken());
        while(n>0)
        {
            int t=Integer.parseInt(br.readLine());
            if(t%k==0) count++;
            n--;
        }
        ps.println(count);
        ps.close();
    }
}
