import java.io.*;
import java.util.*;

public class Main {
	static int answer = Integer.MAX_VALUE, n;
	static int[][] rgb, dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		rgb = new int[n + 1][3];

		int r, g, b;
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			r = Integer.parseInt(st.nextToken());
			g = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			rgb[i][0] = r;
			rgb[i][1] = g;
			rgb[i][2] = b;
		}

		dp = new int[n + 1][3];

		dp[1][0] = rgb[1][0];
		dp[1][1] = rgb[1][1];
		dp[1][2] = rgb[1][2];

		for (int i = 2; i <= n; i++) {
			dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
			dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
			dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
		}

		for (int i = 0; i < 3; i++) {
			answer = Math.min(answer, dp[n][i]);
		}
		bw.write(Integer.toString(answer));

		bw.flush();
		bw.close();
		br.close();
	}
}