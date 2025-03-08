import java.io.*;

public class Main {
    public static void recur(char[][] star, int x, int y, int size){
        if (size == 1) return;

        for(int i = x + size / 3; i < x + (size / 3) * 2; i++){
            for(int j = y + size / 3; j < y + (size / 3) * 2; j++){
                star[i][j] = ' ';
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                recur(star, x + i * size / 3, y + j * size / 3, size / 3);
            }
        }

    }

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        char[][] star = new char[N][N];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                star[i][j] = '*';
            }
        }
        recur(star, 0, 0, N);

        for(int i = 0; i < N; i++){
            wr.write(star[i]);
            wr.write('\n');
        }
        wr.flush();
        wr.close();
    }
}
