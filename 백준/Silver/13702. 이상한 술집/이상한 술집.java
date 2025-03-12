import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static boolean check(long mid, long[] beer, long N, long M, long answer){
        long cnt = 0;
        for(int i = 0; i < N; i++){
            cnt += beer[i] / mid;
            if (cnt >= M) {
                return true;
            }
        }
        return false;
    }

    static long binary_search(int N, int M, long[] beer){
        long answer = 0;
        long start = 1;
        long end = beer[N - 1];

        while(start <= end){
            long mid = (start + end) / 2;
            if (check(mid, beer, N, M, answer)){
                answer = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return answer;
    }

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer str = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(str.nextToken());
        int M = Integer.parseInt(str.nextToken());
        long[] beer = new long[N];

        for(int i = 0; i < N; i++){
            beer[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(beer);
        System.out.println(binary_search(N, M, beer));
    }
}
