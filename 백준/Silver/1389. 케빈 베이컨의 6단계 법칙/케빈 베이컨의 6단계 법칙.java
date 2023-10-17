import java.io.*;
import java.util.*;

public class Main {
	static int minValAns = Integer.MAX_VALUE, answer = 0, n, m;
	static ArrayList<Integer>[] adj;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		adj = new ArrayList[n + 1];
		for (int i = 0; i <= n; i++) adj[i] = new ArrayList<>();

		int a, b;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			adj[b].add(a);
		}

		for (int i = 1; i <= n; i++) {
			int[] dist = new int[n + 1];
			Queue<Integer> Q = new ArrayDeque<>();
			dist[i] = 1;
			Q.add(i);
			while (!Q.isEmpty()) {
				Integer cur = Q.poll();
				for (Integer next : adj[cur]) {
					if (dist[next] > 0) continue;
					dist[next] = dist[cur] + 1;
					Q.add(next);
				}
			}
			int sum = 0;
			for (int j = 1; j <= n; j++) {
				sum += dist[j];
			}
			if (sum < minValAns) {
				minValAns = sum;
				answer = i;
			}
		}
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}
}