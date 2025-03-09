import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] KAKboard;
    static int[][] water;
    static int[] dx = new int[]{0, 1, 0, -1};
    static int[] dy = new int[]{1, 0, -1, 0};
    static char[][] c;
    static Queue<Point> KAKQ = new LinkedList<>();
    static Queue<Point> waterQ = new LinkedList<>();

    static void waterbfs(){
        while(!waterQ.isEmpty()){
            Point p = waterQ.poll();
            for(int dist = 0; dist < 4; dist++){
                int nx = p.x + dx[dist];
                int ny = p.y + dy[dist];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(c[nx][ny] != '.' || water[nx][ny] >= 0 || c[nx][ny] == 'D') continue;
                water[nx][ny] = water[p.x][p.y] + 1;
                waterQ.add(new Point(nx, ny));
            }
        }
    }

    static void KAKbfs(){
        while(!KAKQ.isEmpty()){
            Point p = KAKQ.poll();
            for(int dist = 0; dist < 4; dist++) {
                int nx = p.x + dx[dist];
                int ny = p.y + dy[dist];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(KAKboard[nx][ny] >= 0 || c[nx][ny] == 'X' || c[nx][ny] == '*') continue;
                if(water[nx][ny] != -1 && water[nx][ny] <= KAKboard[p.x][p.y] + 1) continue;
                KAKboard[nx][ny] = KAKboard[p.x][p.y] + 1;
                KAKQ.add(new Point(nx, ny));
                if(c[nx][ny] == 'D'){
                    System.out.println(KAKboard[nx][ny]);
                    System.exit(0);
                }
            }
        }
        System.out.println("KAKTUS");
    }

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer str = new StringTokenizer(br.readLine());
        n = Integer.parseInt(str.nextToken());
        m = Integer.parseInt(str.nextToken());
        KAKboard = new int[n][m];
        water = new int[n][m];
        c = new char[n][m];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                KAKboard[i][j] = -1;
                water[i][j] = -1;
            }
        }

        for(int i = 0; i < n; i++){
            String S = br.readLine();
            for(int j = 0; j < m; j++){
                c[i][j] = S.charAt(j);
                if(c[i][j] == 'S'){
                    KAKQ.add(new Point(i, j));
                    KAKboard[i][j] = 0;
                }
                if(c[i][j] == '*'){
                    waterQ.add(new Point(i, j));
                    water[i][j] = 0;
                }
            }
        }
        waterbfs();
        KAKbfs();
    }
}