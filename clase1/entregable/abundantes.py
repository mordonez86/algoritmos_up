# 1. Generar los primeros cuatro números abundantes.

# Un número abundante es todo número natural que cumple que, la suma de sus divisores propios es mayor que el propio número.

# Por ejemplo, 12 es abundante ya que sus divisores son 1, 2, 3, 4 y 6 y se cumple que 1+2+3+4+6=16, que es mayor que el propio 12.


abundante = 0
counter = 0


while(True):
    counter+=1
    total = 0
    for i in range(1,counter):
        if counter % i == 0:
            total+=i
    if total > counter:
        print(f"{counter} es abundante\n")
        abundante+=1
        print(f"la sumatoria hasta {counter} es {total}\n")
    if abundante >= 4:
        break
    