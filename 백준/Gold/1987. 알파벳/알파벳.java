import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int r, c;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	static boolean[] ok = new boolean[30];
	static char[][] arr;

	static void solve(int x, int y, int cnt) {
		if (cnt > answer)
			answer = cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || ok[arr[nx][ny] - 'A'])
				continue;
			ok[arr[nx][ny] - 'A'] = true;
			solve(nx, ny, cnt + 1);
			ok[arr[nx][ny] - 'A'] = false;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		arr = new char[r][c];

		for (int i = 0; i < r; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i] = st.nextToken().toCharArray();
		}
		ok[arr[0][0] - 'A'] = true;
		solve(0, 0, 1);
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}
}