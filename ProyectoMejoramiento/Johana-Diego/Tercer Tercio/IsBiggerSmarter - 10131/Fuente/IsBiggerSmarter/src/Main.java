import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Hashtable;

class Main{

	/**
	 * @param args
	 */
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Hashtable elefantes = new Hashtable();
		int key=1;
		try{
			String linea=br.readLine();
			while(!linea.equals("")){
				String lineas[] = linea.split(" ");
				Elefante elefante = new Elefante(Integer.parseInt(lineas[0]),Integer.parseInt(lineas[1]));
				elefantes.put(key,elefante);
				key++;
				linea = br.readLine();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		ArrayList elefOrdenados = ordeneElefantes(elefantes);
		int caminos[][] = crearCaminos(elefOrdenados,elefantes);
		imprimaCamino(caminos);
	}

	static void imprimaCamino(int[][] caminos) {
		int max=0,columna=0;
		for(int i=0; i<caminos.length-1;i++){
			if(caminos[0][i]>max){
				max=caminos[0][i];
				columna=i;
			}
		}
		System.out.println(max);
		for(int i=max;i>0;i--){
			System.out.println(caminos[i][columna]);
		}
	}

	static int[][] crearCaminos(ArrayList elefOrdenados,Hashtable elefantes) {
		int caminos[][]=new int [elefOrdenados.size()+1][elefOrdenados.size()];
		int max,columnaNumero;
		for(int i=0;i<elefOrdenados.size();i++){
			max=0;
			columnaNumero=0;
			for(int j=0;j<i;j++){
				if(((Elefante)elefantes.get(elefOrdenados.get(j))).getPeso() < ((Elefante)elefantes.get(elefOrdenados.get(i))).getPeso()){
					if(caminos[0][j]>max){
						max=caminos[0][j];
						columnaNumero=j;
					}
				}
			}
			caminos[0][i]=1+max;
			caminos[1][i]=((Integer)elefOrdenados.get(i));
			for(int j=2;j<max+2;j++){
				caminos[j][i]=caminos[j-1][columnaNumero];
			}
		}
		return caminos;
	}

	 static ArrayList ordeneElefantes(Hashtable elefantes){
		ArrayList ordenados = new ArrayList();
		boolean loEncontro;
		ordenados.add(1);
		for(int i=2;i<elefantes.size()+1;i++){
			loEncontro = false;
			for(int j=0;j<ordenados.size() && !loEncontro;j++){
				if(((Elefante)elefantes.get(i)).getIQ() > ((Elefante)elefantes.get(ordenados.get(j))).getIQ()){
					ordenados.add(j,i);
					loEncontro=true;
				}
			}
			if(!loEncontro){
				ordenados.add(i);
			}
		}
		return ordenados;
	}
}

class Elefante{
	
	 int peso;
	 int iQ;
	
	 Elefante(int peso, int iQ) {
		this.peso = peso;
		this.iQ = iQ;
	}
	
	 int getPeso() {
		return peso;
	}
	 void setPeso(int peso) {
		this.peso = peso;
	}
	 int getIQ() {
		return iQ;
	}
	 void setIQ(int iQ) {
		this.iQ = iQ;
	}
}
