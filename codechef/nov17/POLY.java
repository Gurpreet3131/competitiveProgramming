import java.util.*;
import java.io.*;

class POLY
{ 
    public static long a[] = new long[100005];
    public static long b[] = new long[100005];
    public static long c[] = new long[100005];
    public static long d[] = new long[100005];
    public static int minid[] = new int[100005];
    public static int n;
    public static long evaluate(long x, int index)
    {
        long answer = c[index] + d[index] * x;
        answer = b[index] + answer * x;
        answer = a[index] + answer * x;
        return answer;
    }

    public static void precompute(long val)
    {
        for(int i = 0; i < n; i++)
        {
            for(long j = 0; j <= val; j++)
            {
                long value = evaluate(j, i);
                if(i == 0) minid[(int)j] = i; 
                else
                {
                    int index = (int)j;
                    long val2 = evaluate(j, minid[index]);
                    if(value < val2)
                    {
                        minid[index] = i;
                    }
                }
            }
        }
    }

    public static void bs(long l, long r)
    {
        if(l <= r)
        {
            long mid = (l + r) / 2;
            long vall = evaluate(l, 0);
            long valr = evaluate(r, 0);
            int lid = 0, rid = 0;
            for(int i = 1; i < n; i++)
            {
                long val = evaluate(l, i);
                if(val < vall)
                {
                    vall = val; lid = i;
                }
            }             
            for(int i = 1; i < n; i++)
            {
                long val = evaluate(r, i);
                if(val < valr)
                {
                    valr = val; rid = i;
                }
            }             
            if(lid != rid)
            {   
                bs(mid + 1, r);
                bs(l, mid);
            }
            else
            {
                for(long i = r; i >= l; i--)
                {
                    minid[(int)i] = rid;
                }
            }
        }
    }

    public static void solve(long val)
    {
        long l = val + 1, r = 100000;
        bs(l, r);
    }

    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t = Integer.parseInt(br.readLine());
        while(t > 0)
        {
            n= Integer.parseInt(br.readLine());
            //System.out.println(n);
            for(int i = 0; i < n; i++)
            {
                String[] s = br.readLine().split(" ");
                a[i] = Long.parseLong(s[0]);
                b[i] = Long.parseLong(s[1]);
                c[i] = Long.parseLong(s[2]);
                d[i] = Long.parseLong(s[3]);
            }
            int q = Integer.parseInt(br.readLine());
            long num = 1100;
            solve(num);
            precompute(num);
            for(int i = 0; i < q; i++)
            {
                long tval = Long.parseLong(br.readLine());
                long answer = evaluate(tval, minid[(int)tval]);
                System.out.println(answer);    
            }
            t--;
        }
        
        ps.close();
    }
}