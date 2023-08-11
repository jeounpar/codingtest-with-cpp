import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;
	static int n, m;
	static Map<String, Integer> map;
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
			map = new HashMap<>();
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				map.put(st.nextToken(), 1);
			}
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < m; i++) {
				String s = st.nextToken();
				if (map.get(s) != null) {
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