import java.util.*;

public class Main {
	static ArrayList<Integer>[] adj;
	static boolean[] visited;
	static StringBuilder sb = new StringBuilder();

	static void dfs(int v) {
		if (visited[v]) return;
		visited[v] = true;
		sb.append(v).append(" ");
		for (Integer x : adj[v]) {
			if (!visited[x]) dfs(x);
		}
	}

	static void bfs(int v) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(v);
		visited[v] = true;
		while (!q.isEmpty()) {
			int x = q.poll();
			sb.append(x).append(" ");
			for (Integer y : adj[x]) {
				if (!visited[y]) {
					visited[y] = true;
					q.add(y);
				}
			}
		}
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int v = sc.nextInt();

		adj = new ArrayList[n + 1];
		for (int i = 1; i < n + 1; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		int q, w;
		for (int i = 0; i < m; i++) {
			q = sc.nextInt();
			w = sc.nextInt();
			adj[q].add(w);
			adj[w].add(q);
		}

		for (int i = 1; i < n + 1; i++) {
			Collections.sort(adj[i]);
		}

		visited = new boolean[n + 1];
		dfs(v);
		sb.append("\n");
		visited = new boolean[n + 1];
		bfs(v);
		System.out.println(sb.toString());
	}
}
