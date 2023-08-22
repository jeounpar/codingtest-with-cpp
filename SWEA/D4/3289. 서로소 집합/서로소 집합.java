import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;
	static int n, m, t, a, b;
	static int[] arr;

	static StringBuilder sb = new StringBuilder();

	static int find(int x) {
		if (arr[x] == x) {
			return x;
		}
		return arr[x] = find(arr[x]);
	}

	static void union(int a, int b) {
		int x = find(a);
		int y = find(b);
		arr[x] = y;
	}

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
			arr = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				arr[i] = i;
			}

			sb.append("#").append(test_case).append(" ");
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				t = Integer.parseInt(st.nextToken());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				if (t == 0) {
					union(a, b);
				} else {
					if (find(a) == find(b))
						sb.append(1);
					else
						sb.append(0);
				}
			}
			sb.append("\n");
//			sb.append("#").append(test_case).append(" ").append(answer).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}