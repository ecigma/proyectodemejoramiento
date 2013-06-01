import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Main {

	public static void main(String[] args){
		try{
		new Main().go();
		}catch(Exception e){
			
		}
	 }
	private void go() throws IOException{
	  
		int n,a,b,i=1;
	    int resultado;
	    
	    InputStreamReader isr = new InputStreamReader(System.in);
	    BufferedReader bf = new BufferedReader (isr);
	    String lineaTeclado = bf.readLine();
	    
	    n=Integer.parseInt(lineaTeclado);
	    
	    while(i<=n){
	        resultado=0;
	        lineaTeclado = bf.readLine();
	        a=Integer.parseInt(lineaTeclado);
	    	lineaTeclado = bf.readLine();
	    	b=Integer.parseInt(lineaTeclado);
	        if(a%2==0){
	            a+=1;
	        }
	        if(b%2==0){
	            b-=1;
	        }
	        for(int j=a;j<=b;j+=2){
	            resultado+=j;
	        }
	        System.out.println("Case "+i+": "+resultado);
	        i++;
	    }
		
		
	}
}
