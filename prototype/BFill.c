void Boundary_fill(int x,int y,Color thisColor,Color boundary){
       glutSwapBuffers();
       Color nextpixel=getPixel(x,y);
   if((!((nextpixel.red==boundary.red)&&(nextpixel.blue==boundary.blue)&&(nextpixel.green==boundary.green)))
&& (!((nextpixel.red==thisColor.red)&&
(nextpixel.blue==thisColor.blue)&&
(nextpixel.green==thisColor.green)))){
       glBegin(GL_POINTS);
       glVertex2f(x,y);
       glEnd();
       Boundary_fill((x+1),y,thisColor,boundary);
       Boundary_fill((x-1),y,thisColor,boundary);
       Boundary_fill(x,(y+1),thisColor,boundary);
       Boundary_fill(x,(y-1),thisColor,boundary);
   }
       else
               printf("boundary reached\n");

}
