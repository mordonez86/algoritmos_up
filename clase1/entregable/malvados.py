# 2. Ingresar números hasta leer un cero. Se pide informar la cantidad de números malvados leídos.

# Un Número malvado es todo número natural cuya expresión en base 2 (binaria) contiene un número par de unos. Por ejemplo 12 , y 15 son números malvados ya que 12=11002 y 15=11112.

numero = int(input("ingrese el numero: "))


while (True):
    resultado = numero // 2
    resto= numero % 2    
    print(f"{numero} dividido 2 es {resultado}  y el resto es {resto}  ")
    while(resultado > 0):
        resultado = resultado // 2
        print(f"a{resultado} dividido 2 es {resultado}  y el resto es {resto}  ")
        resto= resultado % 2
    break
        
    
        
        
    