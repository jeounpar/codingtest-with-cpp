import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;
	static StringBuilder sb = new StringBuilder();
	static int n;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for (int test_case = 1; test_case <= 10; test_case++) {
			answer = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			List<Integer> list = new LinkedList<>();
			for (int i = 0; i < n; i++)
				list.add(Integer.parseInt(st.nextToken()));

			st = new StringTokenizer(br.readLine());
			int t = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < t; i++) {
				st.nextToken();
				int idx = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				List<Integer> tmp = new LinkedList<>();
				for (int j = 0; j < y; j++) {
					tmp.add(Integer.parseInt(st.nextToken()));
				}
				if (idx > 10)
					continue;
				list.addAll(idx, tmp);
			}
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < 10; i++) {
				sb.append(list.get(i)).append(" ");
			}
			bw.write("#" + test_case + " " + sb);
			bw.newLine();
		}
		bw.flush();
		bw.close();
		br.close();
	}
}