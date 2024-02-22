unit Unit2;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, DB, ADODB, ExtCtrls, pngimage, Spin;

type
  TForm2 = class(TForm)
    btn1: TButton;
    redt1: TRichEdit;
    Graph1: TADOTable;
    img1: TImage;
    sedt1: TSpinEdit;
    sedt2: TSpinEdit;
    tblPoint: TADOTable;

    procedure btn1Click(Sender: TObject);
    procedure pnl1Click(Sender: TObject);
    procedure sedt1Change(Sender: TObject);
  private
    { Private declarations }
    Distance : array['A'..'O'] of Integer;
    PVertex : array['A'..'O'] of char;
    cEnd:char;
    procedure showtable;
    function GetDistance ( C1, C2 :char):integer;
    function Point1(c:char):integer;
    function Point2(c:char):integer;

  public
    { Public declarations }
  end;

var
  Form2: TForm2;

implementation

{$R *.dfm}

procedure TForm2.btn1Click(Sender: TObject);
var
iLess,iEnds:integer;
  C1,C2,cLess,cFinale,cStart: Char;
Visited,Unvisited,sMessage:string;
  I: Integer;
begin
Graph1.Open;
iEnds:=Graph1.RecordCount;
cEnd:='A';
inc(cEnd,iEnds-1);

 for C1 := 'A' to cEnd do
 begin
  pVertex[C1]:=' ';
  Distance[C1]:=1000000;
  Unvisited:=Unvisited+c1+',';
 end;
 cStart:=upcase(Inputbox('','Start Point','')[1]);
 Distance[cStart]:=0;


repeat
 iLess:=1000000;
 for c1 := 'A' to cEnd do
  if (Distance[c1]<iLess) and (pos(c1+',',Unvisited)<>0)then
  begin
    iLess:=Distance[c1];
    cLess:=c1
  end;

 Delete(Unvisited,pos(cLess+',',Unvisited),2);
 //ShowMessage(Unvisited);

 for C2 := 'A' to cEnd do
  if GetDistance(cLess,c2)<>0 then
   if Distance[cLess]+ GetDistance(cLess,c2) <= Distance[c2] then
   begin
    Distance[c2] := Distance[cLess]+ GetDistance(cLess,c2) ;
    PVertex[c2]:=cLess;
    showtable;
    //showmessage('')
   end;
until  Length( Unvisited) = 0 ;
img1.Picture.LoadFromFile('Screenshot.bmp');

img1.Canvas.Pen.Color := clAqua;
 img1.Canvas.Pen.Width := 5;
 img1.Canvas.Pen.Style := psSolid;

cFinale:=upcase(Inputbox('','End Point','')[1]);
sMessage:=cFinale;
img1.Canvas.PenPos := Point(Point1(cFinale),Point2(cFinale));
repeat
   sMessage:=PVertex[cFinale]+' => '+sMessage;
   cFinale:=PVertex[cFinale];
  img1.Canvas.LineTo(Point1(cFinale),Point2(cFinale));
until (cFinale=cStart);
 redt1.Lines.Add(#13+sMessage);

end;

function TForm2.GetDistance(C1, C2: char): integer;
begin
 Graph1.Open;
 Graph1.First;
 while not Graph1.eof do
 begin
   if Graph1['Top']= c1 then
    Result:=Graph1[c2];
   Graph1.Next
 end;
end;

procedure TForm2.pnl1Click(Sender: TObject);

var
dc: THandle;
begin
//dc := GetDC(Pnl1.Handle);
//MoveToEx(dc, 10, 10, nil); { MoveTo() is obsolete... }
//LineTo(dc, 90, 90);
//ReleaseDC(Pnl1.Handle, dc);

end;

function TForm2.Point1(c: char): integer;
begin
 tblPoint.Open;
 tblpoint.First;
 while not tblPoint.eof do
 begin
   if tblPoint['Point']=c then
    Result:= tblPoint['Point1'];
    tblPoint.Next
 end;
end;

function TForm2.Point2(c: char): integer;
begin
 tblPoint.Open;
 tblpoint.First;
 while not tblPoint.eof do
 begin
   if tblPoint['Point']=c then
    Result:= tblPoint['Point2'] ;
   tblPoint.Next
 end;
end;

procedure TForm2.sedt1Change(Sender: TObject);
begin
 img1.Picture.LoadFromFile('Screenshot.bmp');

 img1.Canvas.Pen.Color := clAqua;
 img1.Canvas.Pen.Width := 5;
 img1.Canvas.Pen.Style := psSolid;

 img1.Canvas.PenPos := Point(sedt1.value,sedt2.value);
 img1.Canvas.LineTo(sedt1.value,sedt2.value);
end;

procedure TForm2.showtable;
var
  c: Char;
begin
redt1.Clear;
 for c := 'A' to 'O' do
  redt1.Lines.Add(c+#9+IntToStr(distance[c])+#9+PVertex[c])
end;

end.
