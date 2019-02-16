h:hopen 5010
syms:`VOD`IBM`APL`AAPL`GOOGL

publishtrade:{[]
   nrow:first 1?1+til 4;
   h(".u.upd";`trade;(nrow#.z.N;nrow?syms;nrow?3?1.0*1+til 10;nrow?10*1+til 10))
 }

.z.ts:{[] 
  publishtrade[]
 }

\t 2000
