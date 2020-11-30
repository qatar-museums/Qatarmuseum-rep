

/*

 TODO
 
 
 Add 'line'?
 Place individual objects and option to rotate / change size with shift / control?
 
 -------------------------------------------------------
 
 DONE 
 
  Option to under-paint / over paint (layers)
 
 Basic colors
 
 Odd reflections 1,2,3,4,5,6,7,8
 
 
 Change shape size
 Add scale for line width
 
 Experiment with giving each white line a thin black border
 
 Select two shapes
 Make shapes into a universal class, rather than shape-specific   
 
 Reflect the square on the other side
 And then in each quartile.
 No need for trig. Just invert axes.
 
 Click to take snapshot
 Bitmaps, for now:
 Click = take snapshot of canvas. Display it
 
 Add a Reset button
 Draw background overlay
 
 -------------------------------------------------------
 
 Deficiencies:
 
 No selection of shape once placed
 Overlaps don't mesh
 
 
 */



// Global vars
int screen_w = 975;
int screen_h = 650;
String mode = "none";
int stroke_width = 7;
float mouse_angle, dx, dy = 0;
Boolean outer_stroke_bool = false;
Boolean stroke_bool = false;
Boolean under_fill_on = true;

// Setup canvas
int canvas_x = 35;
int canvas_y = 100;
int canvas_size = 500;
int centre_x = canvas_x + (canvas_size / 2);
int centre_y = canvas_y + (canvas_size / 2);
PImage canvas_bg;
PGraphics pg;
int btn_diff = 32;

// Brand colors
color c1_blue = color(121, 170, 250);
color c2_orange = color(255, 194, 0);
color c3_yellow = color(250, 255, 30);
color c4_pink = color(237, 60, 138);
color c5_black = color(0, 0, 0);
color c6_white= color(255, 255, 255);

color off_color = color(70, 70, 70);
color bg_color = 0;
color stroke_color = c6_white;

color current_color = c5_black; 
String color_mode = "off";


// Initiate shapes
int max_reflections = 8;
int current_reflections = 8;
BasicShape[] rect_array = new BasicShape[ max_reflections ];
BasicShape[] circle_array = new BasicShape[ max_reflections ];
BasicShape[] triangle_array = new BasicShape[ max_reflections ];
BasicShape[] rhombus_array = new BasicShape[ max_reflections ];


// Initiate interface
int btn_x = 670;
standardButton reset_btn = new standardButton( btn_x, canvas_y + canvas_size- 30, 230, 30, "Reset canvas, set background colour", "none");

standardButton circle_btn = new standardButton( btn_x, canvas_y, 60, 60, "", "circle");
standardButton triangle_btn = new standardButton( btn_x + 70, canvas_y, 60, 60, "", "triangle");
standardButton rect_btn = new standardButton( btn_x + 140, canvas_y, 60, 60, "", "rect");
standardButton rhombus_btn = new standardButton( btn_x + 210, canvas_y, 60, 60, "", "rhombus");

standardButton reflect_1 = new standardButton( btn_x + (btn_diff * 0), canvas_y + 360, 30, 30, "1", "");
standardButton reflect_2 = new standardButton( btn_x + (btn_diff* 1), canvas_y + 360, 30, 30, "2", "");
standardButton reflect_3 = new standardButton( btn_x + (btn_diff* 2), canvas_y + 360, 30, 30, "3", "");
standardButton reflect_4 = new standardButton( btn_x + (btn_diff* 3), canvas_y + 360, 30, 30, "4", "");
standardButton reflect_5 = new standardButton( btn_x + (btn_diff* 4), canvas_y + 360, 30, 30, "5", "");
standardButton reflect_6 = new standardButton( btn_x + (btn_diff* 5), canvas_y + 360, 30, 30, "6", "");
standardButton reflect_7 = new standardButton( btn_x + (btn_diff* 6), canvas_y + 360, 30, 30, "7", "");
standardButton reflect_8 = new standardButton( btn_x + (btn_diff* 7), canvas_y + 360, 30, 30, "8", "");

slidingScale shape_size = new slidingScale( btn_x, canvas_y + 310, 100, "Shape size" );
slidingScale shape_stroke = new slidingScale( btn_x + 150, canvas_y + 310, 100, "Stroke width" );

standardButton col_0 = new standardButton( btn_x + (btn_diff * 0), canvas_y + 100, 30, 30, "/", "");
standardButton col_1 = new standardButton( btn_x + (btn_diff * 1), canvas_y + 100, 30, 30, "", "");
standardButton col_2 = new standardButton( btn_x + (btn_diff * 2), canvas_y + 100, 30, 30, "", "");
standardButton col_3 = new standardButton( btn_x + (btn_diff * 3), canvas_y + 100, 30, 30, "", "");
standardButton col_4 = new standardButton( btn_x + (btn_diff * 4), canvas_y + 100, 30, 30, "", "");
standardButton col_5 = new standardButton( btn_x + (btn_diff * 5), canvas_y + 100, 30, 30, "", "");
standardButton col_6 = new standardButton( btn_x + (btn_diff * 6), canvas_y + 100, 30, 30, "", "");

standardButton set_stroke = new standardButton( btn_x, canvas_y + 205, 115, 30, "Set stroke colour", "");
standardButton under_fill = new standardButton( btn_x + 125, canvas_y + 205, 135, 30, "Strokes on top", "");
standardButton hide_stroke = new standardButton( btn_x, canvas_y + 165, 115, 30, "Hide stroke", "");
standardButton outer_stroke = new standardButton( btn_x + 125, canvas_y + 165, 135, 30, "Hide outer stroke", "");



void setup() {

  size(screen_w, screen_h);

  // Put shapes into their array
  populate_shape_arrays();


  // Create canvas
  fill( bg_color );
  rect(canvas_x, canvas_y, canvas_size, canvas_size);
  pg = createGraphics(canvas_size, canvas_size, P3D);
  clear_canvas();

  current_color = c5_black;
}

void populate_shape_arrays() {

  for (int i = 0; i < rect_array.length; i ++ ) { 

    rect_array[i] = new BasicShape( 40, (360/ max_reflections) * i, "rect" );
  }
  for (int i = 0; i < circle_array.length; i ++ ) { 

    circle_array[i] = new BasicShape( 40, (360/ max_reflections) * i, "circle" );
  }
  for (int i = 0; i < triangle_array.length; i ++ ) { 

    triangle_array[i] = new BasicShape( 40, (360/ max_reflections) * i, "triangle" );
  }
  for (int i = 0; i < rhombus_array.length; i ++ ) { 

    rhombus_array[i] = new BasicShape( 40, (360/ max_reflections) * i, "rhombus" );
  }
}



void draw() {

  smooth();
  background(30, 30, 30);


  // Canvas bg
  update_reflections_bg_color();
  update_colors_bg_color();
  image(canvas_bg, canvas_x, canvas_y);


  // Calculate angle
  mouse_angle = get_angle();     

  // Draw apt shapes
  if ( mode == "circle" ) {

    draw_circles();
  }
  else if ( mode == "rect" ) {

    draw_rects();
  }
  else if ( mode == "triangle" ) {

    draw_triangles();
  }
  else if ( mode == "rhombus" ) {

    draw_rhombi();
  }


  // Draw background (hack solution so that shapes don't go out of canvas
  fill(40);
  noStroke();
  rect( 0, 0, canvas_x, screen_h);
  rect(canvas_x + canvas_size, 0, screen_w - (canvas_x + canvas_size), screen_h);
  rect(canvas_x, 0, canvas_size, canvas_y);
  rect(canvas_x, canvas_y + canvas_size, canvas_size, screen_h - (canvas_y + canvas_size) );

  // Furniture
  noFill();
  stroke(100);
  strokeWeight(1);
  rect(canvas_x, canvas_y, canvas_size, canvas_size);

  fill(200);
  textSize(20);
  text("Pattern generator test", canvas_x, 50); 

  // Labels
  textSize(12);
  text( "Shape", 585, canvas_y+ 10);
  text( "Colour", 585, canvas_y + 105);
  text( "Stroke", 585, canvas_y + 180);
  text( "Dimensions", 585, canvas_y + 285);
  text( "Reflections", 585, canvas_y + 366);
  text( "Reset", 585, canvas_y + 480);

  // Interface
  draw_btns();
  shape_size.draw_scale();
  shape_stroke.draw_scale();
}


void draw_triangles() {
        
    for (int i = 0; i < current_reflections; i ++ ) { 
  
          triangle_array[i].update();
          triangle_array[i].draw_triangle_fill();
          
          if( under_fill_on == false ){
                triangle_array[i].draw_shape();
          }
        
    }
    
     if( under_fill_on == true ){
        
          for (int i = 0; i < current_reflections; i ++ ) { 
              triangle_array[i].draw_shape();
          }
      }
    
}

void draw_rhombi() {

  
   for (int i = 0; i < current_reflections; i ++ ) { 
  
          rhombus_array[i].update();
          rhombus_array[i].draw_rhombus_fill();
          
          if( under_fill_on == false ){
                rhombus_array[i].draw_shape();
          }
        
    }
    
     if( under_fill_on == true ){
        
          for (int i = 0; i < current_reflections; i ++ ) { 
              rhombus_array[i].draw_shape();
          }
      }
  
}


float get_angle() {

  float return_value = 0;

  // Work out angle of mouse 
  dx = mouseX - centre_x;
  dy = mouseY - centre_y;

  // Q1
  return_value = degrees ( atan ( -dx / dy ) );

  // Q4
  if ( (mouseX < centre_x) && (mouseY < centre_y)) {
    return_value = 180 + ( 180 - degrees ( atan ( dx / dy ) ) );
  }
  // Q2
  else if ( (mouseX > centre_x) && (mouseY > centre_y)) {
    return_value = ( 180 - degrees ( atan ( dx / dy ) ) );
  }
  // Q3
  else if ( (mouseX < centre_x) && (mouseY > centre_y)) {
    return_value = 180 + degrees ( atan ( -dx / dy ) );
  }

  return return_value;
}

void draw_circles() {

    for (int i = 0; i < current_reflections; i ++ ) { 
  
        circle_array[i].update();
        circle_array[i].draw_circle_fill();
        
        if( under_fill_on == false ){
          circle_array[i].draw_shape();
        }
    }
    
    if( under_fill_on == true ){
      
        for (int i = 0; i < current_reflections; i ++ ) { 
            circle_array[i].draw_shape();
        }
    }
}

void reset_angles() {

  // Work out angles based on new number of reflections
  for (int i = 0; i < current_reflections; i ++ ) { 

    rect_array[i].r = (360 / current_reflections) * i;
    circle_array[i].r = (360 / current_reflections) * i;
    triangle_array[i].r = (360 / current_reflections) * i;
    rhombus_array[i].r = (360 / current_reflections) * i;
  }
}

void draw_rects() {

  for (int i = 0; i < current_reflections; i ++ ) { 

      rect_array[i].update();
      rect_array[i].draw_rect_fill();
      
      if( under_fill_on == false ){
            rect_array[i].draw_shape();
      }
      
  }
  
   if( under_fill_on == true ){
      
        for (int i = 0; i < current_reflections; i ++ ) { 
            rect_array[i].draw_shape();
        }
    }
  
}

void draw_btns() {

  reset_btn.draw();
  circle_btn.draw();
  rect_btn.draw();
  triangle_btn.draw();
  rhombus_btn.draw();

  reflect_1.draw();
  reflect_2.draw();
  reflect_3.draw();
  reflect_4.draw();
  reflect_5.draw();
  reflect_6.draw();
  reflect_7.draw();
  reflect_8.draw();

  col_0.draw();
  col_1.draw();
  col_2.draw();
  col_3.draw();
  col_4.draw();
  col_5.draw();
  col_6.draw();

  set_stroke.draw();
  under_fill.draw();
  hide_stroke.draw();
  outer_stroke.draw();
}


void clear_canvas() {

  bg_color = current_color;
  fill( bg_color );
  rect(canvas_x, canvas_y, canvas_size, canvas_size);
  canvas_bg  = get(canvas_x, canvas_y, canvas_size, canvas_size);
}


class slidingScale { 

  int x, y, w, value_min, value_max, value_current, pointer_x;
  String label;
  Boolean drag_on = false;

  slidingScale (int  _x, int _y, int _w, String _label) {  

    x = _x;
    y = _y;
    w = _w;
    label = _label;

    value_min = 2;
    value_max = 20;
    value_current = 1500;
    
    if (label == "Shape size") {
      pointer_x = x + 30;
    }
    if (label == "Stroke width") {
       pointer_x = x + 5;
    }
  }

  void draw_scale() {

    stroke(255);
    strokeWeight( 1 );
    line( x, y, x + w, y);

    draw_pointer();

    textSize(12);
    text( label + ": " + value_current, x, y - 23);
  }

  void draw_pointer() {

    if ( drag_on == true ) {

      pointer_x = mouseX;
      pointer_x = constrain( pointer_x, x, x + w - 20);
    }

    // Do some maths to work out reasonable output values for the sliders
    if (label == "Shape size") {

      value_current = 1 + ( (floor( pointer_x)  - 670) * 6);//- x );// - (btn_x - 2) ) * 3 );
    }

    else if (label == "Stroke width") {

      value_current =  1 + ( floor( pointer_x) - x);
    }


    noStroke();
    fill(200);
    rect( pointer_x, y - 10, 20, 10);
  }

  Boolean over_pointer() {

    Boolean x_true = false;
    Boolean y_true = false;
    Boolean both_true = false;


    if ( (mouseX < x + w) && (mouseX > x) ) {

      x_true = true;
    }

    if ( (mouseY > y - 10) && (mouseY < y) ) {

      y_true = true;
    }

    if ( x_true && y_true) {

      both_true = true;
    }

    return both_true;
  }
}


// Tests where the mouse is and actions accordingly

void mousePressed() {

  if ( shape_size.over_pointer() ) {

    shape_size.drag_on = true;
  }

  if ( shape_stroke.over_pointer() ) {

    shape_stroke.drag_on = true;
  }
}



void mouseReleased() {

  shape_size.drag_on = false;
  shape_stroke.drag_on = false;
}

void mouseClicked() {

  // Big switch to catch mouse clicks.

  // Determine mode
  if ( circle_btn.over_btn() ) {

    if ( mode != "circle") {

      mode = "circle";
    } 
    else {

      mode = "none";
    }
  }

  else if ( rect_btn.over_btn() ) {

    if ( mode != "rect") {

      mode = "rect";
    } 
    else {

      mode = "none";
    }
  }
  else if ( triangle_btn.over_btn() ) {


    if ( mode != "triangle") {

      mode = "triangle";
    } 
    else {

      mode = "none";
    }
  }
  else if ( rhombus_btn.over_btn() ) {


    if ( mode != "rhombus") {

      mode = "rhombus";
    } 
    else {

      mode = "none";
    }
  }
  else if ( reflect_1.over_btn() ) {

    current_reflections = 1; 
    reset_angles();
  }
  else if ( reflect_2.over_btn() ) {

    current_reflections = 2; 
    reset_angles();
  }
  else if ( reflect_3.over_btn() ) {

    current_reflections = 3; 
    reset_angles();
  }
  else if ( reflect_4.over_btn() ) {

    current_reflections = 4; 
    reset_angles();
  }
  else if ( reflect_5.over_btn() ) {

    current_reflections = 5; 
    reset_angles();
  }
  else if ( reflect_6.over_btn() ) {

    current_reflections = 6; 
    reset_angles();
  }
  else if ( reflect_7.over_btn() ) {

    current_reflections = 7;
    reset_angles();
  }
  else if ( reflect_8.over_btn() ) {

    current_reflections = 8; 
    reset_angles();
  }


  else if ( reset_btn.over_btn() ) {

    clear_canvas();
  }


  else if ( col_0.over_btn() ) {

    color_mode = "off";
    reset_colors();
    current_color = off_color;
  }
  else if ( col_1.over_btn() ) {

    color_mode = "on";
    reset_colors();
    current_color = c1_blue;
  }
  else if ( col_2.over_btn() ) {

    color_mode = "on";
    reset_colors();
    current_color = c2_orange;
  }
  else if ( col_3.over_btn() ) {

    color_mode = "on";
    reset_colors();
    current_color = c3_yellow;
  }
  else if ( col_4.over_btn() ) {

    color_mode = "on";
    reset_colors();
    current_color = c4_pink;
  }
  else if ( col_5.over_btn() ) {

    color_mode = "on";
    reset_colors();
    current_color = c5_black;
  }
  else if ( col_6.over_btn() ) {

    color_mode = "on";
    reset_colors();
    current_color = c6_white;
  }
  else if ( outer_stroke.over_btn() ) {

    if ( outer_stroke_bool == false) {

      outer_stroke_bool = true;
      outer_stroke.bg_color = 170;
    }
    else {

      outer_stroke_bool = false;
      outer_stroke.bg_color = 70;
    }
  }
  else if ( set_stroke.over_btn() ) {

    stroke_color = current_color;
  }
  
  else if ( under_fill.over_btn() ) {

    if( under_fill_on == false){
      under_fill_on = true;
      under_fill.bg_color = 70;
    }
    else{
      under_fill_on = false; 
      under_fill.bg_color = 170;
    }
  }
  
  else if ( hide_stroke.over_btn() ) {

    if (stroke_bool == true) {

      stroke_bool = false;
      hide_stroke.bg_color = 70;
    }
    else {

      stroke_bool = true; 
      hide_stroke.bg_color = 170;
      outer_stroke_bool = true;
      outer_stroke.bg_color = 170;
    }
  }




  // Save the current canvas over the background image
  if ( (mouseX > canvas_x) && (mouseX < canvas_x + canvas_size) ) {

    if ( (mouseY > canvas_y) && (mouseY < canvas_y + canvas_size) ) {

      canvas_bg  = get(canvas_x, canvas_y, canvas_size, canvas_size);
    }
  }
}


//----------------------------- Buttons ----------------------------


class standardButton { 
  
  float x, y, w, h;//, bg_color;
  color bg_color;
  String label, icon;
  Boolean col_select;
  

  standardButton (int  _x, int _y, int _w, int _h, String _label, String _icon) {  
    
      x = _x;
      y = _y;
      w = _w;
      h = _h;
      label = _label;
      icon = _icon;
      
      bg_color = 70;
      col_select = false;
  
  }  
  
  
  void draw() { 
    
    
     noStroke();
     fill(bg_color);
     rect( x, y, w, h );

     fill(200);
     textSize(12);
     text(label,x + 10,y + 20); 
     
     if( icon != "none"){
       
         draw_icon( icon );
       
     }
     
     if( col_select ){
     
       rect( x + 10, y + 10, w - 20, h - 20 );
       
     }
    
  }
  
  void draw_icon( String icon) { 
    
     if( icon == "circle" ){
      
       stroke( 255 );
       strokeWeight( 2 );
       noFill();
       ellipse( x+29, y +30, 40, 40);
       
     }
     else if( icon == "rect" ){
      
       stroke( 255 );
       strokeWeight( 2 );
       noFill();
       rect( x+ 9, y +10, 40, 40);
       
     }
     else if( icon == "triangle" ){
      
       stroke( 255 );
       strokeWeight( 2 );       
       noFill();
       triangle( x + 10, y+ 39 + 10,   x+40  + 10, y+39 + 10,   x+20 + 10, y+ 10);
       
     }
     else if( icon == "rhombus" ){
      
       stroke( 255 );
       strokeWeight( 2 ); 
       noFill();
       
       pushMatrix();
             
             translate(x + 29, y +10);
             rotate( PI / 4);
             rect( 0,0, 30, 30);
       popMatrix();
       
       
     }

  }
  
  
Boolean over_btn(){
   
    Boolean x_true = false;
    Boolean y_true = false;
    Boolean both_true = false;
    
     if( (mouseX < x + w) && (mouseX > x) ){
       
         x_true = true;
       
     }
     
     if( (mouseY < y + h) && (mouseY > y) ){
       
         y_true = true;
       
     }
     
     if( x_true && y_true){

       both_true = true;
     
     }
     
     return both_true;
    
  }
  
}

void reset_colors() {
  
    col_1.bg_color = c1_blue;
    col_2.bg_color = c2_orange;
    col_3.bg_color = c3_yellow;
    col_4.bg_color = c4_pink;
    col_5.bg_color = c5_black;
    col_6.bg_color = c6_white;
    
    col_1.col_select = false;
    col_2.col_select = false;
    col_3.col_select = false;
    col_4.col_select = false;
    col_5.col_select = false;
    col_6.col_select = false;
  
}

void update_colors_bg_color(){
  
    // Reset all colours
      reset_colors();
  
    if( current_color == c1_blue){
    
        col_1.col_select = true; 
      
    }
    else if( current_color == c2_orange){
    
        col_2.col_select = true; 
      
    }
     else if( current_color == c3_yellow){
    
        col_3.col_select = true; 
      
    }
    else if( current_color == c4_pink){
    
        col_4.col_select = true; 
      
    }
    else if( current_color == c5_black){
    
        col_5.col_select = true; 
      
    }
    else if( current_color == c6_white){
    
        col_6.col_select = true; 
      
    }
      
         
}



void update_reflections_bg_color(){
  
  if( mode == "circle"){
  
    circle_btn.bg_color = 170;
    
    rect_btn.bg_color = 70;
    triangle_btn.bg_color = 70;
    rhombus_btn.bg_color = 70;
    
  } 
  else if( mode == "rect"){
  
    rect_btn.bg_color = 170;
    
    circle_btn.bg_color = 70;
    triangle_btn.bg_color = 70;
    rhombus_btn.bg_color = 70;
    
  } 
  else if( mode == "triangle"){
  
    triangle_btn.bg_color = 170;
    
    circle_btn.bg_color = 70;
    rect_btn.bg_color = 70;
    rhombus_btn.bg_color = 70;

  } 
  else if( mode == "rhombus"){
  
    rhombus_btn.bg_color = 170;
    
    triangle_btn.bg_color = 70;
    circle_btn.bg_color = 70;
    rect_btn.bg_color = 70;

  } 
  else{
   
    circle_btn.bg_color = 70;
    rect_btn.bg_color = 70;
    triangle_btn.bg_color = 70;
    rhombus_btn.bg_color = 70;
  } 
 
  if( current_reflections == 1 ){
    
      reset_reflect_bg_colors();
      reflect_1.bg_color = 170;  
    
  }
  else if( current_reflections == 2 ){
    
      reset_reflect_bg_colors();
      reflect_2.bg_color = 170;  
    
  }
  else if( current_reflections == 3 ){
    
      reset_reflect_bg_colors();
      reflect_3.bg_color = 170;  
    
  }
  else if( current_reflections == 4 ){
    
      reset_reflect_bg_colors();
      reflect_4.bg_color = 170;  
    
  }
  else if( current_reflections == 5 ){
    
      reset_reflect_bg_colors();
      reflect_5.bg_color = 170;  
    
  }
  else if( current_reflections == 6 ){
    
      reset_reflect_bg_colors();
      reflect_6.bg_color = 170;  
    
  }
  else if( current_reflections == 7 ){
    
      reset_reflect_bg_colors();
      reflect_7.bg_color = 170;  
    
  }
  else if( current_reflections == 8 ){
    
      reset_reflect_bg_colors();
      reflect_8.bg_color = 170;  
    
  }
  
 
}

void reset_reflect_bg_colors(){
 
    reflect_1.bg_color = 70;  
    reflect_2.bg_color = 70;  
    reflect_3.bg_color = 70;  
    reflect_4.bg_color = 70;  
    reflect_5.bg_color = 70;  
    reflect_6.bg_color = 70;  
    reflect_7.bg_color = 70;  
    reflect_8.bg_color = 70;  
  
}


//---------------------------- Shapes --------------------------------


class BasicShape { 
  
  float centre, x, y, r, s, stroke_width;
  String type;
  
  //r is for rotation
  BasicShape (float d, float _r, String _type) {  
    
        type = _type;
        r = _r;
        
        println(r);
  }
  
  void update() { 
    
    x = mouseX;
    y = mouseY;
    
    s = shape_size.value_current;
    stroke_width = shape_stroke.value_current;
       
  } 


  void draw_circle_fill(){
    
        if( color_mode == "on" ){
        
            pushMatrix();
              
                noStroke();
                fill(current_color);
            
                translate( centre_x , centre_y );
                rotate( radians( r ) );                
                translate( dx, dy);                
                rotate( radians( mouse_angle) ); 
                
                ellipse(0,0, s,s);
        
            popMatrix();
        
        }
    
  }
  
 void draw_rect_fill(){
    
        if( color_mode == "on" ){
        
            pushMatrix();
              
                noStroke();
                fill(current_color);
            
                translate( centre_x , centre_y );
                rotate( radians( r ) );            
                translate( dx, dy);
                rotate( radians( mouse_angle) );
                
                rect(-(s/2),-(s/2), s,s);
        
            popMatrix();
        
        }
  }
  
  void draw_triangle_fill(){
    
        if( color_mode == "on" ){
        
            pushMatrix();
              
                noStroke();
                fill(current_color);
            
                translate( centre_x , centre_y );
                rotate( radians( r ) );
                translate( dx - ( s / 2 ), dy - ( s / 2 ));
                rotate( radians( mouse_angle) );

                triangle( 0, s * 0.86, s, s * 0.86, s / 2, 0 );
        
            popMatrix();
        
        }
  }
  
  void draw_rhombus_fill(){
    
        if( color_mode == "on" ){
        
            pushMatrix();
              
                noStroke();
                fill(current_color);
            
                translate( centre_x , centre_y );   
                rotate( radians( r + 45 ) );
                translate( dx, dy);
                rotate( radians( mouse_angle) );

                rect( -(s/2), -(s/2), s, s);
        
            popMatrix();
        
        }
  }
  
  void draw_shape(){
      
      x = constrain( x, canvas_x, canvas_x + canvas_size);
      y = constrain( y, canvas_y, canvas_y + canvas_size);
      
            
      if( type == "circle"){  
           
         pushMatrix();
         
                //fill(current_color);
                noFill();
        
                translate( centre_x , centre_y );
                
                rotate( radians( r ) );
                
                translate( dx, dy);
                
                rotate( radians( mouse_angle) );        
                
                if( !outer_stroke_bool){
                    stroke(0);
                    strokeWeight( stroke_width + 2 );
                    ellipse(0,0,s,s);
                }
                if( !stroke_bool ){
                  
                    stroke(stroke_color);
                    strokeWeight( stroke_width );         
                    
                 }
                 else{
                   noStroke();
                 }
                 
                 noFill();
                 ellipse(0,0, s,s);
          
        popMatrix();
          
      }
      
      else if (type == "rect"){
        
          pushMatrix();
          
                noFill();
        
                translate( centre_x , centre_y );
                
                rotate( radians( r ) );
                
                translate( dx, dy);
                
                rotate( radians( mouse_angle) );
                
                if( !outer_stroke_bool){
                
                    stroke(0);
                    strokeWeight( stroke_width + 2 );
                    rect(-(s/2),-(s/2), s,s);
                
                }
                
                if( !stroke_bool ){
                  
                    stroke(stroke_color);
                    strokeWeight( stroke_width );
                    
                }
                else{
                 noStroke(); 
                }
                
                noFill();
                rect(-(s/2),-(s/2), s,s);
          
          popMatrix();
      
      }
      
      else if (type == "triangle"){
        
          pushMatrix();
       
                noFill();
        
                translate( centre_x , centre_y );
                
                rotate( radians( r ) );
                
                translate( dx - ( s / 2 ), dy - ( s / 2 ));
                
                rotate( radians( mouse_angle) );
                
                if( !outer_stroke_bool ){
                
                    stroke(0);
                    strokeWeight( stroke_width + 2 );
                    triangle( 0, s * 0.86, s, s * 0.86, s / 2, 0 );
                
                }
                
                if( !stroke_bool ){
                  
                  stroke(stroke_color);
                  strokeWeight( stroke_width );
                  
                }
                else{
                  noStroke();
                }
                
                
                noFill();
                triangle( 0, s * 0.86, s, s * 0.86, s / 2, 0 );
          
          popMatrix();
      
      }
      
      else if (type == "rhombus"){
        
          pushMatrix();
        
                noFill();
                //fill(current_color);        
        
                translate( centre_x , centre_y );
                
                rotate( radians( r + 45 ) );
                
                translate( dx, dy);
                
                rotate( radians( mouse_angle) );
                
                if( !outer_stroke_bool ){
                
                    stroke(0);
                    strokeWeight( stroke_width + 2 );
                    rect(-(s/2),-(s/2), s, s);
                
                }
                
                if( !stroke_bool ){
                
                    stroke(stroke_color);
                    strokeWeight( stroke_width );
                   
                
                }
                else{
                  noStroke();
                }
          
          
               noFill();
               rect( -(s/2), -(s/2), s, s);
          
          popMatrix();
      
      }
      

    
  }
  
}

