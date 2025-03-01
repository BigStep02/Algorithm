import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer str = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(str.nextToken());
        int m = Integer.parseInt(str.nextToken());
        HashMap<String, Integer> word1 = new HashMap<>();
        for(int i = 0; i < n; i++){
            word1.put(br.readLine(), 0);
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            if(word1.containsKey(br.readLine())) count++;
        }
        System.out.println(count);
    }
}