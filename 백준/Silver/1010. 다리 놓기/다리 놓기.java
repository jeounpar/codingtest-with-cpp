import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	static int answer = 0, n, m;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int test_case = Integer.parseInt(st.nextToken());

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < test_case; i++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			BigInteger a = new BigInteger("1");
			BigInteger b = new BigInteger("1");
			for (int t = m; t >= m - n + 1; t--) {
				a = a.multiply(new BigInteger(Integer.toString(t)));
			}
			for (int t = n; t >= 1; t--) {
				b = b.multiply(new BigInteger(Integer.toString(t)));
			}
			sb.append(a.divide(b)).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}