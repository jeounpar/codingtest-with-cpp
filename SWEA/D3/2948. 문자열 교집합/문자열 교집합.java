import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;
	static int n, m;
	static Set<String> set;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxIter = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = 0;
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			set = new HashSet<>();
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				set.add(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < m; i++) {
				if (set.contains(st.nextToken())) {
					answer++;
				}
			}
			bw.write("#" + test_case + " " + answer);
			bw.newLine();
		}
		bw.flush();
		bw.close();
		br.close();
	}
}