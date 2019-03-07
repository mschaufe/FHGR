%Array/Matrix
A=[1 2 3 4; 1 3 4 5; 7 2 3 4];
B=[1 2 5 6; 5 4 9 3; 3 5 2 4];
C=[1 2 5 6; 5 4 9 3; 3 5 2 4];
r=2
i=3;j=2;
n= 4;
m=3;
%Typ
size(A)
%Summe
A+B
%Skalarenmultiplikation
r*A
%Transponieren
transpose(A)
%Einträge ausgeben
A(i,j)
%Zeile ausgeben
A(i,:)
%Spalte ausgeben
A(:,j)
%Zeile löschen
A(i,:)=[]
%Spalte löschen
A(:,j)=[]
%Matrix ohne i,j Zeile und Spalte
C=A, B(i,:)=[],B(:,j)=[]
%Diagonale
diag(A)
diag([1 2 3 4 5])
%Obere Dreiecksmatrix
triu(A)
%untere Dreiecksmatrix
tril(A)
%Nullmatrix
zeros(i,j)
%einer Matrix
ones(i,j)
%Matrix mit 1 in der Diagonalen
eye(A) = diag([1,1,1,1])
%zufällge Matrix
randi([i j],m,n)
%Spur
trace(C)