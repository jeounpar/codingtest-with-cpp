import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;

	static class Jump {
		int x;
		int y;

		public Jump(int x, int y) {
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
			int[][] arr = new int[n][n];
			Map<Integer, List<Jump>> map = new HashMap<>();
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					if (arr[i][j] >= 6) {
						List<Jump> list;
						if (map.containsKey(arr[i][j])) {
							list = map.get(arr[i][j]);
						} else {
							list = new ArrayList<>(2);
						}
						list.add(new Jump(i, j));
						map.put(arr[i][j], list);
					}
				}
			}
			// 하, 상, 우, 좌
			int[] dx = {1, -1, 0, 0};
			int[] dy = {0, 0, 1, -1};
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == -1 || arr[i][j] > 0) continue;
					for (int dir = 0; dir < 4; dir++) {
						int cnt = 0;
						int curDir = dir;
						int nx = i + dx[curDir];
						int ny = j + dy[curDir];
						while (true) {
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
								cnt++;
								nx -= dx[curDir];
								ny -= dy[curDir];
								if (curDir == 0)
									curDir = 1;
								else if (curDir == 1)
									curDir = 0;
								else if (curDir == 2)
									curDir = 3;
								else
									curDir = 2;
							} else if (arr[nx][ny] >= 6) {
								List<Jump> list = map.get(arr[nx][ny]);
								for (Jump jump : list) {
									if (jump.x != nx || jump.y != ny) {
										nx = jump.x;
										ny = jump.y;
										break;
									}
								}
								nx += dx[curDir];
								ny += dy[curDir];
							} else if (arr[nx][ny] == -1 || (nx == i && ny == j)) {
								break;
							} else if (arr[nx][ny] >= 1 && arr[nx][ny] <= 5) {
								// 하, 상, 우, 좌
								// 0, 1, 2, 3
								cnt++;
								if (arr[nx][ny] == 1) {
									if (curDir == 0)
										curDir = 2;
									else if (curDir == 1)
										curDir = 0;
									else if (curDir == 2)
										curDir = 3;
									else
										curDir = 1;
								} else if (arr[nx][ny] == 2) {
									if (curDir == 0)
										curDir = 1;
									else if (curDir == 1)
										curDir = 2;
									else if (curDir == 2)
										curDir = 3;
									else
										curDir = 0;
								} else if (arr[nx][ny] == 3) {
									if (curDir == 0)
										curDir = 1;
									else if (curDir == 1)
										curDir = 3;
									else if (curDir == 2)
										curDir = 0;
									else
										curDir = 2;
								} else if (arr[nx][ny] == 4) {
									if (curDir == 0)
										curDir = 3;
									else if (curDir == 1)
										curDir = 0;
									else if (curDir == 2)
										curDir = 1;
									else
										curDir = 2;
								} else if (arr[nx][ny] == 5) {
									if (curDir == 0)
										curDir = 1;
									else if (curDir == 1)
										curDir = 0;
									else if (curDir == 2)
										curDir = 3;
									else
										curDir = 2;
								}
								nx += dx[curDir];
								ny += dy[curDir];
							} else {
								nx += dx[curDir];
								ny += dy[curDir];
							}
						}
						if (cnt > answer)
							answer = cnt;
					}
				}
			}

			bw.write("#" + test_case + " " + answer);
			bw.newLine();
			bw.flush();
		}
		bw.close();
		br.close();
	}
}