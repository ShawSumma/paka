width = 500
height = width
wscale = 2 / width
m = 50
limit2 = 4
iters = 0

y = 0
while y <= height - 1:
    ci = 2 * y / height - 1
    xb = 0
    while xb <= width - 1:
        bits = 0
        xbb = xb+7
        if xbb < width:
            loopend = xbb
        else:
            loopend = width - 1
        x = xb
        while x <= loopend:
            bits *= 2
            zr = 0
            zi = 0
            zrq = 0
            ziq = 0
            cr = x * wscale - 3/2
            i = 1
            while i < m:
                zri = zr * zi
                zi = zri * 2 + ci
                zrq = zr * 2
                ziq = zi * 2
                iters += 1
                if zrq + ziq > limit2:
                    bits += 1
                i += 1
            x += 1
        if xbb >= width:
            x = width
            while x < xbb:
                bits += bits + 1
                x += 1
        xb += 8
    y += 1

print(iters)
