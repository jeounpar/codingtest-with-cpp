import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxIter = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = 0;
			String str = br.readLine().trim();
			int strLen = str.length();
			int cnt = 0;
			for (int i = 0; i < strLen; i++) {
				if (str.charAt(i) == '(') {
					cnt++;
				} else {
					cnt--;
					if (str.charAt(i - 1) == '(') {
						answer += cnt;
					} else {
						answer++;
					}
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

// ( )
// ( ( ( ( ) ( ) ) ( ( ) ) ( ) ) )
// ( ( ) )