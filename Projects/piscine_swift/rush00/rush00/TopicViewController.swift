//
//  TopicViewController.swift
//  rush00
//
//  Created by Sergio VELHINHO on 6/18/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class TopicViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {

    static var it : TopicViewController!
    
    @IBOutlet weak var tableView: UITableView!

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Topics.topicMsgs.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "msgCell") as! TopicTableViewCell
        
        cell.topicMsg = Topics.topicMsgs[indexPath.row]
        cell.photoImageView.layer.cornerRadius = cell.photoImageView.frame.size.width / 2
        cell.photoImageView.clipsToBounds = true
        return cell
    }
    
    func topicReplies(_ login : String, _ date : String, _ msg : String, _ id : Int)
    {
        Topics.topicReplies.append((ViewController.loginToImageUrl(login), login, ViewController.parseDate(date), msg, id))
        //        print(Topics.topicMsgs)
    }
    
    
    
    override func viewWillAppear(_ animated: Bool) {
        //        tableView.reloadData()
        tableView.rowHeight = UITableViewAutomaticDimension
        tableView.estimatedRowHeight = 200.0
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        TopicViewController.it = self
        DispatchQueue.main.async {
            self.tableView.reloadData()
        }
    }
    
    override func shouldPerformSegue(withIdentifier identifier: String, sender: Any?) -> Bool
    {
        if identifier == "replySegue"
        {
            if let cell = sender as? TopicTableViewCell
            {
                if cell.topicMsg?.4 == false
                {
                    return false
                }
            }
        }
        return true
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "replySegue"
        {
            if segue.destination is RepliesViewController
            {
                if let cell = sender as? TopicTableViewCell
                {
                    Topics.topicReplies.removeAll()
                    showResponses(topic: (cell.topicMsg?.6)!, message: (cell.topicMsg?.5)!)
                    print(Topics.topicReplies)
                }
            }
        }
    }
    
    
    
    func showResponses(topic: Int, message: Int) {
        print("\nTopic Number \(topic) : Message Number \(message)")
        let url = URL(string: "https://api.intra.42.fr/v2/topics/\(topic)/messages/\(message)/messages")
        var request = URLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer \(ViewController.APPTOKEN)", forHTTPHeaderField: "Authorization")
        
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            //print(response)
            if let err = error {
                print(err)
            } else if let d = data {
                do {
                    print(type(of:try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers)))
                    if let array : NSArray = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSArray {
                        //print(array)
                        print(array.count)
                        for i in 0...array.count - 1 {
                            let dic : NSDictionary = (array[i] as? NSDictionary)!
                            let author : NSDictionary = (dic["author"] as? NSDictionary)!
                            if let login = author["login"], let date = dic["updated_at"], let content = dic["content"], let id = dic["id"] {
                                print("Response from \(login) at \(date)")
                                print(content)
                                print("")
                                self.topicReplies(login as! String, date as! String, content as! String, id as! Int)
                            }
                        }
                        DispatchQueue.main.async {
                            print(Topics.topicReplies)
                            RepliesViewController.it.tableView.reloadData()
                        }
                    }
                }
                catch (let err) {
                    print(err)
                }
            }
        }
        task.resume()
    }

}
