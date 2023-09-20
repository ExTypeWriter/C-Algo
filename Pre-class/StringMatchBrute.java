import java.util.Scanner;
class StringMatchBrute {
    public static void main(String []args)
    {
      Scanner sc = new Scanner(System.in);
      System.out.print("Input original text (target is Jeff): ");
      String Text = sc.nextLine();
      String Target = "Jeff";
      int size_of_target = Target.length();
      for(int i = 0; i < Text.length(); i++)
      {
        if(Text.charAt(i) == Target.charAt(0) && i+3 < Text.length())
        {
            String chunk = Text.substring(i, i + size_of_target);
            if(chunk.equals(Target)){
              System.out.println("Found "+Target+" At index of "+(i+1)+" of original string");
              break;
            }
        }
      }
      sc.close();
    }
}
