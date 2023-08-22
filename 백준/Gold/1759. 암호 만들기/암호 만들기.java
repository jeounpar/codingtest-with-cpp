import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static boolean[] ok = new boolean[16];
	static char[] arr = new char[16];
	static char[] input = new char[16];

	static void solve(int idx, int n, int m, char pre, int vol, int cons) {
		if (idx == m) {
			if (vol < 1 || cons < 2)
				return;
			for (int i = 0; i < m; i++)
				System.out.print(arr[i]);
			System.out.println();
			return;
		}
		for (int i = 0; i < n; i++) {
			if (ok[i])
				continue;
			if (pre > input[i])
				continue;
			if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
				vol += 1;
			else
				cons += 1;
			ok[i] = true;
			arr[idx] = input[i];
			solve(idx + 1, n, m, input[i], vol, cons);
			if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
				vol -= 1;
			else
				cons -= 1;
			ok[i] = false;
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n, m;
		m = scanner.nextInt();
		n = scanner.nextInt();
		for (int i = 0; i < n; i++)
			input[i] = scanner.next().charAt(0);
		Arrays.sort(input, 0, n);
		solve(0, n, m, input[0], 0, 0);
	}
}
