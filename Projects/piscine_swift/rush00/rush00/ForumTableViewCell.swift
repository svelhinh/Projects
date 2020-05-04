//
//  TopicTableViewCell.swift
//  rush00
//
//  Created by Sergio VELHINHO on 6/17/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ForumTableViewCell: UITableViewCell {

    @IBOutlet weak var photoImageView: UIImageView!
    @IBOutlet weak var topicTitleLabel: UILabel!
    @IBOutlet weak var topicAuthorLabel: UILabel!
    @IBOutlet weak var topicDateLabel: UILabel!
    @IBOutlet weak var delButtonOutlet: UIButton!

    var topic : (String, String, String, String, Int)?
    {
        didSet
        {
            if let p = topic
            {
                if let url = NSURL(string: p.0)
                {
                    if let data = NSData(contentsOf: url as URL)
                    {
                        photoImageView.image = UIImage(data: data as Data)
                    }
                }
                topicTitleLabel?.text = p.1
                topicAuthorLabel?.text = p.2
                topicDateLabel?.text = p.3
                delButtonOutlet.isHidden = !(ViewController.LOGIN == p.2)
            }
        }
    }

    @IBAction func delButton(_ sender: Any) {
        ViewController.deleteTopic(id: (topic?.4)!)
        
        var i = 0
        for tuple in Topics.topic {
            if tuple.1 == topic?.1 && tuple.2 == topic?.2 && tuple.3 == topic?.3
            {
                Topics.topic.remove(at: i)
                break
            }
            i += 1
        }

        DispatchQueue.main.async {
            ViewController.it.tableView.reloadData()
        }
    }

}
