import java.io.*;
import java.util.*;

public class Solution {
	static int x, y, dir;
	static int h, w, n;
	static String str;
	static char[][] board;
	static StringBuilder sb = new StringBuilder();

	// UP DOWN LEFT RIGHT
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};

	static int getDir(char dir) {
		if (dir == '^' || dir == 'U') {
			return 0;
		} else if (dir == 'v' || dir == 'D') {
			return 1;
		} else if (dir == '<' || dir == 'L') {
			return 2;
		} else {
			return 3;
		}
	}

	static void move(char direction) {
		board[x][y] = '.';
		dir = getDir(direction);
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w || board[nx][ny] == '-' || board[nx][ny] != '.') {
			;
		} else {
			x = nx;
			y = ny;
		}
		board[x][y] = direction;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxIter = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= maxIter; test_case++) {

			st = new StringTokenizer(br.readLine());
			h = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			board = new char[h][w];

			for (int i = 0; i < h; i++) {
				st = new StringTokenizer(br.readLine());
				board[i] = st.nextToken().toCharArray();
				for (int j = 0; j < w; j++) {
					if (board[i][j] == '<' || board[i][j] == '^' || board[i][j] == '>' || board[i][j] == 'v') {
						x = i;
						y = j;
						dir = getDir(board[i][j]);
					}
				}
			}

			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			str = st.nextToken();

			for (int i = 0; i < n; i++) {
				if (str.charAt(i) == 'U') {
					move('^');
				} else if (str.charAt(i) == 'D') {
					move('v');
				} else if (str.charAt(i) == 'L') {
					move('<');
				} else if (str.charAt(i) == 'R') {
					move('>');
				} else {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					while (true) {
						if (nx < 0 || nx >= h || ny < 0 || ny >= w || board[nx][ny] == '#') break;
						if (board[nx][ny] == '*') {
							board[nx][ny] = '.';
							break;
						}
						nx += dx[dir];
						ny += dy[dir];
					}
				}
//				sb.append(str.charAt(i)).append("\n");
//				for (int a = 0; a < h; a++) {
//					for (int j = 0; j < w; j++) {
//						sb.append(board[a][j]);
//					}
//					sb.append("\n");
//				}
			}
			sb.append("#").append(test_case).append(" ");
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					sb.append(board[i][j]);
				}
				sb.append("\n");
			}
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}