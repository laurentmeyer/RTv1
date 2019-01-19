
RANGEX = 16
RANGEY = 12

def printSphere(r, g, b, posX, posY):
    print("object sphere")
    print("color", r, g, b)
    print("position", posX, posY, 0)
    print("diffuse", 0.8)
    print("specular", 0.9)
    print("phong", 1000)
    print()

def rule3(actu, minIn, maxIn, minOut, maxOut):
    rapp = (actu - minIn) / (maxIn - minIn)
    return (rapp * (maxOut - minOut) + minOut)

for i in range(-RANGEX, RANGEX + 1, 2):
    for j in range(-RANGEY, RANGEY + 1, 2):
        r = rule3 (float(i), -RANGEX, RANGEX, 0., 1.)
        g = rule3 (float(j), -RANGEY, RANGEY, 0., 1.)
        # print(r, g)
        printSphere(g, 0.5, r, i, j)
