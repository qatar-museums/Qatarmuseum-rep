
class standardButton { 
  
  float x, y, w, h, bg_color;
  String label, icon;
  

  standardButton (int  _x, int _y, int _w, int _h, String _label, String _icon) {  
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    label = _label;
    icon = _icon;
    
    bg_color = 70;
  }
  
  
  void draw() { 
    
    
     noStroke();
     fill(bg_color);
     rect( x, y, w, h );

     fill(160);
     textSize(12);
     text(label,x + 10,y + 20); 
     
     if( icon != "none"){
       
         draw_icon( icon );
       
     }
    
  }
  
  void draw_icon( String icon) { 
    
     if( icon == "circle" ){
      
       stroke( 255 );
       noFill();
       ellipse( x+ 50, y +50, 70, 70);
       
     }
     else if( icon == "rect" ){
      
       stroke( 255 );
       noFill();
       rect( x+ 15, y +15, 70, 70);
       
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
