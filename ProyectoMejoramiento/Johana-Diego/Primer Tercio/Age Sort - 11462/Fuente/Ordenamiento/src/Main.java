import java.util.Scanner;

//uva code 11462
 class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner br = new Scanner(System.in);
		int numeroAnos;
		while((numeroAnos=Integer.parseInt(br.nextLine()))!=0){
			String anos[]=br.nextLine().split(" ");
			Quicksort(anos,0,numeroAnos-1);
			for(int i=0;i<anos.length;i++)
				System.out.print(anos[i]+" ");
		}
	}

	static int colocar(String v[], int b, int t)
	   {
	       int i;
	       int pivote, valor_pivote;
	       int temp;
	    
	       pivote = b;
	       valor_pivote = Integer.parseInt(v[pivote]);
	       for (i=b+1; i<=t; i++){
	           if (Integer.parseInt(v[i]) < valor_pivote){
	                   pivote++;    
	                   temp=Integer.parseInt(v[i]);
	                   v[i]=v[pivote];
	                   v[pivote]=String.valueOf(temp);
	    
	           }
	       }
	       temp=Integer.parseInt(v[b]);
	       v[b]=v[pivote];
	       v[pivote]=String.valueOf(temp);
	       return pivote;
	   } 
	   
	   static void Quicksort(String v[], int b, int t)
	   {
	        int pivote;
	        if(b < t){
	           pivote=colocar(v, b, t);
	           Quicksort(v, b, pivote-1);
	           Quicksort(v, pivote+1, t);
	        }  
	   }
 }