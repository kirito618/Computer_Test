package com.pat;

import java.util.Scanner;

/*
 * PAT甲级 Problem1005
 *  
 * 
 * */
public class Problem1005 {
	
	
	public static void main(String[]args) {
		Scanner scanner = new Scanner(System.in);
		String N = scanner.next();
		Long sum = 0L;
		
		for(char temp:N.toCharArray()) {
			sum += temp - '0';
		}
		
		String resultString = sum.toString();
		long order = 0;
		
		for(char digit:resultString.toCharArray()) {
			if(order!=0) {
				System.out.print(" ");
			}
			switch(digit) {
			    case '0':System.out.print("zero");break;
				case '1':System.out.print("one");break;
				case '2':System.out.print("two");break;
				case '3':System.out.print("three");break;
				case '4':System.out.print("four");break;
				case '5':System.out.print("five");break;
				case '6':System.out.print("six");break;
				case '7':System.out.print("seven");break;
				case '8':System.out.print("eight");break;
				case '9':System.out.print("nine");break;	
			}
			order++;
		}
		System.out.println();
	}
}
