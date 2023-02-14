package com.pat;

import java.math.BigInteger;
import java.util.Scanner;

public class Problem1024 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		BigInteger N = scanner.nextBigInteger();
		int K = scanner.nextInt();
		int step = 0;
		boolean flag = true;
		String N_string = N.toString();
		int i=0,j=N_string.length()-1;
		if(N.toString().length()==1) {
			System.out.println(N);
			System.out.println(step);
			return ;
		}
		while(i<j) {
			if(N_string.charAt(i)!=N_string.charAt(j)) {
				flag = false;
				break;
			}
			i++;
			j--;
		}
		
		if(flag) {
			System.out.println(N);
			System.out.println(step);
			return ;
		}
		
		while(K>0) {
			StringBuffer buffer = new StringBuffer(N.toString());
			step++;
			N = N.add(new BigInteger(buffer.reverse().toString()));
			buffer = new StringBuffer(N.toString());
			if(buffer.toString().equals(buffer.reverse().toString())) {
				break;
			}
			K--;
		}
		
		System.out.println(N);
		System.out.println(step);
	}
}
