/*



TODO: 

How to make it clear that when you change the background colour, you also lose everything?






----------------------------------------------------

'Pattern Generator'

Produced for Qatar Museums by Cogapp, 2014

This app is designed to enabled users to create simple
geometric patterns. It is intended for use on 
www.qatarmuseums.org.qa. 

Please contact office@cogapp.com for more information.

All rights reserved.

Code is based on the open source projects
Processing.org and ProcessingJS.org 


Code structure:

  Main
    Setup and Draw functions
  Shapes
    Calculates shape properties and calls class
  Interface
    Buttons and furniture, including standardButton class
  Interactions
    Catches and processes mouse movement
  Shape class
    Main class to manage drawing and filling of shapes

-------------------------------------------------------
 
*/


// --- Initiate variables ---

// Global
  int screen_w = 1174;
  int screen_h = 700;
  String mode = "none";
  int stroke_width = 7;
  float mouse_angle, dx, dy = 0;
  Boolean outer_stroke_bool = true; // *** De-scoped ***
  Boolean stroke_bool = false;
  Boolean under_fill_on = true; // *** De-scoped ***

// Setup canvas
  int canvas_x = 0;
  int canvas_y = 0;
  int canvas_size = screen_h;
  int centre_x = canvas_x + (canvas_size / 2);
  int centre_y = canvas_y + (canvas_size / 2);
  PImage canvas_bg;
  PGraphics pg;
  int btn_diff = 26;

// Brand colours
  color c1_blue = color(121, 170, 250);
  color c2_orange = color(255, 194, 0);
  color c3_yellow = color(250, 255, 30);
  color c4_pink = color(237, 60, 138);
  color c5_black = color(0, 0, 0);
  color c6_white= color(255, 255, 255);

// Other colours
  color off_color = color(70, 70, 70);
  color canvas_bg_color = 0;
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


// --- Initiate interface ---

// Alignment
  int btn_x = 732;
  int shape_y = 40;
  int col_y = 180;
  int stroke_y = 420;
  int reflect_y = 550;
  int reflect_x = 120;

// Footer buttons
  standardButton reset_btn = new standardButton( btn_x + 150, canvas_y + canvas_size- 50, 250, 30, "START AGAIN", "reset");

// Shape buttons
  standardButton triangle_btn = new standardButton( btn_x - 5, canvas_y + shape_y, 50, 60, "", "triangle");
  standardButton circle_btn = new standardButton( btn_x + 45, canvas_y + shape_y, 50, 60, "", "circle");
  standardButton rect_btn = new standardButton( btn_x + 105, canvas_y + shape_y, 50, 60, "", "rect");
  standardButton rhombus_btn = new standardButton( btn_x + 165, canvas_y + shape_y, 50, 60, "", "rhombus");

// Reflections
  standardButton reflect_1 = new standardButton( btn_x + reflect_x +(btn_diff * 0), canvas_y + reflect_y, 22, 22, "1", "");
  standardButton reflect_2 = new standardButton( btn_x + reflect_x +(btn_diff* 1), canvas_y + reflect_y, 22, 22, "2", "");
  standardButton reflect_3 = new standardButton( btn_x + reflect_x +(btn_diff* 2), canvas_y + reflect_y, 22, 22, "3", "");
  standardButton reflect_4 = new standardButton( btn_x + reflect_x +(btn_diff* 3), canvas_y + reflect_y, 22, 22, "4", "");
  standardButton reflect_5 = new standardButton( btn_x + reflect_x +(btn_diff* 4), canvas_y + reflect_y, 22, 22, "5", "");
  standardButton reflect_6 = new standardButton( btn_x + reflect_x + (btn_diff* 5), canvas_y + reflect_y,22, 22, "6", "");
  standardButton reflect_7 = new standardButton( btn_x + reflect_x +(btn_diff* 6), canvas_y + reflect_y, 22, 22, "7", "");
  standardButton reflect_8 = new standardButton( btn_x + reflect_x +(btn_diff* 7), canvas_y + reflect_y, 22, 22, "8", "");

// Scale
  slidingScale shape_size = new slidingScale( btn_x, canvas_y + 20 + reflect_y, 100, "SIZE" );
  //slidingScale shape_stroke = new slidingScale( btn_x + 150, canvas_y + 310, 100, "Stroke width" );

// Colour selection
  standardButton col_0 = new standardButton( btn_x + (btn_diff * 0), canvas_y + col_y, 15, 15, "/", "");
  standardButton col_1 = new standardButton( btn_x + (btn_diff * 1), canvas_y + col_y, 15, 15, "", "");
  standardButton col_2 = new standardButton( btn_x + (btn_diff * 2), canvas_y + col_y, 15, 15, "", "");
  standardButton col_3 = new standardButton( btn_x + (btn_diff * 3), canvas_y + col_y, 15, 15, "", "");
  standardButton col_4 = new standardButton( btn_x + (btn_diff * 4), canvas_y + col_y, 15, 15, "", "");
  standardButton col_5 = new standardButton( btn_x + (btn_diff * 5), canvas_y + col_y, 15, 15, "", "");
  standardButton col_6 = new standardButton( btn_x + (btn_diff * 6), canvas_y + col_y, 15, 15, "", "");

// Stroke
  standardButton set_stroke = new standardButton( btn_x, canvas_y  + 250, 115, 30, "Set stroke colour", "");
  //standardButton hide_stroke = new standardButton( btn_x, canvas_y + stroke_y, 115, 30, "Hide stroke", "");
  //standardButton outer_stroke = new standardButton( btn_x + 125, canvas_y + stroke_y, 135, 30, "Hide outer stroke", "");
  
  standardButton thick_stroke = new standardButton( btn_x, canvas_y + stroke_y, 40, 30, "Thick", "thick");
  standardButton thin_stroke = new standardButton( btn_x + 80, canvas_y + stroke_y, 40, 30, "Thin", "thin");
  standardButton no_stroke = new standardButton( btn_x + 160, canvas_y + stroke_y, 40, 30, "None", "no_stroke");
  
// Colour buttons
   int palette_size = 36;
   colourButton bg_button = new colourButton(800, 300, 70, 70, "Background");  


// -----------------------------------------------------------------------------------------------------------
// --------------------------------------------    Main    ---------------------------------------------------
// -----------------------------------------------------------------------------------------------------------


// Setup (initiation function for Processing)
void setup() {

  size(screen_w, screen_h);

  // Put shapes into their array
    populate_shape_arrays();


  // Create canvas
    fill( canvas_bg_color );
    rect(canvas_x, canvas_y, canvas_size, canvas_size);
    pg = createGraphics(canvas_size, canvas_size, P3D);
    clear_canvas();

  // Set starting colour
    current_color = c5_black;
  
}


// Draw (called per frame by Processing)
void draw() {

  // Make lines smooth
    smooth();
  
  // Set background colour
    background(82, 82, 82);

  // Update buttons
    update_reflections_bg_color();
    update_colors_bg_color();

  // Update canvas
    image(canvas_bg, canvas_x, canvas_y);

  // Calculate angle
    mouse_angle = get_angle();     

  // Draw shapes
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

  // Draw background: This is drawn after the canvas so shapes are cropped to the canvas.
    fill(82);
    noStroke();
    rect( 0, 0, canvas_x, screen_h);
    rect(canvas_x + canvas_size, 0, screen_w - (canvas_x + canvas_size), screen_h);
    rect(canvas_x, 0, canvas_size, canvas_y);
    rect(canvas_x, canvas_y + canvas_size, canvas_size, screen_h - (canvas_y + canvas_size) );

  // Draw furniture
    noFill();
    //stroke(100);
    strokeWeight(1);
    rect(canvas_x, canvas_y, canvas_size, canvas_size);

  // Labels
    fill(255); 
    textSize(12);
    text( "SHAPE", btn_x, canvas_y+ 30);
    text( "COLOUR", btn_x, col_y - 30);
    text( "BORDER", btn_x, stroke_y - 30);
    //text( "SIZE", 585, canvas_y + 285);
    text( "REFLECTIONS", btn_x + reflect_x, reflect_y - 30);

  // Draw buttons
    draw_btns();
    shape_size.draw_scale();
    //shape_stroke.draw_scale();
    
}

// -----------------------------------------------------------------------------------------------------------
// --------------------------------------------    Shapes    -------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

// Create eight of each shape, and put them in four arrays
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


// A drawing function for each of the four shapes:

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


// Reset the angle stored in each shape, based on the number of reflections
void reset_angles() {

    for (int i = 0; i < current_reflections; i ++ ) { 
  
      rect_array[i].r = (360 / current_reflections) * i;
      circle_array[i].r = (360 / current_reflections) * i;
      triangle_array[i].r = (360 / current_reflections) * i;
      rhombus_array[i].r = (360 / current_reflections) * i;
    }
}


// Find the angle of the mouse in relation to the centre of the canvas
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


// -----------------------------------------------------------------------------------------------------------
// --------------------------------------------    Interface    ----------------------------------------------
// -----------------------------------------------------------------------------------------------------------

// Draw interface buttons
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
    
    thick_stroke.draw();
    thin_stroke.draw();
    no_stroke.draw();
    
    bg_button.draw();
    
}

// Reset canvas
void clear_canvas() {

    //canvas_bg_color = current_color;
    fill( canvas_bg_color );
    rect(canvas_x, canvas_y, canvas_size, canvas_size);
    canvas_bg  = get(canvas_x, canvas_y, canvas_size, canvas_size);
}


// Class used to create sliding scale
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
      
      if (label == "SIZE") {
        pointer_x = x + 30;
      }
      if (label == "Stroke width") {
         pointer_x = x + 5;
      }
}

void draw_scale() {

    stroke(180);
    strokeWeight( 2 );
    line( x, y, x + w, y);

    draw_pointer();

    textSize(12);
    text( label, x, y - 23);
}

void draw_pointer() {

    if ( drag_on == true ) {

      pointer_x = mouseX;
      pointer_x = constrain( pointer_x, x, x + w - 20);
    }

    // Do some maths to work out reasonable output values for the sliders
    if (label == "SIZE") {

      value_current = 1 + ( (floor( pointer_x)  - 700) * 6);//- x );// - (btn_x - 2) ) * 3 );
    }

    else if (label == "Stroke width") {

      value_current =  1 + ( floor( pointer_x) - x);
    }

    noStroke();
    fill(220);
    rect( pointer_x, y - 10, 20, 20);
}

Boolean over_pointer() {

    Boolean x_true = false;
    Boolean y_true = false;
    Boolean both_true = false;


    if ( (mouseX < x + w) && (mouseX > x) ) {

      x_true = true;
    }

    if ( (mouseY > y - 10) && (mouseY < y + 10) ) {

      y_true = true;
    }

    if ( x_true && y_true) {

      both_true = true;
    }

    return both_true;
  }
}

// -----------------------------------------------------------------------------------------------------------
// --------------------------------------------    Interactions    -------------------------------------------
// -----------------------------------------------------------------------------------------------------------


// Tests where the mouse is and actions accordingly

void mousePressed() {

  if ( shape_size.over_pointer() ) {

    shape_size.drag_on = true;
  }

}

void mouseReleased() {

  shape_size.drag_on = false;
  
}

void mouseClicked() {

  // --- Switch to manage mouse clicks ---
    // Tests to catch which button the mouse is over, and then calls apt function

  // --- Shape selection ---
  
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
      
  // --- Reflection selection ---
          
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
      
  // --- Colour selection ---
    
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
      
  // --- Stroke selection ---
          
      else if ( thick_stroke.over_btn() ) {
    
          stroke_width = 12;
          stroke_bool = false;

      }
      else if ( thin_stroke.over_btn() ) {
    
        stroke_width = 2;
        stroke_bool = false;

      }
      else if ( no_stroke.over_btn() ) {
    
        stroke_width = 0;
        stroke_bool = true;

      }
      
  // --- Colour buttons ---

      // Test for hit on button whilst the palette is off
      else if ( bg_button.over_btn() && (bg_button.palette_on == false) ) {
      
          if( bg_button.palette_on == true){
           
              bg_button.palette_on = false;
              
          } 
          else{
            
              bg_button.palette_on = true;
            
          }

      }
      else if ( bg_button.over_palette_btn() && (bg_button.palette_on == true) ) {
      
          bg_button.palette_on = false;

      }



  // After each mouse click in the canvas, save the current canvas over the background image
  
    if ( (mouseX > canvas_x) && (mouseX < canvas_x + canvas_size) ) {
  
        if ( (mouseY > canvas_y) && (mouseY < canvas_y + canvas_size) ) {
    
          canvas_bg  = get(canvas_x, canvas_y, canvas_size, canvas_size);
        }
    }
}




// --- standardButton ---
// Used as a simple button, with an action, position, size and (optional) icon

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
      
      bg_color = 82;
      col_select = false;
        
  }  
    
  void draw() { 
    
     noStroke();
     fill(bg_color);
     rect( x, y, w, h );
     
     if( icon != "none"){
       
         draw_icon( icon );
       
     }
     
     if( col_select ){
     
       rect( x + 10, y + 10, w - 20, h - 20 );
       
     }
     
     
     // Draw label
       fill(200);
       textSize(12);
       text(label,x + 10,y + 20); 
    
  }
  
  void draw_icon( String icon) { 
    
     if( icon == "circle" ){
      
       stroke( 0 );
       strokeWeight( 2 );
       fill(255);
       ellipse( x+29, y +30, 40, 40);
       
     }
     else if( icon == "rect" ){
      
       stroke( 0 );
       strokeWeight( 2 );
       fill(255);
       rect( x+ 9, y +10, 40, 40);
       
     }
     else if( icon == "triangle" ){
      
       stroke( 0 );
       strokeWeight( 2 );       
       fill(255);
       triangle( x + 10, y + 10,   x + 45, y + 30,  x + 10, y+ 50);
       
     }
     else if( icon == "rhombus" ){
      
       stroke( 0 );
       strokeWeight( 2 ); 
       fill(255);
       
       pushMatrix();
             
             translate(x + 29, y +10);
             rotate( PI / 4);
             rect( 0,0, 30, 30);
       popMatrix();
       
     }

     else if( icon == "reset" ){
         
       fill(120);
       rect( x , y,  100, 30);
       
     }

     else if( icon == "thick" ){
         
       fill(0);
       rect( x + 10 , y - 7,  45, 5);
          
     }
     
     else if( icon == "thin" ){
         
       fill(60);
       rect( x + 10 , y - 7,  45, 2);
       
     }
     
     else if( icon == "no_stroke" ){
         
       fill(140);
       rect( x + 10 , y - 7,  6, 1);
       rect( x + 22 , y - 7,  6, 1);
       rect( x + 34 , y - 7,  6, 1);
       rect( x + 46 , y - 7,  6, 1);
       
     }

  }
  
  // Test to see if the cursor is currently over this button
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

// --- (end of standardButton class) ---


// --- colourButton ---
// A button which when clicked yields a colour selector

class colourButton { 
  
  float x, y, w, h;//, bg_color;
  color bg_color, current_color;
  String label, icon;
  Boolean col_select, palette_on;
  
  colourButton (int  _x, int _y, int _w, int _h, String _label) {  
    
      x = _x;
      y = _y;
      w = _w;
      h = _h;
      label = _label;
      
      bg_color = 255;
      col_select = false;
      palette_on = false;
      
      current_color = c5_black;
        
  }  
    
  void draw() { 
    
     noStroke();
     fill(current_color);
     rect( x, y, w, h );
     
    
     if( col_select ){
     
       rect( x + 10, y + 10, w - 20, h - 20 );
       
     }
     
     
     // Draw label
       fill(255);
       textSize(12);
       text(label,x,y + 90); 

     // Draw palette
       if(palette_on){
     
         draw_palette();
       
       }
      
  }
  
  
  void draw_palette() {
   
        // Draw palette
       fill(c6_white);
       rect(15 + x,-50 + y,palette_size,palette_size);
       fill(c5_black);
       rect(15 + x + palette_size,-50 + y,palette_size,palette_size);
       fill(c2_orange);
       rect(15 + x,-50 + y + palette_size,palette_size,palette_size);
       fill(c4_pink);
       rect(15 + x+ palette_size,-50 + y+ palette_size,palette_size,palette_size);
       fill(c3_yellow);
       rect(15 + x,-50 + y + (2 * palette_size),palette_size,palette_size);
       fill(c1_blue);
       rect(15 + x + palette_size,-50 + y + (2* palette_size),palette_size,palette_size);
       
  } 
  
   // Test to see if the cursor is currently over the palette
  Boolean over_palette_btn(){
       
        Boolean x_true = false;
        Boolean y_true = false;
        Boolean both_true = false;
        
        // Set location of palette
        float p_x = x + 15;
        float p_y = y - 50;
        float p_w = p_x + ( 2 * palette_size);
        float p_h = p_y + ( 3 * palette_size);
        
        
        // Test if a colour has been clicked
             if( (mouseX > p_x) && (mouseX < p_x + palette_size) ){
               
                  if( (mouseY > p_y) && (mouseY < p_y + palette_size) ){
               
                       current_color = c6_white;
                       canvas_bg_color = c6_white;
                       clear_canvas();
               
                   }
               
             }
             
             if( (mouseX > p_x + palette_size) && (mouseX < p_x + (2 * palette_size )) ){
               
                  if( (mouseY > p_y) && (mouseY < p_y + palette_size) ){
               
                       current_color = c5_black;
                       canvas_bg_color = c5_black;
                       clear_canvas();
               
                   }
               
             }
          
        
        // Test whether the palette has been clicked at all
             if( (mouseX < p_x + p_w) && (mouseX > p_x) ){
               
                 x_true = true;
               
             }
             
             if( (mouseY < p_y + p_h) && (mouseY > p_y) ){
               
                 y_true = true;
               
             }
             
             if( x_true && y_true){
        
               both_true = true;
             
             }
             
             return both_true;
    
  }
  
  // Test to see if the cursor is currently over this button
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

// --- (end of colourButton class) ---


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

// Update the colour of the colour buttons in the interface to show current selection
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


// Update the colour of the reflection buttons in the interface
void update_reflections_bg_color(){
  
  int default_col = 82;
  
  if( mode == "circle"){
  
    circle_btn.bg_color = 170;
    
    rect_btn.bg_color = default_col;
    triangle_btn.bg_color = default_col;
    rhombus_btn.bg_color = default_col;
    
  } 
  else if( mode == "rect"){
  
    rect_btn.bg_color = 170;
    
    circle_btn.bg_color = default_col;
    triangle_btn.bg_color = default_col;
    rhombus_btn.bg_color = default_col;
    
  } 
  else if( mode == "triangle"){
  
    triangle_btn.bg_color = 170;
    
    circle_btn.bg_color = default_col;
    rect_btn.bg_color = default_col;
    rhombus_btn.bg_color = default_col;

  } 
  else if( mode == "rhombus"){
  
    rhombus_btn.bg_color = 170;
    
    triangle_btn.bg_color =default_col;
    circle_btn.bg_color = default_col;
    rect_btn.bg_color = default_col;

  } 
  else{
   
    circle_btn.bg_color = default_col;
    rect_btn.bg_color = default_col;
    triangle_btn.bg_color = default_col;
    rhombus_btn.bg_color = default_col;
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

// Set all reflection buttons back to default
void reset_reflect_bg_colors(){
 
    int default_col = 82;
  
    reflect_1.bg_color = default_col;  
    reflect_2.bg_color = default_col;  
    reflect_3.bg_color = default_col;  
    reflect_4.bg_color = default_col;  
    reflect_5.bg_color = default_col;  
    reflect_6.bg_color = default_col;  
    reflect_7.bg_color = default_col;  
    reflect_8.bg_color = default_col;  
  
}


// -----------------------------------------------------------------------------------------------------------
// --------------------------------------------    BasicShape    ---------------------------------------------
// -----------------------------------------------------------------------------------------------------------

// Calculates, draws and fills each type of shape

class BasicShape { 
  
  float centre, x, y, r, s;
  String type;
  
  // (diameter, rotation, shape type)
  BasicShape (float d, float _r, String _type) {  
    
        type = _type;
        r = _r;
                
  }
  
  void update() { 
    
    x = mouseX;
    y = mouseY;
    
    s = shape_size.value_current;
   // stroke_width = shape_stroke.value_current;
       
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
      
      // Constrain coords to canvas
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



