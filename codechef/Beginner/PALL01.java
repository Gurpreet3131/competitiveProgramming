import java.util.*;
import java.io.*;
    class PALL01 
    {
        public static void main(String[] args) throws Exception
        {
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            PrintStream ps=new PrintStream(System.out);
            int T=Integer.parseInt(br.readLine());
            while(T>0)
            {
                int num=0;
                int N=Integer.parseInt(br.readLine());
                int M=N;
                while(M>0)
                {
                    num=num*10+(M%10);
                    M=M/10;
                }
                if(N==num) ps.println("wins");
                else ps.println("losses");
                T--;
            }  
            ps.close();
        }
    } 