import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Main {
	static char entrada[];
	static boolean verificacion;
	static int numero;
/**
* @param args
*/
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String linea;
		int caso = 1;
		try {
			while(!(linea=br.readLine()).equals(""))
			{
				int numeroIntervalos;
				String intervalo[];
				char numeros[]=linea.toCharArray();
				numeroIntervalos=Integer.parseInt(br.readLine());
				System.out.println("Case "+caso+":");
				for(int i=0;i<numeroIntervalos;i++)
				{
					int min,max;
					intervalo=br.readLine().split(" ");
					min=Integer.parseInt(intervalo[0]);
					max=Integer.parseInt(intervalo[1]);
					String respuesta = solucion(numeros, min, max);
					System.out.println(respuesta);
				}
				caso++;
			}
		} catch (Exception e) {
				e.printStackTrace();
		  }
	}
	
	static String solucion(char binario[], int min, int max) {
		if(max<min){
			int aux = min;
			min = max;
			max = aux;
		}
		char arreglo[]=new char[(max-min)+1];
		int j=0;
		for(int i=min; i<=max; i++){
			arreglo[j] = binario[i];
			j++;
		}
		divide(arreglo);
		if(verificacion) return "Yes";
		else return "No";
	}

	static void divide(char arreglo[]){
		entrada = arreglo;
		numero = arreglo.length;
		verificacion = true;
		mergesort(0,numero-1);
	}

	static void mergesort(int min, int max){
		if(min < max){
			int mitad = min + (max-min) / 2;
			mergesort(min,mitad);
			mergesort(mitad+1,max);
			merge(min,mitad,max);
		}
	}

	static void merge(int min , int mitad, int max){
		if(verificacion){
			for(int i=min; i<=mitad; i++){
				for(int j=max; j>=mitad; j--){
					if(!(entrada[i] == entrada[j])){
						verificacion=false;
					}
				}
			}
		}
	}
}