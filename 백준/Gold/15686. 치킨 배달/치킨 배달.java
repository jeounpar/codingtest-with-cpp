import java.io.*;
import java.util.*;

// 15,464kb	228ms
public class Main {
	static int answer = Integer.MAX_VALUE;
	static int n, m, h_size, c_size;
	static List<Pair> homes = new ArrayList<>();
	static List<Pair> chickens = new ArrayList<>();
	static int[] arr = new int[51];

	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static void solve(int cnt, int idx, int max_m) {
		if (cnt == max_m) {
			int sum = 0;
			for (Pair home : homes) {
				int dist = Integer.MAX_VALUE;
				for (int i = 0; i < max_m; i++) {
					Pair chicken = chickens.get(arr[i]);
					int tmp = Math.abs(home.x - chicken.x) + Math.abs(home.y - chicken.y);
					if (tmp < dist)
						dist = tmp;
				}
				sum += dist;
			}
			if (sum < answer)
				answer = sum;
			return;
		}
		for (int i = idx; i < c_size; i++) {
			arr[cnt] = i;
			solve(cnt + 1, i + 1, max_m);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int t;
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= n; j++) {
				t = Integer.parseInt(st.nextToken());
				if (t == 1) {
					homes.add(new Pair(i, j));
				} else if (t == 2) {
					chickens.add(new Pair(i, j));
				}
			}
		}
		h_size = homes.size();
		c_size = chickens.size();
			solve(0, 0, m);
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}
}