package collatz;

public class collatz {

	public static void main(String[] args) {
		final int MIN = 2;
		final int MAX = 200000;

		// int型からlong型に変更
		for(long i = MIN; i <= MAX; i++) {
			
			if(!collatzTest(i)) {
				System.out.println("コラッツ予想は正しくない。");
				return;
			}
		}
		System.out.println(MIN + "以上" + MAX  + "以下の全ての自然数に関してコラッツ予想は正しい。");
	}

	// int型からlong型に変更
	public static boolean collatzTest(long num) {
		final int TWO = 2;
		final int THREE = 3;
		boolean flg = false;
		long temp = 0;
		System.out.println(num + " について検証\r\n\r\n");
		
		while(num >= 2) {
			if (num % TWO == 0) {
				num /= TWO;
			} else {
				temp = num;
				num = (THREE * num) + 1;
				System.out.println("3 * " + temp + " + 1 = " + num + "\r\n\r\n");
			}
			
			if (num == 1) {
				flg = true;
				break;
			}
		}
		return flg;
	}
}
