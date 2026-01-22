import java.util.List;
import java.util.Scanner;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.nio.file.Files;

public class AWK
{
	public AWK(){}
	
	static private void print(String msg)
	{
		System.out.println(msg);
	}
	
	private String getInTxt(String input)
	{
		String content;
	
		if (input.charAt(0) == '-')
		{
			if (input.equals("-stdin"))
			{
				Scanner sc;
			
				content = new String("");	
				sc = new Scanner(System.in);
				content = sc.nextLine();
				sc.close();
				return (content);
			}
			else
			{
				try
				{
					Path filePath = Paths.get(input.substring(1));
					content = Files.readString(filePath);
					return (content);
				}
				catch(Exception e)
				{
					return ("ERROR File not found");
				}
			}
		}
		else
		{
			return (input);
		}
	}

	private boolean getTokens(List<String> tokens, String inTxt)
	{
		if (inTxt == null || inTxt.isEmpty()) {
		    return false;
		}

		// Example logic: splitting by whitespace
		String[] splitArray = inTxt.split("\\s+");
		for (String s : splitArray) {
		    tokens.add(s);
		}

		return !tokens.isEmpty();
	}

	private boolean getIndexes(List<Integer> tokenIndexes, String which_tokens, int tokensLength)
	{
		int		i;
		String	sub;

		if (which_tokens == null || which_tokens.isEmpty()) {
		    return false;
		}

		// Example logic: splitting by whitespace
		String[] splitArray = which_tokens.split("\\s+");
		for (String s : splitArray) {
			try{
			i = Integer.parseInt(s.substring(1)) - 1;//make .1 to .0
			if (i >= 0 && i < tokensLength)
			    tokenIndexes.add(i);
			}catch (Exception e)
			{continue;}
		}

		return !tokenIndexes.isEmpty();
	}
	
	private String getOutput(Integer[] tokenIndexes, String[] tokens)
	{
		int				i;
		StringBuilder	sb;
		String			output;

		i = -1;
		sb = new StringBuilder();
		while (++i < tokenIndexes.length)
			sb.append(tokens[tokenIndexes[i]]).append(" ");
		output = sb.toString();
		print(output);
		return (output);
	}
	
	public String doAWK(String input, String which_tokens)
	{
		String			output;
		String[]		tokens;
		Integer[]		tokenIndexes;
		List<String>	tokens_list;
		List<Integer>	tokenIndexes_list;

		tokens_list = new ArrayList<>();
		tokenIndexes_list = new ArrayList<>();
		if(!getTokens(tokens_list, getInTxt(input))) return "ERROR";
		tokens = tokens_list.toArray(new String[0]);
		getIndexes(tokenIndexes_list, which_tokens, tokens.length);
		tokenIndexes = tokenIndexes_list.toArray(new Integer[0]);
		return getOutput(tokenIndexes, tokens);
	}
	
	public static void main(String[] args)
	{
		AWK		awk;
		String	input;
		String	tokens;

		awk = new AWK();
		if (args.length < 2) {
			awk.doAWK("-stdin", ".1");
			awk.doAWK("-txt", ".1");
			awk.doAWK("i o p", ".1");
			print("Error: give Arguments Content Tokens.");
			return ;
		}
		input = args[0];
		tokens = args[1];

		awk.doAWK(input, tokens);
	}
}
