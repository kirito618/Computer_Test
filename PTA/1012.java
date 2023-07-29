package com.pat;

import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Problem1012 {
	private static Map<String, List<Integer>> database = new HashMap<>();
	//rankMap 记录每个id的每一科的排名
	private static Map<String, List<Integer>> rankMap = new HashMap<>();
	// 每个id的list集合里的值依次是 C M E的分数 各科的排名(C,M,E,A)
	private static List<String> search = new ArrayList<>();
	// 记录每个id的所有科目平均分
	private static double[] avg = new double[2000];
	public static void rankMethod(String id) {
		int rank;
		List<Integer> scores = database.get(id);
		List<Integer> tempList = new ArrayList<>();
		
		// 计算平均值排名
		int index = scores.get(3);
	    double avgNum = avg[index];
		rank = 1;
		// 计算平均值的排名
	    for(String tempId:database.keySet()) {
			// 拿到某一科的成绩
		    int tempIndex = database.get(tempId).get(3);
		    if (avg[tempIndex] > avgNum) {
				rank++;
			}
	    }
	    tempList.add(rank);
		
		for (int i = 0; i < 3; i++) {
			//这里的每次循环都将id的某一科目的排名计算出来
			//计算C、M、E的排名
			int score = scores.get(i);
			//一开始排名第1，若有一个比他大，就加一
		    rank = 1;
			for(String tempId:database.keySet()) {
				// 拿到某一科的成绩
			    int tempScore = database.get(tempId).get(i);
			    if (tempScore > score) {
					rank++;
				}
		    }
			tempList.add(rank);
		}
		rankMap.put(id, tempList);
	}
	
	public static void main(String[]args) {
		Scanner scanner = new Scanner(System.in);
	    int N,M,Cs,Math,Eng;
	    String tempId;
	    char[] result = new char[4];
	    result[0] = 'A';
	    result[1] = 'C';
	    result[2] = 'M';
	    result[3] = 'E';
	    N = scanner.nextInt();
	    M = scanner.nextInt();
	    for(int i=0;i<N;i++){
	    	List<Integer> temp = new ArrayList<>();
	    	tempId = scanner.next();
	    	// 输入分数
	    	Cs = scanner.nextInt();
	    	Math = scanner.nextInt();
	    	Eng = scanner.nextInt();
	    	temp.add(Cs);
	    	temp.add(Math);
	    	temp.add(Eng);
	    	// 最后一个值是他的下标
	    	temp.add(i);
	    	// 计算平均值
	    	avg[i] = (Cs+Math+Eng)/3.0;
	    	database.put(tempId, temp);
	    }
	    
	    //System.out.println(database.toString());
	    for(int i=0;i<M;i++) {
	    	tempId = scanner.next();
	    	search.add(tempId);
	    }
	    
	    for(String id:search) {
	    	if(!database.containsKey(id)) {
	    		// 不存在此id
	    		System.out.println("N/A");
	    	}else {
	    		// 存在此id,则先计算排名
		    	rankMethod(id);
		    	int min = 0;
		    	List<Integer> rankList = rankMap.get(id);
		    	for (int i = 1; i < 4; i++) {
					if (rankList.get(i)<rankList.get(min)) {
						min =  i;
					}
				}
		    	System.out.println(rankList.get(min) + " " + result[min]);
	    	}
	    }
	}
}
