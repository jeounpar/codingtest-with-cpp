import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;
	static int n;
	static int[][] arr;
	static int[] dx = {1, -1, 0, 0, 1, 1, -1, -1};
	static int[] dy = {0, 0, 1, -1, -1, 1, 1, -1};
	static StringBuilder sb = new StringBuilder();

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
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxIter = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = 0;
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			arr = new int[n][n];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				String str = st.nextToken();
				for (int j = 0; j < n; j++) {
					if (str.charAt(j) == '.') {
						arr[i][j] = 0;
					} else {
						arr[i][j] = -1;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == -1 || arr[i][j] > 0) continue;
					boolean isValid = true;
					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (arr[nx][ny] == -1) {
							isValid = false;
							break;
						}
					}
					if (!isValid)
						continue;
					answer++;
					Queue<Pair> Q = new ArrayDeque<>();
					arr[i][j] = 1;
					Q.add(new Pair(i, j));
					while (!Q.isEmpty()) {
						Pair cur = Q.poll();
						for (int dir = 0; dir < 8; dir++) {

							boolean flag = true;
							for (int k = 0; k < 8; k++) {
								int nx = cur.x + dx[k];
								int ny = cur.y + dy[k];
								if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
								if (arr[nx][ny] == -1) {
									arr[cur.x][cur.y] = 1;
									flag = false;
									break;
								}
							}
							if (!flag) continue;

							int nx = cur.x + dx[dir];
							int ny = cur.y + dy[dir];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] > 0 || arr[nx][ny] == -1) continue;
							Q.add(new Pair(nx, ny));
							arr[nx][ny] = 1;

						}
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == 0)
						answer++;
				}
			}
			sb.append("#").append(test_case).append(" ").append(answer).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}