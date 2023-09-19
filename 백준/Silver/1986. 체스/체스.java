import java.io.*;
import java.util.*;

public class Main {

	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int answer = 0;
	static int n, m;

	static int[][] board;
	static ArrayList<Pair>[] arr;

	static int[] dx = {1, -1, 0, 0, 1, 1, -1, -1, -1, -2, -2, -1, 1, 2, 2, 1};
	static int[] dy = {0, 0, 1, -1, 1, -1, 1, -1, -2, -1, 1, 2, -2, -1, 1, 2};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		board = new int[n][m];

		arr = new ArrayList[2];
		for (int i = 0; i < 2; i++) {
			arr[i] = new ArrayList<>();
		}

		for (int i = 0; i < 3; i++) {
			st = new StringTokenizer(br.readLine());
			int t = Integer.parseInt(st.nextToken());
			for (int j = 0; j < t; j++) {
				int x = Integer.parseInt(st.nextToken()) - 1;
				int y = Integer.parseInt(st.nextToken()) - 1;
				board[x][y] = 2;
				if (i < 2) {
					arr[i].add(new Pair(x, y));
				}
			}
		}
		ArrayList<Pair> Queen = arr[0];
		for (Pair p : Queen) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = p.x + dx[dir];
				int ny = p.y + dy[dir];
				while (true) {
					if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 2) break;
					board[nx][ny] = 1;
					nx += dx[dir];
					ny += dy[dir];
				}
			}
		}
		ArrayList<Pair> Knight = arr[1];
		for (Pair p : Knight) {
			for (int dir = 8; dir < 16; dir++) {
				int nx = p.x + dx[dir];
				int ny = p.y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 2) continue;
				board[nx][ny] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) answer++;
			}
		}
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}
}