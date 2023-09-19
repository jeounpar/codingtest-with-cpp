import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static int caseA(int[][] a, int n, int m) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(j + 3 < m) {
					int t = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
					if (t > ans)
						ans = t;
				}
				if (i + 3 < n) {
					int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
					if (t > ans)
						ans = t;
				}
			}
		}
		return ans;
	}
	public static int caseB(int[][] a, int n, int m) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + 1 < n && j + 1 < m) {
					int t = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
					if (t > ans)
						ans = t;
				}
			}
		}
		return ans;
	}
	public static int caseC(int[][] a, int n, int m) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + 2 < n && j + 1 < m) {
					int t = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
					if (t > ans)
						ans = t;
					int t2 = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+2][j];
					if (t2 > ans)
						ans = t2;
				}
				if (i + 1 < n && j + 2 < m) {
					int t = a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2] + a[i][j + 2];
					if (t > ans)
						ans = t;
					int t2 = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
					if (t2 > ans)
						ans = t2;
				}
				if (i + 2 < n && j + 1 < m) {
					int t = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+2][j+1];
					if (t > ans)
						ans = t;
					int t2 = a[i][j+1] + a[i+1][j+1] + a[i+2][j+1] + a[i+2][j];
					if (t2 > ans)
						ans = t2;
				}
				if (i + 1 < n && j + 2 < m) {
					int t = a[i][j] + a[i+1][j] + a[i][j+1] + a[i][j+2];
					if (t > ans)
						ans = t;
					int t2 = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+2];
					if (t2 > ans)
						ans = t2;
				}
			}
		}
		return ans;
	}
	public static int caseD(int[][] a, int n, int m) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + 2 < n && j + 1 < m) {
					int t = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j+1];
					if (t > ans)
						ans = t;
					int t2 = a[i+2][j] + a[i+1][j] + a[i+1][j+1] + a[i][j+1];
					if (t2 > ans)
						ans = t2;
				}
				if (i + 1 < n && j + 2 < m) {
					int t = a[i+1][j] + a[i+1][j+1] + a[i][j+1] + a[i][j+2];
					if (t > ans)
						ans = t;
					int t2 = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j+2];
					if (t2 > ans)
						ans = t2;
				}
			}
		}
		return ans;
	}
	public static int caseE(int[][] a, int n, int m) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + 1 < n && j + 2 < m) {
					int t = a[i+1][j] + a[i+1][j+1] + a[i+1][j+2] + a[i][j+1];
					if (t > ans)
						ans = t;
					int t2 = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1];
					if (t2 > ans)
						ans = t2;
				}
				if (i + 2 < n && j + 1 < m) {
					int t = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+1][j+1];
					if (t > ans)
						ans = t;
					int t2 = a[i][j+1] + a[i+1][j+1] + a[i+2][j+1] + a[i+1][j];
					if (t2 > ans)
						ans = t2;
				}
			}
		}
		return ans;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x = sc.nextInt();
				a[i][j] = x;
			}
		}
		int[] ans = new int[5];
		ans[0] = caseA(a, n, m);
		ans[1] = caseB(a, n, m);
		ans[2] = caseC(a, n, m);
		ans[3] = caseD(a, n, m);
		ans[4] = caseE(a, n, m);
		Arrays.sort(ans);
		System.out.println(ans[4]);
	}
}
