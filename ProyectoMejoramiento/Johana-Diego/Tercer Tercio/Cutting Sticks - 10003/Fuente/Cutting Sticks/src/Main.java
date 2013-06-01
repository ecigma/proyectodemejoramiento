
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// uva code 10003

class Main {
	static int MAXCOSTO = 900000000;
	static int COSTOS[][] = new int [100][100];
	static int CORTES[];
	static int TAMANO;
	static int NUMEROCORTES;

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			while((TAMANO = Integer.parseInt(br.readLine()))!=0){
				CORTES = new int[100];
				NUMEROCORTES = Integer.parseInt(br.readLine());
				String cortes[] = br.readLine().split(" ");
				for(int i=1;i<=NUMEROCORTES;i++){
					CORTES[i]=Integer.parseInt(cortes[i-1]);
				}
				CORTES[0]=0;
				CORTES[NUMEROCORTES+1]=TAMANO;
				reinicieCostos();
				System.out.println("The minimum cutting is "+minimo(0,NUMEROCORTES+1)+".");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static void reinicieCostos() {
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				COSTOS[i][j]=-1;
			}
		}
	}

	static int minimo(int inicio,int fin){
		if(COSTOS[inicio][fin]!=-1)
			return COSTOS[inicio][fin];
		COSTOS[inicio][fin]=MAXCOSTO;
		if(inicio+1>fin-1)
			return COSTOS[inicio][fin]=0;
		for(int i=inicio+1;i<=fin-1;i++){
			COSTOS[inicio][fin]=Math.min(COSTOS[inicio][fin],minimo(inicio,i)+minimo(i,fin)+CORTES[fin]-CORTES[inicio]);
		}
		return COSTOS[inicio][fin];
	}
}