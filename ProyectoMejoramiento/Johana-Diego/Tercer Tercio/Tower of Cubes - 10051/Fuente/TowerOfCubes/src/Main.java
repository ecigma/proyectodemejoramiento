import java.io.BufferedReader;
import java.io.InputStreamReader;


class Main {
	
	static int MAXCUBOS= 505;
	static int MAXCOLORES = 105;
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int casos=1,numeroCubos,cubos[][],tamanoTorres[][],matrizIncidencia[][],conexionesCaras[][];
		String lineas[];
		try {
			while((numeroCubos=Integer.parseInt(br.readLine()))!=0){
				cubos = new int[MAXCUBOS][11];
				tamanoTorres = new int[MAXCUBOS][MAXCOLORES];
				conexionesCaras = new int[MAXCUBOS][MAXCOLORES];
				matrizIncidencia = new int[MAXCUBOS][MAXCOLORES];
				for(int i=0;i<numeroCubos;i++){
					lineas=br.readLine().split(" ");
					for(int j=0;j<6;j++)
						cubos[i+1][j+1]=Integer.parseInt(lineas[j]);
				}
				for (int i = numeroCubos; i >= 1; i--)
					for (int j = 1; j <= 100; j++){
						tamanoTorres[i][j]=tamanoTorres[i+1][j];
						for(int k=1;k<=6;k++){//                             cuidado aqui
							if (j == cubos[i][k] && tamanoTorres[i+1][cubos[i][(k%2==1)? k+1 : k-1]]+1 > tamanoTorres[i][j]){
								tamanoTorres[i][j] = tamanoTorres[i+1][cubos[i][(k%2==1) ? k+1 : k-1]]+1;
		                        matrizIncidencia[i][j] = 1;
		                        conexionesCaras[i][j] = k;
							}
						}
					}
					
					
						        
		        int maximaTorre=0,columna = 0,cara;
		        for(int i=0;i<=100;i++)
		        	if(tamanoTorres[1][i]>maximaTorre){
		        		maximaTorre=tamanoTorres[1][i];
		        		columna=i;
		        	}
		        System.out.println("Case #"+casos);
		        System.out.println(maximaTorre);
		        for(int i=1;i<=numeroCubos;i++)
		        	if(matrizIncidencia[i][columna]==1){
		        		cara=conexionesCaras[i][columna];
		        		System.out.println(i+" "+getCara(cara));
		        		columna = cubos[i][(cara%2==1)?cara+1:cara-1];
		        	}
		        System.out.println();
		        casos++;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static String getCara(int cara){
		String respuesta=null;
		switch(cara){
		case 1:respuesta = "front";break;
		case 2:respuesta = "back";break;
		case 3:respuesta = "left";break;
		case 4:respuesta = "right";break;
		case 5:respuesta = "top";break;
		case 6:respuesta = "bottom";break;
		};
		return respuesta;
	}
}
