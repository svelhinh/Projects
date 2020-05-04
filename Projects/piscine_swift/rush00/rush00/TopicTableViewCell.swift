//
//  TopicTableViewCell.swift
//  rush00
//
//  Created by Sergio VELHINHO on 6/18/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class TopicTableViewCell: UITableViewCell {

    @IBOutlet weak var photoImageView: UIImageView!
    @IBOutlet weak var msgLabel: UILabel!
    @IBOutlet weak var authorLabel: UILabel!
    @IBOutlet weak var dateLabel: UILabel!
    @IBOutlet weak var replyImageView: UIImageView!
    @IBOutlet weak var delButtonOutlet: UIButton!

    var topicMsg : (String, String, String, String, Bool, Int, Int)?
    {
        didSet
        {
            if let p = topicMsg
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
                
                if p.4
                {
                    if let url = NSURL(string: "https://cdn-img.easyicon.net/png/11744/1174476.gif")
                    {
                        if let data = NSData(contentsOf: url as URL)
                        {
                            replyImageView.image = UIImage(data: data as Data)
                        }
                    }
                }
                
                delButtonOutlet.isHidden = !(ViewController.LOGIN == p.1)
            }
        }
    }

    @IBAction func delButton(_ sender: Any) {
        ViewController.deleteMessage(id: (topicMsg?.5)!)
        
        var i = 0
        for tuple in Topics.topicMsgs {
            if tuple.1 == topicMsg?.1 && tuple.2 == topicMsg?.2 && tuple.3 == topicMsg?.3
            {
                Topics.topicMsgs.remove(at: i)
                break
            }
            i += 1
        }
        
        DispatchQueue.main.async {
            TopicViewController.it.tableView.reloadData()
        }
    }
}
