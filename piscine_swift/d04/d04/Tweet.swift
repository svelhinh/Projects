//
//  Tweet.swift
//  d04
//
//  Created by Sergio VELHINHO on 6/15/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import Foundation

struct Tweet : CustomStringConvertible {
    let name : String
    let text : String
    
    var description: String {
        return name + " " + text
    }
}
