import Foundation

class Deck : NSObject
{
    init(mustBeShuffled : Bool) {
        if mustBeShuffled
        {
            cards.shuffle()
        }
    }
    
    func draw() -> Card? {
        let tmpCard = cards[0]
        cards.remove(at: 0)
        outs.append(tmpCard)
        return tmpCard
    }
    
    func fold(c : Card)
    {
        if outs.contains(c)
        {
            discards.append(c)
            outs.remove(at: outs.index(of: c)!)
        }
    }
    
    static let allSpades : [Card] = Value.allValues.map({
        Card(color: Color.Spade, value: $0)
    })
    
    static let allDiamonds : [Card] = Value.allValues.map({
        Card(color: Color.Diamond, value: $0)
    })
    
    static let allHearts : [Card] = Value.allValues.map({
        Card(color: Color.Heart, value: $0)
    })
    
    static let allClubs : [Card] = Value.allValues.map({
        Card(color: Color.Club, value: $0)
    })
    
    static let allCards : [Card] = allSpades + allDiamonds + allHearts + allClubs
    
    var cards : [Card] = allCards
    var discards : [Card] = []
    var outs : [Card] = []
    
    override var description: String
    {
        return "\(self.cards)"
    }
}

extension Array
{
    mutating func shuffle() {
        for i in 0 ..< self.capacity {
            let rand = Int(arc4random_uniform(UInt32(i)))
            var a = self[rand]
            var b = self[i]
            swap(&a, &b)
            
            self[rand] = a
            self[i] = b
        }
    }
}