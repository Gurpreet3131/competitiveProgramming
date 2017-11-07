import java.util.*;
import java.io.*;
class lighthouse 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            int x[]=new int[n];
            int y[]=new int[n];
            String dir1="",dir2="";
            int minx=1000000001,maxx=-1000000001;
            int minxy1=1000000001,minxy2=-1000000001,maxxy1=1000000001,maxxy2=-1000000001;
            int islnum1=0,islnum2=0,islnum3=0,islnum4=0;
            int island1=0,island2=0,x1=0,y1=0,x2=0,y2=0;
            for(int i=0;i<n;i++)
            {
                StringTokenizer st2 = new StringTokenizer(br.readLine());
                x[i]=Integer.parseInt(st2.nextToken());
                y[i]=Integer.parseInt(st2.nextToken());
                if(x[i]<=minx)
                {
                    if(minx==x[i])
                    {
                        
                        if(y[i]<=minxy1)
                        {
                            minxy1=y[i];
                            islnum1=i+1;
                        }
                        if(y[i]>=minxy2)
                        {
                            minxy2=y[i];
                            islnum2=i+1;
                        }
                    }
                    else 
                    {
                        minxy1=y[i];
                        minxy2=y[i];
                        islnum1=i+1;
                        islnum2=i+1;
                    }
                    minx=x[i];
                        
                }  
                if(x[i]>=maxx)
                {
                    
                    if(x[i]==maxx)
                    {
                        if(y[i]<=maxxy1)
                        {
                            maxxy1=y[i];
                            islnum3=i+1;
                        }
                        if(y[i]>=maxxy2)
                        {
                            maxxy2=y[i];
                            islnum4=i+1;
                        }
                    }
                    else
                    {
                        maxxy1=y[i];
                        maxxy2=y[i];
                        islnum3=i+1;
                        islnum4=i+1;
                    }
                    maxx=x[i];
                        
                    
                }       
            }
            //ps.println("islnum1="+islnum1+" islnum2="+islnum2+"islnum3="+islnum3+" islnum4="+islnum4);
            {
                if(maxxy2>minxy2)
                {
                    island2=islnum4;
                    dir2="SW";
                    island1=islnum1;
                    dir1="NE";
                    x2=maxx;y2=maxxy2;
                    x1=minx;y1=minxy1;
                }
                else
                {
                    island2=islnum2;
                    dir2="SE";
                    island1=islnum3;
                    dir1="NW";
                    x2=minx;y2=minxy2;
                    x1=maxx;y1=maxxy1;
                    
                }
            }            
            //ps.println("island1="+island1+"&island2="+island2);
            //ps.println("x1="+x1+" y1="+y1+"  x2="+x2+" y2="+y2);
            int upy2=0,downy1=0;
            for(int i=0;i<n;i++)
            {
                if(y[i]>y2) upy2=1;
                if(y[i]<y1) downy1=1;
            }
            if(upy2==0 && downy1==0)
            {
                ps.println(1);
                ps.println(island2+" "+dir2);
            }
            else if(upy2==0 && downy1==1)
            {
                ps.println(1);
                ps.println(island2+" "+dir2);
            }
            else if(upy2==1 && downy1==0)
            {
                ps.println(1);
                ps.println(island1+" "+dir1);
            }
            else
            {
                ps.println(2);
                ps.println(island1+" "+dir1);
                ps.println(island2+" "+dir2);
            }
            
            
            t--;
        }
        ps.close();
    }
}
