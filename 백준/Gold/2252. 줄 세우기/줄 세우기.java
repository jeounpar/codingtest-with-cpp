import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n, m;
	static ArrayList<Integer>[] adj;
	static int[] ind;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		adj = new ArrayList[n + 1];
		ind = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			adj[i] = new ArrayList<>();
		}
		int a, b;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			ind[b]++;
		}

		Queue<Integer> Q = new ArrayDeque<>();
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) {
				Q.add(i);
			}
		}

		while (!Q.isEmpty()) {
			Integer cur = Q.poll();
			sb.append(cur).append(" ");
			for (Integer next : adj[cur]) {
				ind[next]--;
				if (ind[next] == 0) {
					Q.add(next);
				}
			}
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}