import java.util.*;
import java.io.*;
class SEGPROD
{
    public static long a[] = new long[1000001];
    public static long b[] = new long[400000];
    public static int n, q;
    public static long x, p, bucketsize, noofbuckets;
    public static long pairrange[][] = new long[1001][1001];
    public static long preprod[][] = new long[1001][1001];
    public static long sufprod[][] = new long[1001][1001];
    public static long bucketprod[] = new long[1001];
    public static long tree[] = new long[4000001];

    public static void debug()
    {
        return;
    }
    public static void build(int start, int end, int node)
    {
        if(start != end)
        {
            int m = (start + end) / 2;
            build(start, m, node*2);
            build(m+1, end, node * 2 + 1);
            tree[node] = (tree[node*2 + 1] * tree[node * 2]) % p;
        }
        else
        {
            tree[node] = a[start - 1];
        }
    }

    public static long segquery(int l, int r, int start, int end, int node)
    {
        if(start > r || end < l) return 1;
        else if(start >= l && end <= r)
        {
            return tree[node];
        } 
        else
        {
            int m = (start + end) / 2;
            long ans = (segquery(l, r, start,m, node*2) * segquery(l, r, m+1, end, node*2+1));
            if(ans >= p) ans %= p;
            return ans;
        }
    }

    public static void range()
    {
        for(int i = 0; i <= noofbuckets; i++)
        {
            for(int j = i; j <= noofbuckets; j++)
            {
                if(i != j)
                {
                    pairrange[i][j] = pairrange[i][j - 1] * bucketprod[j];
                    if(pairrange[i][j] >= p) pairrange[i][j] %= p;
                }
                else pairrange[i][j] = bucketprod[i];

            }
        }
    }

    public static void prefix()
    {
        for(int i = 0; i <= noofbuckets; i++)
        {
            int index = i * (int)bucketsize;
            for(int j = index; j < (index + bucketsize); j++)
            {
                if(j >= n) break;
                if(j == index) preprod[i][j - index] = a[j];
                else preprod[i][j - index] = preprod[i][j - index - 1] * a[j];
                if(preprod[i][j - index] >= 0) preprod[i][j - index] %= p;
            }
        }
    }

    public static void suffix()
    {
        for(int i = 0; i <= noofbuckets; i++)
        {
            int index = i * (int)bucketsize;
            for(int j = (int)bucketsize - 1; j >= 0; j--)
            {
                index = i * (int)bucketsize + j;
                if(index >= n) continue;

                if(j == (bucketsize - 1) || index == (n - 1))
                {
                    sufprod[i][j] = a[index];
                }
                else sufprod[i][j] = sufprod[i][j+1] * a[index];

                if(sufprod[i][j] >= p) sufprod[i][j] %= p;
            }
        }
    }

    public static void precomputeblocks()
    {
        for(int i = 0; i <= noofbuckets; i++)
        {
            debug();
            int index = i * (int)bucketsize;
            for(int j = index; j < (index + bucketsize); j++)
            {
                if(j >= n) break;

                if(j == index) bucketprod[i] = a[j];
                else bucketprod[i] *= a[j];
                if(bucketprod[i] >= p) bucketprod[i] %= p;
            }
        }
    }

    public static void solve()
    {
        x = 0;
        long left = 0, right = 0;
        long leftbucket = 0, rightbucket = 0;
        long leftindex = 0, rightindex = 0;
        for(int i = 0; i < q; i++)
        {
            long answer = 1;
            if(i % 64 != 0)
            {
                left = (x + left) % n; 
                right = (x + right) % n;
                //System.out.println(left + " " + right);
            }    
            else
            {
                left = (x + b[i / 64]) % n;
                right = (x + b[(i / 64 + 1)]) % n;    
            }
            if(left > right)
            {
                long temp = left; left = right; right = temp;
            }
            leftindex = left % bucketsize;
            rightindex = right % bucketsize;
            rightbucket = right / bucketsize;
            leftbucket = left / bucketsize;
            //System.out.println(left + " " + right);

            if(leftbucket != rightbucket)
            {
                int lb = (int)(leftbucket);
                int rb = (int)(rightbucket);
                int lp = (int)leftindex;
                int rp = (int)rightindex;

                if(rightbucket - leftbucket > 1)
                    answer = pairrange[lb+1][rb-1];

                //System.out.println(preprod[rb][rp] + " " + sufprod[lb][lp]);
                long ans = (preprod[rb][rp] * sufprod[lb][lp]) % p;
                answer = (answer * ans) % p;
            }
            else
            {
                int lb = (int)(left+1), rb = (int)(right + 1);
                answer = segquery(lb, rb, 1, n, 1);
            }
            //System.out.println("ans = " +  answer);
            x = (answer + 1) % p;
           // System.out.println("x = " + x);
        }
        System.out.println(x);   
    }
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	    PrintStream ps=new PrintStream(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while(t > 0)
        {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            StringTokenizer st3 = new StringTokenizer(br.readLine());
            StringTokenizer st4 = new StringTokenizer(br.readLine());
            
            n = Integer.parseInt(st2.nextToken());
            bucketsize = (long)Math.sqrt(n);
            noofbuckets = (n - 1) / bucketsize;
            p= Long.parseLong(st2.nextToken());
            q = Integer.parseInt(st2.nextToken());
            x = 0;
            for(int i = 0; i < n; i++)
            {
                a[i] = Long.parseLong(st3.nextToken());
                if(a[i] >= p) a[i] %= p;
            }
            int bn = q / 64 + 2;
            for(int i = 0; i < bn; i++)
            {
                b[i] = Long.parseLong(st4.nextToken());
            }
            precomputeblocks();
            suffix(); prefix(); range();
            build(1, n, 1);
            solve();
            t--;
        }

    }
}