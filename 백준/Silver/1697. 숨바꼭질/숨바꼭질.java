import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static final int MAX = 100000;
	static int n, k;
	static int[] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		arr = new int[MAX + 10];
		for (int i = 0; i < MAX + 10; i++) {
			arr[i] = 10000000;
		}

		Queue<Integer> Q = new ArrayDeque<>();
		Q.add(n);
		arr[n] = 0;
		while (!Q.isEmpty()) {
			Integer cur = Q.poll();
//			System.out.println(cur);
			if (cur - 1 >= 0 && arr[cur] + 1 < arr[cur - 1]) {
				arr[cur - 1] = arr[cur] + 1;
				Q.add(cur - 1);
			}
			if (cur + 1 <= MAX && arr[cur] + 1 < arr[cur + 1]) {
				arr[cur + 1] = arr[cur] + 1;
				Q.add(cur + 1);
			}
			if (cur * 2 <= MAX && arr[cur] + 1 < arr[cur * 2]) {
				arr[cur * 2] = arr[cur] + 1;
				Q.add(cur * 2);
			}

		}
//		System.out.println(Arrays.toString(arr));

		bw.write(Integer.toString(arr[k]));

		bw.flush();
		bw.close();
		br.close();
	}
}