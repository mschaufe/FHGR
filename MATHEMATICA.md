# Mathematica Cheat Sheet
   ## 0 Eingabe ##
   
   ## 1 Vektoren ##
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
   
   ## 2 Funktionen ##
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
   ## 3 Plot ##
   
   ### 2D Plot ###
   
   ```
   Plot[Sin[x], {x, 0, 6 Pi}]
   ```
   
   ### Plot Optionen ###
   
   #### Frame ####
   Umrandet die Grafik
   ```
   Frame -> True
   ```
   
   #### PlotRange ####
   Koordinatenbereich der Grafik
   ```
   PlotRange -> {{0, 5}, {0, 20}}
   ```
   y,x
   
   #### Grid ####
   Linienfarbe
   ```   
   GridLinesStyle -> LightGray
   ```
   Abstand der Linien
   ``` 
   GridLines -> {Range[0, 5], Range[0, 20,2]}
   ``` 
   
   #### AspectRatio ####
   Hier kann das Seitenverhältnis angegeben werden. 
   ``` 
   AspectRatio -> 0.5
   ``` 
   
   #### SetOptions ####
   ```
   SetOptions[Plot, PlotStyle -> Dashing[{.05, .01}]];
   ```
   
   
  
