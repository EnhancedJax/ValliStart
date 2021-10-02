

[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Showfade
ActionList2=Hidefade
Showfade=[!SHowFade]
HideFade=[!HideFade]


; ---------------------------------------------------------------------------- ;
;                                     Load                                     ;
; ---------------------------------------------------------------------------- ;

[ACTIONLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Execute 1"][!Setvariable SliderX ([MeasureWin7Audio:0]/100*#SliderW#+#SliderM#)]#BT_CheckBluetooth#[!UpdateMeterGroup VolumeElements][!Redraw]
Disabled=1
Group=NUOL

[ACTIONUNLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Execute 2"]
Disabled=1
Group=NUOL

[ImportAnimated]
Measure=String
OnUpdateAction=[!SetVariable AnimatedA "255"][!SetVariable ActualBlur #Blur#][!UpdateMeasure FrostedGlass]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Container]
Meter=Shape
Y=#TweenNode1#
DynamicVariables=1
Shape=Rectangle 0,0,#W#,(#H#),(#edge#*#scale#),(#edge#*#scale#) | StrokeWidth 1 | Stroke Color #Border#
