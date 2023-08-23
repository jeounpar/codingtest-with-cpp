import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n, m;
	static int[] arr;
	static Tuple[] tuples;

	static int find(int x) {
		if (arr[x] == x) {
			return x;
		}
		return arr[x] = find(arr[x]);
	}

	static void union(int a, int b) {
		int x = find(a);
		int y = find(b);
		arr[y] = x;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			arr[i] = i;
		}

		st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());

		tuples = new Tuple[m];

		int x, y, dist;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			dist = Integer.parseInt(st.nextToken());
			tuples[i] = new Tuple(x, y, dist);
		}

		Arrays.sort(tuples);

		for (int i = 0; i < m; i++) {
			Tuple cur = tuples[i];
			if (find(cur.x) != find(cur.y)) {
				answer += cur.dist;
				union(cur.x, cur.y);
			}
		}

		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}

	static class Tuple implements Comparable<Tuple> {
		int x, y, dist;

		public Tuple(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.dist = dist;
		}

		@Override
		public int compareTo(Tuple o) {
			return Integer.compare(this.dist, o.dist);
		}
	}
}