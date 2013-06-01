import java.io.BufferedReader;
import java.io.InputStreamReader;

//uva code 10408 

class Main {

	static int MAXFRACCIONES = 1000000;

	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String linea;
		try {
			while(!(linea=br.readLine()).equals("")){
				Fraccion fracciones[] = new Fraccion[MAXFRACCIONES];
				String lineas[] = linea.split(" ");
				int n,k,numeroFracciones=0;
				n = Integer.parseInt(lineas[0]);
				k = Integer.parseInt(lineas[1]);
				for(int i=1;i<=n;i++){
					boolean termino=false;
					for(int j=i+1;j<=n && !termino;j++){
						if(i<j){
							Fraccion fraccion=new Fraccion(i,j);
							Fraccion antiguaFraccion = new Fraccion(i,j);
							if(i==1 || ((Fraccion.Simplificar(fraccion)).equals(antiguaFraccion))){
								fracciones[numeroFracciones]=fraccion;
								numeroFracciones++;
							}
						}else
							termino=true;
					}
				}
				fracciones[numeroFracciones]=new Fraccion(1,1);
				numeroFracciones++;
				mergeSort(fracciones,numeroFracciones);
				System.out.println(fracciones[k-1].getNumerador()+"/"+fracciones[k-1].getDenominador());
			}
		}catch (Exception e) {
			e.printStackTrace();
		}
	}

	static void mergeSort( Fraccion a[ ],int tamanoArreglo){
		Fraccion tmpArray[] = new Fraccion[tamanoArreglo];

		mergeSort( a, tmpArray, 0, tamanoArreglo - 1 );
	}
	static void mergeSort( Fraccion a[ ], Fraccion tmpArray[],int left, int right ){
		if( left < right )
		{
			int center = ( left + right ) / 2;
			mergeSort( a, tmpArray, left, center );
			mergeSort( a, tmpArray, center + 1, right );
			merge( a, tmpArray, left, center + 1, right );
		}
	}

	static void merge( Fraccion a[ ],Fraccion tmpArray[],int leftPos, int rightPos, int rightEnd){
		int leftEnd = rightPos - 1;
		int tmpPos = leftPos;
		int numElements = rightEnd - leftPos + 1;

		while( leftPos <= leftEnd && rightPos <= rightEnd ){
			if( a[leftPos].getfraccion()<( a[rightPos].getfraccion() ) ){
				tmpArray[tmpPos++] = a[leftPos++];
			}
			else{
				tmpArray[tmpPos++] = a[rightPos++];
			}
		}
		while( leftPos <= leftEnd ){
			tmpArray[tmpPos++] = a[leftPos++];
		}
		while( rightPos <= rightEnd ){
			tmpArray[tmpPos++] = a[rightPos++];
		}
		for( int i = 0; i < numElements; i++, rightEnd-- ){
			a[rightEnd] = tmpArray[rightEnd];
		}
	}
}

class Fraccion{
	int numerador;
	int denominador;

	Fraccion(int num,int den){
		numerador=num;
		denominador=den;
	}

	double getfraccion(){
		double respuesta = ((double)numerador/(double)denominador);
		return respuesta;
	}

	int getNumerador(){
		return numerador;
	}

	int getDenominador(){
		return denominador;
	}
	
	boolean equals (Fraccion fraccion){
		return (numerador==fraccion.getNumerador() && denominador==fraccion.getDenominador());
	}
	
	 static Fraccion swap(Fraccion s){
		
		     Fraccion c = new Fraccion(0,0);
		 
		    c.setNumerador(s.getNumerador());
		    s.setNumerador(s.getDenominador());
		    s.setDenominador(c.getNumerador());
		
		     return s;
		 
		     }
	
	 int[] swap(int a, int b){
		 
		 int[] d = new int[2];
		 
		 int c;
		 
		 c=a;
		 a=b;
		 b=c;
		 
		 d[0]=a; d[1]=b;
		 
		 return d;
		 
		 }		
		 
		     /* Metodo que devuelve el MCD de n y m  */
		 
		     static int Euclides(Fraccion aux){
		 
		         Fraccion e = new Fraccion(aux.getNumerador(), aux.getDenominador());
		 
		if(e.getNumerador()<0)
		e.setNumerador(Math.abs(e.getNumerador()));
		
		if(e.getNumerador() < e.getDenominador())
		swap(e);
		
		while (e.getDenominador()!=0) {
		e.setNumerador(e.getNumerador() % e.getDenominador());
		swap(e);
		}
		
		return e.getNumerador();
		
		}
		
		void setNumerador(int num) {
				numerador=num;
			}
		
		void setDenominador(int den) {
			denominador=den;
		}

		static public Fraccion Simplificar(Fraccion s){
		
		int MCD;
		
		if(s.getDenominador()<0){
		
		s.setNumerador((-1)*(s.getNumerador()));
		s.setDenominador((-1)*(s.getDenominador()));
		
		}
		
		if(s.getNumerador()!=0){
		
		MCD = Euclides(s);
		s.setNumerador(s.getNumerador()/MCD);
		s.setDenominador(s.getDenominador()/MCD);
		
		
		}
		else
		s.setDenominador(1);
				
		return s;
		     }
}