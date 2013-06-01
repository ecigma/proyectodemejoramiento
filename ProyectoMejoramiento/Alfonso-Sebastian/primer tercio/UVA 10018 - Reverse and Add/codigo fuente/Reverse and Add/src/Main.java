import java.io.*;
class Main {
	public static void main(String[] args) {
		try {
			new Main().go();
		} catch (Exception e) {}
		
	}
	private void go() throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int casos;
		int sumas;
		long numero;
		
		casos=Integer.parseInt(br.readLine());
		for (int i = 0; i < casos; i++) {
			sumas=0;
			numero=Integer.parseInt(br.readLine());
			while(!esPalindrome(numero+"")){
				numero=numero+sumaReversa(numero);
				sumas++;
			}
			System.out.println(sumas+" "+numero);
		}
	}
	
	private long sumaReversa(long numero) {
		long reversa=0;
		int modulo;
		while(numero>0){
			 modulo = (int) (numero%10);
			reversa=reversa*10+modulo;
			numero=numero/10;
		}
		reversa+=numero;
		return reversa;
	}
	private boolean esPalindrome(String numero){
		boolean esPalindrome=true;
		for (int i = 0; i < numero.length()/2 && esPalindrome; i++) {
			if(numero.charAt(i)!=numero.charAt(numero.length()-1-i)){
				esPalindrome=false;
			}
		}
		return esPalindrome;		
	}

}
