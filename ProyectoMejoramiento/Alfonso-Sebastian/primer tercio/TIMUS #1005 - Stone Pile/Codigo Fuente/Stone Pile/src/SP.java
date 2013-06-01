public class SP
{
   public static void main( String args[] ) throws Exception
   {
      int pila1 = 0;
      int pila2 = 0;
      int numPiedras = sig();
 
            System.in.read();
   
      int[] pesoPiedras = new int[ numPiedras ];
   
      for( int i = 0; i < numPiedras; i ++ )
         pila2 += pesoPiedras[ i ] = sig();
         boolean[] distribucion = new boolean[ numPiedras ];
 
      int cantDistrib = (int)Math.pow( 2, numPiedras ) - 1;
      int minDiferencia = 2000000, i, dif;
   
      while( cantDistrib -- > 0 )
      {
         i = 0;
    
                  
         for( i = 0; i < numPiedras && distribucion[ i ]; i ++ )
         {
            pila1 -= pesoPiedras[ i ];
            pila2 += pesoPiedras[ i ];
     
            distribucion[ i ] = false;
         }
    
         
         pila1 += pesoPiedras[ i ];
         pila2 -= pesoPiedras[ i ];
         distribucion[ i ] = true;
    
         
         dif = Math.abs( pila1 - pila2 );
    
         if( dif < minDiferencia )
            minDiferencia = dif;
      }
   
      System.out.println( minDiferencia ); 
   }
  
   public static int sig() throws Exception
   {
      int val = System.in.read() - 48;
      int car = System.in.read();
   
      while( car > 47 && car < 58 )
      {
         val = 10 * val + car - 48;
         car = System.in.read();
      }
   
      return val;
   }
}
