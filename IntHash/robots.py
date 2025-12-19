print("--Creando los robots en las ubicaciones--")
# Robots en las cuatro ubicaciones respectivamente
robots = []

print("ingrese la cantidad de robots en estadio, coliseo,centro y villa")
while True:
	robInp= input()
	if robInp == " ":
		break
	robots.append(robInp)


def vientorosa(robots):
	I =  random.randint(1, 4)
	robots[I] = robots[I] + 10

def lluviaAcida(robots):
	posicion = int(input( "ingrese el lugar de la lluvia acida fuerte"))
	robots[posicion] = 0

def fraseTia():
	print(" Ay, niño! ¿No puedes encontrar un juego donde no haya que matar? ¡Hay tantos que son más divertidos!")

def terminarjuego(robots):
	while I < len(robots):
		if robots[I] != 0:
			 break
		else:
			quit()

def misterio():
	print("has desbloqueado el final secreto")
	print("ahora, los robots fueron infectados con un virus que les hizo simpatizar con los humanos")
	print("ahora los robots y los humanos coexiste en paz gracias a un misterioso hacker")
	quit()

def seguridad(robots):
	i = 0 
	robots_i = []
	while i < len(robots): 
		robots_i.append(robots[i] / 2)
		i = i + 1
	robots = list(robots_i)
 
def mostrar(robots):
	print("EN:", robots[0], "|", "CO:", robots[1])
	print("CN:", robots[2], "|", "VO:",robots[3])

def disparar(robots):
	posicionADisparar = int(input("Ingrese la ubicación a disparar (0, 1, 2 o 3): "))
	robotsAmatar = int(input("robots a matar"))
	robbie = robots[posicionADisparar]
	robots[posicionADisparar] = int(robbie) - robotsAmatar

while(True):
	mostrar(robots)
	print("--Ingrese--")
	print("1) para disparar a los robots de una ubicación")
    print("2) para aaaaa")
	accion = int(input())
	if(accion == 1):
		disparar(robots)
    if(accion == 2):
    disparar(robots)
    
