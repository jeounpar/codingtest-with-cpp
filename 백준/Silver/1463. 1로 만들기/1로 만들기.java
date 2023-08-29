import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0, n;
	static int[] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		dp = new int[n + 10];

		dp[1] = 0;
		dp[2] = 1;
		dp[3] = 1;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + 1;
			if (i % 3 == 0)
				dp[i] = Math.min(dp[i / 3] + 1, dp[i]);
			if (i % 2 == 0)
				dp[i] = Math.min(dp[i / 2] + 1, dp[i]);
		}
		bw.write(Integer.toString(dp[n]));
		bw.flush();
		bw.close();
		br.close();
	}
}