import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int maxIter = 10;
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = 0;
			int[] arr = new int[100];
			st = new StringTokenizer(br.readLine());
			int dump = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 100; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			for (int i = 0; i < dump; i++) {
				Arrays.sort(arr);
				arr[0]++;
				arr[99]--;
				Arrays.sort(arr);
				answer = arr[99] - arr[0];
			}
			bw.write("#" + test_case + " " + answer);
			bw.newLine();
			bw.flush();
		}
		bw.close();
		br.close();
	}
}