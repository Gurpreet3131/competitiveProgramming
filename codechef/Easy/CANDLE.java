import java.util.*;
import java.io.*;
class CANDLE
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int number[]=new int[10];
            int min=9,age=0,num=0;
            for(int i=0;i<10;i++)
            {
                number[i]=Integer.parseInt(st.nextToken());
                if(i==0) continue;
                if(min>number[i])
                {
                    min=number[i];
                    age=i;
                }
            }
            
            if(min==0)
            {
                ps.println(age);
                t--; continue;
            }
            if(number[0]<min)
            {
                num=1;
                min=number[0];
                while(min>0)
                {
                    num=num*10;
                    min--;
                }
                age=num*10;
            }
            else
            {
                while(min>0)
                {
                    num=num*10+age;
                    min--;
                }
                age=num*10+age;
            }
            ps.println(age);
            t--;
        }
        ps.close();
    }
}
