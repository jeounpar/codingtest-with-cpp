import java.util.*;
 
public class Main {    
    
    static int n;
    static ArrayList<Integer>[] list;
    static boolean[] visited;
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        int m = scan.nextInt();
        
        list = new ArrayList[n];
        for(int i = 0; i < n; i++) {
            list[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < m; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            list[a].add(b);
            list[b].add(a);
        }
        
        for(int i = 0; i < n; i++) {
            visited = new boolean[n];
            dfs(i, 0);
        }
        System.out.println(0);
    }
    
    public static void dfs(int x, int len) {
        if(len == 4) {
            System.out.println(1);
            System.exit(0);
        }
        
        visited[x] = true;
        for(int i = 0; i < list[x].size(); i++) {
            int temp = list[x].get(i);
            if(visited[temp] == false) {
                visited[temp] = true;
                dfs(temp, len + 1);
                visited[temp] = false;
            }
        }
    }
}
