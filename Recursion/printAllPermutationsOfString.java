import java.util.*;

class GFG {

    public static String swap(String s, int i, int j){
        char[] c = s.toCharArray();
        char temp = c[i];
        c[i] = c[j];
        c[j] = temp;
        s = String.valueOf(c);
        return s;
    }

    public static void printPermutations(String s,int n,int idx){
        if(idx==n){
            System.out.println(s);
            return;
        }
        for(int i=idx;i<n;i++){
            s = swap(s,idx,i);
            printPermutations(s,n,idx+1);
            s = swap(s,idx,i); // backtracking step
        }
    }

    public static void printPermutations(String s){
        int n = s.length();
        printPermutations(s,n,0);
    }

	public static void main (String[] args) {
		Scanner z = new Scanner(System.in);
		while(z.hasNext()){
		    String s = z.next();
		    printPermutations(s);
		}
	}
}
