import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n, m;
	static int max_cctv = 0;
	static char[][] arr;
	static ArrayList<Pair> gps = new ArrayList<>();
	static ArrayList<Integer> cctv = new ArrayList<>();
	static int[] vc;

	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static void solve(int k) {
		if (k == max_cctv) {
			char[][] tmp = new char[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					tmp[i][j] = arr[i][j];

			// 1 - 동
			// 2 - 서
			// 3 - 남
			// 4 - 북
			for (int i = 0; i < max_cctv; i++) {
				int x = gps.get(i).x;
				int y = gps.get(i).y;
				if (vc[i] == 1) {
					if (arr[x][y] == '1') {
						// east
						for (int j = y + 1; j < m; j++) {
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
					} else if (arr[x][y] == '2') {
						// east
						for (int j = y + 1; j < m; j++) {
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// west
						for (int j = y - 1; j >= 0; j--) {
							if (y - 1 < 0)
								break;
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
					} else if (arr[x][y] == '3') {
						// east
						for (int j = y + 1; j < m; j++) {
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// 북
						for (int j = x - 1; j >= 0; j--) {
							if (x - 1 < 0)
								break;
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					} else if (arr[x][y] == '5') {
						// east
						for (int j = y + 1; j < m; j++) {
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// west
						for (int j = y - 1; j >= 0; j--) {
							if (y - 1 < 0)
								break;
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// 남
						for (int j = x + 1; j < n; j++) {
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
						// 북
						for (int j = x - 1; j >= 0; j--) {
							if (x - 1 < 0)
								break;
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					} else if (arr[x][y] == '4') {
						// east
						for (int j = y + 1; j < m; j++) {
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// west
						for (int j = y - 1; j >= 0; j--) {
							if (y - 1 < 0)
								break;
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// 북
						for (int j = x - 1; j >= 0; j--) {
							if (x - 1 < 0)
								break;
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					}
				} else if (vc[i] == 2) {
					if (arr[x][y] == '1') {
						for (int j = y - 1; j >= 0; j--) {
							if (y - 1 < 0)
								break;
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
					} else if (arr[x][y] == '2') {
						// 남
						for (int j = x + 1; j < n; j++) {
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
						// 북
						for (int j = x - 1; j >= 0; j--) {
							if (x - 1 < 0)
								break;
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					} else if (arr[x][y] == '3') {
						// east
						for (int j = y + 1; j < m; j++) {
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// 남
						for (int j = x + 1; j < n; j++) {
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					} else if (arr[x][y] == '4') {
						// east
						for (int j = y + 1; j < m; j++) {
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// 남
						for (int j = x + 1; j < n; j++) {
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
						// 북
						for (int j = x - 1; j >= 0; j--) {
							if (x - 1 < 0)
								break;
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					}
				} else if (vc[i] == 3) {
					// 남
					if (arr[x][y] == '1') {
						for (int j = x + 1; j < n; j++) {
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					} else if (arr[x][y] == '3') {
						// 서
						for (int j = y - 1; j >= 0; j--) {
							if (y - 1 < 0)
								break;
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// 남
						for (int j = x + 1; j < n; j++) {
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					} else if (arr[x][y] == '4') {
						// east
						for (int j = y + 1; j < m; j++) {
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// west
						for (int j = y - 1; j >= 0; j--) {
							if (y - 1 < 0)
								break;
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// 남
						for (int j = x + 1; j < n; j++) {
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					}
				} else if (vc[i] == 4) {
					if (arr[x][y] == '1') {
						// 북
						for (int j = x - 1; j >= 0; j--) {
							if (x - 1 < 0)
								break;
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					} else if (arr[x][y] == '3') {
						// 서
						for (int j = y - 1; j >= 0; j--) {
							if (y - 1 < 0)
								break;
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// 북
						for (int j = x - 1; j >= 0; j--) {
							if (x - 1 < 0)
								break;
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					} else if (arr[x][y] == '4') {
						// west
						for (int j = y - 1; j >= 0; j--) {
							if (y - 1 < 0)
								break;
							if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
								continue;
							if (tmp[x][j] == '6')
								break;
							tmp[x][j] = '#';
						}
						// 남
						for (int j = x + 1; j < n; j++) {
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
						// 북
						for (int j = x - 1; j >= 0; j--) {
							if (x - 1 < 0)
								break;
							if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
								continue;
							if (tmp[j][y] == '6')
								break;
							tmp[j][y] = '#';
						}
					}
				}
			}
			int zero_cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (tmp[i][j] == '0')
						zero_cnt++;
				}
			}
			if (zero_cnt < answer)
				answer = zero_cnt;
			return;
		}
		for (int i = 1; i <= cctv.get(k); i++) {
			vc[k] = i;
			solve(k + 1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new char[n][m];

		answer = Integer.MAX_VALUE;

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = st.nextToken().charAt(0);
				if (arr[i][j] >= '1' && arr[i][j] <= '5') {
					max_cctv++;
					gps.add(new Pair(i, j));
					if (arr[i][j] == '1')
						cctv.add(4);
					else if (arr[i][j] == '2')
						cctv.add(2);
					else if (arr[i][j] == '3')
						cctv.add(4);
					else if (arr[i][j] == '4')
						cctv.add(4);
					else if (arr[i][j] == '5')
						cctv.add(1);
				}
			}
		}
		vc = new int[max_cctv + 1];
		solve(0);
		bw.write(Integer.toString(answer));

		bw.flush();
		bw.close();
		br.close();
	}
}