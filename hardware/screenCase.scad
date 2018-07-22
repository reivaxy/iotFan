
include <../../iotinator/hardware/oledPanel.scad>;


x = 33;
y = 40;
z = 5.2;

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
  windowPanel(x, y, 0.9, topOffset);
  side = 5;
  screwBase(0, 0, side);
  screwBase(x - side, 0, side);
  screwBase(0, y - side, side);
  screwBase(x - side, y - side, side);
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
