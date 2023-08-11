import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int[] arr = new int[n + 10];
		for (int i = 1; i <= n; i++)
			arr[i] = 100000;
		Deque<Integer> queue = new ArrayDeque<>();
		queue.offer(0);
		while (!queue.isEmpty()) {
			Integer cur = queue.poll();
			if ((cur >= 3 && cur + 3 == n) || (cur >= 5 && cur + 5 == n)) {
				arr[n] = Math.min(arr[n - 5] + 1, arr[n - 3] + 1);
			}
			if (cur + 3 <= n && arr[cur] + 1 < arr[cur + 3]) {
				arr[cur + 3] = arr[cur] + 1;
				queue.offer(cur + 3);
			}
			if (cur + 5 <= n && arr[cur] + 1 < arr[cur + 5]) {
				arr[cur + 5] = arr[cur] + 1;
				queue.offer(cur + 5);
			}
		}
		if (arr[n] == 100000)
			answer = -1;
		else
			answer = arr[n];
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}
}