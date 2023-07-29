package com.pat;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/*
 * PAT1009  判断等式是否能成立
 * */

// 例如输入 6 110 1 10  意思是 等式左边是6,右边是110,标签= 1代表后面的10是6的进制,就是说这个6是10进制下的
// 要求我们输出一个进制数,意思是当不确定进制的那个数是 这个进制下的数的时候, 这个等式就成立了
public class Problem1010 {
	
	// 此方法将传入的某进制下的数字或字母字符串转换成十进制数
	public static long toTenRedix(String know,long redix) {
		int tempNum = 0;
		long i = know.length()-1,result = 0;
		for(char temp:know.toCharArray()) {
			if(temp>='a'&&temp<='z') {
				tempNum = temp - 'a' +10;
			}else {
				tempNum = temp - '0';
			}
			// 每一位都不能大于他的进制
			if(tempNum>=redix) {
				return -1;
			}
			result += tempNum*Math.pow(redix, i);
			i--;
		}
		//System.out.println(know + ": " +result);
		return result;
	}
	
	
	//若输入的N1或N2 是字母串，a = 10,b=11,....,z=35
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String[] N = new String[2];
		String know;
		long[] a = {0,0};
		int tag,redix,tempNum = 0,other;
		long result=0;
		boolean ifCan = false;
		
		
		//读入数据
		N[0] = scanner.next();
		N[1] = scanner.next();
		
		for(int i=0;i<2;i++) {
			int index = -1;
			//把输入的数据的开头的0都去掉
		    for(char temp:N[i].toCharArray()) {
		    	if(temp!='0') {
		    		break;
		    	}
		    	index++;
		    }
		    if(index==-1) {
		    	//说明这个字符串没有0开头
		    	continue;
		    }
		    N[i] = N[i].substring(index+1);
		}
		
		
		tag = scanner.nextInt();
		tag = tag - 1;
		redix = scanner.nextInt();
		//把已知进制的数先记录下来
		know = N[tag];
		//获取另一个未知进制的数的下标
		other = tag==1?0:1;
		
		//把已知转成十进制
		a[tag] = toTenRedix(know, redix);
		
		//此题有坑,这里用二分法
		for(int r = 1;r<=100000;r++) {
			a[other] = toTenRedix(N[other], r);
			// 转成十进制后相等了
			if(a[other]==a[tag]) {
				result = r;
				ifCan = true;
				break;
			}else if(a[other]>a[tag]) {
				//现在都比已知的值大了,权重再变大就更大了,不可能相等了
				break;
			}
		}
		
		//为了通过最后一个恶心的测试点
		if(a[other]<a[tag]) {
			//如果我都把进制调成100000了还是小
			//那用二分法开始找
			for(long low = 100001,high = Long.MAX_VALUE;low<=high;) {
				long mid = (low + high)/2;
				a[other] = toTenRedix(N[other], mid);
				if(a[other]>a[tag]) {
					high = mid - 1;
				}else if(a[other]<a[tag]) {
					low = mid + 1;
				}else {
					ifCan = true;
					result = mid;
					break;
				}
			}
		}
		
		if(ifCan) {
			System.out.println(result);
		}else {
			System.out.println("Impossible");
		}
	}
}
