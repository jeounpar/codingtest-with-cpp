import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n, m;
	static int[][] arr, copy;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	static ArrayList<Pair> virus;

	static void solve(int cnt) {
		if (cnt == 3) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					copy[i][j] = arr[i][j];
				}
			}

			for (Pair p : virus) {
				Queue<Pair> Q = new ArrayDeque<>();
				Q.add(new Pair(p.x, p.y));
				while (!Q.isEmpty()) {
					Pair cur = Q.poll();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m || copy[nx][ny] != 0) continue;
						copy[nx][ny] = 2;
						Q.add(new Pair(nx, ny));
					}
				}
			}

			int t = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (copy[i][j] == 0) {
						t++;
					}
				}
			}
			if (t > answer) answer = t;
			return;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) continue;
				arr[i][j] = 1;
				solve(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		arr = new int[n][m];
		copy = new int[n][m];
		virus = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 2) {
					virus.add(new Pair(i, j));
				}
			}
		}

		solve(0);

		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}

	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}