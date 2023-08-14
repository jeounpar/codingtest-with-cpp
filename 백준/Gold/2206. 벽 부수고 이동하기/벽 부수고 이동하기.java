import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n, m;
	static char[][] arr;
	static int[][][] dist;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};

	static class Data {
		int x;
		int y;
		int broken;

		public Data(int x, int y, int broken) {
			this.x = x;
			this.y = y;
			this.broken = broken;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new char[n + 1][m + 1];
		dist = new int[n + 1][m + 1][2];
		for (int i = 1; i <= n; i++) {
			String str = br.readLine().trim();
			for (int j = 1; j <= m; j++) {
				arr[i][j] = str.charAt(j - 1);
				dist[i][j][0] = dist[i][j][1] = -1;
			}
		}
		Queue<Data> Q = new ArrayDeque<>();
		Q.add(new Data(1, 1, 0));
		dist[1][1][0] = 1;
		dist[1][1][1] = 1;
		while (!Q.isEmpty()) {
			Data cur = Q.poll();
			int x, y, broken;
			x = cur.x;
			y = cur.y;
			broken = cur.broken;
			if (x == n && y == m) {
				bw.write(Integer.toString(dist[x][y][broken]));
				bw.flush();
				return;
			}
			int next_dist = dist[x][y][broken] + 1;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 1 || nx > n || ny < 1 || ny > m)
					continue;
				if (arr[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
					dist[nx][ny][broken] = next_dist;
					Q.add(new Data(nx, ny, broken));
				}
				if (broken == 0 && arr[nx][ny] == '1' && dist[nx][ny][1] == -1) {
					dist[nx][ny][1] = next_dist;
					Q.add(new Data(nx, ny, 1));
				}
			}
		}
		bw.write(Integer.toString(-1));
		bw.flush();
		bw.close();
		br.close();
	}
}