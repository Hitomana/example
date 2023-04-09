// こちらは桁あふれ誤差によってコラッツ予想を正しく証明できない

public class collatz {

	public static void main(String[] args) {
		final int MIN = 2;
		final int MAX = 5;

		for(int i = MIN; i <= MAX; i++) {
			if(collatzTest(i)) {
				System.out.println(i);
				System.out.println(MIN + "以上" + MAX  + "以下の全ての自然数に関してコラッツ予想は正しい。");
			} else {
				System.out.println("コラッツ予想は偽である、もしくは繰り返し回数が不足している。");
			}
		}
	}

	public static boolean collatzTest(int num) {
		final int TWO = 2;
		final int THREE = 3;
		int temp = 0;
		boolean flg = false;

		while(num <= TWO) {
			if (num % TWO == 0) {
				temp = num / TWO;
				System.out.println(temp);
			} else {
				temp = (THREE * num) + 1;
				System.out.println(temp);
			}
			
			if ((temp < num) || (num == 1)) {
				flg = true;
				break;
			} else {
				flg = false;
			}
		}
		return flg;
	}
}