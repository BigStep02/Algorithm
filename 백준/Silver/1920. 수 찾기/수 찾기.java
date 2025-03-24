import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer str = new StringTokenizer(br.readLine());
        HashSet<Integer> hash = new HashSet<>();
        for(int i = 0; i < n; i++){
            hash.add(Integer.parseInt(str.nextToken()));
        }
        int m = Integer.parseInt(br.readLine());
        str = new StringTokenizer(br.readLine());
        int result = 0;
        for(int i = 0; i < m; i++){
            result = Integer.parseInt(str.nextToken());
            if(hash.contains(result)){
                System.out.println(1);
            }
            else System.out.println(0);
        }
    }
}