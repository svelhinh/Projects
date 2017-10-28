let card1 : Card = Card(color: Color.Diamond, value: Value.Jack)
let card2 : Card = Card(color: Color.Diamond, value: Value.Queen)
let card3 : Card = Card(color: Color.Diamond, value: Value.Jack)

//init
print(card1)
print(card2)
print(card3)

//isEqual
print("card1 isEqual card2 : \(card1.isEqual(card2))")
print("card1 isEqual card3 : \(card1.isEqual(card3))")
print("card1 isEqual card2 : \(card2.isEqual(card3))")

//==
print("card1 == card2 : \(card1 == card2)")
print("card1 == card3 : \(card1 == card3)")
print("card2 == card3 : \(card2 == card3)")