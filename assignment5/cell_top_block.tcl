#!/bin/sh
# tricking... the line after a these comments are interpreted as standard shell script \
exec $ESPRESSO_SOURCE/Espresso $0 $*1

set PI 3.14159

set visu 1

set teq 1000
set trun 10000

set Nrod 10
set Nperrod 5

set Nwallseg 10
set Lgap 3

set ywall 50

set L 100

setmd box_l 100 100 100
setmd periodic 1 1 1
setmd time_step 0.01
setmd skin 0.4

set eps 1.0
set sig 1.0
set rc [expr pow(2.0,1.0/6.0)*$sig]
set shi 0.25
set kap [expr 30.0*$eps/($sig*$sig)]
set lam [expr 1.5*$sig]

inter 0 0 lennard-jones $eps $sig $rc $shi 0.0
inter 0 fene $kap $lam
inter 7 angle 100 $PI

thermostat langevin 1.0 1.0

set npart 0
for { set i 0 } { $i < $Nrod } { incr i } {
   for { set xshift 0} { $xshift < 3 } { incr xshift } {
	   set x [expr ($i+$Nrod*$xshift)*3 + 1.0 ]
	   for { set j 0 } { $j < $Nperrod*($xshift + 1) } { incr j } {
		   set y [expr $j*$sig +1.0]
		   part $npart pos $x $y 0 type 0 fix 0 0 1 
		
		   if { $j > 0 } {
			   part $npart bond 0 [expr $npart - 1 ]
		   }
		   if { $j > 1 } {
			   part [expr $npart-1] bond 7 [expr $npart - 2 ] [expr $npart]
		   }
			
		incr npart
	   }
   }
}




set npartwall 0
set x 0 
set counter 0
while { $x < $L } {
	for { set i 0 } { $i < $Nwallseg } { incr i } {
		if { $x < $L} {
			part [expr $npart + $npartwall] pos $x $ywall 0 fix
         incr npartwall
         part [expr $npart + $npartwall] pos $x [expr $ywall - 10] 0 fix
			incr npartwall
			set x [expr $x + $sig]
         
		}
	}

	set x [expr $x + $Lgap]
   set ywall [expr $ywall + 2]
}

#boxes
set x 0 
set a 0 
while { $x < $L } {
   set x [expr $x + $Nwallseg]
   for { set y 0 } { $y < $Nwallseg } { incr y } {
    #  part [expr $npart + $npartwall] pos [expr $L - 1] [expr ($ywall - 2) - $y] 0 fix
      part [expr $npart + $npartwall] pos $x [expr ($ywall - 1.5*$Nwallseg + 2*$a) - $y] 0 fix
      incr npartwall
   }
   incr a
   set x [expr $x + $Lgap]
   #set x [expr $x + $Nwallseg + $Lgap]
}








if [expr $visu == 1] {
	prepare_vmd_connection nano 11000
	#exec sleep 3
	imd positions
	imd listen 500
}

for { set t 0 } { $t < $teq } { incr t } {
	integrate 100
	imd positions
}

for { set i 0 } { $i < $npart } { incr i } {
	part $i ext_force 0 0.5 0
}

for { set t 0 } { $t < $trun } { incr t } {
	integrate 100
	imd positions
}
