import java.io.*;
import java.math.*;
import java.util.*;
static class Reader{
    private BufferedReader br;
    private StringTokenizer st;
    public Reader(){
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    boolean hasNext() throws IOException{
        String s;
        while (st == null || !st.hasMoreElements()){
            if ((s = br.readLine())==null) return false;
            st = new StringTokenizer(s);
        }
        return true;
    }
    String next() throws IOException{
        while (st == null || !st.hasMoreElements())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    int nextInt() throws IOException{
        return Integer.parseInt(next());
    }// Long.parseLong, Double.parseDouble, br.readLine
}