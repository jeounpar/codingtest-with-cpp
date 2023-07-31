import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxIter = Integer.parseInt(st.nextToken());
		char[] arr = new char[51];
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = 0;

			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			int strSize = str.length();
			for (int i = 0; i < strSize; i++)
				arr[i] = '0';
			char c = '0';
			for (int i = 0; i < strSize; i++) {
				if (str.charAt(i) != c) {
					c = str.charAt(i);
					answer++;
				}
			}

			bw.write("#" + test_case + " " + answer);
			bw.newLine();
			bw.flush();
		}
		bw.close();
		br.close();
	}
}