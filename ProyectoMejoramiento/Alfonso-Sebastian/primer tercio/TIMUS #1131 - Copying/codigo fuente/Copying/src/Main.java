import java.io.*;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) {
		try {
			new Main().go();
		} 
		catch (NumberFormatException e) {}
		catch (IOException e) {}
	}

	private void go() throws NumberFormatException, IOException {
		int N,K,computadorActivo=1,horas=0;
		StringTokenizer st;
		BufferedReader br=new  BufferedReader(new InputStreamReader(System.in));
		
		st=new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		K=Integer.parseInt(st.nextToken());
		
		while(true){
			if(computadorActivo<=K){
				computadorActivo*=2;
			}
			
			horas++;
			
			if ( computadorActivo >= N ){
	            break;
            }

	        if ( K < computadorActivo ){
	            horas += (int) Math.ceil((N - computadorActivo) / (double) K);
	            break;
	        }
			
		}
		
		System.out.println(horas);
	}

}
