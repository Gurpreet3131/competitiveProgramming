import java.io.*;
import java.util.*;
class rob
{
    public static void main(String[] args)throws Exception
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(in.readLine());
        double total=1000000000.0;
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int m=Integer.parseInt(st.nextToken());
            double p=Double.parseDouble(st.nextToken());
            double amountchef=0;
            amountchef=(total)*(1-(Math.pow(-p,m)))/(1+p);
            System.out.println(amountchef+" "+(1000000000-amountchef));
            t--;
        }
        
    }
}
