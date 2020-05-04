//
//  RepliesTableViewCell.swift
//  rush00
//
//  Created by Sergio VELHINHO on 6/18/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class RepliesTableViewCell: UITableViewCell {

    @IBOutlet weak var photoImageView: UIImageView!
    @IBOutlet weak var msgLabel: UILabel!
    @IBOutlet weak var authorLabel: UILabel!
    @IBOutlet weak var dateLabel: UILabel!
    @IBOutlet weak var delButtonOutlet: UIButton!

    var topicReply : (String, String, String, String, Int)?
        {
        didSet
        {
            if let p = topicReply
            {
                if let url = NSURL(string: p.0)
                {
                    if let data = NSData(contentsOf: url as URL)
                    {
                        photoImageView.image = UIImage(data: data as Data)
                    }
                }
                authorLabel?.text = p.1
                dateLabel?.text = p.2
                msgLabel?.text = p.3
                delButtonOutlet.isHidden = !(ViewController.LOGIN == p.1)
            }
        }
    }

    @IBAction func delButton(_ sender: Any) {
        ViewController.deleteMessage(id: (topicReply?.4)!)
        
        var i = 0
        for tuple in Topics.topicReplies {
            if tuple.1 == topicReply?.1 && tuple.2 == topicReply?.2 && tuple.3 == topicReply?.3
            {
                Topics.topicReplies.remove(at: i)
                break
            }
            i += 1
        }
        
        DispatchQueue.main.async {
            RepliesViewController.it.tableView.reloadData()
        }
    }

}
