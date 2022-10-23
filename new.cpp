//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "astrnew2.h"

#include "new.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CCALENDR"
#pragma resource "*.dfm"
TForm1 *Form1;
float tt,li1,li2,dl,l,dt,l1,l2;
float z,c1,c2,c3,c4,c5,dd1,dd2,dd3,id,jd;
long int y,m;
long int Y,M,D;
float p1,p2,a1,a2,t1,t2,a01,a02,a11,a12,w1,w2;
float a,w,t,v,v0,e;
float xx,yy;
float vH;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
CCalendar1->Year=(StrToInt(Edit1->Text));
CCalendar1->Month=(ComboBox2->ItemIndex+1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//----------------------------
p1=(ListBox1->ItemIndex)+1;
p2=(ListBox2->ItemIndex)+1;
if(p1==1){
 a1=0.38710;
 t1=87.97;
 a01=178.17907;
 a02=149474.07;
 w1=4.0923041;
}
if(p1==2){
 a1=0.72333;
 t1=224.70;
 a01=342.767053;
 a02=58519.212;
 w1=1.6021361;
}
if(p1==3){
 a1=1;
 t1=365.26;
 a01=99.697;
 a02=36000.769;
 w1=0.9855992;
}
if(p1==4){
 a1=1.52369;
t1=686.98;
a01=293.73733;
a02=19141.696;
w1=0.5240327;
}
if(p1==5){
 a1=5.2028;
 t1=4332.59;
 a01=238.04926;
 a02=3036.302;
 w1=0.0830911;
}
if(p1==6){
 a1=9.540;
 t1=10759.21;
 a01=266.56438;
 a02=1223.5099;
 w1=0.0334597;
}
if(p1==7){
 a1=19.18;
 t1=30685;
 a01=244.19747;
 a02=429.83655;
 w1=0.0117321;
}
if(p1==8){
 a1=30.07;
 t1=60188;
 a01=84.457994;
 a02=219.88591;
 w1=0.0059812;
//276.04598
}
if(p2==1){
 a2=0.38710;
 t2=87.97;
 a11=178.17907;
 a12=149474.07;
 w2=4.0923041;
}
if(p2==2){
 a2=0.72333;
 t2=224.70;
 a11=342.767053;
 a12=58519.212;
 w2=1.6021361;
}
if(p2==3){
 a2=1;
 t2=365.26;
 a11=99.697;
 a12=36000.769;
 w2=0.9855992;
}
if(p2==4){
 a2=1.52369;
 t2=686.98;
 a11=293.73733;
 a12=19141.696;
 w2=0.5240327;
}
if(p2==5){
 a2=5.2028;
 t2=4332.59;
 a11=238.04926;
 a12=3036.302;
 w2=0.0830911;
}
if(p2==6){
 a2=9.540;
 t2=10759.21;
 a11=266.56438;
 a12=1223.5099;
 w2=0.0334597;
}
if(p2==7){
a2=19.18;
 t2=30685;
 a11=244.19747;
 a12=429.83655;
 w2=0.0117321;
}
if(p2==8){
 a2=30.07;
 t2=60188;
 a11=84.457994;
 a12=219.88591;
 w2=0.0059812;
}
//----------------------------
if(p1!=0 && p2!=0 && p1!=p2 ){
Button2->Enabled=true;
a=(a1+a2)/2;
w=sqrt((w1-w2)*(w1-w2));
t=sqrt(a*a*a)*365.25/2;
v=29.78/(sqrt(a));
e=1-a2/a;
v0=v*sqrt((1-e)/(1+e));

Memo1->Lines->Clear();
Memo1->Lines->Add("I. Общие характеристики перелёта.");
Memo1->Lines->Add(" 1) Начальная скорость отн-но Солнца:");
Memo1->Lines->Add("  Vн = "+FloatToStr(v0)+" км/с.");
Memo1->Lines->Add(" 2) Средняя орбитальная скорость КК:");
Memo1->Lines->Add("  Va = "+FloatToStr(v)+" км/с.");
Memo1->Lines->Add(" 3) Время перелёта:");
Memo1->Lines->Add("  dT = "+FloatToStr(t)+" дня.");
Memo1->Lines->Add("II. Основные параметры орбиты КК:");
Memo1->Lines->Add(" 1) a = "+FloatToStr(a)+".");
Memo1->Lines->Add(" 2) e = "+FloatToStr(e)+".");
//-----------------------------
Y=CCalendar1->Year;
M=CCalendar1->Month;
D=CCalendar1->Day;
if(M>2){y=Y;m=M;}
else {y=Y-1;m=M+12;}
id=int(365.25*y)+int(30.6001*(m+1))+D+(2-int(Y/100)+int(Y/400))+1720994;
//-----------------------------
tt=(id-2415020)/36525;
li1=a01+a02*tt;
li2=a11+a12*tt;
li1=int(li1)%360+li1-int(li1);
li2=int(li2)%360+li2-int(li2);
dl=li2-li1;
if(p1<p2)l=180-360*t/t2;
else l=360*t/t2-180;
if(p1<p2){
if(li2>li1){
if(dl>l)dt=(dl-l)/w;
else dt=(360-l+dl)/w;
}
else dt=(360-abs(dl)-l)/w;
}
if(p2<p1){
if(li2<li1){
if(abs(dl)>abs(l))dt=(abs(dl)-abs(l))/w;
else dt=(360-abs(l)+abs(dl))/w;
}
else dt=(360-abs(l)-dl)/w;
}
jd=id;
id=id+abs(dt);
z=int(id);
if(z<2299161)c1=z;
else c1=z+1+int((z-1867216.25)/36524.25)-int(int((z-1867216.25)/36524.25)/4);
c2=c1+1524;
c3=int((c2-122.1)/365.25);
c4=int(365.25*c3);
c5=int((c2-c4)/30.6001);
dd3=c2-c4-int(30.6001*c5)+id-z;
if(c5<13.5)dd2=c5-1;
else dd2=c5-13;
if(dd2>2.5)dd1=c3-4716;
else dd1=c3-4715;
dd3=int(dd3);
Memo1->Lines->Add("III.");
Memo1->Lines->Add(" 1) Разность гелиоцентрических долгот на выбранную дату:");
Memo1->Lines->Add(" dL'="+FloatToStr(dl)+".");
Memo1->Lines->Add(" 2) Необходимая разность гелиоцентрических долгот в момент запуска:");
Memo1->Lines->Add(" dL="+FloatToStr(l)+".");
Memo1->Lines->Add(" 3) Необходимое время ожидания:");
Memo1->Lines->Add(" dT'="+FloatToStr(dt)+" дней.");
Memo1->Lines->Add(" 4) Выбранная дата в J.D. - "+FloatToStr(jd));
Memo1->Lines->Add(" 5) День запуска в J.D.     - "+FloatToStr(id));
Memo1->Lines->Add(" 6) Дата запуска: "+ FloatToStr(dd3)+"."+FloatToStr(dd2)+"."+FloatToStr(dd1));
}}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
Button2->Enabled=false;
Memo1->Clear();
}
//--------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Form2->Canvas->Pen->Style= psSolid;

Form2->Visible=true;
Form2->Canvas->Pen->Color=clYellow;
Form2->Canvas->Brush->Color=clYellow;
Form2->Canvas->Brush->Style=bsSolid;
Form2->Canvas->Ellipse(285,285,315,315);
Form2->Canvas->Brush->Style=bsClear;
Form2->Canvas->Pen->Color=clWhite;
Form2->Canvas->Ellipse(200,200,400,400);
Form2->Canvas->Ellipse(50,50,550,550);
Form2->Canvas->Brush->Color=clBlue;
Form2->Canvas->Brush->Style=bsSolid;
if(p1>p2){
Form2->Canvas->Brush->Style=bsClear;
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->Ellipse(180,200,420,550);
Form2->Canvas->Brush->Style=bsSolid;
Form2->Canvas->MoveTo(410,380);
Form2->Canvas->LineTo(430,380);
Form2->Canvas->LineTo(420,360);
Form2->Canvas->LineTo(410,380);
}
else {
Form2->Canvas->Brush->Style=bsClear;
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->Ellipse(180,50,420,400);
Form2->Canvas->Brush->Style=bsSolid;
Form2->Canvas->MoveTo(410,230);
Form2->Canvas->LineTo(430,230);
Form2->Canvas->LineTo(420,210);
Form2->Canvas->LineTo(410,230);
}
tt=(id-2415020)/36525;
l1=a01+a02*tt;
l2=a11+a12*tt;
l1=int(l1)%360+l1-int(l1);
l2=int(l2)%360+l2-int(l2);

Form2->Canvas->Brush->Color=clBlue;
Form2->Canvas->Pen->Color=clWhite;

if(p2>p1){
Form2->Canvas->MoveTo(300,300);
xx=300;
yy=400;
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->Ellipse(xx-10,yy-10,xx+10,yy+10);
Form2->Canvas->MoveTo(300,300);

yy=300+250*cos(l/57);
xx=300+250*sin(l/57);
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->Ellipse(xx-10,yy-10,xx+10,yy+10);
Form2->Canvas->MoveTo(300,300);

yy=300+550*cos(-l1/57);
xx=300+550*sin(-l1/57);
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->MoveTo(300,300);

Form2->Canvas->Pen->Style = psDot;

yy=300+100*cos((-l1+li1)/57);
xx=300+100*sin((-l1+li1)/57);
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->Brush->Color=clGreen;
Form2->Canvas->Ellipse(xx-10,yy-10,xx+10,yy+10);
Form2->Canvas->MoveTo(300,300);

yy=300+250*cos((-l1+li2)/57);
xx=300+250*sin((-l1+li2)/57);
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->Brush->Color=clGreen;
Form2->Canvas->Ellipse(xx-10,yy-10,xx+10,yy+10);
Form2->Canvas->MoveTo(300,300);
}
else {
Form2->Canvas->MoveTo(300,300);
xx=300;
yy=550;
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->Ellipse(xx-10,yy-10,xx+10,yy+10);
Form2->Canvas->MoveTo(300,300);

yy=300+100*cos(l/57);
xx=300+100*sin(l/57);
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->Ellipse(xx-10,yy-10,xx+10,yy+10);
Form2->Canvas->MoveTo(300,300);

yy=300+550*cos(-l1/57);
xx=300+550*sin(-l1/57);
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->MoveTo(300,300);

Form2->Canvas->Pen->Style = psDot;

yy=300+250*cos((-l1+li1)/57);
xx=300+250*sin((-l1+li1)/57);
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->Brush->Color=clGreen;
Form2->Canvas->Ellipse(xx-10,yy-10,xx+10,yy+10);
Form2->Canvas->MoveTo(300,300);

yy=300+100*cos((-l1+li2)/57);
xx=300+100*sin((-l1+li2)/57);
Form2->Canvas->LineTo(xx,yy);
Form2->Canvas->Brush->Color=clGreen;
Form2->Canvas->Ellipse(xx-10,yy-10,xx+10,yy+10);
Form2->Canvas->MoveTo(300,300);
}
}
//---------------------------------------------------------------------------


