import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n;
	static char[][] arr;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};

	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new char[n][n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			for (int j = 0; j < n; j++) {
				arr[i][j] = str.charAt(j);
			}
		}
		int a1 = 0, a2 = 0;
		boolean[][] ok = new boolean[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ok[i][j]) continue;
				a1++;
				Queue<Pair> Q = new ArrayDeque<>();
				ok[i][j] = true;
				Q.add(new Pair(i, j));
				char target = arr[i][j];
				while (!Q.isEmpty()) {
					Pair cur = Q.poll();
//					System.out.println("asd");
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n || ok[nx][ny] || arr[nx][ny] != target) continue;
						ok[nx][ny] = true;
						Q.add(new Pair(nx, ny));
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 'R')
					arr[i][j] = 'G';
			}
		}

		ok = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ok[i][j]) continue;
				a2++;
				Queue<Pair> Q = new ArrayDeque<>();
				ok[i][j] = true;
				Q.add(new Pair(i, j));
				char target = arr[i][j];
				while (!Q.isEmpty()) {
					Pair cur = Q.poll();
//					System.out.println("asd");
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n || ok[nx][ny] || arr[nx][ny] != target) continue;
						ok[nx][ny] = true;
						Q.add(new Pair(nx, ny));
					}
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(a1).append( " ").append(a2);
		bw.write(sb.toString());
		
		bw.flush();
		bw.close();
		br.close();
	}
}