# Mathematica Cheat Sheet
   ## 0 Eingabe ##
   
   ## 1 Vektoren :triangular_ruler: ##
   ### Betrag eines Vektors
   Der Betrag eines Vektors entspricht der Länge dieses Vektors.
   ```
   Norm[{x, y, z}]
   ```
   ### Kreuzprodukt
   Bei einem Vektorprodukt zweier Vektoren entsteht ein neuer Vektor. Dieser Vektor steht senkrecht auf den beiden Ausgangsvektoren und ist ein Normalenvektor der von den Ausgangsvektoren aufgespannten Ebene und der Betrag dieses Vektors ist ein Maß für die Fläche des aufgespannten Parallelogramms.
   ```
   Cross[{a, b, c}, {x, y, z}]
   ```
   oder 
   ```
   {a, b, c}\[Cross]{x, y, z}
   ```
   Eingabe mit `esc` cross `esc`.
   
   ### Skalarprodukt
   Das Skalarprodukt benötigst du in der analytischen Geometrie sehr häufig. Du kannst es verwenden um den von zwei Vekoten aufgespannten Winkel oder die Fläche des dazugehörigen Parallelogramms zu berechnen. Weiter kannst du mit dem Skalarprodukt einfach Orthogonalität oder Kolliniarität nachweisen.
   ```
   {a, b, c} . {x, y, z}
   ```
   
   ## 2 Funktionen :crystal_ball:  ##
   Auf der linken Seite legen wir den Funktionsnamen fest, hier “f” und wählen einen Namen für das
Argument der Funktion “x”. Beachten Sie das wichtige “x_” auf der linken Seite, das ein sogenanntes
Pattern bezeichnet. Auf der rechten Seite von “:=” steht dann die eigentliche Fuktionsdefinition mit “x” als Argument, ohne dem “_”.<br><br>
   Definieren
   ```
   f[x_] := x^2
   ```
   Anwendung
   ```
   f[5]
   ```
   ## 3 Plot :chart_with_upwards_trend: ##
   
   ### 2D Plot ###
   
   ```
   Plot[Sin[x], {x, 0, 6 Pi}]
   ```
   
   ### Plot Optionen ###
   
   #### Frame ####
   Umrandet die Grafik
   ```
   Frame -> True
   FrameLabel -> {{"links", None}, {"unten", "oben"}}
   FrameTicks -> {{Automatic, None}, {Range[0, 20, 5], None}
   ```
   
   #### PlotRange ####
   Koordinatenbereich der Grafik (y,x)
   ```
   PlotRange -> {{0, 5}, {0, 20}}
   ```

   #### Grid ####
   Linienfarbe
   ```   
   GridLinesStyle -> LightGray
   GridLines -> {Range[0, 5], Range[0, 20,2]}
   ```
   
   #### AspectRatio ####
   Hier kann das Seitenverhältnis angegeben werden. 
   ``` 
   AspectRatio -> 0.5
   ``` 
   #### PlotStyle ####
   Mit Directive werden mehrere Styles kombiniert.
   ```
   PlotStyle -> Directive[Dashing[{.01, .01}], Red]
   ```
   
   #### SetOptions ####
   ```
   SetOptions[Plot,
     Frame -> True,
     FrameLabel -> {{"links", None}, {"unten", "oben"}},
     FrameTicks -> {{Automatic, None}, {Automatic, None}},
     GridLinesStyle -> LightGray,
     GridLines -> {Automatic, Automatic},
     PlotStyle -> Directive[Dashing[{.01, .01}], Red]
    ];
   ```
   
   ## 4 Import :customs: ##
   
   ### Microsoft Excel ###
   Importiert die Excel-Datei in Mathematica.

   ```
   Import["/Users/ms/Desktop/test.xlsx"]
   Import["/Users/ms/Desktop/test.xlsx", {"Data", 1, All, 2}]
   Import["/Users/ms/Desktop/test.xlsx", {"Data", 1, {1,3,66}, 2}]
   Import["/Users/ms/Desktop/test.xlsx", {"Data", 1, Range[1,5], 2}]
   ```
   Syntax:
   ```
   {"Data", # of sheet(s), # of row(s), # of column(s)}
   ```
   
   
  
