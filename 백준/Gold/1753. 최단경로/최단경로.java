import java.io.*;
import java.util.*;

public class Main {
	static int v, e, k;
	static ArrayList<Pair>[] adj;
	static int[] dist;

	static class Pair implements Comparable<Pair> {
		int node;
		int dist;

		public Pair(int node, int dist) {
			this.node = node;
			this.dist = dist;
		}

		@Override
		public int compareTo(Pair o) {
			return Integer.compare(this.dist, o.dist);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());

		adj = new ArrayList[v + 1];
		for (int i = 1; i <= v; i++) {
			adj[i] = new ArrayList<>();
		}
		dist = new int[v + 1];
		for (int i = 1; i <= v; i++) {
			dist[i] = 100000000;
		}

		int a, b, c;
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			adj[a].add(new Pair(b, c));
		}
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		dist[k] = 0;
		pq.add(new Pair(k, 0));
		while (!pq.isEmpty()) {
			Pair cur = pq.poll();
			for (Pair next : adj[cur.node]) {
				if (dist[cur.node] + next.dist < dist[next.node]) {
					dist[next.node] = dist[cur.node] + next.dist;
					pq.add(new Pair(next.node, dist[next.node]));
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= v; i++) {
			if (dist[i] != 100000000) {
				sb.append(dist[i]).append("\n");
			} else {
				sb.append("INF").append("\n");
			}
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}