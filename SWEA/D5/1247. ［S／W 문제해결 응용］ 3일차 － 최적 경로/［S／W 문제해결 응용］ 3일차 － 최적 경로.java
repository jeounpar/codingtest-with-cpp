import java.io.*;
import java.util.*;

public class Solution {
	static long answer;
	static int n;
	static int c_x, c_y, h_x, h_y;
	static Pair[] arr;
	static boolean[] ok;
	static int[] tmp;
	static StringBuilder sb = new StringBuilder();

	static void solve(int cnt) {
		if (cnt == n) {
			long sum = Math.abs(c_x - arr[tmp[0]].x) + Math.abs(c_y - arr[tmp[0]].y);
			for (int i = 0; i < cnt - 1; i++) {
				sum += Math.abs(arr[tmp[i + 1]].x - arr[tmp[i]].x)
						+ Math.abs(arr[tmp[i + 1]].y - arr[tmp[i]].y);
			}
			sum += Math.abs(h_x - arr[tmp[cnt - 1]].x) + Math.abs(h_y - arr[tmp[cnt - 1]].y);
			if (sum < answer)
				answer = sum;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (ok[i]) continue;
			ok[i] = true;
			tmp[cnt] = i;
			solve(cnt + 1);
			ok[i] = false;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxIter = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = Long.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			c_x = Integer.parseInt(st.nextToken());
			c_y = Integer.parseInt(st.nextToken());
			h_x = Integer.parseInt(st.nextToken());
			h_y = Integer.parseInt(st.nextToken());

			arr = new Pair[n];
			ok = new boolean[n];
			tmp = new int[n];
			int a, b;
			for (int i = 0; i < n; i++) {
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				arr[i] = new Pair(a, b);
			}
			solve(0);
			sb.append("#").append(test_case).append(" ").append(answer).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}

	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}