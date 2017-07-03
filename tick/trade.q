/* File name: trade.q */
/* File should be stored in the tick folder */
trade:([] 
  time:`timespan$(); 
  sym:`symbol$(); 
  price:`float$(); 
  size:`long$() 
 )
