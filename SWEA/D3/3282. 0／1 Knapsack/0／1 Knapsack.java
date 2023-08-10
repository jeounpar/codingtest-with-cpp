import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;
	static int[] v;
	static int[] c;
	static int[][] dp;
	static int n, k;
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
			k = Integer.parseInt(st.nextToken());
			v = new int[n + 1];
			c = new int[n + 1];
			dp = new int[n + 1][k + 1];
			for (int i = 1; i <= n; i++) {
				st = new StringTokenizer(br.readLine());
				v[i] = Integer.parseInt(st.nextToken());
				c[i] = Integer.parseInt(st.nextToken());
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= k; j++) {
					dp[i][j] = dp[i - 1][j];
					if (v[i] <= j) {
						dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - v[i]] + c[i]);
					}
				}
			}
			for (int i = 0; i <= k; i++) {
				answer = Math.max(answer, dp[n][i]);
			}
			sb.append("#").append(test_case).append(" ").append(answer).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}