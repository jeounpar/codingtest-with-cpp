import java.io.*;
import java.net.Inet4Address;
import java.util.*;

public class Main {
	static int answer = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		int[] arr = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			arr[i] = i;
		}
		int cur = 0;
		StringBuilder sb = new StringBuilder();
		sb.append('<');
		while (n > 0) {
			cur = (cur + k) % n;
			if (cur == 0) cur = n;
			if (n == 1) {
				sb.append(arr[cur]).append('>');
			} else {
				sb.append(arr[cur]).append(", ");
				for (int i = cur; i < n; i++) {
					arr[i] = arr[i + 1];
				}
				cur--;
			}
			n--;
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}// 0 1 2 4 5 6 7