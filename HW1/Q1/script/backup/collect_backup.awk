#!/usr/bin/awk
# Common awk script for both cc1.din and spice.din
# Collect Occurence of each address from the data and record their information
# Not used for HW1
BEGIN{
    count = 0;
    sum = 0;
    mix = 0;
    max = 0;
    cur = 0;
    n_range = 1000; # Target number of sub-range;
}
{
    count++;
    if(min == 0) { # Initial assign
        min = $2;
    }

    if($2 > max) max = $2;

    if($2 == cur) sum++; # Add up
    else{ # End of the previous record
        if(cur > 0){
            arr[cur] = sum;
        }
        cur = $2;
        sum = 1; 
        arr[cur] = 1; # In case of single record
    }
}
END{
    # Assume a normal distribution: count/(max-min) = (records per unit range)
    # e.g. [cc1.din] 832477/(2147418288-17192) = approx. 0.000387667 record per unit range
    # Target gap: = (max-min)/n_range 
    # e.g. [cc1.din]  (2147418288-17192)/1000 = approx.   2147401  
    gap = int((max-min)/n_range);
    # Expected number of unit per range = gap*(count/(max-min))
    # e.g. [cc1.din] 2147401*0.000387667 = approx.  832
    printf "min %d \n", min;
    printf "max %d \n", max;
    printf "gap %d \n", gap;
    printf "total %d \n", count;
    for(i in arr) printf "%d %d\n", i , arr[i];
}