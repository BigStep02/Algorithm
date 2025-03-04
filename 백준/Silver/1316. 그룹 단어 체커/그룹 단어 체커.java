import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int result = 0;
        boolean bool;
        for(int i = 0; i < N; i++) {
            String word = br.readLine();
            char[] c = new char[word.length()];
            c = word.toCharArray();
            ArrayList<Character> wordcheck = new ArrayList<>();
            ArrayList<Character> list = new ArrayList<>();
            bool = true;
            for (int j = 0; j < word.length(); j++) {
                wordcheck.add(c[j]);
            }
            for (int j = 0; j < word.length(); j++) {
                if(j > 0) {
                    if (list.contains(wordcheck.get(j)) && wordcheck.get(j) != wordcheck.get(j - 1)) {
                        bool = false;
                        break;
                    }
                }
                list.add(c[j]);
            }
            if (bool) {
                result++;
            }
        }
        System.out.println(result);
    }
}