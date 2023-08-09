import java.io.*;
import java.util.*;

public class Solution {
	static int answer = 0;
	static StringBuilder sb = new StringBuilder();
	static Node[] nodes;
	static ArrayList<Integer> ancestorA, ancestorB;

	static class Node {
		List<Integer> children;
		int parent;

		Node() {
			this.children = new ArrayList<>();
			this.parent = 0;
		}
	}

	static void traverse(int idx, ArrayList<Integer> ancestor) {
		int parent = nodes[idx].parent;
		if (parent != 0) {
			traverse(parent, ancestor);
		}
		ancestor.add(idx);
	}

	static int dfs(int idx) {
		if (nodes[idx].children.size() == 0) return 1;
		int res = 1;
		for (int child : nodes[idx].children) {
			res += dfs(child);
		}
		return res;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int maxIter = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= maxIter; test_case++) {
			answer = 0;
			st = new StringTokenizer(br.readLine());
			int v = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			nodes = new Node[v + 1];
			ancestorA = new ArrayList<>();
			ancestorB = new ArrayList<>();
			for (int i = 0; i < v + 1; i++) {
				nodes[i] = new Node();
			}
			int p, c;
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < e; i++) {
				p = Integer.parseInt(st.nextToken());
				c = Integer.parseInt(st.nextToken());
				nodes[p].children.add(c);
				nodes[c].parent = p;
			}

			traverse(a, ancestorA);
			traverse(b, ancestorB);
			for (int i = 0; i < v; i++) {
				if (!ancestorA.get(i).equals(ancestorB.get(i))) break;
				answer = ancestorA.get(i);
			}

			bw.write("#" + test_case + " " + answer + " " + dfs(answer));
			bw.newLine();
		}
		bw.flush();
		bw.close();
		br.close();
	}
}