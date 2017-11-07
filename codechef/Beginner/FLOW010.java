import java.util.*;
import java.io.*;
class FLOW010
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintStream ps=new PrintStream(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t>0)
        {
            String s=br.readLine();
            char id=s.charAt(0);
            if(id=='B' || id=='b') ps.println("BattleShip");
            else if(id=='C' || id=='c') ps.println("Cruiser");
            else if(id=='D' || id=='d') ps.println("Destroyer");
            else ps.println("Frigate");
            t--;
        }
        ps.close();
    }
}

