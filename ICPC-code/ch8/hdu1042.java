 //����һ��Main.java�ļ����� javac Main.java�����һ��Main.class�ļ���
//��Main.class��Ŀ¼ ִ�У�java Main
import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main{ 
public static void main(String[] args) { 
Scanner input = new Scanner(System.in); 
while(input.hasNext()) { 
int n = input.nextInt(); 
BigInteger ans = BigInteger.ONE; 
for(int i = 1; i <= n; i++) { 
ans = ans.multiply(BigInteger.valueOf(i)); 
} 
System.out.println(ans); 
} 
}
} 
