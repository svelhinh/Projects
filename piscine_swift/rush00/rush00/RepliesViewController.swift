//
//  RepliesViewController.swift
//  rush00
//
//  Created by Sergio VELHINHO on 6/18/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class RepliesViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    static var it : RepliesViewController!
    
    @IBOutlet weak var tableView: UITableView!

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Topics.topicReplies.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "replyCell") as! RepliesTableViewCell
        
        cell.topicReply = Topics.topicReplies[indexPath.row]
        cell.photoImageView.layer.cornerRadius = cell.photoImageView.frame.size.width / 2
        cell.photoImageView.clipsToBounds = true
        return cell
    }
    
    override func viewWillAppear(_ animated: Bool) {
        //        tableView.reloadData()
        tableView.rowHeight = UITableViewAutomaticDimension
        tableView.estimatedRowHeight = 200.0
    }
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        RepliesViewController.it = self
    }

}
