package com.pat;
import java.util.Scanner;

public class Problem1015 {
    public static boolean isPrime(int x){
//         System.out.println(x);
        if(x  < 2) return false;
        for(int i = 2; i <= x / i; i++){
            if(x % i == 0) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N,D;
        N = scanner.nextInt();
        if(N<0) return;
        D = scanner.nextInt();
        while(N >= 0){
            String s = Integer.toString(N, D);
            StringBuffer stringBuffer = new StringBuffer(s).reverse();
            String s1 = new String(stringBuffer);
            int value = Integer.parseInt(s1, D);
            if(isPrime(value) && isPrime(N)){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
            N = scanner.nextInt();
            if(N >= 0){
                D = scanner.nextInt();
            }
        }
    }
}
