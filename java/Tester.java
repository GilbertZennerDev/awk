public class Tester
{
	public static void main(String[] args)
	{
		System.out.println("Tester active...");
		AWK awk = new AWK();
		awk.doAWK("-stdin", ".1");
		awk.doAWK("-txt", ".1");
		awk.doAWK("i o p", ".1");
	}
}
