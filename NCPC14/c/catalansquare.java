import java.math.BigInteger;
import java.util.Scanner;

public class catalansquare {
	final static int maxn = 10005;
	static BigInteger[] fact;
	public static BigInteger c(int n, int k) {
		BigInteger ret;
		ret = fact[n];
		ret = ret.divide(fact[n - k]);
		ret = ret.divide(fact[k]);
		return ret;
	}
	public static void calcFact() {
		fact = new BigInteger[maxn];
		fact[0] = fact[1] = BigInteger.ONE;
		for (int i = 2; i < maxn; i++) {
			BigInteger cur = new BigInteger(Integer.toString(i));
			fact[i] = cur.multiply(fact[i - 1]);
		}
	}
	public static void main(String[] args) {
		calcFact();
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		BigInteger n = new BigInteger(Integer.toString(in));
		BigInteger ans = c(2 * (in + 1), in + 1);
		ans = ans.divide(new BigInteger(Integer.toString(in + 2)));
		System.out.println(ans);
	}
}
