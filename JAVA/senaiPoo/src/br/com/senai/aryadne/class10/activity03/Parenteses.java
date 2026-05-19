/*3- PILHA: Escreva um programa para verificar se uma 
 * expressão matemática tem os parenteses agrupados de 
 * forma correta.
Ex.:
((A + B) - INCORRETO
A+B( - INCORRETO
)A + B(-C - INCORRETO
(A+B))-(C+D - INCORRETO
((A + B)+D) - CORRETA
*/

package br.com.senai.aryadne.class10.activity03;

import java.util.Map;
import java.util.Stack;

public class Parenteses {

	public static boolean ehValida(String s) {
		Stack<Character> stack = new Stack<>();
		for (char c : s.toCharArray() ) {
			if (c == '(') {
				stack.push(c);
			} else if (c == ')') {
				if (stack.isEmpty()) return false;
				stack.pop();
			}
		}
		return stack.isEmpty();
	}

	public static void main(String[] args) {
			Parenteses p = new Parenteses();
			String expressao = "((A + B)+D)";
			
			if (ehValida(expressao)) {
				System.out.println("CORRETA");
			} else {
				System.out.println("INCORRETA");
			}
	}
}