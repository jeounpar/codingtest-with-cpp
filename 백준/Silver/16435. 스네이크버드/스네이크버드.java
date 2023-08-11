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
		int l = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		st = new StringTokenizer(br.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			pq.add(Integer.parseInt(st.nextToken()));
		}
		while (!pq.isEmpty()) {
			Integer cur = pq.poll();
			if (cur <= l)
				l++;
			else
				break;
		}
		bw.write(Integer.toString(l));
		bw.flush();
		bw.close();
		br.close();
	}
}