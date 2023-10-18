import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int[][] board;
	static long[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		board = new int[n][n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		dp = new long[n][n];
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int jump = board[i][j];
				if (i != n - 1 && i + jump < n) dp[i + jump][j] += dp[i][j];
				if (j != n - 1 && j + jump < n) dp[i][j + jump] += dp[i][j];
			}
		}

		bw.write(Long.toString(dp[n - 1][n - 1]));
		bw.flush();
		bw.close();
		br.close();
	}
}