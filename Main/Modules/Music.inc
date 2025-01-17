; ---------------------------------------------------------------------------- ;
;                                     Music                                    ;
; ---------------------------------------------------------------------------- ;

[Variables]
MusicHeight=145

[MusicImg]
Meter=Image
Y=r
W=#W#
H=(145*#Scale#)
ImageAlpha=100
PreserveAspectRatio=2
ImageName=[mCover]
Container=Container
DynamicVariables=1
Group=Music

[MediaName]
Meter=String
X=(25*#Scale#)
Y=(25*#Scale#)r
W=(#W#-50*#scale#)
Clipstring=1
MeterStyle=SemiBoldText
MeasureName=mTrack
Container=Container
Group=Music

[MediaArtist]
Meter=String
X=r
Y=(10*#Scale#)R
FontSize=(10*#Scale#)
MeterStyle=RegularText
MeasureName=mArtist
Container=Container
Group=Music

[ProgBar]
Meter=Shape
X=(25*#Scale#)
Y=(40*#scale#)r
Shape=Line 0,0,(#W#-50*#Scale#),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color #FontColor#,150 | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,((#W#-50*#Scale#)*[mProgress]/100),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color #FontColor# | StrokeStartCap Round | StrokeEndCap Round
Shape3=Ellipse ((#W#-50*#Scale#)*[mProgress]/100),0,4,4 | strokeWidth 0 | Fill Color #FontColor#
DynamicVariables=1
UpdateDivider=1
Group=Music
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#W#-50*#Scale#)*100)"][!UpdateMeasure PosCalc]
Container=Container
[PosCalc]
Measure=calc
OnUpdateAction=[!CommandMeasure mState "SetPosition [PosCalc]"]
Disabled=1
DynamicVariables=1
Group=NUOL
Container=Container

[CurrentTime]
Meter=String
MeterStyle=RegularText
X=r
Y=R
FontColor=#FontColor#
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=mCurrentPosition
UpdateDivider=1
Group=Music
Container=Container
[MediaLength]
Meter=String
MeterStyle=RegularText
X=(#W#-50*#Scale#)r
Y=r
FontColor=#FontColor#
StringAlign=Right
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=mLength
Group=Music
Container=Container




[Heart]
Meter=Image
X=(#W#-200*#Scale#)
Y=(-50*#scale#)r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
Container=Container
[FullHeart]
ImageName=#@#Icons\HeartFull.png
LeftMouseUpAction=[!SetOption Heart MeterStyle EmptyHeart][!UpdateMeter Heart][!Redraw][!CommandMeasure mState "ToggleThumbsDown"]
[EmptyHeart]
ImageName=#@#Icons\Heart.png
LeftMouseUpAction=[!SetOption Heart MeterStyle Fullheart][!UpdateMeter Heart][!Redraw][!CommandMeasure mState "ToggleThumbsUp"]


[Previous]
Meter=Image
ImageName=#@#Icons\Previous.png
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
LeftMouseUpAction=[!CommandMeasure mState "Previous"]
Container=Container


[PlayPause]
Meter=Image
MeterStyle=
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
Container=Container
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure mState "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure mState "PlayPause"]

[Next]
Meter=Image
ImageName=#@#Icons\Next.png
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
LeftMouseUpAction=[!CommandMeasure mState "Next"]
Container=Container

[MusicAnchor]
Meter=String
Y=([MusicImg:Y]+[MusicImg:H]-#TweenNode1#)
DynamicVariables=1
Container=Container