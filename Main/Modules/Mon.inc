; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
MonHeight=160

[SettingImport3]
Measure=String
String=#Monitor#
DynamicVariables=1
IfMatch=1
IfMatchAction=[!SetOption MonBox1 Monitor "Fill Color #Accent#"][!SetOption MonBox2 Monitor "Fill Color 0,0,0,0"][!SetOption MonBox3 Monitor "Fill Color 0,0,0,0"][!SetOption MonBox4 Monitor "Fill Color 0,0,0,0"]
IfMatch2=2
IfMatchAction2=[!SetOption MonBox2 Monitor "Fill Color #Accent#"][!SetOption MonBox1 Monitor "Fill Color 0,0,0,0"][!SetOption MonBox3 Monitor "Fill Color 0,0,0,0"][!SetOption MonBox4 Monitor "Fill Color 0,0,0,0"]
IfMatch3=3
IfMatchAction3=[!SetOption MonBox3 Monitor "Fill Color #Accent#"][!SetOption MonBox2 Monitor "Fill Color 0,0,0,0"][!SetOption MonBox1 Monitor "Fill Color 0,0,0,0"][!SetOption MonBox4 Monitor "Fill Color 0,0,0,0"]
IfMatch4=4
IfMatchAction4=[!SetOption MonBox4 Monitor "Fill Color #Accent#"][!SetOption MonBox2 Monitor "Fill Color 0,0,0,0"][!SetOption MonBox3 Monitor "Fill Color 0,0,0,0"][!SetOption MonBox1 Monitor "Fill Color 0,0,0,0"]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[MonStyle]
X=((#MonW#/2-64*#Scale#/2)+20*#Scale#)R
Y=(-#MonW#/2.2/2+64*#Scale#/2)r
Shape=Rectangle 0,0,#MonW#,(#MonW#/2.2),(#Corner#*3),(#Corner#*3) | StrokeWidth (#Stroke#*2) | Stroke Color #BoxBorder#,(#Alpha#*0.5) | Extend This
Shape2=Rectangle (8*#Scale#),(7*#Scale#),(4*#Scale#),(#MonW#/2.2-7*2*#Scale#),(#Corner#*2),(#Corner#*2) | StrokeWidth 0 | Extend Monitor
Monitor=Fill Color 0,0,0,0
This=Fill Color #DarkColor#,(#Alpha#*0.1)
Container=Container
Group=Monboxes
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #DarkColor#,(#Alpha#*0.4)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #DarkColor#,(#Alpha#*0.1)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[MonIconStyle]
X=(#MonW#/2-64*#Scale#/2)r
Y=(#MonW#/2.2/2-64*#Scale#/2)r
W=(64*#Scale#)
Container=Container
[MonTextStyle]
X=(20*#Scale#+#MonW#)r
Y=r
StringAlign=Center
FontColor=#DarkColor#
FontSize=(10*#Scale#)
Container=Container

[MonSubtitle]
Meter=String
X=(25*#Scale#)
Y=(25*#Scale#)R
MeterStyle=RegularText
Text=Monitor Configuration
FontColor=#DarkColor#,200
Container=Container
[MonBox1]
Meter=Shape
x=r
y=(10*#Scale#)R
LeftMouseUpAction=["DisplaySwitch.exe" "/internal"][!SetVariable Monitor 1][!WriteKeyValue Variables Monitor 1 "#@#Vars.inc"][!UpdateMeasure SettingImport4][!UpdateMeterGroup MonBoxes][!Redraw]
meterstyle=monstyle
[MonIcon1]
Meter=Image
ImageTint=#FontColor#
ImageName=#@#Icons\Single.png
MeterStyle=MonIconStyle
[MonBox2]
Meter=Shape
meterstyle=monstyle
LeftMouseUpAction=["DisplaySwitch.exe" "/double"][!SetVariable Monitor 2][!WriteKeyValue Variables Monitor 2 "#@#Vars.inc"][!UpdateMeasure SettingImport4][!UpdateMeterGroup MonBoxes][!Redraw]
[MonIcon2]
Meter=Image
ImageTint=#FontColor#
ImageName=#@#Icons\Duplicate.png
MeterStyle=MonIconStyle
[MonBox3]
Meter=Shape
LeftMouseUpAction=["DisplaySwitch.exe" "/extend"][!SetVariable Monitor 3][!WriteKeyValue Variables Monitor 3 "#@#Vars.inc"][!UpdateMeasure SettingImport4][!UpdateMeterGroup MonBoxes][!Redraw]
meterstyle=monstyle
[MonIcon3]
Meter=Image
ImageTint=#FontColor#
ImageName=#@#Icons\Extend.png
MeterStyle=MonIconStyle
[MonBox4]
Meter=Shape
LeftMouseUpAction=["DisplaySwitch.exe" "/external"][!SetVariable Monitor 4][!WriteKeyValue Variables Monitor 4 "#@#Vars.inc"][!UpdateMeasure SettingImport4][!UpdateMeterGroup MonBoxes][!Redraw]
meterstyle=monstyle
[MonIcon4]
Meter=Image
ImageTint=#FontColor#
ImageName=#@#Icons\Second.png
MeterStyle=MonIconStyle
[MonText1]
Meter=String
X=(25*#Scale#+#MonW#/2)
Y=(65*#Scale#)r
Text=Single
MeterStyle=RegularText | MonTextStyle
[MonText2]
Meter=String
Text=Duplicate
MeterStyle=RegularText | MonTextStyle
[MonText3]
Meter=String
Text=Extend
MeterStyle=RegularText | MonTextStyle
[MonText4]
Meter=String
Text=Second
MeterStyle=RegularText | MonTextStyle

[MonAnchor]
Meter=String
Y=(45*#Scale#)r
DynamicVariables=1
Container=Container