#!/usr/bin/gnuplot --persist ARG1 ARG2 ARG3
# BEFORE EXECUTE DO FIRST: 'chmod +x ./script/${dataname}_plot.gnu' 
# EXECUTE AS: 'gnuplot -c ./script/${dataname}_plot.gnu ./output/${dataname}.dat ./output/${dataname}_histogram.png'
reset # INIT
set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 3000, 2000
set output ARG1
set boxwidth 0.9 absolute
set style fill   solid 1.00 border lt -1
set key fixed right top vertical Right noreverse noenhanced autotitle nobox
set style histogram clustered gap 1 title textcolor lt -1
unset parametric
set datafile missing '-'
set style data histograms
set xtics border in scale 0,0 nomirror rotate by -45 autojustify
set xtics  norangelimit 
set xtics   ()
set title "Occurance of Addresses by Range" 
set xrange [ * : * ] noreverse writeback
set yrange [ 0 : ARG3 ] noreverse writeback
set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front  noinvert bdefault
NO_ANIMATION = 1
plot ARG2 using 2:xtic(1) ti col