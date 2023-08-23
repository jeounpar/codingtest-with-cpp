import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n, d, k, c;
	static int[] arr, ans;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());

		arr = new int[n + k];
		ans = new int[d + 1];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int cnt = 0;
		for (int i = n; i < n + k; i++) {
			arr[i] = arr[i - n];
		}

		for (int i = 0; i < k; i++) {
			if (ans[arr[i]] == 0) cnt++;
			ans[arr[i]]++;
		}

		answer = cnt;
		for (int i = 1; i <= n; i++) {
			if (answer <= cnt) {
				if (ans[c] == 0) answer = cnt + 1;
				else answer = cnt;
			}

			if (ans[arr[i + k - 1]] == 0) cnt++;
			ans[arr[i + k - 1]]++;

			ans[arr[i - 1]]--;
			if (ans[arr[i - 1]] == 0) cnt--;
		}

		bw.write(Integer.toString(answer));

		bw.flush();
		bw.close();
		br.close();
	}
}