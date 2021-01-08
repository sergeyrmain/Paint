#include "pch.h"
#include "So_spray.h"

IMPLEMENT_SERIAL(So_spray, SO_shape, 1)


So_spray::So_spray() {	addPoints(); };
So_spray::So_spray(int size, COLORREF front, COLORREF back):SO_shape(size,front,back)
{
	addPoints(); // Create K (K=50) points around the clicked point 
};
void So_spray::drawShape(CPaintDC& dc) {
	for (int i = 0; i < 50; i++)
	{
		//Set 1 Pixel with a point around the clicked point
		randomPixel.SetPoint(getBegin().x + Dx[i], getBegin().y + Dy[i]); 
		dc.SetPixel(randomPixel,_front ); //Draw Pixel on the Canvas
	}
};
// Create K (K=50) Points around the clicked point 
void So_spray::addPoints() {
	for (int i = 0; i < 50; i++)
	{
		Dx.push_back((rand() % (30))); //push Dx vector array random value (X values)
		Dy.push_back((rand() % (30))); //push Dy vector array random value (Y values)
	}
};
