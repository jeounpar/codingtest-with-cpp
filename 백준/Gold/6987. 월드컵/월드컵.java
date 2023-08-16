import java.io.*;
import java.util.*;

public class Main {
	static class Pair {
		int A;
		int B;

		public Pair(int a, int b) {
			A = a;
			B = b;
		}

		@Override
		public String toString() {
			return "Pair{" +
					"A=" + A +
					", B=" + B +
					'}';
		}
	}

	static int answer = 0;
	static ArrayList<Pair> list = new ArrayList<>();
	static int[] arr, winCnt, loseCnt, tieCnt;
	static int[][] rst;
	static int[] tmp = new int[2];

	static void roundCase(int cnt, int idx) {
		if (cnt == 2) {
			list.add(new Pair(tmp[0], tmp[1]));
			return;
		}
		for (int i = idx; i < 6; i++) {
			tmp[cnt] = i;
			roundCase(cnt + 1, i + 1);
		}
	}

	static void solve(int roundCnt) {
		if (answer == 1)
			return;
		if (roundCnt == 15) {
			for (int i = 0; i < 6; i++) {
				if (winCnt[i] != rst[i][0] || tieCnt[i] != rst[i][1] || loseCnt[i] != rst[i][2]) {
					return;
				}
			}
			answer = 1;
			return;
		}
		// win
		int A = list.get(roundCnt).A;
		int B = list.get(roundCnt).B;
		rst[A][0]++;
		rst[B][2]++;
		solve(roundCnt + 1);
		rst[A][0]--;
		rst[B][2]--;

		// tie
		rst[A][1]++;
		rst[B][1]++;
		solve(roundCnt + 1);
		rst[A][1]--;
		rst[B][1]--;

		//lose
		rst[A][2]++;
		rst[B][0]++;
		solve(roundCnt + 1);
		rst[A][2]--;
		rst[B][0]--;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		roundCase(0, 0);

		for (int i = 0; i < 4; i++) {
			answer = 0;
			arr = new int[6];
			winCnt = new int[6];
			loseCnt = new int[6];
			tieCnt = new int[6];
			rst = new int[6][3];
			st = new StringTokenizer(br.readLine());
			int win, tie, lose;
			boolean flag = true;
			for (int j = 0; j < 6; j++) {
				win = Integer.parseInt(st.nextToken());
				tie = Integer.parseInt(st.nextToken());
				lose = Integer.parseInt(st.nextToken());
				winCnt[j] = win;
				loseCnt[j] = lose;
				tieCnt[j] = tie;
				arr[j] = win + tie + lose;
			}
			for (int j = 0; j < 6; j++) {
				if (arr[j] != 5) {
					flag = false;
					break;
				}
			}
			if (flag) {
				int[][] teamA = new int[6][3];
				int[][] teamB = new int[6][3];
				solve(0);

			}
			sb.append(answer).append(" ");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}