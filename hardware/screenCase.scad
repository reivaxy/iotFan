
include <../../iotinator/hardware/oledPanel.scad>;


x = 45;
y = 45;
z = 5;

topOffset = 0;


screenCase();

// uncomment below to see screen model in position
// translate([(x - screenX)/2, (y - screenY)/2 + topOffset, 2])
//   screen();

module screenCase() {
  difference() {
    cube([x, y, z]);
    translate([1, 1, -0.1]) {
      cube([x-2, y-2, z+1]);
    }
  }
  windowPanel(x, y, 1.5, topOffset);
  screwBase(1,1, 7);
  screwBase(x - 8, y - 8, 7);
}

module screwBase(x, y, side) {
  translate([x, y, 0]) {
    difference() {
      cube([side, side, z]);
      translate([side/2, side/2, 1])
        cylinder(d=2, h = 10, $fn=20);
    }
    
  }
  
}
