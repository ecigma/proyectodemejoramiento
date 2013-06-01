import java.io.IOException;
import java.util.*;
public class FlipSort {
	
	public static int V[];
	/**
	 * Metodo principal
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		V = new int[100];
		int n, cont;
		n=System.in.read();
	    while(n!=0){
	        for (int i=0; i<n; i++){
	        	System.out.println( "entro : "+i);
	            V[i]=System.in.read();
	        }
	        cont= buscaCantidad(n);
	        System.out.println( "Minimum exchange operations : "+ cont);
	        n=System.in.read();
	    }

	}
	
	/*
	 * Busca la cantidad de movimientos que son necesarios para ordenar el vector
	 * @return cont, numero de movimientos en el vector
	 */
	public static int buscaCantidad(int n){
		int cont, aux;
	    cont=0;
	    for (int i=1; i<n; i++){
	         for (int j=0; j<n-1; j++){
	              if (V[j] > V[j+1]){
	                    aux = V[j];
	                    V[j] = V[j+1];
	                    V[j+1] = aux;
	                    cont++;
	              }
	         }
	     }
	    return cont;
	}
}
