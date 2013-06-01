import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

// uva code 10020
class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String linea;
		ArrayList<String> intervalos;
		int casosPrueba;
		try {
			casosPrueba = Integer.parseInt(br.readLine());
			for(int i=0;i<casosPrueba;i++)
			{
				intervalos = new ArrayList<String>();
				br.readLine();
				ArrayList<String> solucion = new ArrayList<String>();
				int segmentoM = Integer.parseInt(br.readLine());
				while(!(linea = br.readLine()).equals("0 0"))
					intervalos.add(linea);
				solucion=voraz(segmentoM,intervalos);
				if(solucion.size()==0)
					System.out.println("0");
				else{
					System.out.println(objetivo(solucion));
					for(int j=0;j<solucion.size();j++)
						System.out.println(solucion.get(j));
				}
				if(i+1!=casosPrueba)System.out.println();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static ArrayList<String> voraz(int M,ArrayList<String> intervalos) {
		ArrayList<String> solucion=new ArrayList<String>();
		int conexion=0;
		boolean haySeleccion = true,haySolucion;
		while(!(haySolucion=solucion(solucion,M)) && haySeleccion){
			String nuevoElemento=seleccioneIntervalo(conexion,intervalos),numeros[];
			if(nuevoElemento!=null)
			{
				solucion.add(nuevoElemento);
				numeros=nuevoElemento.split(" ");
				conexion=Integer.parseInt(numeros[1]);
			}
			else{
				haySeleccion=false;
			}
		}
		if(!haySolucion)solucion = new ArrayList<String>();
		return solucion;
	}

	static String seleccioneIntervalo(int conexion, ArrayList<String> intervalos) {
		int posicion = -1,tamanoIntervalo=0;
		String solucion=null;
		for(int i=0;i<intervalos.size();i++){
			String lineas[]=intervalos.get(i).split(" ");
			int l=Integer.parseInt(lineas[0]),r=Integer.parseInt(lineas[1]);
			if(seEncuentraEnIntervalo(conexion,l,r) && r-conexion>tamanoIntervalo){
				posicion=i;
				tamanoIntervalo=r-conexion;
			}
		}
		if(posicion!=-1){
			solucion=intervalos.get(posicion);
			intervalos.remove(posicion);
		}
		return solucion;
	}

	static boolean solucion(ArrayList<String> solucion, int M) {
		int conexion=0;
		boolean hayErrores=true;
		String lineas[];
		if(solucion.size()!=0)
		{
			lineas=solucion.get(solucion.size()-1).split(" ");
			if(seEncuentraEnIntervalo(M,Integer.parseInt(lineas[0]),Integer.parseInt(lineas[1])))
				hayErrores=false;
			for(int i=0;i<solucion.size()&&!hayErrores;i++){
				lineas=solucion.get(i).split(" ");
				if(seEncuentraEnIntervalo(conexion,Integer.parseInt(lineas[0]),Integer.parseInt(lineas[1])))
					hayErrores=false;
				conexion=Integer.parseInt(lineas[1]);
			}
		}
		return !hayErrores;
	}

	static boolean seEncuentraEnIntervalo(int numero,int l, int r){
		return (l<=numero && numero<=r);	
	}

	static int objetivo(ArrayList<String> solucion) {
		return solucion.size();
	}

}