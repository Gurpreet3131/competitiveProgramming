import java.util.Scanner;
class sumsintriangle
{
    public static int possum(int a)
    {
        int p=1;
        for(int i=1;i<=a;i++)
        {
            p=p*2;
        }
        return p;
    }
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        int sumnum=0,d=0,a=0,count=0,switchtemp=1;
        while(t>0)
        {
            int rows=in.nextInt();
            int array[][]=new int[rows][rows];
            sumnum=0;d=0;a=1;switchtemp=1;
            int num=0;
            int sum[]=new int[possum(rows-1)];
            int temp1[]=new int[possum(rows-1)];
            int temp2[]=new int[possum(rows-1)];
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<=i;j++)
                {
                    array[i][j]=in.nextInt();
                }
            }
            for(int i=rows-1;i>0;i--)
            {
                sumnum=0;
                num=0;
                a=a*2;
                for(int j=0;j<i;j++)
                {
                    count=1;
                    if(d==0)
                    {
                        temp1[sumnum]+=array[i][j]+array[i-1][j];
                        sum[sumnum]+=array[i][j]+array[i-1][j];
                        temp2[sumnum]+=array[i][j]+array[i-1][j];
                        sumnum++;
                        temp1[sumnum]+=array[i][j+1]+array[i-1][j];
                        sum[sumnum]+=array[i][j+1]+array[i-1][j];
                        temp2[sumnum]+=array[i][j+1]+array[i-1][j];
                        sumnum++;
                    }
                    else
                    {
                        for(int k=j;count<=a;count++)
                        {
                            if(switchtemp==1)
                            {
                                temp1[sumnum]+=array[i-1][k];
                                sum[num]=temp1[sumnum];
                            }
                            else
                            {
                                temp2[sumnum]+=array[i-1][k];
                                sum[num]=temp2[sumnum];
                            }
                            sumnum++;
                            num++;
                        }
                        if(switchtemp==1) switchtemp=2;
                        else switchtemp=1;
                        sumnum=(a/2)*(j+1);
                    }
                    
                }
                d=1;
                for(int z=0;z<possum(rows-1);z++)
                {
                    temp1[z]=sum[z];
                    temp2[z]=sum[z];
                }
            }
            int maxsum=0;
            for(int i=0;i<possum(rows-1);i++)
            {
                if(sum[i]>maxsum)
                {
                    maxsum=sum[i];
                }
            }
            if(rows==1) maxsum=array[0][0];
            System.out.println(maxsum);
            t--;
        }
    }
}
