import turtle
import re

t = turtle.Turtle()
with open('turtle_script') as f:
    for line in f:
        nb = re.findall("\d+", line)
        if (len(nb) > 0):
            nb = int(nb[0])
        if line[:6] == 'Avance':
            t.forward(nb)
        if line[:6] == 'Recule':
            t.backward(nb)
        if line[:6] == 'Tourne':
            if line[7:13] == 'droite':
                t.right(nb)
            if line[7:13] == 'gauche':
                t.left(nb)