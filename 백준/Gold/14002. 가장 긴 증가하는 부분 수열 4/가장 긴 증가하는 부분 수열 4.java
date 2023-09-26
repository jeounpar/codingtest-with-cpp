
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] d = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int[] pre = new int[n];
		for (int i = 0; i < n; i++) {
			d[i] = 1;
			pre[i] = -1;
			int maxValue = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] < a[i]) {
					if (d[j] > maxValue) {
						pre[i] = j;
						maxValue = d[j];
					}
				}
			}
			d[i] = maxValue + 1;
		}
		int ans = d[0];
		int st = 0;
		for (int i = 0; i < n; i++) {
			if (d[i] > ans) {
				ans = d[i];
				st = i;
			}
		}
		System.out.println(ans);
		ArrayList<Integer> arrayList = new ArrayList<>();
		while (pre[st] != -1) {
			arrayList.add(a[st]);
			st = pre[st];
		}
		arrayList.add(a[st]);
		Collections.sort(arrayList);
		for (int i = 0; i < arrayList.size(); i++) {
			System.out.printf("%d", arrayList.get(i));
			if (i + 1 != arrayList.size())
				System.out.printf(" ");
			else
				System.out.printf("\n");
		}
	}
}
