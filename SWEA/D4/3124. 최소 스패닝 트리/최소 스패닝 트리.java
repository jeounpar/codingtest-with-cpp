import java.io.*;
import java.util.*;

public class Solution {
	static long answer = 0;
	static int v, e;
	static Tuple[] tuples;
	static int[] parents, rank;
	static StringBuilder sb = new StringBuilder();

	static class Tuple implements Comparable<Tuple> {
		int x, y, dist;

		public Tuple(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.dist = dist;
		}

		@Override
		public int compareTo(Tuple o) {
			return Integer.compare(this.dist, o.dist);
		}
	}

	static int find(int x) {
		if (parents[x] == x) return x;
		return parents[x] = find(parents[x]);
	}

	static void union(int a, int b) {
		int x = find(a);
		int y = find(b);
		parents[y] = x;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxIter = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = 0;
			st = new StringTokenizer(br.readLine());

			v = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());

			int x, y, dist;
			tuples = new Tuple[e];
			for (int i = 0; i < e; i++) {
				st = new StringTokenizer(br.readLine());
				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				dist = Integer.parseInt(st.nextToken());
				tuples[i] = new Tuple(x, y, dist);
			}

			Arrays.sort(tuples);
			parents = new int[v + 1];
			rank = new int[v + 1];
			for (int i = 1; i <= v; i++) {
				parents[i] = i;
				rank[i] = 0;
			}

			for (int i = 0; i < e; i++) {
				int a = tuples[i].x;
				int b = tuples[i].y;
				if (find(a) != find(b)) {
					union(a, b);
					answer += tuples[i].dist;
				}
			}
			sb.append("#").append(test_case).append(" ").append(answer).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}