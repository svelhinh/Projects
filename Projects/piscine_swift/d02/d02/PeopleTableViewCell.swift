//
//  PeopleTableViewCell.swift
//  d02
//
//  Created by Sergio VELHINHO on 6/13/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class PeopleTableViewCell: UITableViewCell {
    
    @IBOutlet weak var nameLabel: UILabel!
    @IBOutlet weak var dateLabel: UILabel!
    @IBOutlet weak var descriptionTextView: UITextView!

    var people : (String, String, String)?
    {
        didSet
        {
            if let p = people
            {
                nameLabel?.text = p.0
                descriptionTextView?.text = p.1
                dateLabel?.text = p.2
            }
        }
    }
    
    
}
