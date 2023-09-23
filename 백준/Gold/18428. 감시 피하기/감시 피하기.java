import java.io.*;
import java.util.*;

public class Main {
	static boolean answer = false;
	static int n;
	static char[][] arr;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	static ArrayList<Pair> teacher;

	static void solve(int cnt) {
		if (answer) return;

		if (cnt == 3) {
//			System.out.println("here");
			for (Pair t : teacher) {
				boolean flag = true;
				for (int i = 0; i < 4; i++) {
					int nx = t.x;
					int ny = t.y;
					while (true) {
						nx += dx[i];
						ny += dy[i];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] == 'O') break;
						if (arr[nx][ny] == 'S') {
							flag = false;
							break;
						}
					}
				}
				if (!flag) return;
			}
			answer = true;
			return;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != 'X') continue;
				arr[i][j] = 'O';
				solve(cnt + 1);
				arr[i][j] = 'X';
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new char[n][n];
		teacher = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[i][j] = st.nextToken().charAt(0);
				if (arr[i][j] == 'T') teacher.add(new Pair(i, j));
			}
		}

		solve(0);

		if (answer) bw.write("YES");
		else bw.write("NO");

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