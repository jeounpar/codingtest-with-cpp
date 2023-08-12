import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxIter = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = 0;
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			Set<Integer> set = new HashSet<>();
			int mul = 1;
			int t = n;
			while (true) {
				n = t * mul;
				mul++;
				String str = Integer.toString(n);
				for (int i = 0; i < str.length(); i++) {
					set.add(str.charAt(i) - '0');
				}
				if (set.size() == 10)
					break;
			}
			answer = n;
			bw.write("#" + test_case + " " + answer);
			bw.newLine();
		}
		bw.flush();
		bw.close();
		br.close();
	}
}