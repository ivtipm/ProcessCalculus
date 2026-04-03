import sys

def triangle_square( base:float, height:float ) -> float:
    """..."""
    return base * height / 2.0


def main():

    print(sys.argv)

    # b = float(input("base = "))
    # h = float(input("height = "))
    b = float(sys.argv[1])
    h = float(sys.argv[2])

    S = triangle_square(b,h)
    print(f"S = {S:.2f}")


if __name__ == "__main__":
    main()
