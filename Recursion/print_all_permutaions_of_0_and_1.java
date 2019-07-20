/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    
    public static void printBinStringsHelper(int n, char[] p ,int i){
        
        if(i==n){
            String str = String.valueOf(p);
            System.out.println(p);
            return;
        }
        
        for(int j=0;j<=1;j++){
            p[i] = (char)('0'+j);
            printBinStringsHelper(n,p,i+1);
        }
    }
    
    public static void printBinStrings(int n, char[] p){
        printBinStringsHelper(n,p,0);
    }
    
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        char[] p = new char[n];
        printBinStrings(n,p);
    }
}
