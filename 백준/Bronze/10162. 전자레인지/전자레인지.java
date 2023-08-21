import java.io.*;
import java.util.*;

public class Main {
	static int t; // 요리 시간 t
	// a := 300초 타이머를 몇번 눌렀는지, b := 60초 타이머를 몇번 눌렀는지, c := 10초 타이머를 몇번 눌렀는지
	static int a, b, c;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		st = new StringTokenizer(br.readLine());
		t = Integer.parseInt(st.nextToken()); // 요리시간 입력 받기
		a = b = c = 0; // a,b,c 타이머 0으로 초기화

		// 300초 타이머 -> 60초 타이머 -> 10초 타이머 순서대로 누를 수 있는지 검사
		if (t / 300 > 0) { // 300초 타이머를 누를 수 있으면
			a += t / 300; // a타이머 횟수를 저장하고
			t = t % 300; // 요리시간 업데이트
		}

		if (t / 60 > 0) { // 60초 타이머를 누를 수 있으면
			b += t / 60; // b타이머 횟수를 저장하고
			t = t % 60; // 요리시간 업데이트
		}

		if (t / 10 > 0) { // 10초 타이머를 누를 수 있으면
			c += t / 10; // c타이머 횟수를 저장하고
			t = t % 10; // 요리시간 업데이트
		}
		
		if (t != 0 || a == 0 && b == 0 && c == 0) { //  3개의 버튼으로 t초를 맞출 수 없을 때
			sb.append(-1);
		} else { // 3개의 버튼으로 t초를 맞출 수 있을 때
			sb.append(a).append(" ").append(b).append(" ").append(c);
		}
		sb.append("\n");
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}

}
