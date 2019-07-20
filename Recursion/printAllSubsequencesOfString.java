import java.util.*;

class Main {

    public static void printSubsequences(String s,String p,int n,int idx){
        if(idx==n){
            System.out.println(p);
            return;
        }
        printSubsequences(s,p,n,idx+1); // does not include character at idx
        printSubsequences(s,p+s.charAt(idx),n,idx+1); // includes character at idx
    }

    public static void printSubsequences(String s){
        int n = s.length();
        String p = "";
        printSubsequences(s,p,n,0);
    }

	public static void main (String[] args) {
		Scanner z = new Scanner(System.in);
		while(z.hasNext()){
		    String s = z.next();
		    printSubsequences(s);
		}
	}
}
