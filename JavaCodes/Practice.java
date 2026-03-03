import java.util.Scanner;
/*
public class Practice {
public static void main(String args[]){
Scanner sc = new Scanner(System.in);
System.out.print("Enter a number : ");
int n = sc.nextInt();
for(int i = 1; i <= 10; i++){
System.out.println(n + " X " + i + " = " + n * i);
}
sc.close();
}
}
*/

/*
public class Practice {
public static void main(String args[]){
for(int i = 5; i > 0; i--){
for(int j = 0; j < i; j++){
System.out.print("* ");
}
System.out.println();
}
}
}
*/

/*
public class Practice {
public static void main(String args[]){
Scanner sc = new Scanner(System.in);
String a = sc.nextLine();
String b = sc.nextLine();
String res = Integer.toBinaryString(Integer.parseInt(a, 2) + Integer.parseInt(b, 2));
System.out.println(res);
}
}
*/

/*
public class Practice {
public static void main(String args[]){
String s = "Hello World";
char ch[] = s.toCharArray();
for(int i = s.length() - 1; i >= 0; i--){
System.out.print(ch[i]);
}
}
}
*/

/*
public class Practice {
public static void main(String args[]){
Scanner sc = new Scanner(System.in);
String str = sc.nextLine();

int letterC = 0, numC = 0, spaceC = 0, otherC = 0;

for(int i = 0; i < str.length(); i++){
char ch = str.charAt(i);
if((ch >= 'a' && ch <= 'z') | (ch >= 'A' && ch <= 'Z')) letterC++;
else if(ch >= '0' && ch <= '9') numC++;
else if(ch == ' ') spaceC++;
else otherC++;
}

System.out.println("Letter Count " + letterC);
System.out.println("Number Count " + numC);
System.out.println("Space Count " + spaceC);
System.out.println("Other Count " + otherC);

}
}
*/

public class Practice {
    public static void main(String args[]) {
        String str = "racecar";
        int start = 0, end = str.length() - 1;
        boolean isPalindrome = true;

        char ch[] = str.toCharArray();

        while (start < end && isPalindrome) {
            if (ch[start] != ch[end])
                isPalindrome = false;
            start++;
            end--;
        }

        System.out.println("The given string is "
                + (isPalindrome ? "" : "not ")
                + "a Palindrome");
    }
}




 




