import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Money = Integer.parseInt(st.nextToken());
        int [] arr = new int[N];
        int count = 0;
        int temp = 0;

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 1; i <= N; i++) {
            if(Money >= arr[N-i]){
                temp = Money%arr[N-i];
                count += Money/arr[N-i];
                Money = temp;
            }
        }
        System.out.println(count);
    }
}