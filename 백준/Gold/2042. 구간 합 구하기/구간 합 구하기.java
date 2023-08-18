import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n, m, k;
	static long[] arr, tree;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		arr = new long[n + 1];
		tree = new long[4 * n + 1];

		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i] = Long.parseLong(st.nextToken());
		}
		init(1, n, 1);

		int a, b;
		long c;
		for (int i = 0; i < m + k; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Long.parseLong(st.nextToken());
			if (a == 1) {
				// origin + x = c
				long diff = c - arr[b];
				arr[b] = c;
				update(1, n, 1, b, diff);
			} else {
				sb.append(sum(1, n, 1, b, (int) c)).append("\n");
			}
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}

	static long init(int start, int end, int node) {
		if (start == end) {
			return tree[node] = arr[start];
		}
		int mid = (start + end) / 2;
		long leftSum = init(start, mid, node * 2);
		long rightSum = init(mid + 1, end, node * 2 + 1);
		return tree[node] = leftSum + rightSum;
	}

	static void update(int start, int end, int node, int idx, long diff) {
		if (idx < start || idx > end)
			return;

		tree[node] += diff;
		if (start == end)
			return;

		int mid = (start + end) / 2;
		update(start, mid, node * 2, idx, diff);
		update(mid + 1, end, node * 2 + 1, idx, diff);
	}

	static long sum(int start, int end, int node, int left, int right) {
		if (left > end || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[node];
		}
		int mid = (start + end) / 2;
		long leftSum = sum(start, mid, node * 2, left, right);
		long rightSum = sum(mid + 1, end, node * 2 + 1, left, right);
		return leftSum + rightSum;
	}
}