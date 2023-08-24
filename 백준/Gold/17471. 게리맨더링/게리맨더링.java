import java.io.*;
import java.util.*;

public class Main {
	static int answer = Integer.MAX_VALUE, n;
	static int[] arr, tmp;
	static boolean[] ok;
	static ArrayList<Integer>[] adj;

	static void solve(int idx) {
		if (idx == n + 1) {
			int a1 = 0, a2 = 0;
			for (int i = 1; i <= n; i++) {
				if (tmp[i] == 1) a1 += arr[i];
				else a2 += arr[i];
			}
			ok = new boolean[n + 1];
			int split = 0;
			for (int i = 1; i <= n; i++) {
				if (ok[i]) continue;
				split++;
				Queue<Integer> Q = new ArrayDeque<>();
				Q.add(i);
				ok[i] = true;
				while (!Q.isEmpty()) {
					Integer cur = Q.poll();
					for (Integer next : adj[cur]) {
						if (ok[next] || tmp[next] != tmp[i]) continue;
						ok[next] = true;
						Q.add(next);
					}
				}
			}
			int val = Math.abs(a1 - a2);
			if (split == 2 && val < answer) answer = val;
			return;
		}
		tmp[idx] = 1;
		solve(idx + 1);

		tmp[idx] = 2;
		solve(idx + 1);

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		arr = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		adj = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) {
			adj[i] = new ArrayList<>();
		}

		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			int t = Integer.parseInt(st.nextToken());
			for (int j = 0; j < t; j++) {
				int b = Integer.parseInt(st.nextToken());
				adj[i].add(b);
				adj[b].add(i);
			}
		}
		tmp = new int[n + 1];
		solve(1);
		if (answer != Integer.MAX_VALUE)
			bw.write(Integer.toString(answer));
		else
			bw.write(Integer.toString(-1));
		bw.flush();
		bw.close();
		br.close();
	}
}