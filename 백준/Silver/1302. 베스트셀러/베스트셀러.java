import java.io.*;
import java.util.*;

public class Main {
	static int answer = 0;
	static int n;
	static HashMap<String, Integer> hashMap = new HashMap<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());

		int maxVal = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String key = st.nextToken();
			Integer value = hashMap.get(key);
			if (value == null) {
				hashMap.put(key, 1);
				maxVal = Math.max(maxVal, 1);
			} else {
				hashMap.put(key, value + 1);
				maxVal = Math.max(maxVal, value + 1);
			}
		}
		ArrayList<String> list = new ArrayList<>();
		int finalMaxVal = maxVal;
		hashMap.forEach((key, value) -> {
			if (value == finalMaxVal)
				list.add(key);
		});
		Collections.sort(list);
		bw.write(list.get(0));
		bw.flush();
		bw.close();
		br.close();
	}
}