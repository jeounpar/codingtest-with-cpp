import java.io.*;
import java.util.*;

public class Solution {
	static double answer = 0;
	static double E;
	static int n, e;
	static int[] parents, rank;
	static Pair[] arr;
	static Tuple[] tuples;
	static StringBuilder sb = new StringBuilder();

	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static class Tuple implements Comparable<Tuple> {
		int x, y;
		long dist;

		public Tuple(int x, int y, long dist) {
			this.x = x;
			this.y = y;
			this.dist = dist;
		}

		@Override
		public int compareTo(Tuple o) {
			return Long.compare(this.dist, o.dist);
		}
	}

	static int find(int x) {
		if (parents[x] == x)
			return x;
		return parents[x] = find(parents[x]);
	}

	static void union(int a, int b) {
		int x = find(a);
		int y = find(b);
		if (rank[x] > rank[y]) {
			parents[y] = x;
		} else {
			parents[x] = y;
			if (rank[x] == rank[y])
				rank[y]++;
		}
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
			arr = new Pair[n];
			parents = new int[n];
			rank = new int[n];
			for (int i = 0; i < n; i++) {
				parents[i] = i;
			}

			e = (n * (n - 1)) / 2;
			tuples = new Tuple[e];

			int x, y;
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				x = Integer.parseInt(st.nextToken());
				arr[i] = new Pair(x, 0);
			}

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				y = Integer.parseInt(st.nextToken());
				arr[i].y = y;
			}

			st = new StringTokenizer(br.readLine());
			E = Double.parseDouble(st.nextToken());

			int idx = 0;
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					long dist = ((long) (arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (long) (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y));
					tuples[idx] = new Tuple(i, j, dist);
					idx++;
				}
			}

			Arrays.sort(tuples);

			for (int i = 0; i < e; i++) {
				Tuple cur = tuples[i];
				if (find(cur.x) != find(cur.y)) {
//					System.out.println(cur.dist);
					answer += E * cur.dist;
					union(cur.x, cur.y);
				}
			}

			sb.append("#").append(test_case).append(" ").append(Math.round(answer)).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}