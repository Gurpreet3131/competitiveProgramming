import java.util.*;
import java.io.*;
import java.math.*;
class codecrickk
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintStream ps=new PrintStream(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        long i=Long.parseLong(st.nextToken());
        long k=Long.parseLong(st.nextToken());
        double s=Double.parseDouble(st.nextToken());
        double ai=Double.parseDouble(st2.nextToken());
        double bi=Double.parseDouble(st2.nextToken());
        double tempa=ai,tempb=bi,x=Math.sqrt(2.0),y=Math.sqrt(3.0);
        double q;
            if(Math.abs(k-i)%2 !=0)
            {
                ai=(x*(tempa+tempb))-(x*y*(tempa-tempb));
                bi=(x*(tempa-tempb))+(x*y*(tempa+tempb));
                tempa=ai;
                tempb=bi;
                k--;
            }
        q=((ai+bi)*Math.pow(2.0,((2*(k-i))-s)));
        ps.println(q);
        ps.close();
    }
}
