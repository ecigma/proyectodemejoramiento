import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;


class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String linea;
		BigInteger p,k = new BigInteger("0");
		int n = 0,i;
		try {
			while((linea=br.readLine()).length()!=0){
				n=Integer.parseInt(linea);
				p = new BigInteger(br.readLine());
				for(i=0;p.compareTo(k)!=0;i++){
					k=potencia(i,n);
				}
				System.out.println(i-1);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static BigInteger potencia(int base, int exponente) {
		BigInteger respuesta;
		if(exponente==0)
			respuesta=new BigInteger(String.valueOf(1));
		else if(exponente%2==0)
			respuesta=potencia(base,exponente/2).multiply(potencia(base,exponente/2));
		else
			respuesta=potencia(base,exponente-1).multiply(new BigInteger(String.valueOf(base)));
		return respuesta;
	}
}
