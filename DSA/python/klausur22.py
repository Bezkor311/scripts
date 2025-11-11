class Node:
    def __init__(self, data):
        self.name = data
        self.con = []

    def add_con(self, c):
        self.con.append(c)

print("Geben Sie Verbindungen zwischen Gebäuden an (leere Zeile beendet)")

adj = {}          # statt 'dict'
lines = []        # statt 'list'
geb_list = []

# Eingabe sammeln
while True:
    inp = input("Gebäude A;Gebäude B: ")
    if inp.strip():
        lines.append(inp.strip())
    else:
        break

# Kanten parsen
for line in lines:
    pos = line.find(";")
    if pos == -1:               # kein Trenner -> Zeile ignorieren oder Fehler melden
        print(f"Ignoriere ungültige Zeile: {line!r}")
        continue
    a = line[:pos].strip()
    b = line[pos+1:].strip()
    if not a or not b:
        print(f"Ignoriere unvollständige Zeile: {line!r}")
        continue

    # sicheres Einfügen ohne KeyError
    adj.setdefault(a, []).append(b)
    # optional: sicherstellen, dass auch b als Knoten existiert
    adj.setdefault(b, adj.get(b, []))

# Nodes bauen
for name, cons in adj.items():
    g = Node(name)
    for c in cons:
        g.add_con(c)
    geb_list.append(g)

# Kontrolle: schönere Ausgabe
for g in geb_list:
    print(g.name, "->", ", ".join(g.con) if g.con else "—")

