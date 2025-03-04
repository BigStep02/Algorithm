import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n, m, k, result = 1, index;
    static int[][] board;
    static int[][] size;
    static int[] dx = new int[]{0, 1, 0, -1};
    static int[] dy = new int[]{1, 0, -1, 0};
    static ArrayList<Integer> check = new ArrayList<>();
    static Queue<Point> Q = new LinkedList<>();

    static void bfs(){
        while(!Q.isEmpty()){
            Point p = Q.poll();
            for(int dist = 0; dist < 4; dist++){
                int nx = p.x + dx[dist];
                int ny = p.y + dy[dist];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == -1 || size[nx][ny] > 0) continue;
                size[nx][ny] = size[p.x][p.y] + 1;
                Q.add(new Point(nx, ny));
                result++;
            }
        }
        check.add(result);
        index++;
        result = 1;
    }

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer str = new StringTokenizer(br.readLine());
        n = Integer.parseInt(str.nextToken());
        m = Integer.parseInt(str.nextToken());
        k = Integer.parseInt(str.nextToken());

        board = new int[n][m];
        size = new int[n][m];

        for(int i = 0; i < k; i++){
            str = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(str.nextToken());
            int y1 = Integer.parseInt(str.nextToken());
            int x2 = Integer.parseInt(str.nextToken());
            int y2 = Integer.parseInt(str.nextToken());
            for(int j = y1; j < y2; j++){
                for(int x = x1; x < x2; x++){
                    board[j][x] = -1;
                    size[j][x] = -1;
                }
            }
        }

        int count = 0;
        index = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] != -1 && size[i][j] == 0){
                    size[i][j] = 1;
                    Q.add(new Point(i, j));
                    count++;
                    bfs();
                }
            }
        }

        Collections.sort(check);

        System.out.println(count);
        for(int i = 0; i < check.size(); i++){
            System.out.print(check.get(i) + " ");
        }
    }
}
