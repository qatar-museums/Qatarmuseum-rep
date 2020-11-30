
class BasicShape { 
  
  float centre, x, y, r, s, stroke_width;
  String type;
  
  //r is for rotation
  BasicShape (float d, float r, String _type) {  
    
        type = _type;
  }
  
  void update() { 
    
    x = mouseX;
    y = mouseY;
    
    // Calcalate
   // s = 2 + ( floor( shape_size.value_current - 598 ) * 5 );
    s = shape_size.value_current;
    stroke_width = shape_stroke.value_current;
       
  } 

  void reflect_90() {
   
    // Flip the coords
    if( mouseX > centre_x ){
      
        x = centre_x - (mouseX - centre_x);  
    }
    else{
     
        x = centre_x + (centre_x - mouseX);  
      
    }
    
  } 
  
  
  void reflect_270() {
   
    // Flip the coords
    if( mouseY > centre_y ){
      
        y = centre_y - (mouseY - centre_y);  
    }
    else{
     
        y = centre_y + (centre_y - mouseY);  
      
    }
    
  } 
  
  void reflect_opposite() { 
    
    // Flip the coords
    if( mouseX > centre_x ){
      
        x = centre_x - (mouseX - centre_x);  
    }
    else{
     
        x = centre_x + (centre_x - mouseX);  
      
    }
    
    
    if( mouseY > centre_y ){
      
        y = centre_y - (mouseY - centre_y);  
    }
    else{
     
        y = centre_y + (centre_y - mouseY);  
      
    }
   
       
  } 
  
  void draw_shape(){
      
      x = constrain( x, canvas_x, canvas_x + canvas_size);
      y = constrain( y, canvas_y, canvas_y + canvas_size);
      
      noFill();
    
      if( type == "circle"){  
  
          stroke(0);
          strokeWeight( stroke_width + 2 );
          ellipse(x,y, s,s);
          
          stroke(255);
          strokeWeight( stroke_width );
          ellipse(x,y, s,s);
          
      }
      
      else if (type == "rect"){
      
          stroke(0);
          strokeWeight( stroke_width + 2 );
          rect(x-(s/2),y-(s/2), s,s);
          
          stroke(255);
          strokeWeight( stroke_width );
          rect(x-(s/2),y-(s/2), s,s);
      
      }
    
  }
  
}
