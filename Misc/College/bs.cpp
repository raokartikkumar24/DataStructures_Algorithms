#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<dos.h>
const int w=15;
const int mar=10;

class shape
{
	protected:
	int xco,yco;
	int linecolour,fillcolour;
	public:
	shape()
	{
		xco=0;
		yco=0;
		linecolour=WHITE;
		fillcolour=WHITE;
	}
	void set(int x,int y,int lc,int fc)
	{
		xco=x;
		yco=y;
		linecolour=lc;
		fillcolour=fc;
	}
	void draw()
	{
		setcolor(linecolour);
		setfillstyle(SOLID_FILL,fillcolour);
	}
};
class ball:public shape
{
	public:
	ball():shape()
	{}
	void set(int x,int y,int lc,int fc)
	{
		shape::set(x,y,lc,fc);
	}
	void draw()
	{
		shape::draw();
		circle(xco,yco,w);
		floodfill(xco,yco,linecolour);
	}
};
class rect:public shape
{
	public:
	rect():shape()
	{}
	void set(int x,int y,int lc,int fc)
	{
		shape::set(x,y,lc,fc);
	}
	void draw()
	{
		shape::draw();
		rectangle(xco-w,yco-w,xco+w,yco+w);
		floodfill(xco,yco,linecolour);
		moveto(xco-w,yco+w);
		lineto(xco+w,yco-w);
	}
};
class tria:public shape
{
	public:
	tria():shape()
	{}
	void set(int x,int y,int lc,int fc)
	{
		shape::set(x,y,lc,fc);
	}
	void draw()
	{
		int triarray[]={xco,yco-w,xco+w,yco+w,xco-w,yco+w};
		shape::draw();
		fillpoly(3,triarray);
	}
};
class noshape:public shape
{
	public:
	void erase()
	{
		int border[]={xco-w-mar,yco-w-mar,xco+w+mar,yco-w-mar,xco+w+mar,yco+w+mar,xco-w-mar,yco+w+mar};
		setfillstyle(SOLID_FILL,DARKGRAY);
		fillpoly(4,border);
	}
};
class cherry:public ball,public noshape
{
	public:
	cherry():ball()
	{}
	void set(int x,int y)
	{
		ball::set(x,y,WHITE,RED);
		noshape::set(x,y,WHITE,RED);
	}
	void draw()
	{
		erase();
		ball::draw();
	}
};
class grape:public ball,public noshape
{
	public:
	grape():ball()
	{}
	void set(int x,int y)
	{
		ball::set(x,y,WHITE,BLUE);
		noshape::set(x,y,WHITE,BLUE);
	}
	void draw()
	{
		erase();
		ball::draw();
	}
};
class square:public rect,public noshape
{
	public:
	square():rect()
	{}
	void set(int x,int y)
	{
		rect::set(x,y,WHITE,CYAN);
		noshape::set(x,y,WHITE,CYAN);
	}
	void draw()
	{
		erase();
		rect::draw();
	}
};
class pyramid:public tria,public noshape
{
	public:
	pyramid():tria()
	{}
	void set(int x,int y)
	{
		tria::set(x,y,WHITE,GREEN);
		noshape::set(x,y,WHITE,GREEN);
	}
	void draw()
	{
		erase();
		tria::draw();
	}
};
class wheel:public shape
{
	private:
	cherry ch;
	grape gr;
	square sq;
	pyramid py;
	public:
	wheel()
	{
		xco=0;
		yco=0;
	}
	void set(int x,int y)
	{
		xco=x;yco=y;
		ch.set(xco,yco);
		gr.set(xco,yco);
		sq.set(xco,yco);
		py.set(xco,yco);
	}
	void draw();
};
void wheel::draw()
{
	setcolor(WHITE);
	rectangle(xco-w-mar,yco-w-mar,xco+w+mar,yco+w+mar);
	switch(random(4))
	{
		case 0:ch.draw();break;
		case 1:gr.draw();break;
		case 2:sq.draw();break;
		case 3:py.draw();break;
	}
}
void main()
{
	const int NUMBER=60;
	int driver,mode;
	driver=DETECT;
	initgraph(&driver,&mode,"\\tc\\bgi");
	randomize();

	wheel w1;
	wheel w2;
	wheel w3;

	w1.set(100,100);
	w2.set(160,100);
	w3.set(220,100);

	for(int j=0;j<NUMBER;j++)
	{
		w1.draw();
		w2.draw();
		w3.draw();
		sound(100);
		delay(20);
		nosound();
		delay(j*j/20);
	}
	sound(400);delay(700);
	sound(500);delay(900);nosound();
	getche();
	closegraph();
}