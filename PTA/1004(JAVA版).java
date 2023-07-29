package com.pat;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Problem1004 {
	// 因为Max(N) = 100
	private static int[] nums = new int[100];
	private static int maxLevel = 0;
	private static Map<Integer, List<Integer>> all = new HashMap<>();
	
	
	public static void dfs(int cur,int level) {
	if(level>maxLevel) {
		// 更新最大层数
		maxLevel = level;
	}
	
	
	if(!all.containsKey(cur)) {
		//没有子节点,当前节点是个叶子节点,对应层数的叶子节点数+1
		nums[level]++;
		return;
	}
	
	// 接下来,若不是叶子节点则继续向下走
	for(Integer son:all.get(cur)) {
		    dfs(son, level+1);
	    }
    }
	
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N,M;
		N = scanner.nextInt();
		M = scanner.nextInt();
		
		for(int i=0;i<M;i++) {
			// 先输入这个非叶子节点的信息,作为根节点
			Integer rootOrder = scanner.nextInt();
			// 用来暂时存储这非叶子节点的所有子节点
			List<Integer> tempList = new ArrayList<>();
			// 这一层的节点数
			int k = scanner.nextInt();
			for(int j=0;j<k;j++) {
				// 把儿子节点存入临时集合
				Integer order = scanner.nextInt();
				tempList.add(order);
			}
			// 将根节点存入总记录表中
			all.put(rootOrder, tempList);
		}
		dfs(1,0);
		System.out.print(nums[0]);
		for(int i=1;i<=maxLevel;i++) {
			System.out.print(" " + nums[i]);
		}
		System.out.println();
	}
}
