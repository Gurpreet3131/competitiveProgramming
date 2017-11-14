import java.util.*;
import java.io.*;

class nodes
{
    public long answer;
    public int leftone, rightone;
    public long leftzc, rightzc; 
    
    public nodes()
    {
        answer = 1; 
        leftzc = 1; rightzc = 1;
        leftone = -1; rightone = -1;
    }
    public nodes(int val)
    {
        answer = 0;
        leftone = -1; rightone = -1;
        leftzc = 0; rightzc = 0;
    }
}

class CSUBQ
{ 

    public static int size = 10000001;
    public static nodes leftseg[] = new nodes[size];
    public static nodes rightseg[] = new nodes[size];
    public static long arr[]=new long[500005];

    
    public static nodes dummynode = new nodes(1);

    public static long L, R;

    public static void debug()
    {
        return;
    }
    public static void buildsegmenttree(int start, int end, int node)
    {
        //System.out.println(start + " " + end);
        if(leftseg[node] == NULL)
        {
            leftseg[node] = new nodes();
            rightseg[node] = new nodes();
        }
        if(start != end)
        {
            //System.out.println(start + " " + end);
            int m = (start + end) / 2;

            buildsegmenttree(start, m, node*2);
            buildsegmenttree(m + 1, end, node*2+1);

            //System.out.println("node = " + node);

            leftseg[node].leftzc = leftseg[node*2].leftzc+leftseg[node*2+1].rightzc;
            leftseg[node].rightzc = leftseg[node].leftzc;

            leftseg[node].answer = leftseg[node*2].rightzc * leftseg[node*2 + 1].leftzc;
            leftseg[node].answer += (leftseg[node*2].answer + leftseg[node*2+1].answer);
                  
            rightseg[node].leftzc = rightseg[node*2].leftzc+rightseg[node*2+1].rightzc;
            rightseg[node].rightzc = rightseg[node].leftzc;

            rightseg[node].answer = rightseg[node*2].rightzc * rightseg[node*2 + 1].leftzc;
            rightseg[node].answer += (rightseg[node*2].answer + rightseg[node*2+1].answer);
            
        }
    }

    public static nodes combine(nodes a, nodes b)
    {
        nodes temp = new nodes();
        temp.answer = a.answer + b.answer;
        
        if(a.rightone > 0 && b.leftone > 0)
        {
            temp.leftone = a.leftone;
            temp.rightone = b.rightone;
            temp.leftzc = a.leftzc;
            temp.rightzc = b.rightzc;
            temp.answer += a.rightzc * b.leftzc;
        }
        else if(a.rightone < 0 && b.leftone > 0)
        {
            temp.leftone = b.leftone;
            temp.rightone = b.rightone;
            temp.leftzc = a.rightzc + b.leftzc;
            temp.rightzc = b.rightzc;
            temp.answer += a.rightzc * b.leftzc;
        }
        else if(a.rightone > 0 && b.leftone < 0)
        {
            temp.leftone = a.leftone;
            temp.rightone = a.rightone;
            temp.leftzc = a.leftzc;
            temp.rightzc = a.rightzc + b.leftzc;
            temp.answer += a.rightzc * b.leftzc;
        }
        if(a.rightone < 0 && b.leftone < 0)
        {
            temp.answer += a.rightzc * b.leftzc;
            temp.leftone = -1;
            temp.rightone = -1;
            temp.leftzc = a.rightzc + b.leftzc;
            temp.rightzc = temp.leftzc;
        }

        return temp;    
    }

    public static void rightupdate(int l, int r, long val, int start, int end, int node)
    {
        if(start > r || end < l) return;
        else if(start >= l && end <= r)
        {
            if(val >= (R+1))
            {
                rightseg[node].leftzc = 0;
                rightseg[node].rightzc = 0;
                rightseg[node].leftone = start;
                rightseg[node].rightone = start;
                rightseg[node].answer = 0;
            }
            else
            {
                rightseg[node].leftzc = 1;
                rightseg[node].rightzc = 1;
                rightseg[node].leftone = -1;
                rightseg[node].rightone = -1;
                rightseg[node].answer = 1;
            }
        }
        else
        {
            int mid = (start + end) / 2;
            rightupdate(l,r,val,start,mid,node*2);
            rightupdate(l,r,val,mid+1,end, node*2 + 1);
            nodes temp = new nodes(); 
            temp = combine(rightseg[node*2], rightseg[node*2+1]);
            rightseg[node] = temp;
            /*
            rightseg[node].answer = temp.answer;
            rightseg[node].leftone = temp.leftone;
            rightseg[node].rightone = temp.rightone;
            rightseg[node].leftzc = temp.leftzc;
            rightseg[node].rightzc = temp.rightzc;
            */
        }
    }

    public static void leftupdate(int l, int r, long val, int start, int end, int node)
    {
        if(start > r || end < l) return;
        else if(start >= l && end <= r)
        {
            //System.out.println(start + " this " + end + " " + node);
            if(val >= L)
            {
                leftseg[node].leftzc = 0;
                leftseg[node].rightzc = 0;
                leftseg[node].leftone = start;
                leftseg[node].rightone = start;
                leftseg[node].answer = 0;
            }
            else
            {
                leftseg[node].leftzc = 1;
                leftseg[node].rightzc = 1;
                leftseg[node].leftone = -1;
                leftseg[node].rightone = -1;
                leftseg[node].answer = 1;
            }
        }
        else
        {
            int mid = (start + end) / 2;
            leftupdate(l,r,val,start,mid,node*2);
            leftupdate(l,r,val,mid+1,end, node*2 + 1);
            nodes temp = new nodes(); 
            temp = combine(leftseg[node*2], leftseg[node*2+1]);
            leftseg[node] = temp;
            /*
            leftseg[node].answer = temp.answer;
            leftseg[node].leftone = temp.leftone;
            leftseg[node].rightone = temp.rightone;
            leftseg[node].leftzc = temp.leftzc;
            leftseg[node].rightzc = temp.rightzc;
            */

        }
    }

    public static nodes rightquery(int l, int r, int start, int end, int node)
    {
        if(start > r || end < l) return dummynode;
        else if(start >= l && end <= r) return rightseg[node];
        else
        {
            int mid = (start + end) / 2;
            return combine(rightquery(l, r, start, mid, node*2), rightquery(l,r,mid + 1,end,node*2 + 1));
        }
    }

    public static nodes leftquery(int l, int r, int start, int end, int node)
    {
        if(start > r || end < l) return dummynode;
        else if(start >= l && end <= r) return leftseg[node];
        else
        {
            int mid = (start + end) / 2;
            nodes tempnode = combine(leftquery(l, r, start, mid, node*2), leftquery(l,r,mid + 1,end,node*2 + 1));
            //System.out.println(node + " seg = " + tempnode.answer + " " + tempnode.leftone + " " + tempnode.rightone + " " + tempnode.leftzc + " " + tempnode.rightzc);
            return tempnode;
        }
    }


    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        //for(int i = 0; i < size; i++)
        {
            //if(i % 1000000 == 0) System.out.println(i);
          //  leftseg[i] = new nodes();
            //rightseg[i] = new nodes();
        }
        //return;
        
        String[] s = br.readLine().split(" ");

        int n= Integer.parseInt(s[0]);
        int q= Integer.parseInt(s[1]);
        L = Long.parseLong(s[2]);
        R = Long.parseLong(s[3]);

        for(int i = 0; i <= n; i++) arr[i] = 0;
        int type, l; long r;
        //ps.println(n + " " + q + " " + L + " " + R);
        //ps.println(leftseg[0].answer + " " + rightseg[0].answer);
        buildsegmenttree(1, n, 1);

        while(q > 0)
        {
            //System.out.println(q);
            String[] s2 = br.readLine().split(" ");            
            type = Integer.parseInt(s2[0]);
            l = Integer.parseInt(s2[1]);
            r = Long.parseLong(s2[2]);
            //ps.println(type + " " + l + " " + r);
            if(type == 1)
            {
                debug();
                if((arr[l] >= (R+1) && r < (R+1)) || (arr[l] < (R+1) && r >= (R+1)) )
                        rightupdate(l, l, r, 1, n, 1);

                if( (arr[l] >= L && r < L) || (arr[l] < L && r >= L) )
                    leftupdate(l, l, r, 1, n, 1);

                arr[l] = r;
            }
            else 
            {
                int rr = (int)r;
                nodes right = rightquery(l, rr, 1, n, 1);
                nodes left = leftquery(l, rr, 1, n, 1); 
                long leftans = 0, rightans = 0;
                long total = (r - l + 1);
                total  = (total * (total + 1)) / 2;
                rightans = total - right.answer;
                leftans = total - left.answer;
                //ps.println(leftans + " " + rightans);

                long ans = leftans - rightans;
                ps.println(ans);
            }
            //for(int i = 1; i <= 26; i++)
                {
              //      ps.println(i + " seg = " + leftseg[i].answer + " " + leftseg[i].leftone + " " + leftseg[i].rightone + " " + leftseg[i].leftzc + " " + leftseg[i].rightzc);
                }
            q--;
        }
        ps.close();
    }
}