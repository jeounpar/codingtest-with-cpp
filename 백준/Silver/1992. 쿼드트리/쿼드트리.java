import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n;
	static char[][] arr;
	static StringBuilder sb = new StringBuilder();

	static boolean isValid(int x, int y, int size) {
		char target = arr[x][y];
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (arr[i][j] != target) {
					return false;
				}
			}
		}
		return true;
	}

	static void solve(int x, int y, int size) {
		if (isValid(x, y, size)) {
			sb.append(arr[x][y]);
			return;
		}
		sb.append("(");
		solve(x, y, size / 2);
		solve(x, y + size / 2, size / 2);
		solve(x + size / 2, y, size / 2);
		solve(x + size / 2, y + size / 2, size / 2);
		sb.append(")");
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new char[n + 1][n + 1];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			for (int j = 0; j < n; j++) {
				arr[i][j] = str.charAt(j);
			}
		}
//		System.out.println("here");
		solve(0, 0, n);
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}