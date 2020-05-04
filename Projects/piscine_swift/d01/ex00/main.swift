import Foundation

var color: [Color] = Color.allColors
var value: [Value] = Value.allValues

for col in color
{
    print("\(col) : \(col.rawValue)")
}

for val in value {
    print("\(val) : \(val.rawValue)")
}

print("color nb : \(Color.allColors.count)")
print("value nb : \(Value.allValues.count)")