import Foundation

var t = Deck(mustBeShuffled: false)

print(">>>>>SORTED FALSE<<<<< : \(t)")
//52 print de la methode draw
for i in 0..<52 {
    print(t.draw()!)
}

let uno = Card(color: Color.Club, value: Value.Ace)
//outs false
print(">>>>>>>OUTS<<<<<<< : \(t.outs)")
t.fold(c: uno)
//f.fold(c: dos)
print("DISCARD : \(t.discards)")
var f = Deck(mustBeShuffled: true)
print(">>>>>SORTED TRUE<<<<< : \(f)")
//52 print de la methode draw
for i in 0..<52 {
    print(f.draw()!)
}
let dos = Card(color: Color.Spade, value: Value.Jack)
print(">>>>>>>OUTS<<<<<<< : \(t.outs)")
f.fold(c: dos)
print("DISCARD : \(f.discards)")