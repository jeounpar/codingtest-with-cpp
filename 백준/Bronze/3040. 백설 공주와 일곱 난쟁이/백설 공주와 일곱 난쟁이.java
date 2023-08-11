import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int[] arr;
	static int[] tmp = new int[9];

	static void solve(int cnt, int idx) {
		if (cnt == 7) {
			int sum = 0;
			for (int i = 0; i < 7; i++) {
				sum += arr[tmp[i]];
				if (sum > 100)
					return;
			}
			if (sum == 100) {
				for (int i = 0; i < 7; i++) {
					System.out.println(arr[tmp[i]]);
				}
			}
			return;
		}

		for (int i = idx; i < 9; i++) {
			tmp[cnt] = i;
			solve(cnt+ 1, i + 1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		arr = new int[9];
		for (int i = 0; i < 9; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		solve(0, 0);
		bw.flush();
		bw.close();
		br.close();
	}
}