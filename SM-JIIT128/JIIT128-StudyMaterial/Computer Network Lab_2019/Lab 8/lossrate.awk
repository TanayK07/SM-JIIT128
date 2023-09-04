BEGIN {
# Initialization. Set two variables. fsDrops: packets drop. numFs: packets sent
        fsDrops = 0;
        numFs = 0;
        bits=0;
        ratio1 = 0.0;
	LossRate=0.0;
        measure_interval = 0.10;
        first_time = 0;
}

{
   action = $1;
   time = $2;
   from = $3;
   to = $4;
   type = $5;
   pktsize = $6;
   flow_id = $8;
   src = $9;
   dst = $10;
   seq_no = $11;
   packet_id = $12;
#here the 20 and 21 node act as a router where the packet is lodt due to the algorithm established on it.
   if ((from==20) && (to==21) && (type=="cbr" || type=="tcp") && action == "+")
        numFs++;

   if (( from==20 && to==21) &&(action == "d"))
     {
     fsDrops++;
     if ((time - first_time) > measure_interval) {
         first_time = first_time + measure_interval;
         LossRate = (bits1/1000000)/first_time;
         ratio1 = 100*fsDrops/numFs;
         printf("%f %f %f\n",first_time, LossRate);
      }
      bits1 = bits1 + $6 * 8;
        
   }

 }
END {
        measure_interval = 0.10;
        first_time = first_time + measure_interval;        
        ratio1 = 100*fsDrops/numFs;
	LossRate=(bits1/1000000)/first_time;
          
  printf("%f %f %f\n",first_time,LossRate);  
}



