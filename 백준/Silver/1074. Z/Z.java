import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n, r, c;

	static void solve(int x, int y, int cnt) {


	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		int size = (int) Math.pow(2, n); //한 변의 사이즈
		find(size, r, c);
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}

	static void find(int size, int r, int c) {
		if (size == 1) return;

		if (r < size / 2 && c < size / 2) {
			find(size / 2, r, c);
		} else if (r < size / 2 && c >= size / 2) {
			answer += size * size / 4;
			find(size / 2, r, c - size / 2);
		} else if (r >= size / 2 && c < size / 2) {
			answer += (size * size / 4) * 2;
			find(size / 2, r - size / 2, c);
		} else {
			answer += (size * size / 4) * 3;
			find(size / 2, r - size / 2, c - size / 2);
		}
	}

}