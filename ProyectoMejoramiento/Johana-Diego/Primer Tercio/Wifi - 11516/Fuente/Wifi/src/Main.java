import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

// uva code 11516

public class Main {

	static int MAXDISTANCIA=1000000;
	static int cantidadRouter;
	static int cantidadCasas;
	static int casas[] = new int [100000];


	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int casosPrueba;
		try {
			casosPrueba = Integer.parseInt(br.readLine());
			for(int i=0;i<casosPrueba;i++){
				int limiteInferior=0,limiteSuperior=MAXDISTANCIA,mitad=0;
				String lineas[] = br.readLine().split(" ");
				cantidadRouter=Integer.parseInt(lineas[0]);
				cantidadCasas=Integer.parseInt(lineas[1]);
				for(int j=0;j<cantidadCasas;j++)
					casas[j]=Integer.parseInt(br.readLine());
				if(cantidadRouter>=cantidadCasas)
					System.out.println("0.0");
				else{
					Arrays.sort(casas,0,cantidadCasas);
					while(limiteSuperior-limiteInferior>1){
						mitad = (limiteInferior+limiteSuperior)/2;
						if(verificar(mitad*2))
							limiteSuperior=mitad;
						else
							limiteInferior=mitad;
					}

					limiteSuperior*=10;
					limiteInferior*=10;

					for(int j=0;j<cantidadCasas;j++)
						casas[j]*=10;
					while(limiteSuperior-limiteInferior>1){
						mitad = (limiteInferior+limiteSuperior)/2;
						if(verificar(mitad*2))
							limiteSuperior=mitad;
						else
							limiteInferior=mitad;
					}
					System.out.println((limiteSuperior/10)+"."+(limiteSuperior%10));
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	static boolean verificar (int mitad){
		int routerUtilizados =1,wifi=casas[0]+mitad;
		for(int i =0; i<cantidadCasas;i++)
			if(casas[i]>wifi){
				wifi=casas[i]+mitad;
				routerUtilizados++;
			}		
		return cantidadRouter>=routerUtilizados; 
	}

}
