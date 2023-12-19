import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int answer = 0;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    static class Pair {

        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int max_iter = Integer.parseInt(st.nextToken());
        while (max_iter-- > 0) {
            answer = 0;
            int n, m, k;
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            boolean[][] arr = new boolean[n + 1][m + 1];
            int x, y;
            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine());
                x = Integer.parseInt(st.nextToken());
                y = Integer.parseInt(st.nextToken());
                arr[x][y] = true;
            }
            boolean[][] ok = new boolean[n + 1][m + 1];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] && !ok[i][j]) {
                        ok[i][j] = true;
                        answer++;
                        Queue<Pair> Q = new ArrayDeque<>();
                        Q.offer(new Pair(i, j));
                        while (!Q.isEmpty()) {
                            Pair cur = Q.poll();
                            for (int l = 0; l < 4; l++) {
                                int nx = cur.x + dx[l];
                                int ny = cur.y + dy[l];
                                if (nx < 0 || nx >= n || ny < 0 || ny >= m || ok[nx][ny]
                                    || !arr[nx][ny]) {
                                    continue;
                                }
                                ok[nx][ny] = true;
                                Q.offer(new Pair(nx, ny));
                            }
                        }
                    }
                }
            }
            bw.write(answer + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}