
const tak = (x, y, z) => {
    if (y < x) {
        return tak(
            tak(x-1, y, z),
            tak(y-1, z, x),
            tak(z-1, x, y)
        );
    } else {
        return z;
    }
};

console.log(tak(57, 49, 84));
