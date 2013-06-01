import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


 class Main {

	public static void main(String[] args){
		String respuesta=null;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String linea, lineas[];
		try {
			linea = br.readLine();
				while(!linea.equals("")){
					String s,t;
					lineas=linea.split(" ");
					s=lineas[0];
					t=lineas[1];
					respuesta=voraz(s,t);
					System.out.println(respuesta);
					linea=br.readLine();
				}
		}catch (Exception e1) {
			e1.printStackTrace();
		}
	}

	public static String voraz(String s,String t) {
		String c="";
		char x;
		int i=0;
		for(int j=0;j<t.length();j++){
			if(i<s.length()){
				x=t.charAt(j);
				if((Character.toString(x)).equals(Character.toString(s.charAt(i)))){
					i++;
					c=c+Character.toString(x);
				}
			}
		}
		if(c.equals(s)){
			return "Yes";
		}
		else{
			return "No";
		}
	}
}
