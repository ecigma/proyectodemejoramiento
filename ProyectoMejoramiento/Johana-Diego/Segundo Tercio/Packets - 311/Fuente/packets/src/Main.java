import java.io.BufferedReader;
import java.io.InputStreamReader;

// uva code 311

class Main {
	
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Candidatos c = new Candidatos();
		String linea;
		int respuesta;
		try {
			while(!(linea=br.readLine()).equals("0 0 0 0 0 0"))
			{
				c.agregueParselas(linea);
				respuesta=voraz(c);
				System.out.println(respuesta);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static int voraz(Candidatos c) {
		int contadorParcelas=1,x=0;
		Parcela m= new Parcela();
		while(!objetivo(c)){
			x=seleccionePaquete(c,m);
			if(x==-1){
				contadorParcelas+=1;
				m = new Parcela();
			}else{
				c.eliminarCandidato(x);
				m.agregeParcela(x);
			}
			int prueba[]=c.getParselas();

		}
		return contadorParcelas;
	}

	static int seleccionePaquete(Candidatos c, Parcela m){
		int respuesta=0,espacioDisponible=0;
		espacioDisponible=m.demePaqueteMaximo();
		respuesta=c.demeCandidatosMaximo(espacioDisponible);
		return respuesta;
	}

	static boolean objetivo(Candidatos c) {
		int parselas[] = c.getParselas();
		boolean esObjetivo=true;
		for(int i=0;i<parselas.length && esObjetivo;i++){
			if(parselas[i]!=0)
				esObjetivo=false;
		}
		return esObjetivo;
	}
}

class Candidatos {
	
	int parcelas[];
	
	Candidatos() {
		parcelas = new int [6];
		for(int i=0;i<parcelas.length;i++)
			parcelas[i]=0;
	}
	
	void agregueParselas(String parselas){
		String parselasNuevas[] = parselas.split(" ");
		for(int i=0;i<parselasNuevas.length;i++){
			this.parcelas[i]+=Integer.parseInt(parselasNuevas[i]);
		}
	}
	
	int demeCandidatosMaximo(int maximoEspacio){
		int respuesta = -1;
		boolean loEncontro=false;
		for(int i=maximoEspacio-1;i>=0 && !loEncontro;i--){
			if(parcelas[i]!=0){
				respuesta=i+1;
				loEncontro=true;
			}				
		}
		return respuesta;
	}
	
	void eliminarCandidato(int candidato){
		parcelas[candidato-1]-=1;
	}

	int[] getParselas() {
		return parcelas;
	}

}

class Parcela {
	int paquetes1x1;
	int paquetes2x2;
	int paquetes3x3;
	int paquetes4x4;
	int paquetes5x5;
	int paquetes6x6;
	Parcela() {

		paquetes1x1 = 36;
		paquetes2x2 = 9;
		paquetes3x3 = 4;
		paquetes4x4 = 1;
		paquetes5x5 = 1;
		paquetes6x6 = 1;
	}
	
	int demePaqueteMaximo(){
		int paqueteMaximo;
		if(paquetes6x6!=0)
			paqueteMaximo=6;
		else if(paquetes5x5!=0)
			paqueteMaximo=5;
		else if(paquetes4x4!=0)
			paqueteMaximo=4;
		else if(paquetes3x3!=0)
			paqueteMaximo=3;
		else if(paquetes2x2!=0)
			paqueteMaximo=2;
		else if(paquetes1x1!=0)
			paqueteMaximo=1;
		else paqueteMaximo=-1;
		return paqueteMaximo;
	}
	
	void agregeParcela(int parcela){
		switch(parcela){
		case 1: paquetes6x6=0;
				paquetes5x5=0;
				paquetes4x4=0;
				paquetes3x3=0;
				paquetes2x2=0;
				paquetes1x1-=1;
				break;
		case 2: paquetes6x6=0;
				paquetes5x5=0;
				paquetes4x4=0;
				paquetes3x3=0;
				paquetes2x2-=1;
				paquetes1x1-=4;
				break;
		case 3: paquetes6x6=0;
				paquetes5x5=0;
				paquetes4x4=0;
				paquetes3x3-=1;
				if(paquetes3x3!=0)
					paquetes2x2=((paquetes3x3*9)-(4+paquetes3x3))/4;
				else
					paquetes2x2=0;
				paquetes1x1-=9;
				break;
		case 4: paquetes6x6=0;
				paquetes5x5=0;
				paquetes4x4=0;
				paquetes3x3=0;
				paquetes2x2=5;
				paquetes1x1=20;
				break;
		case 5: paquetes6x6=0;
				paquetes5x5=0;
				paquetes4x4=0;
				paquetes3x3=0;
				paquetes2x2=0;
				paquetes1x1-=25;
				break;
		case 6: paquetes6x6=0;
				paquetes5x5=0;
				paquetes4x4=0;
				paquetes3x3=0;
				paquetes2x2=0;
				paquetes1x1=0;
				break;
		}
	}
}

