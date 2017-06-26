h:neg hopen `::5050
syms:`VOD`IBM`APL;

publishtrade:{[]
  nrow:first 1?1+til 4;
  h(".u.upd";`trade;(nrow#.z.T;nrow?syms;nrow?3?1.0*1+til 10;nrow?10*1+til 10));
 }; 

.z.ts:{[] 
  publishtrade[];
 }

\t 1000
