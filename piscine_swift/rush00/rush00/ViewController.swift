//
//  ViewController.swift
//  rush00
//
//  Created by Sergio VELHINHO on 6/17/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {

    static var it : ViewController!
    
    @IBOutlet weak var tableView: UITableView!
    
    static var canRefreshTableView : Bool = false

    let UID = "47d7156f81c9a79e9e8ac631aaf8da3e6f13f1fc327886e37cd174f6fc6f6726"
    let SECRET = "9dc38f803c4e9fc5118daa2ecc24ef0bae1141d45cd062f55d66a9fb5de10eb0"
    let URI = "rush00://rush00"
    
    static var master:ViewController?
    static var APPTOKEN = ""
    static var USERTOKEN = ""
    static var LOGIN = ""
    var USERID = 0

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Topics.topic.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "topicCell") as! ForumTableViewCell
        cell.topic = Topics.topic[indexPath.row]
        cell.photoImageView.layer.cornerRadius = cell.photoImageView.frame.size.width / 2
        cell.photoImageView.clipsToBounds = true
        return cell
    }
    
    override func viewWillAppear(_ animated: Bool) {
        //        tableView.reloadData()
        tableView.rowHeight = UITableViewAutomaticDimension
        tableView.estimatedRowHeight = 200.0
    }
    
    static func loginToImageUrl(_ login : String) -> String
    {
        return "https://cdn.intra.42.fr/users/medium_" + login + ".jpg"
    }
    
    static func parseDate(_ date : String) -> String
    {
        if let range = date.range(of: "T") {
            let dateTmp = date.substring(to: range.upperBound)
            let finalDate = dateTmp.substring(to: dateTmp.index(before: dateTmp.endIndex))
            return finalDate
        }
        return date
    }
    
    func topicList(_ title : String, _ login : String, _ date : String, _ id : Int)
    {
        Topics.topic.append((ViewController.loginToImageUrl(login), title, login, ViewController.parseDate(date), id))
//        print(Topics.topic)
        
        DispatchQueue.main.async {
            self.tableView.reloadData()
        }
    }
    
    func topicMsgs(_ login : String, _ date : String, _ msg : String, _ hasReplies : Bool, _ idMsg : Int, _ id : Int)
    {
        Topics.topicMsgs.append((ViewController.loginToImageUrl(login), login, ViewController.parseDate(date), msg, hasReplies, idMsg, id))
//        print(Topics.topicMsgs)
    }
    
    @IBAction func logOutButton(_ sender: Any)
    {
        logOut()
        Topics.topic.removeAll()
        performSegue(withIdentifier: "logoutUnwindSegue", sender: self)
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "topicSegue"
        {
            if segue.destination is TopicViewController
            {
                if let cell = sender as? ForumTableViewCell
                {
                    Topics.topicMsgs.removeAll()
                    showMessages(id: (cell.topic?.4)!)
//                    print(Topics.topicMsgs)
                }
            }
        }
    }
    
//    override func viewDidAppear(_ animated: Bool) {
//        Topics.topic.removeAll()
//        showTopics()
//    }
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        ViewController.it = self
        // Do any additional setup after loading the view, typically from a nib.
        
        ViewController.master = self
        
        //Connection pour l'user
        authenticateUser()
        
        //Connection a l'API pour le token
        authenticateApp()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func showTopics() {
        let url = URL(string: "https://api.intra.42.fr/v2/topics.json?page[size]=100")
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
//                    print(type(of:try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers)))
                    if let array : NSArray = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSArray {
//                        print(array)
//                        print(array.count)
                        for i in 0...array.count - 1 {
                            let dic : NSDictionary = (array[i] as? NSDictionary)!
                            let author : NSDictionary = (dic["author"] as? NSDictionary)!
                            if let name = dic["name"], let login = author["login"], let update = dic["updated_at"], let id = dic["id"] {
//                                print(name)
//                                print(login)
//                                print(update)
//                                print(id)
                                self.topicList(name as! String, login as! String, update as! String, id as! Int)
                            }
//                            print("")
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
    
    func whoAmI(code: String) {
        let url = URL(string: "https://api.intra.42.fr/v2/me")
        var request = URLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer \(ViewController.USERTOKEN)", forHTTPHeaderField: "Authorization")
        
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            //print(response)
            if let err = error {
                print(err)
            } else if let d = data {
                do {
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                        //print(dic)
                        if let login = dic["login"] {
                            ViewController.LOGIN = login as! String
                        }
                        if let id = dic["id"] {
                            self.USERID = id as! Int
                        }
//                        print("Login : \(self.LOGIN)\nID : \(self.USERID)")
                        self.showTopics()
                    }
                }
                catch (let err) {
                    print(err)
                }
            }
        }
        task.resume()
    }
    
    func exchangeCode (code: String) {
        let url = URL(string: "https://api.intra.42.fr/oauth/token?grant_type=authorization_code&client_id=\(UID)&client_secret=\(SECRET)&code=\(code)&redirect_uri=\(URI)")
        var request = URLRequest(url: url!)
        request.httpMethod = "POST"
        
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            //print(response)
            if let err = error {
                print(err)
            } else if let d = data {
                do {
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                        //print(dic)
                        if let tok = dic["access_token"] {
                            ViewController.USERTOKEN = tok as! String
//                            print("User token : " + self.USERTOKEN)
                            self.whoAmI(code: code)
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
    
    func authenticateUser() {
        let redirectUri = "rush00://rush00".addingPercentEncoding(withAllowedCharacters: .urlUserAllowed)
        let urlString = "https://api.intra.42.fr/oauth/authorize?client_id=\(UID)&redirect_uri=\(redirectUri!)&response_type=code&scope=public%20forum&state=test"
        if let url = URL(string: urlString) {
            UIApplication.shared.open(url, options: [:], completionHandler: nil)
        } else {
            print("url error")
        }
    }
    
    func authenticateApp() {
        let url = URL(string: "https://api.intra.42.fr/oauth/token")
        var request = URLRequest(url: url!)
        request.httpMethod = "POST"
        request.setValue("application/x-www-form-urlencoded;charset=UTF-8", forHTTPHeaderField: "Content-Type")
        request.httpBody = "grant_type=client_credentials&client_id=\(UID)&client_secret=\(SECRET)".data(using: String.Encoding.utf8)
        
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            //print(response)
            if let err = error {
                print(err)
            } else if let d = data {
                do {
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                        //print(dic)
                        if let tok = dic["access_token"] {
                            ViewController.APPTOKEN = tok as! String
//                            print("My token : " + self.APPTOKEN)
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

    func logOut() {
        ViewController.USERTOKEN = ""
        ViewController.LOGIN = ""
        self.USERID = 0
    }
    
    func showMessages(id: Int) {
//        print("\nTopic Number \(id)")
        let url = URL(string: "https://api.intra.42.fr/v2/topics/\(id)/messages")
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
                            if let login = author["login"], let date = dic["updated_at"], let content = dic["content"], let replies = dic["replies"], let idMsg = dic["id"]
                            {
                                var hasReplies = false
                                
//                                print("\(login) at \(date)")
                                if (replies as AnyObject).count != 0 {
                                    hasReplies = true
//                                    print("REPLIES")
                                }
//                                print(content)
//                                print("")
                                self.topicMsgs(login as! String, date as! String, content as! String, hasReplies, idMsg as! Int, id)
                            }
                        }
                        DispatchQueue.main.async {
//                            print(Topics.topicMsgs)
                            TopicViewController.it.tableView.reloadData()
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
    
    static func deleteTopic(id: Int) {
        print("\nDeletion Topic Number \(id)")
        let url = URL(string: "https://api.intra.42.fr/v2/topics/\(id)")
        var request = URLRequest(url: url!)
        request.httpMethod = "DELETE"
        request.setValue("Bearer \(ViewController.USERTOKEN)", forHTTPHeaderField: "Authorization")
        
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            //print(response)
            if let err = error {
                print(error)
            } else if let d = data {
                do {
                    print(type(of:try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers)))
                    if let array : NSArray = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSArray {
                        //print(array)
                    }
                }
                catch (let err) {
                    print(err)
                }
            }
        }
        task.resume()
    }
    
    
    static func deleteMessage(id: Int) {
        print("\nDeletion Message Number \(id)")
        let url = URL(string: "https://api.intra.42.fr/v2/messages/\(id)")
        var request = URLRequest(url: url!)
        request.httpMethod = "DELETE"
        request.setValue("Bearer \(ViewController.USERTOKEN)", forHTTPHeaderField: "Authorization")
        
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

