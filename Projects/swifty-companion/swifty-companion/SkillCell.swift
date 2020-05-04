//
//  SkillCell.swift
//  swifty-companion
//
//  Created by Sergio VELHINHO on 12/21/18.
//  Copyright © 2018 Sergio VELHINHO. All rights reserved.
//

import UIKit

class SkillCell: UITableViewCell {

    @IBOutlet weak var skillLabel: UILabel!
    @IBOutlet weak var skillProgressBar: UIProgressView!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
