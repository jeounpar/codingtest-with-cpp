import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n, m;
	static ArrayList<Integer>[] adj;
	static boolean[] ok;

	static void solve(int cur, int cnt) {
		if (cnt == 5) {
			answer = 1;
			return;
		}
		for (Integer next : adj[cur]) {
			if (ok[next]) continue;
			ok[next] = true;
			solve(next, cnt + 1);
			ok[next] = false;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
		}

		int a, b;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			adj[b].add(a);
		}

		for (int i = 0; i < n; i++) {
			if (answer == 1) break;
			ok = new boolean[n];
			ok[i] = true;
			solve(i, 1);
		}
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}
}