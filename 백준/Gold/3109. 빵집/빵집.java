import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int[][] arr;
	static int r, c;
	static int[] dx = {-1, 0, 1};
	static int[] dy = {1, 1, 1};
	static boolean isOk;
	static HashSet<Integer> set;

	static void solve(int x, int y) {
		if (isOk)
			return;

		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r) continue;
			if (ny == c - 1) {
				isOk = true;
				return;
			}
			if (isOk)
				return;
			if (arr[nx][ny] > 0) continue;
			arr[nx][ny] = 2;
			solve(nx, ny);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		arr = new int[r][c];
		for (int i = 0; i < r; i++) {
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			for (int j = 0; j < c; j++) {
				if (str.charAt(j) == '.') {
					arr[i][j] = 0;
				} else {
					arr[i][j] = 1;
				}
			}
		}
		for (int i = 0; i < r; i++) {
			isOk = false;
//			arr[i][0] = 2;
			solve(i, 0);
			if (isOk) {
				answer++;
			}
		}
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}
}