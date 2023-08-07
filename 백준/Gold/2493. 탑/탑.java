import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;

	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Pair{" +
					"x=" + x +
					", y=" + y +
					'}';
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		Stack<Pair> stack = new Stack<>();
		stack.push(new Pair(100_000_001, 0));
		st = new StringTokenizer(br.readLine());
		int height;
		for (int i = 0; i < n; i++) {
			height = Integer.parseInt(st.nextToken());
			while (stack.peek().x < height) {
				stack.pop();
			}
			sb.append(stack.peek().y).append(" ");
			stack.push(new Pair(height, i + 1));
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}