//
//  ViewController.swift
//  swifty-companion
//
//  Created by Sergio VELHINHO on 12/18/18.
//  Copyright © 2018 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var loginSearchBar: UISearchBar!
    
    let UID = "e085511e2e00b2f9b62a49bc36acf6ab0061b9e6508d49357ac3c9fd68dfb867"
    let SECRET = "b6c913b465e798075abf1ae128cd956fefaa6b69436ac4992df25f92b96afc2e"
    let URI = "swifty-companion://swifty-companion"
    
    static var master:ViewController?
    static var APPTOKEN = ""
    static var USERTOKEN = ""
    static var LOGIN = ""
    var USERID = 0
    var searchedLogin = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        ViewController.master = self
        

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func SearchProfile(_ sender: Any) {
        searchedLogin = (loginSearchBar.text?.lowercased())!
        //Connection pour l'user
        if ViewController.USERTOKEN == "" {
            authenticateUser()
        }
        
        if ViewController.APPTOKEN == "" {
            authenticateApp()
        }
        
        if ViewController.USERTOKEN != "" && ViewController.APPTOKEN != "" {
            whoami()
        }
        
        //Connection a l'API pour le token
        //
    }
    
    func whoami() {
        let url = URL(string: "https://api.intra.42.fr/v2/me")
        var request = URLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer \(ViewController.USERTOKEN)", forHTTPHeaderField: "Authorization")
        
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            if let err = error {
                print(err)
            } else if let d = data {
                do {
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                        if let login = dic["login"] {
                            ViewController.LOGIN = login as! String
                        }
                        if let id = dic["id"] {
                            self.USERID = id as! Int
                        }
                        self.setUserId()
                    }
                }
                catch (let err) {
                    print(err)
                }
            }
        }
        task.resume()
    }
    
    func setUserId() {
        var request : URLRequest
        if let url = URL(string: "https://api.intra.42.fr/v2/users?filter[login]=\(searchedLogin)") {
            request = URLRequest(url: url)
        }
        else {
            DispatchQueue.main.async() {
                self.loginSearchBar.text = ""
                self.loginSearchBar.placeholder = "Bad format"
            }
            return
        }
        request.httpMethod = "GET"
        request.setValue("Bearer \(ViewController.APPTOKEN)", forHTTPHeaderField: "Authorization")
        
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            if let err = error {
                print(err)
            } else if let d = data {
                do {
                    if let array : NSArray = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSArray {
                        if array.count == 0 || self.searchedLogin == "" {
                            DispatchQueue.main.async {
                                self.loginSearchBar.text = ""
                                self.loginSearchBar.placeholder = "No Login Found"
                            }
                            return
                        }
                        let dic : NSDictionary = (array[0] as? NSDictionary)!
                        if let id = dic["id"] {
                            ProfileViewController.id = id as! Int
                            DispatchQueue.main.async {
                                self.performSegue(withIdentifier: "toProfile", sender: self)
                            }
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
    
    func exchangeCode (code: String) {
        let url = URL(string: "https://api.intra.42.fr/oauth/token?grant_type=authorization_code&client_id=\(UID)&client_secret=\(SECRET)&code=\(code)&redirect_uri=\(URI)")
        var request = URLRequest(url: url!)
        request.httpMethod = "POST"
        
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            if let err = error {
                print(err)
            } else if let d = data {
                do {
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                        if let tok = dic["access_token"] {
                            ViewController.USERTOKEN = tok as! String
                            self.whoami()
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
        let redirectUri = URI.addingPercentEncoding(withAllowedCharacters: .urlUserAllowed)
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
            if let err = error {
                print(err)
            } else if let d = data {
                do {
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                        if let tok = dic["access_token"] {
                            ViewController.APPTOKEN = tok as! String
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

