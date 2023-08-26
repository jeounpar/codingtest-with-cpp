import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0, n, start;
	static ArrayList<Integer>[] adj;
	static ArrayList<Data> ans;
	static boolean[] ok;
	static StringBuilder sb = new StringBuilder();

	static class Pair {
		int node;
		int depth;

		public Pair(int node, int depth) {
			this.node = node;
			this.depth = depth;
		}
	}

	static class Data implements Comparable<Data> {
		int depth, node;

		public Data(int depth, int node) {
			this.depth = depth;
			this.node = node;
		}

		@Override
		public int compareTo(Data o) {
			if (this.depth == o.depth) {
				return Integer.compare(this.node, o.node) * -1;
			}
			return Integer.compare(this.depth, o.depth) * -1;
		}

		@Override
		public String toString() {
			return "Data{" +
					"depth=" + depth +
					", node=" + node +
					'}';
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int maxIter = 10;
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = 0;
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			start = Integer.parseInt(st.nextToken());

			ok = new boolean[101];
			adj = new ArrayList[101];
			for (int i = 1; i <= 100; i++) {
				adj[i] = new ArrayList<>();
			}

			st = new StringTokenizer(br.readLine());
			int from, to;
			for (int i = 0; i < n / 2; i++) {
				from = Integer.parseInt(st.nextToken());
				to = Integer.parseInt(st.nextToken());
				adj[from].add(to);
			}

			ok[start] = true;
			Queue<Pair> Q = new ArrayDeque<>();
			Q.add(new Pair(start, 0));
			ans = new ArrayList<>();

			while (!Q.isEmpty()) {
				Pair cur = Q.poll();
				ans.add(new Data(cur.depth, cur.node));
				for (Integer next : adj[cur.node]) {
					if (ok[next]) continue;
					ok[next] = true;
					Q.add(new Pair(next, cur.depth + 1));
				}
			}
			Collections.sort(ans);
			answer = ans.get(0).node;
//			System.out.println(Arrays.toString(ans.toArray()));

			sb.append("#").append(test_case).append(" ").append(answer).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}