#!/bin/bash
# 0: init
mkdir -p ./output
rm -rf ./output/*

# 1: cc1.din

## 1-1: Data conversion(Address: HEX->DECIMAL) then sort by ascedent 
awk '{printf "%d %d\n", $1, strtonum("0x"$2)}' ./input/${1}.din | sort -k2 -n >> ./output/${1}_sorted.din
## 1-2: Data collect by each address
awk -f ./script/collect.awk ./output/${1}_sorted.din | sort -k1 -n >> ./output/${1}_collected.din
## 1-3: Sampling 500 addresses
head -n 500  ./output/${1}_collected.din>> ./output/${1}.dat
## 1-4: Data plot(partial for 500 addresses)
chmod +x ./script/plot.gp
gnuplot -c ./script/plot.gp ./output/${1}_hist_partial.png ./output/${1}.dat $(sort -k2 -r -n ./output/${1}.dat | head -n 1 | awk '{print $2*1.1}')
## 1-5: Data source summary 
awk '{
        if($1==0)sum_w++; 
        else if($1==1) sum_r++; 
        else if($1==2) sum_ins++;
    } END { printf "write=%d, read=%d, instruction=%d, total=%d", sum_w, sum_r, sum_ins, sum_w+sum_r+sum_ins;}' ./input/${1}.din >> ./output/${1}_total.txt

# 2: spice.din

## 2-1: Data conversion(Address: HEX->DECIMAL) then sort by ascedent 
awk '{printf "%d %d\n", $1, strtonum("0x"$2)}' ./input/${2}.din | sort -k2 -n >> ./output/${2}_sorted.din
## 1-2: Data collect by each address
awk -f ./script/collect.awk ./output/${2}_sorted.din | sort -k1 -n >> ./output/${2}_collected.din
## 1-3: Sampling 500 addresses
head -n 500  ./output/${2}_collected.din >> ./output/${2}.dat
## 1-4: Data plot(partial for 500 addresses)
chmod +x ./script/plot.gp
gnuplot -c ./script/plot.gp ./output/${2}_hist_partial.png ./output/${2}.dat $(sort -k2 -r -n ./output/${2}.dat | head -n 1 | awk '{print $2*1.1}')
## 1-5: Data source summary 
awk '{
        if($1==0)sum_w++; 
        else if($1==1) sum_r++; 
        else if($1==2) sum_ins++;
    } END { printf "write=%d, read=%d, instruction=%d, total=%d", sum_w, sum_r, sum_ins, sum_w+sum_r+sum_ins;}' ./input/${2}.din >> ./output/${2}_total.txt

