import java.io.*;
import java.util.*;

public class Main {
	static int n; // 이번 분기가 몇분인지 저장

	static class Pair {
		int time; // 업무가 걸리는 시간
		int score; // 업무을 완료했을때 받는 점수

		public Pair(int time, int score) {
			this.time = time;
			this.score = score;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());

		Deque<Pair> Q = new ArrayDeque<Pair>(); // Pair를 관리하는 Deque
		int t, score, time;
		int answer = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			t = Integer.parseInt(st.nextToken());
			if (t == 1) { // (i+1)시간에 업무가 주어졌다
				score = Integer.parseInt(st.nextToken()); // 해당 업무의 점수 저장
				time = Integer.parseInt(st.nextToken()); // 해당 업무가 소요되는 시간 저장
				time--; // 업무를 받자마자 바로 일할 수 있으므로 시간은 1감소
				if (time == 0) { // 업무를 받자마자 끝냈다면
					answer += score;  // 정답에 해당 업무의 점수를 더해주고
				} else { // 업무를 받자마자 못 끝냈다면
					Q.offerFirst(new Pair(time, score)); // Deque 맨 앞에 넣어준다
				}
			} else { // (i+1)시간 주어진 업무가 없다
				if (!Q.isEmpty()) { // Deque가 비어있지 않다면 := 해야 할 업무가 남아있다면
					Pair cur = Q.pollFirst(); // Deque 맨 앞의 업무를 꺼내주고
					cur.time--; // 업무를 1분 진행한뒤
					if (cur.time == 0) { // 만약 해당 업무가 완료되었다면
						answer += cur.score;  // 정답에 해당 업무의 점수를 더해주고
					} else { // 해당 업무를 완료하지 못했다면
						Q.addFirst(cur); // Deque 맨 앞에 넣어준다
					}
				}
			}
		}
		
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		br.close();
	}
}
// (10, 3) (100) (20)
// 1 (10, 2)
// 2 (10, 1)
// 3 (100, 1) (10, 1)
// 4 (20, 0) (100, 1) (10, 1)
// 5
