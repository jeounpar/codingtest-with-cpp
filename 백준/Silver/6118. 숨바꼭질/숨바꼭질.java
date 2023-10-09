import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static ArrayList<Integer>[] adj;
	static int[] dist;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		dist = new int[n + 1];
		adj = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();

		int a, b;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			adj[b].add(a);
		}

		Queue<Integer> Q = new ArrayDeque<>();
		Q.add(1);
		dist[1] = 1;
		int maxDist = 0;
		while (!Q.isEmpty()) {
			Integer cur = Q.poll();
			for (Integer next : adj[cur]) {
				if (dist[next] > 0) continue;
				dist[next] = dist[cur] + 1;
				maxDist = Math.max(maxDist, dist[next]);
				Q.add(next);
			}
		}

		int target = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (target == 0 && dist[i] == maxDist) target = i;
			if (dist[i] == maxDist) cnt++;
		}

		StringBuilder sb = new StringBuilder();
		sb.append(target).append(" ").append(maxDist - 1).append(" ").append(cnt);

		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}