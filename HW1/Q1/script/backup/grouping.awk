#!/usr/bin/awk
# Common awk script for both cc1.din and spice.din
# Grouping data by deginated ranges from the previous execution(collect.awk)
# Not used for HW1
BEGIN{
    mix = 0;
    max = 0;
    gap = 0;
    total = 0;
    sum = 0;
    l_range = 0;
    r_range = 0;
    print "ADDRESS OCCURENCE";
}
{
    if(match($1,"[0-9]+")) {  # Numberic
        if($1 >= l_range && $1 < r_range){
            sum+= $2;
        }
        else{   # New range needed
            arr[r_range] = sum;
            printf "%d-%d %d \n", l_range, r_range, arr[r_range]; # Record
            l_range = r_range; # Set new left boundary
            r_range += gap; # Set new ringht boundary
            sum = $2; # Initial as current r_range
            arr[r_range] = sum; # In case of single address
        }
    }
    else{
        # Non Numberic
        if($1 == "min") {
            l_range = min = $2;
        }
        else if($1 == "max") max = $2;
        else if($1 == "gap") {
            gap = $2;
            r_range = min + gap; # set initial range end
        }
        else total = $2;
    }
}
END{}