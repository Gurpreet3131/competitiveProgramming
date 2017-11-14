#include <stdio.h>
#include <stdlib.h>
struct nodes
{
    long long answer;
    int leftone, rightone;
    long long leftzc, rightzc; 
};

struct nodes leftseg[10000001], rightseg[10000001];
struct nodes dummynode;

long long arr[500005];
long long L, R;
void debug()
{
    return;
}
void buildsegmenttree(int start, int end, int node)
{
    if(start != end)
    {
        int m = (start + end) / 2;
        buildsegmenttree(start, m, node*2);
        buildsegmenttree(m + 1, end, node*2+1);

        leftseg[node].leftzc = leftseg[node*2].leftzc+leftseg[node*2+1].rightzc;
        leftseg[node].rightzc = leftseg[node].leftzc;
        leftseg[node].leftone = -1; leftseg[node].rightone = -1;
        leftseg[node].answer = leftseg[node*2].rightzc * leftseg[node*2 + 1].leftzc;
        leftseg[node].answer += (leftseg[node*2].answer + leftseg[node*2+1].answer);
                  
        rightseg[node].leftzc = rightseg[node*2].leftzc+rightseg[node*2+1].rightzc;
        rightseg[node].rightzc = rightseg[node].leftzc;
        rightseg[node].leftone = -1; rightseg[node].rightone = -1;
        rightseg[node].answer = rightseg[node*2].rightzc * rightseg[node*2 + 1].leftzc;
        rightseg[node].answer += (rightseg[node*2].answer + rightseg[node*2+1].answer);       
    }
    else 
    {
        leftseg[node].answer = 1; 
        leftseg[node].leftzc = 1; leftseg[node].rightzc = 1;
        leftseg[node].leftone = -1; leftseg[node].rightone = -1;

        rightseg[node].answer = 1; 
        rightseg[node].leftzc = 1; rightseg[node].rightzc = 1;
        rightseg[node].leftone = -1; rightseg[node].rightone = -1;
    
    }
}

struct nodes combine(struct nodes a, struct nodes b)
{
    struct nodes temp; 
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
    else if(a.rightone < 0 && b.leftone < 0)
    {
        temp.answer += a.rightzc * b.leftzc;
        temp.leftone = -1;
        temp.rightone = -1;
        temp.leftzc = a.rightzc + b.leftzc;
        temp.rightzc = temp.leftzc;
    }
    return temp;    
}

void rightupdate(int l, int r, long val, int start, int end, int node)
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
        struct nodes temp = combine(rightseg[node*2], rightseg[node*2+1]);
        //rightseg[node] = temp;
        rightseg[node].answer = temp.answer;
        rightseg[node].leftone = temp.leftone;
        rightseg[node].rightone = temp.rightone;
        rightseg[node].leftzc = temp.leftzc;
        rightseg[node].rightzc = temp.rightzc;
    }
}

void leftupdate(int l, int r, long val, int start, int end, int node)
{
    if(start > r || end < l) return;
    else if(start >= l && end <= r)
    {
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
        //nodes temp = new nodes(); 
        struct nodes temp = combine(leftseg[node*2], leftseg[node*2+1]);
        //leftseg[node] = temp;
        leftseg[node].answer = temp.answer;
        leftseg[node].leftone = temp.leftone;
        leftseg[node].rightone = temp.rightone;
        leftseg[node].leftzc = temp.leftzc;
        leftseg[node].rightzc = temp.rightzc;
    }
}

struct nodes rightquery(int l, int r, int start, int end, int node)
{
    if(start > r || end < l) return dummynode;
    else if(start >= l && end <= r) return rightseg[node];
    else
    {
        int mid = (start + end) / 2;
        return combine(rightquery(l, r, start, mid, node*2), rightquery(l,r,mid + 1,end,node*2 + 1));
    }
}

struct nodes leftquery(int l, int r, int start, int end, int node)
{
    if(start > r || end < l) return dummynode;
    else if(start >= l && end <= r) return leftseg[node];
    else
    {
        int mid = (start + end) / 2;
        struct nodes tempnode = combine(leftquery(l, r, start, mid, node*2), leftquery(l,r,mid + 1,end,node*2 + 1));
        //System.out.println(node + " seg = " + tempnode.answer + " " + tempnode.leftone + " " + tempnode.rightone + " " + tempnode.leftzc + " " + tempnode.rightzc);
        return tempnode;
    }
}


int main() 
{
    dummynode.answer = 0;
    dummynode.leftone = -1; dummynode.rightone = -1;
    dummynode.leftzc = 0; dummynode.rightzc = 0;
    
    int n, q; 
    scanf("%d%d%lld%lld",&n,&q,&L,&R);
    for(int i = 0; i <= n; i++) arr[i] = 0;
    int type, l; long long r;
    buildsegmenttree(1, n, 1);
    while(q > 0)
    {
        scanf("%d%d%lld",&type,&l,&r);
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
            struct nodes right = rightquery(l, rr, 1, n, 1);
            struct nodes left = leftquery(l, rr, 1, n, 1); 
            long long leftans = 0, rightans = 0;
            long long total = (r - l + 1);
            total = (total * (total + 1)) / 2;
            rightans = total - right.answer;
            leftans = total - left.answer;
            //printf("%lld %lld\n", leftans, rightans);
            long long ans = leftans - rightans;
            printf("%lld\n",ans);
        }
        //for(int i = 1; i <= 10; i++)
        {
          //  printf("%d seg = %lld\n",i, leftseg[i].answer);
        }
        q--;
    }
}