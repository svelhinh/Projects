//
//  LocationTableViewCell.swift
//  d05
//
//  Created by Sergio VELHINHO on 6/19/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit
import CoreLocation

class LocationTableViewCell: UITableViewCell {

    @IBOutlet weak var locLabel: UILabel!
    
    var loc : (String, String, CLLocationCoordinate2D)?
        {
        didSet
        {
            if let p = loc
            {
                locLabel?.text = p.0
            }
        }
    }

}
