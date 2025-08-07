import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        int num1 = 0;
        int num2 = 0;
        for(int i = 1; i <= count; i++){
            StringTokenizer str = new StringTokenizer(br.readLine());
            num1 = Integer.parseInt(str.nextToken());
            num2 = Integer.parseInt(str.nextToken());
            System.out.println("Case #" + i + ": " + num1 + " + " + num2 + " = " + (num1 + num2));
        }
    }
}