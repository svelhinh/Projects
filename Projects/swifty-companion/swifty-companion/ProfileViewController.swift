//
//  ProfileViewController.swift
//  swifty-companion
//
//  Created by Sergio VELHINHO on 12/19/18.
//  Copyright © 2018 Sergio VELHINHO. All rights reserved.
//

import UIKit

class ProfileViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {

    static var master:ProfileViewController?
    static var id : Int = 0

    var login = "-"
    var phone = "-"
    var location = "Unavailable"
    var correctionPts = "Correction : -"
    var level = 0.0
    var skillsNames = [String]()
    var skillsLevels = [Double]()
    var projectsNames = [String]()
    var projectsLevels = [Int]()

    @IBOutlet weak var profileImg: UIImageView!
    @IBOutlet weak var loginLabel: UILabel!
    @IBOutlet weak var phoneLabel: UILabel!
    @IBOutlet weak var locationLabel: UILabel!
    @IBOutlet weak var correctionPointsLabel: UILabel!
    @IBOutlet weak var levelLabel: UILabel!
    @IBOutlet weak var progressLevel: UIProgressView!
    @IBOutlet weak var skillsTableView: UITableView!
    @IBOutlet weak var projectsTableView: UITableView!
    
    @IBOutlet weak var globalView: UIView!
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        getProfile(id: ProfileViewController.id)
        ProfileViewController.master = self
        progressLevel.layer.cornerRadius = 8
        progressLevel.clipsToBounds = true
        progressLevel.layer.sublayers![1].cornerRadius = 8
        progressLevel.subviews[1].clipsToBounds = true
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    func getProfile(id: Int) {
        globalView.isHidden = true
        let url = URL(string: "https://api.intra.42.fr/v2/users/\(id)")
        var request = URLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer \(ViewController.APPTOKEN)", forHTTPHeaderField: "Authorization")

        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            if let err = error {
                print(err)
            } else if let d = data {
                do {
                    if let profile : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                        if let url = URL(string: profile["image_url"] as! String) {
                            self.downloadImage(from: url)
                        }
                        if let cursus : NSArray = profile["cursus_users"] as? NSArray {
                            if let cursus42 : NSDictionary = cursus[0] as? NSDictionary {
                                if let levelCursus42 : Double = cursus42["level"] as? Double {
                                    self.level = levelCursus42
                                }
                                if let skills : NSArray = cursus42["skills"] as? NSArray {
                                    if skills.count == 0 {
                                        self.skillsNames.append("-")
                                        self.skillsLevels.append(0)
                                    }
                                    else {
                                        for i in 0...skills.count - 1 {
                                            if let skill : NSDictionary = skills[i] as? NSDictionary {
                                                if let skillLevel : Double = skill["level"] as? Double {
                                                    if let skillName : String = skill["name"] as? String {
                                                        self.skillsNames.append(skillName)
                                                    }
                                                    else {
                                                        self.skillsNames.append("-")
                                                    }
                                                    self.skillsLevels.append(skillLevel)
                                                }
                                                else {
                                                    self.skillsLevels.append(0)
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if let projects : NSArray = profile["projects_users"] as? NSArray {
                            if projects.count == 0 {
                                self.projectsNames.append("-")
                                self.projectsLevels.append(0)
                            }
                            else {
                                for i in 0...projects.count - 1 {
                                    if let project : NSDictionary = projects[i] as? NSDictionary {
                                        if let projectInfos : NSDictionary = project["project"] as? NSDictionary {
                                            if let projectName : String = projectInfos["name"] as? String {
                                                self.projectsNames.append(projectName)
                                            }
                                            else {
                                                self.projectsNames.append("-")
                                            }
                                            
                                        }
                                        if let projectFinalMark : Int = project["final_mark"] as? Int {
                                            self.projectsLevels.append(projectFinalMark)
                                        }
                                        else {
                                            self.projectsLevels.append(0)
                                        }
                                    }
                                }
                            }
                        }
                        if let login : String = profile["login"] as? String {
                            self.login = login
                        }
                        if let phone : String = profile["phone"] as? String {
                            self.phone = phone
                        }
                        if let location : String = profile["location"] as? String {
                            self.location = location
                        }
                        if let correctionPts : Int = profile["correction_point"] as? Int {
                            self.correctionPts = "Evaluation Points : " + String(correctionPts)
                        }
                        DispatchQueue.main.async {
                            self.setProfileInfos()
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

    
    
    func getData(from url: URL, completion: @escaping (Data?, URLResponse?, Error?) -> ()) {
        URLSession.shared.dataTask(with: url, completionHandler: completion).resume()
    }
    
    func downloadImage(from url: URL) {
        print("Download Started")
        getData(from: url) { data, response, error in
            guard let data = data, error == nil else { return }
            print(response?.suggestedFilename ?? url.lastPathComponent)
            print("Download Finished")
            DispatchQueue.main.async() {
                self.profileImg.image = UIImage(data: data)
            }
        }
    }
    
    func setProfileInfos() {
        self.loginLabel.text = login
        self.phoneLabel.text = phone
        self.locationLabel.text = location
        self.correctionPointsLabel.text = correctionPts
        let levelInteger = Int(floor(level))
        let levelPercentage = modf(level).1
        self.levelLabel.text = "Level : " + String(levelInteger) + " - " + String(Int(floor(levelPercentage * 100))) + "%"
        self.progressLevel.progress = Float(levelPercentage)
        self.skillsTableView.reloadData()
        self.projectsTableView.reloadData()
        globalView.isHidden = false
    }

    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if tableView == skillsTableView {
            return self.skillsNames.count
        }
        else {
            return self.projectsNames.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if tableView == skillsTableView {
            let cell = tableView.dequeueReusableCell(withIdentifier: "cellSkill", for: indexPath) as! SkillCell

            cell.skillLabel.text = self.skillsNames[indexPath.row] + " - level " + String(self.skillsLevels[indexPath.row])
            cell.skillProgressBar.progress = Float(modf(self.skillsLevels[indexPath.row]).1)
            return cell
        }
        else {
            let cell = tableView.dequeueReusableCell(withIdentifier: "cellProject", for: indexPath) as! ProjectTableViewCell
            
            cell.projectLabel.text = self.projectsNames[indexPath.row] + " - " + String(self.projectsLevels[indexPath.row]) + "%"
            return cell
        }
    }

}
