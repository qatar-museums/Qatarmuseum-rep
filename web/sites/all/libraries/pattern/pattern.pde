/*

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
  int screen_h = 650;
  String language = document.getElementsByTagName('html')[0].getAttribute('lang') + "/"; // Either "ar/" or "en/"
  int res_screen_width = 0; // calculated screen width on setup, or when the window size changes
  int res_screen_height = 0; // calculated screen height on setup, or when the window size changes
  int res_mouseX = 0; // This will be calculated, based on the window size.
  int res_mouseY = 0;

  String mode = "circle"; // Starting shape
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
  int interface_w = screen_w - canvas_size;

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
  color current_color = c5_black; // Shape fill colour
  String color_mode = "off";
  int select_colour = 57;

// Initiate shapes
  int max_reflections = 8;
  int current_reflections = 8;
  BasicShape[] rect_array = new BasicShape[ max_reflections ];
  BasicShape[] circle_array = new BasicShape[ max_reflections ];
  BasicShape[] triangle_array = new BasicShape[ max_reflections ];
  BasicShape[] rhombus_array = new BasicShape[ max_reflections ];
  int icon_shape_size = floor(interface_w / 8.1); //65;
  int icon_bg_size = floor(interface_w / 6.2); //85; // 527 / 85 screen_w

// --- Initiate interface ---

// Alignment: May need updating to be responsive
  int btn_x = canvas_size + floor(interface_w / 13); // 682
  int stroke_y = floor( screen_h / 1.5 ); // 426;
  int reflect_y = stroke_y;//429;
  int reflect_x = floor(interface_w / 2.6);//202;  // interface_w / 245
  int btn_diff = floor(interface_w / 16.6); // 32
  // Add button size for all buttons
  // Add label positions (search for 'Labels')
  // Update over_palette


// Shape buttons
  standardButton triangle_btn = new standardButton( btn_x - 5, 63, icon_bg_size , icon_bg_size, "", "triangle");
  standardButton circle_btn = new standardButton( btn_x + 100, 63, icon_bg_size, icon_bg_size, "", "circle");
  standardButton rect_btn = new standardButton( btn_x + 220, 63, icon_bg_size, icon_bg_size, "", "rect");
  standardButton rhombus_btn = new standardButton( btn_x + 340, 63, icon_bg_size, icon_bg_size, "", "rhombus");

// Reflections
  standardButton reflect_2 = new standardButton( btn_x + reflect_x +(btn_diff* 0), canvas_y + reflect_y, 22, 22, "2", "");
  standardButton reflect_3 = new standardButton( btn_x + reflect_x +(btn_diff* 1), canvas_y + reflect_y, 22, 22, "3", "");
  standardButton reflect_4 = new standardButton( btn_x + reflect_x +(btn_diff* 2), canvas_y + reflect_y, 22, 22, "4", "");
  standardButton reflect_5 = new standardButton( btn_x + reflect_x +(btn_diff* 3), canvas_y + reflect_y, 22, 22, "5", "");
  standardButton reflect_6 = new standardButton( btn_x + reflect_x + (btn_diff* 0), canvas_y + reflect_y + 55, 22, 22, "6", "");
  standardButton reflect_7 = new standardButton( btn_x + reflect_x +(btn_diff* 1), canvas_y + reflect_y + 55, 22, 22, "7", "");
  standardButton reflect_8 = new standardButton( btn_x + reflect_x +(btn_diff* 2), canvas_y + reflect_y + 55, 22, 22, "8", "");

// Scale
  slidingScale shape_size = new slidingScale( btn_x + 410, 430, 118, "SIZE" );

// Stroke
  //standardButton set_stroke = new standardButton( btn_x, canvas_y  + 250, 115, 30, "Set stroke colour", "");
  standardButton thick_stroke = new standardButton( btn_x , canvas_y + stroke_y, 150, 30, "Thick", "thick");
  standardButton thin_stroke = new standardButton( btn_x - 5, 481, 150, 30, "Thin", "thin");
  standardButton no_stroke = new standardButton( btn_x - 3, 537, 150, 30, "None", "no_stroke");
  int thick_stroke_width = 10;
  int thin_stroke_width = 2;
  int no_stroke_width = 0;
  int stroke_bg_col = 82;

// Colour buttons
   int palette_size = 25;
   //colourButton bg_btn = new colourButton(800, 600, 70, 70, "Background");  // *** no longer needed? ***
   colourButton shape_colour_btn = new colourButton(btn_x, 240, 75, 75, "Shape");
   colourButton stroke_colour_btn = new colourButton(957, 240,75, 75, "Border");

// Footer buttons
  resetButton reset_btn = new resetButton( btn_x, 595, 150, 35, "START AGAIN", "reset");

// Images to load
  PImage shape_label, colour_label, border_label,size_label, reflections_label, start_again_label, select_background_colour, border_small, shape_small,
        thick_select, thin_select, none_select,
        thick_deselect, thin_deselect, none_deselect,
        deselect_1, deselect_2, deselect_3, deselect_4, deselect_5, deselect_6, deselect_7, deselect_8,
        select_1, select_2, select_3, select_4, select_5, select_6, select_7, select_8;



// -----------------------------------------------------------------------------------------------------------
// --------------------------------------------    Main    ---------------------------------------------------
// -----------------------------------------------------------------------------------------------------------


// Setup (initiation function for Processing)
void setup() {

  if(res_screen_width == 0) {

    calculateScreenSize();

  }

  size(screen_w, screen_h);

  // Put shapes into their array
    populate_shape_arrays();


  // Create canvas
    fill( canvas_bg_color );
    rect(canvas_x, canvas_y, canvas_size, canvas_size);
    pg = createGraphics(canvas_size, canvas_size, P2D);
    clear_canvas();

  // Set starting colour and stroke
    current_color = c5_black;
    thick_stroke.col_select = true;
    stroke_width = thick_stroke_width;



    // Images are loaded as text so we don't need to handle Arabic text and fonts
    String img_path = "/sites/all/libraries/pattern/img/";// //"/sites/all/libraries/pattern/img/"; // - OR -  /img/
    //String language = "en/"; // "en/" - OR - "ar/"

        // Images
           shape_label = loadImage(img_path + language +"shape.png");
           colour_label = loadImage(img_path + language+ "colour.png");
           border_label = loadImage(img_path + language+ "border.png");
           size_label = loadImage(img_path + language+ "size.png");
           reflections_label = loadImage(img_path + language+ "reflections.png");
           start_again_label = loadImage(img_path + language+ "start_again.png");
           select_background_colour = loadImage(img_path + "en/select_background_colour.png");
           border_small = loadImage(img_path + language+ "border_small.png");
           shape_small = loadImage(img_path + language+ "shape_small.png");

         // Border images
           thick_select = loadImage(img_path + language+ "thick_select.png");
           thin_select = loadImage(img_path + language+ "thin_select.png");
           none_select = loadImage(img_path + language+ "none_select.png");
           thick_deselect = loadImage(img_path + language+ "thick_deselect.png");
           thin_deselect = loadImage(img_path + language+ "thin_deselect.png");
           none_deselect = loadImage(img_path + language+ "none_deselect.png");

         // Reflection images
           deselect_1 = loadImage(img_path + "deselect_1.png");
           deselect_2 = loadImage(img_path + "deselect_2.png");
           deselect_3 = loadImage(img_path + "deselect_3.png");
           deselect_4 = loadImage(img_path + "deselect_4.png");
           deselect_5 = loadImage(img_path + "deselect_5.png");
           deselect_6 = loadImage(img_path + "deselect_6.png");
           deselect_7 = loadImage(img_path + "deselect_7.png");
           deselect_8 = loadImage(img_path + "deselect_8.png");

           select_1 = loadImage(img_path + "select_1.png");
           select_2 = loadImage(img_path + "select_2.png");
           select_3 = loadImage(img_path + "select_3.png");
           select_4 = loadImage(img_path + "select_4.png");
           select_5 = loadImage(img_path + "select_5.png");
           select_6 = loadImage(img_path + "select_6.png");
           select_7 = loadImage(img_path + "select_7.png");
           select_8 = loadImage(img_path + "select_8.png");

}

void calculateScreenSize() {

  res_screen_width = jQuery('canvas#__processing0').width();
  res_screen_height = jQuery('canvas#__processing0').height();

  //console.log(res_screen_width + " x " + res_screen_height);

}

// Draw (called per frame by Processing)
void draw() {

  // Calculate mouse position, adjusted for window size:
  res_mouseX = mouseX * ( ( screen_w ) / res_screen_width);    // OR: constrain(window.innerWidth, 0, 1174) );
  res_mouseY = mouseY * ( ( screen_h ) / res_screen_height);   // OR: constrain(window.innerHeight, 0, 650) );

  // Make lines smooth
    smooth();

  // Set background colour
    background(82, 82, 82);

  // Update buttons' selection state
    update_reflections_select_state();
    update_colors_bg_color();


  // Update canvas
    image(canvas_bg, canvas_x, canvas_y);

  // Calculate angle
    mouse_angle = get_angle();

  // Draw shapes
    if( res_mouseY < screen_h ){

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
    strokeWeight(1);
    rect(canvas_x, canvas_y, canvas_size, canvas_size);

  // Labels
    fill(255);
    textSize(12);
    image(shape_label, btn_x, 38);
    image(colour_label, btn_x, 200);
    image(border_label, btn_x, 388);
    image(size_label, btn_x + 386, 388);
    image(reflections_label, btn_x + reflect_x, 388);
    image(shape_small, btn_x,324);
    image(border_small, 954,324);

  // Draw buttons
    draw_btns();
    shape_size.draw_scale();

  // Update stroke button selection states
    draw_stroke_buttons();
    draw_reflection_buttons();


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
        dx = res_mouseX - centre_x;
        dy = res_mouseY - centre_y;

      // Q1
      return_value = degrees ( atan ( -dx / dy ) );

      // Q4
      if ( (res_mouseX < centre_x) && (res_mouseY < centre_y)) {
        return_value = 180 + ( 180 - degrees ( atan ( dx / dy ) ) );
      }
      // Q2
      else if ( (res_mouseX > centre_x) && (res_mouseY > centre_y)) {
        return_value = ( 180 - degrees ( atan ( dx / dy ) ) );
      }
      // Q3
      else if ( (res_mouseX < centre_x) && (res_mouseY > centre_y)) {
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

    reflect_2.draw();
    reflect_3.draw();
    reflect_4.draw();
    reflect_5.draw();
    reflect_6.draw();
    reflect_7.draw();
    reflect_8.draw();


    thick_stroke.draw();
    thin_stroke.draw();
    no_stroke.draw();

    shape_colour_btn.draw();
    stroke_colour_btn.draw();
}

// Reset canvas
void clear_canvas() {

    fill( canvas_bg_color );
    rect(canvas_x, canvas_y, canvas_size, canvas_size);
    canvas_bg  = get(canvas_x, canvas_y, canvas_size, canvas_size);
}


// Class used to create sliding scale
class slidingScale {

    int x, y, w, value_min, value_max, value_current, pointer_y;
    String label;
    Boolean drag_on = false;

    slidingScale (int  _x, int _y, int _w, String _label) {

      x = _x;
      y = _y;
      w = _w;
      label = _label;

      value_min = 2;
      value_max = 20;
      value_current = 0;

      if (label == "SIZE") {
        pointer_y = y + 45;
      }
      if (label == "Stroke width") { //////////////// THIS NO LONGER EXISTS
         pointer_y = x + 5;
      }
}

void draw_scale() {

    noStroke();
    fill(140);
    rect( x, y, 4, w);

    draw_pointer();

}

void draw_pointer() {

    if ( drag_on == true ) {

      pointer_y = res_mouseY;
      pointer_y = constrain( pointer_y, y, y + w - 10);
    }

    // Do some maths to work out reasonable output values for the sliders
    if (label == "SIZE") {

      value_current = 439 - ( ( ( floor( pointer_y) - y ) ) * 4 );//- x );// - (btn_x - 2) ) * 3 );
    }

    else if (label == "Stroke width") {

      value_current =  1 + ( floor( pointer_y) - y); // Remove this? ******
    }

    noStroke();
    fill(220);
    rect(x - 15 , pointer_y, 34, 13);
}

Boolean over_pointer() {

    Boolean x_true = false;
    Boolean y_true = false;
    Boolean both_true = false;


    if ( (res_mouseX < x + 30) && (res_mouseX > x - 10) ) {

      x_true = true;
    }

    if ( (res_mouseY > pointer_y) && (res_mouseY < pointer_y + 20) ) {

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


// Tests where the mouse is and assigns actions accordingly

void mouseReleased() { // This is only required in one circumstance

  shape_size.drag_on = false;

}

void mousePressed() {

  // Calculate mouse position, adjusted for window size:
  res_mouseX = mouseX * ( ( screen_w ) / res_screen_width);    // OR: constrain(window.innerWidth, 0, 1174) );
  res_mouseY = mouseY * ( ( screen_h ) / res_screen_height);   // OR: constrain(window.innerHeight, 0, 650) );

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

  // --- Slider ---

      if ( shape_size.over_pointer() ) {

        shape_size.drag_on = true;
      }

  // --- Reflection selection ---

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

         if( reset_btn.bg_palette_open == true){

             reset_btn.close_bg_palette();

         }
         else{

            reset_btn.open_bg_palette();

         }
      }
      else if ( reset_btn.over_palette() == "true" ){

         canvas_bg_color = reset_btn.bg_color;
         reset_btn.close_bg_palette();
         clear_canvas();
      }


  // --- Stroke selection ---

      else if ( thick_stroke.over_btn() ) {

          stroke_width = thick_stroke_width;
          stroke_bool = false;

          thick_stroke.col_select = true;
          thin_stroke.col_select = false;
          no_stroke.col_select = false;

      }
      else if ( thin_stroke.over_btn() ) {

        stroke_width = thin_stroke_width;
        stroke_bool = false;

        thick_stroke.col_select = false;
        thin_stroke.col_select = true;
        no_stroke.col_select = false;

      }
      else if ( no_stroke.over_btn() ) {

        stroke_width = no_stroke_width;
        stroke_bool = true;

        thick_stroke.col_select = false;
        thin_stroke.col_select = false;
        no_stroke.col_select = true;

      }

          // If the palette is clicked on, make it disappear
           else if ( shape_colour_btn.over_palette_btn() ) {

                //shape_colour_btn.palette_on = false;

            }

          // If the palette is clicked on, make it disappear
            if ( stroke_colour_btn.over_palette_btn() ) {

                stroke_colour_btn.palette_on = true; // (Only required if palettes are pop-ups)

            }



  // After each mouse click in the canvas, save the current canvas over the background image

    if ( (res_mouseX > canvas_x) && (res_mouseX < canvas_x + canvas_size) ) {

        if ( (res_mouseY > canvas_y) && (res_mouseY < canvas_y + canvas_size) ) {

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
      col_select = false; // Determines if this option is currently selected

  }

  void draw() {

     // Draw selection or background
         noStroke();
         if( (label == "Thick") ||  (label =="Thin") ||  (label == "None") ){
           bg_color = 82;
         }
         fill(bg_color);
         rect( x, y, w, h );

     // Draw icons
         if( icon != "none"){

             draw_icon( icon );

         }

  }

  void draw_icon( String icon) {

     if( icon == "circle" ){

       stroke( 0 );
       strokeWeight( 4 );
       fill(255);
       ellipse( x + 10 + (icon_shape_size / 2), y + 10 + (icon_shape_size / 2), icon_shape_size, icon_shape_size);

     }
     else if( icon == "rect" ){

       stroke( 0 );
       strokeWeight( 4 );
       fill(255);
       rect( x+ 9, y +10, icon_shape_size, icon_shape_size);

     }
     else if( icon == "triangle" ){

       stroke( 0 );
       strokeWeight( 4 );
       fill(255);
       triangle( x + 10, y + 10,   x + icon_shape_size, y + 10 + (icon_shape_size / 2),  x + 10, y + 10 + icon_shape_size);

     }
     else if( icon == "rhombus" ){

       stroke( 0 );
       strokeWeight( 4 );
       fill(255);

       pushMatrix();

             translate(x + 43, y +10);
             rotate( PI / 4);
             rect( 0,0, icon_shape_size - 18, icon_shape_size - 18);
       popMatrix();

     }

     else if( icon == "reset" ){

       fill(120);
       rect( x , y,  100, 30);

     }

  }

  // Test to see if the cursor is currently over this button
  Boolean over_btn(){

    Boolean x_true = false;
    Boolean y_true = false;
    Boolean both_true = false;

     if( (res_mouseX < x + w) && (res_mouseX > x) ){

         x_true = true;

     }

     if( (res_mouseY < y + h) && (res_mouseY > y) ){

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
  color bg_color, palette_selection;
  String label, icon;
  Boolean col_select, palette_on; // palette_on is only required if palette's are pop-ups

  colourButton (int  _x, int _y, int _w, int _h, String _label) {

      x = _x;
      y = _y;
      w = _w;
      h = _h;
      label = _label;

      bg_color = 255;
      col_select = false;
      palette_on = true;

      if( label == "Border"){
        palette_selection = c6_white;
      }

  }

  void draw() {

     noStroke();
     fill(palette_selection);
     rect( x, y, w, h );

     // Selection highlight
       if( col_select ){

         rect( x + 10, y + 10, w - 20, h - 20 );

       }

     // Draw palette
         //if(palette_on){

           draw_palette();

         //}

         color_mode = "on";
  }


  void draw_palette() {

        // Draw palette - 6 colours
           fill(c6_white);
           rect( 83 + x, y , palette_size,palette_size);
           fill(c5_black);
           rect( 83 + x + palette_size, y, palette_size,palette_size);
           fill(c2_orange);
           rect( 83 + x, y + palette_size,palette_size,palette_size);
           fill(c4_pink);
           rect( 83 +  x + palette_size, y+ palette_size,palette_size,palette_size);
           fill(c3_yellow);
           rect( 83 + x, y + (2 * palette_size),palette_size,palette_size);
           fill(c1_blue);
           rect( 83 + x + palette_size, y + (2* palette_size),palette_size,palette_size);

        //

  }

   // Test to see if the cursor is currently over the palette
  Boolean over_palette_btn(){


        Boolean x_true = false;
        Boolean y_true = false;
        Boolean both_true = false;

        // Set location of palette
        float p_x = x + 80;
        float p_y = y;
        float p_w = p_x + ( 2 * palette_size);
        float p_h = p_y + ( 3 * palette_size);


        // Test if a colour has been clicked
             // White
             if( (res_mouseX > p_x) && (res_mouseX < p_x + palette_size) ){

                  if( (res_mouseY > p_y) && (res_mouseY < p_y + palette_size) ){

                       palette_selection = c6_white;
                       apply_colour_selection();

                  }

             }
             // Black
             if( (res_mouseX > p_x + palette_size) && (res_mouseX < p_x + (2 * palette_size )) ){

                  if( (res_mouseY > p_y) && (res_mouseY < p_y + palette_size) ){

                       palette_selection = c5_black;
                       apply_colour_selection();

                   }

             }
             // Orange
             if( (res_mouseX > p_x ) && (res_mouseX < p_x + palette_size ) ) {

                  if( (res_mouseY > ( p_y + palette_size ) ) && (res_mouseY < p_y + ( 2 * palette_size ) ) ){

                       palette_selection = c2_orange;
                       apply_colour_selection();

                   }

             }
             // Pink
             if( (res_mouseX > p_x + palette_size) && (res_mouseX < p_x +( 2 * palette_size  ) ) ) {

                  if( (res_mouseY > ( p_y + palette_size ) ) && (res_mouseY < p_y + ( 2 * palette_size ) ) ){

                       palette_selection = c4_pink;
                       apply_colour_selection();

                   }

             }
             // Yellow
             if( (res_mouseX > p_x ) && (res_mouseX < p_x + palette_size ) ) {

                  if( (res_mouseY > p_y + ( 2 * palette_size ) ) && (res_mouseY < p_y + ( 3 * palette_size ) ) ){

                       palette_selection = c3_yellow;
                       apply_colour_selection();

                   }

             }
           // Blue
             if( (res_mouseX > ( p_x + palette_size) ) && (res_mouseX < p_x + ( 2 * palette_size ) ) ) {

                  if( (res_mouseY > p_y + ( 2 * palette_size ) ) && (res_mouseY < p_y + ( 3 * palette_size ) ) ){

                       palette_selection = c1_blue;
                       apply_colour_selection();

                   }

             }



        // Test whether the palette has been clicked at all
             if( (res_mouseX < p_x + p_w) && (res_mouseX > p_x) ){

                 x_true = true;

             }

             if( (res_mouseY < p_y + p_h) && (res_mouseY > p_y) ){

                 y_true = true;

             }

             if( x_true && y_true){

               both_true = true;

             }

             return both_true;

  }

  void apply_colour_selection(){

           // Apply chosen colour to either the stroke colour or fill colour
              if( label == "Border"){

                  stroke_color = palette_selection;

              }
              else if( label == "Shape"){

                  current_color = palette_selection;

              }
  }

  // Test to see if the cursor is currently over this button
  Boolean over_btn(){

    Boolean x_true = false;
    Boolean y_true = false;
    Boolean both_true = false;

     if( (res_mouseX < x + w) && (res_mouseX > x) ){

         x_true = true;

     }

     if( (res_mouseY < y + h) && (res_mouseY > y) ){

         y_true = true;

     }

     if( x_true && y_true){

       both_true = true;

     }

     return both_true;

  }

}

// --- (end of colourButton class) ---



// --- resetButton ---

class resetButton {

  float x, y, w, h, pal_y;
  color bg_color;
  String label, icon;
  Boolean col_select, bg_palette_open;

  resetButton (int  _x, int _y, int _w, int _h, String _label, String _icon) {  // *** _label is not needed, as there is only one of these buttons

      x = _x;
      y = _y;
      w = _w;
      h = _h;
      label = "Start again";
      icon = _icon;
      bg_palette_open = false;
      pal_y = 6;//palette_size - 1; // How far down the palette is
      bg_color = c5_black;


  }

  void draw(){

       noStroke();
       fill( 118 );
       rect( x, y, w, h );

       draw_reset_label();

       // Draw palette
         if( bg_palette_open == true ){

           draw_reset_palette();

         }

  }

  void draw_reset_label(){

      // select background colour
      // start again

      if( label == "Start again"){

         // Draw label
           image(start_again_label, x + 20, y  + 5 );

      }
      else{

            image(select_background_colour, x, y);
      }
  }

  // Test to see if the cursor is currently over this button
  String over_palette(){


        // Test here for each colour being hit, and return apt colour
        if( (res_mouseY > (y + pal_y))&& (res_mouseY < ( y + pal_y + palette_size) ) ){

          // White
              if( (res_mouseX > x + 175 ) && res_mouseX < (x + palette_size + 175 ) ){

                   bg_color = c6_white;
                   return "true";

              }

         // Black
              if( res_mouseX > x + 175 + (1 * palette_size) && res_mouseX < x + 175 + ( 2 * palette_size) ) {

                   bg_color = c5_black;
                   return "true";

              }

         // Orange
              if( res_mouseX > x+ 175  + (2 * palette_size) && res_mouseX < x + 175 + ( 3 * palette_size) ) {

                   bg_color = c2_orange;
                   return "true";

              }

         // Pink
              if( res_mouseX > x+ 175  + (3 * palette_size) && res_mouseX < x+ 175  + ( 4 * palette_size) ) {

                   bg_color = c4_pink;
                   return "true";

              }

         // Yellow
              if( res_mouseX > x+ 175  + (4 * palette_size) && res_mouseX < x + 175 + ( 5 * palette_size) ) {

                   bg_color = c3_yellow;
                   return "true";

              }

         // Blue
              if( res_mouseX > x+ 175  + (5 * palette_size) && res_mouseX < x+ 175  + ( 6 * palette_size) ) {

                   bg_color = c1_blue;
                   return "true";

              }
              else{
                 return "false";
              }

        }
        else{

             //bg_color = c5_black;
             return "false";
        }

  }

  // Test to see if the cursor is currently over this button
  Boolean over_btn(){

    Boolean x_true = false;
    Boolean y_true = false;
    Boolean both_true = false;

     if( (res_mouseX < x + w) && (res_mouseX > x) ){

         x_true = true;

     }

     if( (res_mouseY < y + h) && (res_mouseY > y) ){

         y_true = true;

     }

     if( x_true && y_true){

       both_true = true;

     }

     return both_true;

  }

  void open_bg_palette(){

      // Open it here
      bg_palette_open = true;
      reset_btn.label = "Select Background Colour";
  }

  void close_bg_palette(){

      // Close it here
      bg_palette_open = false;
      reset_btn.label = "Start again";

  }

  void draw_reset_palette(){

         // Draw palette - 6 colours
           fill(c6_white);
           rect(x + 175, y + pal_y, palette_size,palette_size);
           fill(c5_black);
           rect(x  + 175 + ( 1 * palette_size ), y + pal_y,palette_size,palette_size);
           fill(c2_orange);
           rect(x  + 175 + ( 2 * palette_size ), y + pal_y ,palette_size,palette_size);
           fill(c4_pink);
           rect(x + 175 + ( 3 * palette_size ), y + pal_y,palette_size,palette_size);
           fill(c3_yellow);
           rect(x + 175 + ( 4 * palette_size ), y + pal_y ,palette_size,palette_size);
           fill(c1_blue);
           rect(x + 175 + ( 5 * palette_size ),y + pal_y ,palette_size,palette_size);

  }

}

// ---- End of resetButton ---

void reset_colors() {

  // No longer needed.

}

void draw_reflection_buttons(){

    // 2
        if( reflect_2.col_select == true ){
            image(select_2, reflect_2.x, reflect_2.y);
        }
        else{
            image(deselect_2, reflect_2.x, reflect_2.y);
        }

    // 3
        if( reflect_3.col_select == true ){
            image(select_3, reflect_3.x, reflect_3.y);
        }
        else{
            image(deselect_3, reflect_3.x, reflect_3.y);
        }
    // 4
        if( reflect_4.col_select == true ){
            image(select_4, reflect_4.x, reflect_4.y);
        }
        else{
            image(deselect_4, reflect_4.x, reflect_4.y);
        }
    // 5
        if( reflect_5.col_select == true ){
            image(select_5, reflect_5.x, reflect_5.y);
        }
        else{
            image(deselect_5, reflect_5.x, reflect_5.y);
        }
    // 6
        if( reflect_6.col_select == true ){
            image(select_6, reflect_6.x, reflect_6.y);
        }
        else{
            image(deselect_6, reflect_6.x, reflect_6.y);
        }
    // 7
        if( reflect_7.col_select == true ){
            image(select_7, reflect_7.x, reflect_7.y);
        }
        else{
            image(deselect_7, reflect_7.x, reflect_7.y);
        }
    // 8
        if( reflect_8.col_select == true ){
            image(select_8, reflect_8.x, reflect_8.y);
        }
        else{
            image(deselect_8, reflect_8.x, reflect_8.y);
        }

}

// Update the colour of the stroke buttons in the interface to show current selection
void draw_stroke_buttons(){

  // Change appearance of buttons
     if( thick_stroke.col_select == false ){
       image(thick_deselect, thick_stroke.x + 7, thick_stroke.y);
     }
     else{
       image(thick_select, thick_stroke.x, thick_stroke.y);
     }

     if( thin_stroke.col_select == false ){
       image(thin_deselect, thin_stroke.x + 8, thin_stroke.y);
     }
     else{
       image(thin_select, thin_stroke.x, thin_stroke.y);
     }

     if( no_stroke.col_select == false ){
       image(none_deselect, no_stroke.x + 6, no_stroke.y);
     }
     else{
       image(none_select, no_stroke.x, no_stroke.y);
     }



}

// Update the colour of the colour buttons in the interface to show current selection
void update_colors_bg_color(){

    // No longer needed

}


// Update the colour of the reflection buttons in the interface
void update_reflections_select_state(){

  int default_col = 82;

  // Update shape backgroun state ********* Move this to a separate function. It does not belong in reflections.
      if( mode == "circle"){

        circle_btn.bg_color = select_colour;

        rect_btn.bg_color = default_col;
        triangle_btn.bg_color = default_col;
        rhombus_btn.bg_color = default_col;

      }
      else if( mode == "rect"){

        rect_btn.bg_color = select_colour;

        circle_btn.bg_color = default_col;
        triangle_btn.bg_color = default_col;
        rhombus_btn.bg_color = default_col;

      }
      else if( mode == "triangle"){

        triangle_btn.bg_color = select_colour;

        circle_btn.bg_color = default_col;
        rect_btn.bg_color = default_col;
        rhombus_btn.bg_color = default_col;

      }
      else if( mode == "rhombus"){

        rhombus_btn.bg_color = select_colour;

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


  // Update the background state of reflections

      if( current_reflections == 2 ){

          reset_reflect_bg_colors();
          reflect_2.col_select = true;

      }
      else if( current_reflections == 3 ){

          reset_reflect_bg_colors();
          reflect_3.col_select = true;

      }
      else if( current_reflections == 4 ){

          reset_reflect_bg_colors();
          reflect_4.col_select = true;

      }
      else if( current_reflections == 5 ){

          reset_reflect_bg_colors();
          reflect_5.col_select = true;

      }
      else if( current_reflections == 6 ){

          reset_reflect_bg_colors();
          reflect_6.col_select = true;

      }
      else if( current_reflections == 7 ){

          reset_reflect_bg_colors();
          reflect_7.col_select = true;

      }
      else if( current_reflections == 8 ){

          reset_reflect_bg_colors();
          reflect_8.col_select = true;

      }


}

// Set all reflection buttons back to default
void reset_reflect_bg_colors(){

    int default_col = 82;

    reflect_2.bg_color = default_col;
    reflect_3.bg_color = default_col;
    reflect_4.bg_color = default_col;
    reflect_5.bg_color = default_col;
    reflect_6.bg_color = default_col;
    reflect_7.bg_color = default_col;
    reflect_8.bg_color = default_col;

    reflect_2.col_select = false;
    reflect_3.col_select = false;
    reflect_4.col_select = false;
    reflect_5.col_select = false;
    reflect_6.col_select = false;
    reflect_7.col_select = false;
    reflect_8.col_select = false;

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

    x = res_mouseX;
    y = res_mouseY;

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
                    strokeCap(SQUARE);
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





