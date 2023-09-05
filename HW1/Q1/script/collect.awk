#!/usr/bin/awk
# Common awk script for both cc1.din and spice.din
# Collect Occurence of each address from the data and record their information
BEGIN{
    sum = 0;
    cur = 0;
}
{
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
    print "ADDRESS OCCURENCE"
    for(i in arr) printf "%d %d\n", i , arr[i];
}