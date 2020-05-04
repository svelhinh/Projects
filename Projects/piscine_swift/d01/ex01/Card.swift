import Foundation

class   Card : NSObject
{
    var color: Color
    var value: Value
    
    init(color: Color, value: Value) {
        self.color = color
        self.value = value
    }
    
    override var description: String
    {
        return "(\(value.rawValue), \(color))"
    }
    
    override func isEqual(_ object: Any?) -> Bool {
        let card = object as? Card
        return self.color == card?.color && self.value == card?.value
    }
}

func ==(card1 : Card, card2 : Card) -> Bool
{
    return card1.color == card2.color && card1.value == card2.value
}